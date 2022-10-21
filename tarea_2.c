#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
//las 28 piezas
int piezas[28][2] = {{6,6},{6,5},{5,5},{6,4},{5,4},{4,4},{6,3},{5,3},{4,3},{3,3},{6,2},{5,2},{4,2},{3,2},{2,2},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,6},{0,5},{0,4},{0,3},{0,2},{0,1},{0,0}};
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
int crear_piezas(struct mazo *jugador){
    int posicion = 0;
    int numero = 0;
    int flag = 0;
    int mayor = 0;
    int suma = 0;
    srand(time(NULL));
    while (flag == 0){
        posicion = rand() % 27; //cambiar a 27
        if (piezas[posicion][0] == -1){
            continue;
        }
        suma = piezas[posicion][0] + piezas[posicion][1];
        if (suma > mayor){
            printf("Mayor actual: %d, %d\n", piezas[posicion][0], piezas[posicion][1]);
            mayor = suma;
        }
        if (numero == 0) {
            jugador->pieza1[0] = piezas[posicion][0];
            jugador->pieza1[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if (numero == 1) {
            jugador->pieza2[0] = piezas[posicion][0];
            jugador->pieza2[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if (numero == 2) {
            jugador->pieza3[0] = piezas[posicion][0];
            jugador->pieza3[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if (numero == 3){
            jugador->pieza4[0] = piezas[posicion][0];
            jugador->pieza4[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if (numero == 4){
            jugador->pieza5[0] = piezas[posicion][0];
            jugador->pieza5[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if(numero == 5){
            jugador->pieza6[0] = piezas[posicion][0];
            jugador->pieza6[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
        }
        else if(numero == 6){
            jugador->pieza7[0] = piezas[posicion][0];
            jugador->pieza7[1] = piezas[posicion][1];
            piezas[posicion][0] = -1;
            numero++;
            // flag = 1;
            return mayor;
        }

    }
    return mayor;
}


int main(){
    struct mazo p1;
    int mayor;
    mayor = crear_piezas(&p1);
    printf("%d\n",mayor);
    printf("Creado el mazo1\n");
    printf("%d, %d\n", p1.pieza1[0], p1.pieza1[1]);
    printf("%d, %d\n", p1.pieza2[0], p1.pieza2[1]);
    printf("%d, %d\n", p1.pieza3[0], p1.pieza3[1]);
    printf("%d, %d\n", p1.pieza4[0], p1.pieza4[1]);
    printf("%d, %d\n", p1.pieza5[0], p1.pieza5[1]);
    printf("%d, %d\n", p1.pieza6[0], p1.pieza6[1]);
    printf("%d, %d\n", p1.pieza7[0], p1.pieza7[1]);

    return 0;
}