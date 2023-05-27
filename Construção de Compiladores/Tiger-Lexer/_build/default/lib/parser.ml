
type token = 
  | WHILE
  | VAR
  | UMINUS
  | TYPE
  | TO
  | TIMES
  | THEN
  | STR of (string)
  | SEMICOLON
  | RPAREN
  | RBRACK
  | RBRACE
  | PLUS
  | OR
  | OF
  | NIL
  | NE
  | MINUS
  | LT
  | LPAREN
  | LET
  | LE
  | LBRACK
  | LBRACE
  | INT of (int)
  | IN
  | IF
  | ID of (Symbol.symbol)
  | GT
  | GE
  | FUNCTION
  | FOR
  | EQ
  | EOF
  | END
  | ELSE
  | DOT
  | DO
  | DIV
  | COMMA
  | COLON
  | BREAK
  | ASSIGN
  | ARRAY
  | AND
