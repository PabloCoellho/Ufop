{
  module L = Lexing

  type token = [%import: Parser.token] [@@deriving show]

  let illegal_character loc char =
    Error.error loc "illegal character '%c'" char

  let unterminated_comment loc =
    Error.error loc "unterminated comment"

  let unterminated_string loc =
    Error.error loc "unterminated string"

  let illegal_escape loc sequence =
    Error.error loc "illegal escape sequence: %s" sequence

  let str_incr_linenum str lexbuf =
    String.iter (function '\n' -> L.new_line lexbuf | _ -> ()) str

  let append_char str ch =
    str ^ (String.make 1 (Char.chr ch))
}

let spaces = [' ' '\t']+
let alpha = ['a'-'z' 'A'-'Z']
let digit = ['0'-'9']
let litint = digit+
let id = alpha+ (alpha | digit | '_')*

rule token = parse
  | spaces { token lexbuf }
  | '\n' { L.new_line lexbuf; token lexbuf }
  | litint as lxm { INT (int_of_string lxm) }
  | "/*" {comentario [lexbuf.L.lex_start_p] lexbuf }
  | '"' { string lexbuf.L.lex_start_p "" lexbuf }
  | "for" { FOR }
  | "while" { WHILE }
  | "break" { BREAK }
  | "let" { LET }
  | "in" { IN }
  | "nil" { NIL }
  | "to" { TO }
  | "end" { END }
  | "function" { FUNCTION }
  | "var" { VAR }
  | "type" { TYPE }
  | "array" { ARRAY }
  | "if" { IF }
  | "then" { THEN }
  | "else" { ELSE }
  | "do" { DO }
  | "of" { OF }
  | '(' { LPAREN }
  | ')' { RPAREN }
  | '[' { LBRACK }
  | ']' { RBRACK }
  | '{' { LBRACE }
  | '}' { RBRACE }
  | '.' { DOT }
  | ':' { COLON }
  | ',' { COMMA }
  | ';' { SEMICOLON }
  | '+' { PLUS } 
  | '-' { MINUS }
  | '*' { TIMES }
  | '/' { DIV }
  | '%' { UMINUS }
  | '=' { EQ }
  | "<>" { NE }
  | '<' { LT }
  | "<=" { LE }
  | '>' { GT }
  | ">=" { GE }
  | '&' { AND }
  | '|' { OR }
  | ":=" { ASSIGN }
  | id as lxm { ID (Symbol.symbol lxm) }
  | eof { EOF }
  | _ as lxm      { illegal_character (Location.curr_loc lexbuf) lxm }

and comentario nivel = parse 
  | "*/" { match nivel with
            | [_] -> token lexbuf
            | _::nivel' -> comentario nivel' lexbuf
            | [] -> failwith "erro na leitura do comentario"
          }
  | "/*" { comentario (lexbuf.L.lex_start_p :: nivel) lexbuf }
  | '\n' { L.new_line lexbuf; comentario nivel lexbuf }
  | eof { unterminated_comment (List.hd nivel, lexbuf.L.lex_start_p) }
  | _  { comentario nivel lexbuf }

and string pos buf = parse 
  | '"' { lexbuf.L.lex_start_p <- pos; STR buf }
  | "\\n" { string pos (buf ^ "\n") lexbuf }
  | "\\t" { string pos (buf ^ "\t") lexbuf }
  | "\\\"" { string pos (buf ^ "\"") lexbuf }
  | "\\\\" { string pos (buf ^ "\\") lexbuf }
  | "\\^" (['@' 'A'-'Z'] as x) { string pos (append_char buf (Char.code x - Char.code '@')) lexbuf }
  | "\\^" (['a'-'z'] as x) { string pos (append_char buf (Char.code x - Char.code 'a' + 1)) lexbuf }
  | "\\" (digit digit digit as x) { string pos (append_char buf (int_of_string x)) lexbuf }
  | "\\" ([' ' '\t' '\n'] + as x) "\\" { str_incr_linenum x lexbuf; string pos buf lexbuf }
  | "\\" _ as x { illegal_escape (lexbuf.L.lex_start_p, lexbuf.L.lex_curr_p) x }
  | [^ '\\' '"'] + as x { str_incr_linenum x lexbuf; string pos (buf ^ x) lexbuf }
  | eof { unterminated_string (pos, lexbuf.L.lex_start_p) }
