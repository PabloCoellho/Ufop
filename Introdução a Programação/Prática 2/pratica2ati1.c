#include <stdio.h>

int main(){
    char letra;
    printf("Digite uma letra\n");
    scanf("%c", &letra);
    if(letra=='a' || letra=='A' || letra=='e' || letra=='E' || letra=='i' 	|| letra=='I' || letra=='o' || letra=='O' || letra=='u' ||          	letra=='U')
    	printf("Ah letra '%c' e uma vogal\n", letra);
    if(letra!='a' && letra!='A' && letra!='e' && letra!='E' && letra!='i' 	&& letra!='I' && letra!='o' && letra!='O' && letra!='u' &&          	letra!='U')
    	printf("Ah letra '%c' nao e uma vogal\n", letra);
    return 0;
}
