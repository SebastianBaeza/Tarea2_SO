#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
//las 28 piezas
int piezas[7][2] = {{6,6},{6,5},{6,4},{6,3},{6,2},{6,1},{6,0}};
//mazo de cada jugador
struct mazo{
    int pieza1[2];
    int pieza2[2];
    int pieza3[2];
    int pieza4[2];
    int pieza5[2];
    int pieza6[2];
    int pieza7[2];
};
//el tablero de juego, solo me importa lo que hay a la izq y a la der,
//si pongo una pieza en la izq reemplazo el valor
struct colocar{
    int piezader[2];
    int piezaizq[2];
};
//quiero rellenar los mazos de los jugadores, el random es para que me de un numero del 0 al 27 para rellenar el mazo con la pieza
//en la posición del numero del arreglo piezas
void crear_piezas(struct mazo *jugador){
    int posicion = 0;
    printf("%s","hasta aca bien-1");
    // srand(time(NULL)); pass the srand() parameter  
    // printf("\n");  print the space 
    printf("\n%s","hasta aca bien0"); 
    for (int i = 0; i < 7; i++)  
    {  
         posicion=rand() % 7; //cambiar a 27
         printf("%s","hasta aca bien1");
         jugador->pieza1[0]=piezas[posicion][0];
         jugador->pieza1[1]=piezas[posicion][1];
         printf("%s","hasta aca bien2");
    }  

}
//esto no
/*
int* generar_pieza(){
    NULL;
}

//esto no
void inicializar_jugador(struct mazo *jugador){
    int*pieza;
    int flag=-1;
    while(flag==-1){
        pieza=generar_pieza();
        for(int i=0;i<2;i++){
            if(pieza[i]==jugador->pieza1[i]){
                
            }
        }
    }
    
    
    

}
*/
//el main
int main(){
    struct mazo *jugador1;
    crear_piezas(jugador1);
    printf("%d",*jugador1->pieza1);
    
    return 0;
}
