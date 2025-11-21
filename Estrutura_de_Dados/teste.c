#include <stdio.h>
#include <ctype.h>

int controleRepetir(){
    char tempC;
    do{
        printf("deseja repetir a operacao?\n");
        scanf(" %c", &tempC);
        if(!(tolower(tempC)=='s'||tolower(tempC)=='n'))
            printf("character invalido, digite novamente!\n");

        if(tolower(tempC)=='s')
            return 1;
        if(tolower(tempC)=='n')
            return 0;
    }while(!(tolower(tempC)=='s'||tolower(tempC)=='n'));
    return 0;
}

int main(void){
    int con=0;
    do{
        printf("%i\n", con);
        con++;
    }while(controleRepetir());

    return 0;
}