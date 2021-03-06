#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define TAMANHO 10

typedef enum {MORTO=0, VIVO} status; //MORTO == 0 | VIVO == 1

typedef struct {
    char vivoMorto;
    status estado;
    //int vizinhos;

} celula;

typedef struct {
    celula individuo;

} mapaMundo;

mapaMundo mapa[TAMANHO][TAMANHO]; //mapa 10x10

void montarMundo(){
    for(int i = 0; i <= 10; i++){

        for(int j = 0; j <= 10; j++){

                mapa[i][j].individuo.vivoMorto = ' ';
                mapa[i][j].individuo.estado = MORTO;
            }
    }
}

void individuosIniciais(){

    int n1 = 0;
    int n2 = 0;
    int i = 1;

    while(n1 != -1 && n2 != -1){

        printf("\n Selecione a posição (X, Y) do %dº indivíduo,no intervalo de 1 a 10\n", i);
        printf("    (Para terminar, selecione 99 nas duas posições)\n");
        scanf("%d", &n1);
        scanf("%d", &n2);

        if((n1 > 10 || n2 > 10) || (n1 == 0 || n2 == 0))
            printf("\nApenas valores de 1 a 10!\n");

        else if(n1 < -1 || n2 < -1)
            printf("\nNão são permitidos números negativos!\n");

        else{
            mapa[n1][n2].individuo.vivoMorto = '+';
            mapa[n1][n2].individuo.estado = VIVO;
            i++;
        }
    }

}

void mostrarMapa(){

    system("cls");
    for(int i = 0; i <= 10; i++){ //linha 0 e coluna 0 -> printar coordenadas
        printf("\n                ");

        for(int j = 0; j <= 10; j++){
            if(i == 0 && j != 0)
                printf("  %d  ", j);
            else{
                if(j == 0)
                    printf("\n               %d  ", i);
                else
                    printf("  %c  ", mapa[i][j].individuo.vivoMorto);
            }

        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    montarMundo();
    individuosIniciais();
    mostrarMapa();

    printf("\n\n\n\n");

    return 0;
}
