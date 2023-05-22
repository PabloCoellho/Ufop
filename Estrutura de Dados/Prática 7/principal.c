#include "pilha.h"
#include <stdio.h>
#include <string.h>

int main()
{
        Pilha pilha;
        char ch;
        Item item;
                
        Pilha_Inicia(&pilha);

        while (scanf("%c", &ch) != EOF)
        {
          item.paren = ch;     
          if (item.paren == '(') 
            Pilha_Push(&pilha, item);
          
          else if(item.paren == ')') {
            if (Pilha_EhVazia(&pilha)) {
              Pilha_Push(&pilha, item);
              break;
            }  

            Pilha_Pop(&pilha, &item);   
          }
        }
      

        if (Pilha_EhVazia(&pilha))
          printf("correto\n");
          
        else 
          printf("incorreto\n");

        Pilha_Esvazia(&pilha);

        return 0;//nao remova
}
