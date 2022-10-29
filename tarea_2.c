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
    // printf("%d\n",mayor);
    // printf("Creado el mazo\n");
    // printf("%d, %d\n", p1.pieza1[0], p1.pieza1[1]);
    // printf("%d, %d\n", p1.pieza2[0], p1.pieza2[1]);
    // printf("%d, %d\n", p1.pieza3[0], p1.pieza3[1]);
    // printf("%d, %d\n", p1.pieza4[0], p1.pieza4[1]);
    // printf("%d, %d\n", p1.pieza5[0], p1.pieza5[1]);
    // printf("%d, %d\n", p1.pieza6[0], p1.pieza6[1]);
    // printf("%d, %d\n", p1.pieza7[0], p1.pieza7[1]);
    int pipeP1[2], pipeP2[2], pipeP3[2], pipeP4[2];
    int pipe1P[2], pipe2P[2], pipe3P[2], pipe4P[2];
    // int pipe12[2];
    // int pipe23[2];
    // int pipe34[2];
    // int pipe41[2];

    pipe(pipeP1);
    pipe(pipeP2);
    pipe(pipeP3);
    pipe(pipeP4);
    pipe(pipe1P);
    pipe(pipe2P);
    pipe(pipe3P);
    pipe(pipe4P);
    // pipe(pipe12);
    // pipe(pipe23);
    // pipe(pipe34);
    // pipe(pipe41);
    int J1;
    int J2 = -1;
    int J3 = -1;
    int J4 = -1;
    int flag = 0;
    
    //J1: Jugador 1, manual
    J1 = fork();
    if (J1 == 0) {
        printf("Entrando al proceso hijo: J1\n");
        close(pipeP1[1]);// cierro el modo de Escritura del padre al hijo
        close(pipe1P[0]);// cierro el modo de Lectura del hijo al padre
        struct mazo p1;
        int mayor1 = crear_piezas(&p1);

        printf("Creado el mazo\n");
        printf("%d, %d\n", p1.pieza1[0], p1.pieza1[1]);
        printf("%d, %d\n", p1.pieza2[0], p1.pieza2[1]);
        printf("%d, %d\n", p1.pieza3[0], p1.pieza3[1]);
        printf("%d, %d\n", p1.pieza4[0], p1.pieza4[1]);
        printf("%d, %d\n", p1.pieza5[0], p1.pieza5[1]);
        printf("%d, %d\n", p1.pieza6[0], p1.pieza6[1]);
        printf("%d, %d\n", p1.pieza7[0], p1.pieza7[1]);

        write(pipe1P[1], &mayor1, sizeof(int));
        // while (flag == 0){
        //     //poner codigo aca
        // } 
    } else {
        //J2: Jugador 2, PC
        J2 = fork();
        if (J2 == 0) {
            printf("Entrando al proceso hijo: J2\n");
            close(pipeP2[1]);// cierro el modo de Escritura del padre al hijo
            close(pipe2P[0]);// cierro el modo de Lectura del hijo al padre
            struct mazo p2;
            int mayor2 = crear_piezas(&p2);

            printf("Creado el mazo\n");
            printf("%d, %d\n", p2.pieza1[0], p2.pieza1[1]);
            printf("%d, %d\n", p2.pieza2[0], p2.pieza2[1]);
            printf("%d, %d\n", p2.pieza3[0], p2.pieza3[1]);
            printf("%d, %d\n", p2.pieza4[0], p2.pieza4[1]);
            printf("%d, %d\n", p2.pieza5[0], p2.pieza5[1]);
            printf("%d, %d\n", p2.pieza6[0], p2.pieza6[1]);
            printf("%d, %d\n", p2.pieza7[0], p2.pieza7[1]);

            write(pipe1P[1], &mayor2, sizeof(int));
            // while (flag == 0){
            //     //poner codigo aca
            // } 
        } else {
            //J3: Jugador 3, PC
            J3 = fork();
            if (J3 == 0) {
                printf("Entrando al proceso hijo: J3\n");
                close(pipeP3[1]);// cierro el modo de Escritura del padre al hijo
                close(pipe3P[0]);// cierro el modo de Lectura del hijo al padre
                struct mazo p3;
                int mayor3 = crear_piezas(&p3);

                printf("Creado el mazo\n");
                printf("%d, %d\n", p3.pieza1[0], p3.pieza1[1]);
                printf("%d, %d\n", p3.pieza2[0], p3.pieza2[1]);
                printf("%d, %d\n", p3.pieza3[0], p3.pieza3[1]);
                printf("%d, %d\n", p3.pieza4[0], p3.pieza4[1]);
                printf("%d, %d\n", p3.pieza5[0], p3.pieza5[1]);
                printf("%d, %d\n", p3.pieza6[0], p3.pieza6[1]);
                printf("%d, %d\n", p3.pieza7[0], p3.pieza7[1]);

                write(pipe3P[1], &mayor3, sizeof(int));
                // while (flag == 0){
                //     //poner codigo aca
                // } 
            } else {
                //J4: Jugador 4, PC
                J4 = fork();
                if (J4 == 0) {
                    printf("Entrando al proceso hijo: J4\n");
                    close(pipeP4[1]);// cierro el modo de Escritura del padre al hijo
                    close(pipe4P[0]);// cierro el modo de Lectura del hijo al padre
                    struct mazo p4;
                    int mayor4 = crear_piezas(&p4);

                    printf("Creado el mazo\n");
                    printf("%d, %d\n", p4.pieza1[0], p4.pieza1[1]);
                    printf("%d, %d\n", p4.pieza2[0], p4.pieza2[1]);
                    printf("%d, %d\n", p4.pieza3[0], p4.pieza3[1]);
                    printf("%d, %d\n", p4.pieza4[0], p4.pieza4[1]);
                    printf("%d, %d\n", p4.pieza5[0], p4.pieza5[1]);
                    printf("%d, %d\n", p4.pieza6[0], p4.pieza6[1]);
                    printf("%d, %d\n", p4.pieza7[0], p4.pieza7[1]);

                    write(pipe4P[1], &mayor4, sizeof(int));
                    // while (flag == 0){
                    //     //poner codigo aca
                    // } 
                }
            }
        }
    }
    
    if (J1 != 0 && J2 != 0 && J3 != 0 && J4 != 0){
        printf("Dentro del proceso padre\n");

        int mayor1, mayor2, mayor3, mayor4;

        close(pipeP1[0]);// cierro el modo de Lectura del padre al hijo
        close(pipe1P[1]);// cierro el modo de Escritura del hijo al padre
        read(pipe1P[0], &mayor1, sizeof(int));
        printf("Mayor de J1: %d\n",mayor1);

        close(pipeP2[0]);// cierro el modo de Lectura del padre al hijo
        close(pipe2P[1]);// cierro el modo de Escritura del hijo al padre
        read(pipe2P[0], &mayor2, sizeof(int));
        printf("Mayor de J2: %d\n",mayor2);

        close(pipeP3[0]);// cierro el modo de Lectura del padre al hijo
        close(pipe3P[1]);// cierro el modo de Escritura del hijo al padre
        read(pipe3P[0], &mayor3, sizeof(int));
        printf("Mayor de J3: %d\n",mayor3);

        close(pipeP4[0]);// cierro el modo de Lectura del padre al hijo
        close(pipe4P[1]);// cierro el modo de Escritura del hijo al padre
        read(pipe4P[0], &mayor4, sizeof(int));
        printf("Mayor de J4: %d\n",mayor4);
    }
    return 0;
}