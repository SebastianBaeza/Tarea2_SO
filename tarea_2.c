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
//tablero dentro de pipe
//en la posición del numero del arreglo piezas
//busca el numero de pieza que puede jugar izquierda y derecha representan a los numeros en el tablero retorna el numero de la pieza
//si no encuentra retorna -1, esta función no debiese servir para partir
int mayor_pieza(struct mazo *jugador){
    int actual;
    int pos = 1;
    int sum1 = (jugador->pieza1[0]) + (jugador->pieza1[1]);
    actual = sum1;
    int sum2 = (jugador->pieza2[0])+(jugador->pieza2[1]);
    if (sum2 > actual){
        actual = sum2;
        pos = 2;
    }
    int sum3 = (jugador->pieza3[0])+(jugador->pieza3[1]);
    if (sum3 > actual){
        actual = sum3;
        pos = 3;
    }
    int sum4 = (jugador->pieza4[0]) + (jugador->pieza4[1]);
        if (sum4 > actual){
        actual = sum4;
        pos = 4;
    }
    int sum5 = (jugador->pieza5[0]) + (jugador->pieza5[1]);
        if (sum5 > actual){
        actual = sum5;
        pos = 5;
    }
    int sum6 = (jugador->pieza6[0]) + (jugador->pieza6[1]);
        if (sum6 > actual){
        actual = sum6;
        pos = 6;
    }
    int sum7 = (jugador->pieza7[0]) + (jugador->pieza7[1]);
        if(sum7 > actual){
        actual = sum7;
        pos = 7;
    }
    return pos;
}
int jugada(struct mazo *jugador,int izquierda, int derecha){
    if (jugador->pieza1[0] == izquierda){
        return 1;
    }
    else if (jugador->pieza2[0] == izquierda){
        return 2;
    }
    else if (jugador->pieza3[0] == izquierda){
        return 3;
    }
    else if (jugador->pieza4[0] == izquierda){
        return 4;
    }
    else if (jugador->pieza5[0] == izquierda){
        return 5;
    }
    else if (jugador->pieza6[0] == izquierda){
        return 6;
    }
    else if (jugador->pieza7[0] == izquierda){
        return 7;
    }
    /////////////////////////////////////////////////
    if (jugador->pieza1[1] == izquierda){
        return 1;
    }
    else if (jugador->pieza2[1] == izquierda){
        return 2;
    }
    else if (jugador->pieza3[1] == izquierda){
        return 3;
    }
    else if (jugador->pieza4[1] == izquierda){
        return 4;
    }
    else if (jugador->pieza5[1] == izquierda){
        return 5;
    }
    else if (jugador->pieza6[1] == izquierda){
        return 6;
    }
    else if (jugador->pieza7[1] == izquierda){
        return 7;
    }
    ////////////////////////////////////////////
    if(jugador->pieza1[0]==derecha){
        return 8;
    }
    else if (jugador->pieza2[0] == derecha){
        return 9;
    }
    else if (jugador->pieza3[0] == derecha){
        return 10;
    }
    else if (jugador->pieza4[0] == derecha){
        return 11;
    }
    else if (jugador->pieza5[0] == derecha){
        return 12;
    }
    else if (jugador->pieza6[0] == derecha){
        return 13;
    }
    else if (jugador->pieza7[0] == derecha){
        return 14;
    }
    //////////////////////////////////////
    if (jugador->pieza1[1] == derecha){
        return 8;
    }
    else if (jugador->pieza2[1] == derecha){
        return 9;
    }
    else if (jugador->pieza3[1] == derecha){
        return 10;
    }
    else if (jugador->pieza4[1] == derecha){
        return 11;
    }
    else if (jugador->pieza5[1] == derecha){
        return 12;
    }
    else if (jugador->pieza6[1] == derecha){
        return 13;
    }
    else if (jugador->pieza7[1] == derecha){
        return 14;
    }
    else {
        return -1;
    }
}
void crear_piezas(struct mazo *jugador, int posicion[7]){
    // int posicion = 0;
    int numero = 0;
    int flag = 0;
    while (flag == 0){
        // posicion = rand() % 27; //cambiar a 27
        // if (piezas[posicion][0] == -1){
        //     continue;
        // }
        if (numero == 0) {
            jugador->pieza1[0] = piezas[posicion[0]][0];
            jugador->pieza1[1] = piezas[posicion[0]][1];
            // piezas[posicion][0] = -1;
            numero++;
        }
        else if (numero == 1) {
            jugador->pieza2[0] = piezas[posicion[1]][0];
            jugador->pieza2[1] = piezas[posicion[1]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
        }
        else if (numero == 2) {
            jugador->pieza3[0] = piezas[posicion[2]][0];
            jugador->pieza3[1] = piezas[posicion[2]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
        }
        else if (numero == 3){
            jugador->pieza4[0] = piezas[posicion[3]][0];
            jugador->pieza4[1] = piezas[posicion[3]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
        }
        else if (numero == 4){
            jugador->pieza5[0] = piezas[posicion[4]][0];
            jugador->pieza5[1] = piezas[posicion[4]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
        }
        else if(numero == 5){
            jugador->pieza6[0] = piezas[posicion[5]][0];
            jugador->pieza6[1] = piezas[posicion[5]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
        }
        else if(numero == 6){
            jugador->pieza7[0] = piezas[posicion[6]][0];
            jugador->pieza7[1] = piezas[posicion[6]][1];
            // piezas[posicion[1]][0] = -1;
            numero++;
            flag = 1;
        }

    }
}


int main(){
    int proceso;
    int pid, pid1, pid2, pid3, pid4;
            //Crear las PIPES [0]: Lectura [1]: Escritura
    int pipe_p0[2];
    int pipe_0p[2];
    int pipe_p1[2];
    int pipe_1p[2];
    int pipe_p2[2];
    int pipe_2p[2];
    int pipe_p3[2];
    int pipe_3p[2];
    //el tablero
    int tablero[4] ={-1,-1,-1,-1};
    //Inicializar PIPES
    pipe(pipe_p0);
    pipe(pipe_0p);
    pipe(pipe_p1);
    pipe(pipe_1p);
    pipe(pipe_p2);
    pipe(pipe_2p);
    pipe(pipe_p3);
    pipe(pipe_3p);
    int parte;
    int mayor;
    int pieza;
    int entero;
    int pos[28];
    int var = 0;
    int check = 0;
    srand(time(NULL));
    parte = 0;

    int flag = 0;

    for (int a = 0; a < 28;){
        var = rand() % 28;
        for (int b = 0; b <= a; b++){
            check = pos[b];
            if (check == var){
                break;
            }
        }
        if (check == var){
            continue;
        } else {
            pos[a] = var;
            // printf("Arreglo de posiciones, espacio %d = %d\n", a, pos[a]);
            a++;
        }
    }
  
    // los mazos$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    struct mazo p1;
    struct mazo p2;
    struct mazo p3;
    struct mazo p4;

    int pos1[7];
    memcpy(pos1, pos, sizeof(int) * 7);
    crear_piezas(&p1, pos1);

    int pos2[7];
    memcpy(pos2,pos + 8,sizeof(int)*7);
    crear_piezas(&p2, pos2);

    int pos3[7];
    memcpy(pos3,pos + 15,sizeof(int)*7);
    crear_piezas(&p3, pos3);

    int pos4[7];
    memcpy(pos4,pos + 22,sizeof(int)*7);
    crear_piezas(&p4, pos4);

    // hago los procesos$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    // value returned from fork() system call
    pid = fork();
  
    // If fork() returns zero then it
    // means it is child process.
    if (pid == 0) {
  
        // First child needs to be printed
        // later hence this process is made
        // to sleep for 3 seconds.
        
  
        // This is first child process
        // getpid() gives the process
        // id and getppid() gives the
        // parent id of that process.
        proceso = 0;
        
    } else {
        pid1 = fork();
        if (pid1 == 0) {
            proceso = 1;
        } else {
            pid2 = fork();
            if (pid2 == 0) {
                proceso = 2;
            } else {
                pid3 = fork();
                if (pid3 == 0) {
                    proceso = 3;
                } else {
                    proceso = 4;
                }
            
            }
        }
    }
    if (proceso == 4){
        close(pipe_0p[0]);
        close(pipe_p0[1]);
        close(pipe_1p[0]);
        close(pipe_p1[1]);
        close(pipe_2p[0]);
        close(pipe_p2[1]);
        close(pipe_3p[0]);
        close(pipe_p3[1]);
    }
    else if (proceso == 0){
        //cambiar for por coso manual
        for(int i = 0; i < 2; i++){
            close(pipe_1p[i]);
            close(pipe_p1[i]);
            close(pipe_2p[i]);
            close(pipe_p2[i]);
            close(pipe_p3[i]);
            close(pipe_3p[i]);
        }
        close(pipe_0p[1]);
        close(pipe_p0[0]);
    }
    else if (proceso == 1){
        //cambiar for por coso manual
        for(int i = 0; i < 2; i++){
            close(pipe_0p[i]);
            close(pipe_p0[i]);
            close(pipe_2p[i]);
            close(pipe_p2[i]);
            close(pipe_p3[i]);
            close(pipe_3p[i]);
        }
        close(pipe_1p[1]);
        close(pipe_p1[0]);
    }
    else if (proceso == 2){
        //cambiar for por coso manual
        for(int i = 0; i < 2; i++){
            close(pipe_0p[i]);
            close(pipe_p0[i]);
            close(pipe_1p[i]);
            close(pipe_p1[i]);
            close(pipe_3p[i]);
            close(pipe_p3[i]);
        }
        close(pipe_2p[1]);
        close(pipe_p2[0]);
    }
    else if (proceso == 3){
        //cambiar for por coso manual
        for(int i = 0; i < 2; i++){
            close(pipe_0p[i]);
            close(pipe_p0[i]);
            close(pipe_1p[i]);
            close(pipe_p1[i]);
            close(pipe_2p[i]);
            close(pipe_p2[i]);
        }
        close(pipe_3p[1]);
        close(pipe_p3[0]);
    }
    //intento que interactuen entre sí los procesos, mas tarde lo extiendo a los otros$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    for (int i = 1; i < 20; i++){
        //if del proceso padre con whiles para cada hijo vrible que aumenta si todos juegan +1
        if (proceso == 4){
            if (parte == 0){
                printf("turno del primer jugador\n");
                write(pipe_0p[1], &tablero[0], sizeof(int));
                write(pipe_0p[1], &tablero[1], sizeof(int));
                write(pipe_0p[1], &tablero[2], sizeof(int));
                write(pipe_0p[1], &tablero[3], sizeof(int));
                read(pipe_p0[0], &tablero[0], sizeof(int));
                read(pipe_p0[0], &tablero[1], sizeof(int));
                read(pipe_p0[0], &tablero[2], sizeof(int));
                read(pipe_p0[0], &tablero[3], sizeof(int));
                printf("[%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 1;
            }
            if (parte == 1){
                printf("turno del segundo jugador\n");
                write(pipe_1p[1], &tablero[0], sizeof(int));
                write(pipe_1p[1], &tablero[1], sizeof(int));
                write(pipe_1p[1], &tablero[2], sizeof(int));
                write(pipe_1p[1], &tablero[3], sizeof(int));
                read(pipe_p1[0], &tablero[0], sizeof(int));
                read(pipe_p1[0], &tablero[1], sizeof(int));
                read(pipe_p1[0], &tablero[2], sizeof(int));
                read(pipe_p1[0], &tablero[3], sizeof(int));
                printf("[%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 2;
            }
            if (parte == 2){
                printf("turno del tercer jugador\n");
                write(pipe_2p[1], &tablero[0], sizeof(int));
                write(pipe_2p[1], &tablero[1], sizeof(int));
                write(pipe_2p[1], &tablero[2], sizeof(int));
                write(pipe_2p[1], &tablero[3], sizeof(int));
                read(pipe_p2[0], &tablero[0], sizeof(int));
                read(pipe_p2[0], &tablero[1], sizeof(int));
                read(pipe_p2[0], &tablero[2], sizeof(int));
                read(pipe_p2[0], &tablero[3], sizeof(int));
                printf("[%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 3;
            }
            if (parte == 3){
                printf("turno del cuarto jugador\n");
                write(pipe_3p[1], &tablero[0], sizeof(int));
                write(pipe_3p[1], &tablero[1], sizeof(int));
                write(pipe_3p[1], &tablero[2], sizeof(int));
                write(pipe_3p[1], &tablero[3], sizeof(int));

                read(pipe_p3[0], &tablero[0], sizeof(int));
                read(pipe_p3[0], &tablero[1], sizeof(int));
                read(pipe_p3[0], &tablero[2], sizeof(int));
                read(pipe_p3[0], &tablero[3], sizeof(int));
                printf("[%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 0;
            }

        } 

        if (proceso == 0){


/*          printf("Creado el mazo del Jugador 1\n");
            printf("%d, %d\n", p1.pieza1[0], p1.pieza1[1]);
            printf("%d, %d\n", p1.pieza2[0], p1.pieza2[1]);
            printf("%d, %d\n", p1.pieza3[0], p1.pieza3[1]);
            printf("%d, %d\n", p1.pieza4[0], p1.pieza4[1]);
            printf("%d, %d\n", p1.pieza5[0], p1.pieza5[1]);
            printf("%d, %d\n", p1.pieza6[0], p1.pieza6[1]);
            printf("%d, %d\n", p1.pieza7[0], p1.pieza7[1]);*/

            //modificar tablero[0]y [1] para poner pieza
            //se juega y se actualiza un par de numeros del tabler (una peiza y se manda al padre el tablero actualizado)
            read(pipe_0p[0], &tablero[0], sizeof(int));
            read(pipe_0p[0], &tablero[1], sizeof(int));
            read(pipe_0p[0], &tablero[2], sizeof(int));
            read(pipe_0p[0], &tablero[3], sizeof(int));
            if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p1);
                if (mayor == 1){
                    tablero[0] = p1.pieza1[0];
                    tablero[1] = p1.pieza1[1];
                }
                else if(mayor == 2){
                    tablero[0] = p1.pieza2[0];
                    tablero[1] = p1.pieza2[1];

                }
                else if(mayor == 3){
                    tablero[0] = p1.pieza3[0];
                    tablero[1] = p1.pieza3[1];
                }
                else if(mayor == 4){
                    tablero[0] = p1.pieza4[0];
                    tablero[1] = p1.pieza4[1];

                }
                else if(mayor == 5){
                    tablero[0] = p1.pieza5[0];
                    tablero[1] = p1.pieza5[1];
                }
                else if(mayor == 6){
                    tablero[0] = p1.pieza6[0];
                    tablero[1] = p1.pieza6[1];
                }
                else if(mayor == 7){
                    tablero[0] = p1.pieza7[0];
                    tablero[1] = p1.pieza7[1];
                }
                write(pipe_p0[1], &tablero[0], sizeof(int));
                write(pipe_p0[1], &tablero[1], sizeof(int)); 
                write(pipe_p0[1], &tablero[2], sizeof(int));
                write(pipe_p0[1], &tablero[3], sizeof(int)); 
            }
            //si es la segunda jugada después de la primera pieza
            else if (tablero[2] == -1){
                pieza = jugada(&p1,-1,tablero[1]);
                if (pieza == 1){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 4){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p1.pieza1[0]){
                        tablero[2] = p1.pieza1[0];
                        tablero[3] = p1.pieza1[1];
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = p1.pieza1[1];
                        tablero[3] = p1.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if(tablero[1] == p1.pieza2[0]){
                        tablero[2] = p1.pieza2[0];
                        tablero[3] = p1.pieza2[1];
                    }
                    else if(tablero[1] == p1.pieza2[1]){
                        tablero[2] = p1.pieza2[1];
                        tablero[3] = p1.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if(tablero[1] == p1.pieza3[0]){
                        tablero[2] = p1.pieza3[0];
                        tablero[3] = p1.pieza3[1];
                    }
                    else if(tablero[1] == p1.pieza3[1]){
                        tablero[2] = p1.pieza3[1];
                        tablero[3] = p1.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if(tablero[1] == p1.pieza4[0]){
                        tablero[2] = p1.pieza4[0];
                        tablero[3] = p1.pieza4[1];
                    }
                    else if(tablero[1] == p1.pieza4[1]){
                        tablero[2] = p1.pieza4[1];
                        tablero[3] = p1.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if(tablero[1] == p1.pieza5[0]){
                        tablero[2] = p1.pieza5[0];
                        tablero[3] = p1.pieza5[1];
                    }
                    else if(tablero[1] == p1.pieza5[1]){
                        tablero[2] = p1.pieza5[1];
                        tablero[3] = p1.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if(tablero[1] == p1.pieza6[0]){
                        tablero[2] = p1.pieza6[0];
                        tablero[3] = p1.pieza6[1];
                    }
                    else if (tablero[1] == p1.pieza6[1]){
                        tablero[2] = p1.pieza6[1];
                        tablero[3] = p1.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if(tablero[1] == p1.pieza7[0]){
                        tablero[2] = p1.pieza7[0];
                        tablero[3] = p1.pieza7[1];
                    }
                    else if(tablero[1] == p1.pieza7[1]){
                        tablero[2] = p1.pieza7[1];
                        tablero[3] = p1.pieza7[0];
                    }
                }
                write(pipe_p0[1], &tablero[0], sizeof(int));
                write(pipe_p0[1], &tablero[1], sizeof(int));
                write(pipe_p0[1], &tablero[2], sizeof(int));
                write(pipe_p0[1], &tablero[3], sizeof(int));
            }
            //jugda enésima
            else {
                pieza = jugada(&p1,tablero[0],tablero[3]);
                if (pieza == 1){
                    if(tablero[0] == p1.pieza1[0]){
                        tablero[1] = p1.pieza1[0];
                        tablero[0] = p1.pieza1[1];
                    }
                    else if(tablero[0] == p1.pieza1[1]){
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                    }
                }
                if (pieza == 2){
                    if(tablero[0] == p1.pieza2[0]){
                        tablero[1] = p1.pieza2[0];
                        tablero[0] = p1.pieza2[1];
                    }
                    else if(tablero[0] == p1.pieza2[1]){
                        tablero[0] = p1.pieza2[0];
                        tablero[1] = p1.pieza2[1];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p1.pieza3[0]){
                        tablero[1] = p1.pieza3[0];
                        tablero[0] = p1.pieza3[1];
                    }
                    else if (tablero[0] == p1.pieza3[1]){
                        tablero[0] = p1.pieza3[0];
                        tablero[1] = p1.pieza3[1];
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p1.pieza4[0]){
                        tablero[1] = p1.pieza4[0];
                        tablero[0] = p1.pieza4[1];
                    }
                    else if (tablero[0] == p1.pieza4[1]){
                        tablero[0] = p1.pieza4[0];
                        tablero[1] = p1.pieza4[1];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p1.pieza5[0]){
                        tablero[1] = p1.pieza5[0];
                        tablero[0] = p1.pieza5[1];
                    }
                    else if (tablero[0] == p1.pieza5[1]){
                        tablero[0] = p1.pieza5[0];
                        tablero[1] = p1.pieza5[1];
                    }
                }
                if (pieza == 6){
                    if(tablero[0] == p1.pieza6[0]){
                        tablero[1] = p1.pieza6[0];
                        tablero[0] = p1.pieza6[1];
                    }
                    else if(tablero[0] == p1.pieza6[1]){
                        tablero[0] = p1.pieza6[0];
                        tablero[1] = p1.pieza6[1];
                    }
                }
                if (pieza==7){
                    if (tablero[0] == p1.pieza7[0]){
                        tablero[1] = p1.pieza7[0];
                        tablero[0] = p1.pieza7[1];
                    }
                    else if (tablero[0] == p1.pieza7[1]){
                        tablero[0] = p1.pieza7[0];
                        tablero[1] = p1.pieza7[1];
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p1.pieza1[0]){
                        tablero[2] = p1.pieza1[0];
                        tablero[3] = p1.pieza1[1];
                    }
                    else if (tablero[3] == p1.pieza1[1]){
                        tablero[2] = p1.pieza1[1];
                        tablero[3] = p1.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p1.pieza2[0]){
                        tablero[2] = p1.pieza2[0];
                        tablero[3] = p1.pieza2[1];
                    }
                    else if (tablero[3] == p1.pieza2[1]){
                        tablero[2] = p1.pieza2[1];
                        tablero[3] = p1.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if(tablero[3] == p1.pieza3[0]){
                        tablero[2] = p1.pieza3[0];
                        tablero[3] = p1.pieza3[1];
                    }
                    else if(tablero[3] == p1.pieza3[1]){
                        tablero[2] = p1.pieza3[1];
                        tablero[3] = p1.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p1.pieza4[0]){
                        tablero[2] = p1.pieza4[0];
                        tablero[3] = p1.pieza4[1];
                    }
                    else if (tablero[3] == p1.pieza4[1]){
                        tablero[2] = p1.pieza4[1];
                        tablero[3] = p1.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if(tablero[3] == p1.pieza5[0]){
                        tablero[2] = p1.pieza5[0];
                        tablero[3] = p1.pieza5[1];
                    }
                    else if(tablero[3] == p1.pieza5[1]){
                        tablero[2] = p1.pieza5[1];
                        tablero[3] = p1.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p1.pieza6[0]){
                        tablero[2] = p1.pieza6[0];
                        tablero[3] = p1.pieza6[1];
                    }
                    else if (tablero[3] == p1.pieza6[1]){
                        tablero[2]=p1.pieza6[1];
                        tablero[3]=p1.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if(tablero[3] == p1.pieza7[0]){
                        tablero[2] = p1.pieza7[0];
                        tablero[3] = p1.pieza7[1];
                    }
                    else if(tablero[3] == p1.pieza7[1]){
                        tablero[2] = p1.pieza7[1];
                        tablero[3] = p1.pieza7[0];
                    }
                }
                write(pipe_p0[1], &tablero[0], sizeof(int));
                write(pipe_p0[1], &tablero[1], sizeof(int));
                write(pipe_p0[1], &tablero[2], sizeof(int));
                write(pipe_p0[1], &tablero[3], sizeof(int));
            }

           
        } if (proceso == 1){
 /*           printf("Creado el mazo del Jugador 2\n");
            printf("%d, %d\n", p2.pieza1[0], p2.pieza1[1]);
            printf("%d, %d\n", p2.pieza2[0], p2.pieza2[1]);
            printf("%d, %d\n", p2.pieza3[0], p2.pieza3[1]);
            printf("%d, %d\n", p2.pieza4[0], p2.pieza4[1]);
            printf("%d, %d\n", p2.pieza5[0], p2.pieza5[1]);
            printf("%d, %d\n", p2.pieza6[0], p2.pieza6[1]);
            printf("%d, %d\n", p2.pieza7[0], p2.pieza7[1]);*/
            read(pipe_1p[0], &tablero[0], sizeof(int));
            read(pipe_1p[0], &tablero[1], sizeof(int));
            read(pipe_1p[0], &tablero[2], sizeof(int));
            read(pipe_1p[0], &tablero[3], sizeof(int));
            if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p2);
                if (mayor == 1){
                    tablero[0] = p2.pieza1[0];
                    tablero[1] = p2.pieza1[1];
                }
                else if (mayor == 2){
                    tablero[0] = p2.pieza2[0];
                    tablero[1] = p2.pieza2[1];

                }
                else if (mayor == 3){
                    tablero[0] = p2.pieza3[0];
                    tablero[1] = p2.pieza3[1];
                }
                else if (mayor == 4){
                    tablero[0] = p2.pieza4[0];
                    tablero[1] = p2.pieza4[1];

                }
                else if(mayor == 5){
                    tablero[0] = p2.pieza5[0];
                    tablero[1] = p2.pieza5[1];
                }
                else if(mayor == 6){
                    tablero[0] = p2.pieza6[0];
                    tablero[1] = p2.pieza6[1];
                }
                else if(mayor == 7){
                    tablero[0] = p2.pieza7[0];
                    tablero[1] = p2.pieza7[1];
                }
                write(pipe_p1[1], &tablero[0], sizeof(int));
                write(pipe_p1[1], &tablero[1], sizeof(int)); 
                write(pipe_p1[1], &tablero[2], sizeof(int));
                write(pipe_p1[1], &tablero[3], sizeof(int)); 
            }
            //si es la segunda jugada después de la primera pieza
            else if (tablero[2] == -1){
                pieza = jugada(&p2,-1,tablero[1]);
                if (pieza == 1){
                    if (tablero[0] == p2.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza1[0];
                        tablero[1] = p2.pieza1[1];
                    }
                    else if (tablero[1] == p2.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza1[1];
                        tablero[1] = p2.pieza1[0];
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p2.pieza2[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza2[0];
                        tablero[1] = p2.pieza2[1];
                    }
                    else if (tablero[1] == p2.pieza2[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza2[1];
                        tablero[1] = p2.pieza2[0];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p2.pieza3[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza3[0];
                        tablero[1] = p2.pieza3[1];
                    }
                    else if (tablero[1] == p2.pieza3[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza3[1];
                        tablero[1] = p2.pieza3[0];
                    }
                }
                if (pieza == 4){
                    if (tablero[0] == p2.pieza4[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza4[0];
                        tablero[1] = p2.pieza4[1];
                    }
                    else if (tablero[1] == p2.pieza4[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza4[1];
                        tablero[1] = p2.pieza4[0];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p2.pieza5[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza5[0];
                        tablero[1] = p2.pieza5[1];
                    }
                    else if (tablero[1] == p2.pieza5[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza5[1];
                        tablero[1] = p2.pieza5[0];
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p2.pieza6[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza6[0];
                        tablero[1] = p2.pieza6[1];
                    }
                    else if (tablero[1] == p2.pieza6[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza6[1];
                        tablero[1] = p2.pieza6[0];
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p2.pieza7[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza7[0];
                        tablero[1] = p2.pieza7[1];
                    }
                    else if (tablero[1] == p2.pieza7[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p2.pieza7[1];
                        tablero[1] = p2.pieza7[0];
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p2.pieza1[0]){
                        tablero[2] = p2.pieza1[0];
                        tablero[3] = p2.pieza1[1];
                    }
                    else if (tablero[1] == p2.pieza1[1]){
                        tablero[2] = p2.pieza1[1];
                        tablero[3] = p2.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if (tablero[1] == p2.pieza2[0]){
                        tablero[2] = p2.pieza2[0];
                        tablero[3] = p2.pieza2[1];
                    }
                    else if (tablero[1] == p2.pieza2[1]){
                        tablero[2] = p2.pieza2[1];
                        tablero[3] = p2.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if (tablero[1] == p2.pieza3[0]){
                        tablero[2] = p2.pieza3[0];
                        tablero[3] = p2.pieza3[1];
                    }
                    else if (tablero[1] == p2.pieza3[1]){
                        tablero[2] = p2.pieza3[1];
                        tablero[3] = p2.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if (tablero[1] == p2.pieza4[0]){
                        tablero[2] = p2.pieza4[0];
                        tablero[3] = p2.pieza4[1];
                    }
                    else if (tablero[1] == p2.pieza4[1]){
                        tablero[2] = p2.pieza4[1];
                        tablero[3] = p2.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if (tablero[1] == p2.pieza5[0]){
                        tablero[2] = p2.pieza5[0];
                        tablero[3] = p2.pieza5[1];
                    }
                    else if (tablero[1] == p2.pieza5[1]){
                        tablero[2] = p2.pieza5[1];
                        tablero[3] = p2.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if (tablero[1] == p2.pieza6[0]){
                        tablero[2] = p2.pieza6[0];
                        tablero[3] = p2.pieza6[1];
                    }
                    else if (tablero[1] == p2.pieza6[1]){
                        tablero[2] = p2.pieza6[1];
                        tablero[3] = p2.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if (tablero[1] == p2.pieza7[0]){
                        tablero[2] = p2.pieza7[0];
                        tablero[3] = p2.pieza7[1];
                    }
                    else if (tablero[1] == p2.pieza7[1]){
                        tablero[2] = p2.pieza7[1];
                        tablero[3] = p2.pieza7[0];
                    }
                }
                write(pipe_p1[1], &tablero[0], sizeof(int));
                write(pipe_p1[1], &tablero[1], sizeof(int));
                write(pipe_p1[1], &tablero[2], sizeof(int));
                write(pipe_p1[1], &tablero[3], sizeof(int));
            }
            //jugda enésima
            else {
                pieza = jugada(&p2,tablero[0],tablero[3]);
                if (pieza == 1){
                    if (tablero[0] == p2.pieza1[0]){
                        tablero[1] = p2.pieza1[0];
                        tablero[0] = p2.pieza1[1];
                    }
                    else if(tablero[0] == p2.pieza1[1]){
                        tablero[0] = p2.pieza1[0];
                        tablero[1] = p2.pieza1[1];
                    }
                }
                if (pieza == 2){
                    if(tablero[0] == p2.pieza2[0]){
                        tablero[1] = p2.pieza2[0];
                        tablero[0] = p2.pieza2[1];
                    }
                    else if (tablero[0] == p2.pieza2[1]){
                        tablero[0] = p2.pieza2[0];
                        tablero[1] = p2.pieza2[1];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p2.pieza3[0]){
                        tablero[1] = p2.pieza3[0];
                        tablero[0] = p2.pieza3[1];
                    }
                    else if (tablero[0] == p2.pieza3[1]){
                        tablero[0] = p2.pieza3[0];
                        tablero[1] = p2.pieza3[1];
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p2.pieza4[0]){
                        tablero[1] = p2.pieza4[0];
                        tablero[0] = p2.pieza4[1];
                    }
                    else if (tablero[0] == p2.pieza4[1]){
                        tablero[0] = p2.pieza4[0];
                        tablero[1] = p2.pieza4[1];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p2.pieza5[0]){
                        tablero[1] = p2.pieza5[0];
                        tablero[0] = p2.pieza5[1];
                    }
                    else if (tablero[0] == p2.pieza5[1]){
                        tablero[0] = p2.pieza5[0];
                        tablero[1] = p2.pieza5[1];
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p2.pieza6[0]){
                        tablero[1] = p2.pieza6[0];
                        tablero[0] = p2.pieza6[1];
                    }
                    else if (tablero[0] == p2.pieza6[1]){
                        tablero[0] = p2.pieza6[0];
                        tablero[1] = p2.pieza6[1];
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p2.pieza7[0]){
                        tablero[1] = p2.pieza7[0];
                        tablero[0] = p2.pieza7[1];
                    }
                    else if (tablero[0] == p2.pieza7[1]){
                        tablero[0] = p2.pieza7[0];
                        tablero[1] = p2.pieza7[1];
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p2.pieza1[0]){
                        tablero[2] = p2.pieza1[0];
                        tablero[3] = p2.pieza1[1];
                    }
                    else if (tablero[3] == p2.pieza1[1]){
                        tablero[2] = p2.pieza1[1];
                        tablero[3] = p2.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p2.pieza2[0]){
                        tablero[2] = p2.pieza2[0];
                        tablero[3] = p2.pieza2[1];
                    }
                    else if (tablero[3] == p2.pieza2[1]){
                        tablero[2] = p2.pieza2[1];
                        tablero[3] = p2.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if (tablero[3] == p2.pieza3[0]){
                        tablero[2] = p2.pieza3[0];
                        tablero[3] = p2.pieza3[1];
                    }
                    else if (tablero[3] == p2.pieza3[1]){
                        tablero[2] = p2.pieza3[1];
                        tablero[3] = p2.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p2.pieza4[0]){
                        tablero[2] = p2.pieza4[0];
                        tablero[3] = p2.pieza4[1];
                    }
                    else if (tablero[3] == p2.pieza4[1]){
                        tablero[2] = p2.pieza4[1];
                        tablero[3] = p2.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if (tablero[3] == p2.pieza5[0]){
                        tablero[2] = p2.pieza5[0];
                        tablero[3] = p2.pieza5[1];
                    }
                    else if (tablero[3] == p2.pieza5[1]){
                        tablero[2] = p2.pieza5[1];
                        tablero[3] = p2.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p2.pieza6[0]){
                        tablero[2] = p2.pieza6[0];
                        tablero[3] = p2.pieza6[1];
                    }
                    else if (tablero[3] == p2.pieza6[1]){
                        tablero[2] = p2.pieza6[1];
                        tablero[3] = p2.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if (tablero[3] == p2.pieza7[0]){
                        tablero[2] = p2.pieza7[0];
                        tablero[3] = p2.pieza7[1];
                    }
                    else if (tablero[3] == p2.pieza7[1]){
                        tablero[2] = p2.pieza7[1];
                        tablero[3] = p2.pieza7[0];
                    }
                }
                write(pipe_p1[1], &tablero[0], sizeof(int));
                write(pipe_p1[1], &tablero[1], sizeof(int));
                write(pipe_p1[1], &tablero[2], sizeof(int));
                write(pipe_p1[1], &tablero[3], sizeof(int));
            }

         


        } if (proceso == 2){
            read(pipe_2p[0], &tablero[0], sizeof(int));
            read(pipe_2p[0], &tablero[1], sizeof(int));
            read(pipe_2p[0], &tablero[2], sizeof(int));
            read(pipe_2p[0], &tablero[3], sizeof(int));
            if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p3);
                if (mayor == 1){
                    tablero[0] = p3.pieza1[0];
                    tablero[1] = p3.pieza1[1];
                }
                else if (mayor == 2){
                    tablero[0] = p3.pieza2[0];
                    tablero[1] = p3.pieza2[1];

                }
                else if (mayor == 3){
                    tablero[0] = p3.pieza3[0];
                    tablero[1] = p3.pieza3[1];
                }
                else if (mayor == 4){
                    tablero[0] = p3.pieza4[0];
                    tablero[1] = p3.pieza4[1];

                }
                else if (mayor == 5){
                    tablero[0] = p3.pieza5[0];
                    tablero[1] = p3.pieza5[1];
                }
                else if (mayor == 6){
                    tablero[0] = p3.pieza6[0];
                    tablero[1] = p3.pieza6[1];
                }
                else if (mayor == 7){
                    tablero[0] = p3.pieza7[0];
                    tablero[1] = p3.pieza7[1];
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int)); 
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int)); 
            }
            //si es la segunda jugada después de la primera pieza
            else if (tablero[2] == -1){
                pieza = jugada(&p3, -1, tablero[1]);
                if (pieza == 1){
                    if (tablero[0] == p3.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza1[0];
                        tablero[1] = p3.pieza1[1];
                    }
                    else if (tablero[1] == p3.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza1[1];
                        tablero[1] = p3.pieza1[0];
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p3.pieza2[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza2[0];
                        tablero[1] = p3.pieza2[1];
                    }
                    else if (tablero[1] == p3.pieza2[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza2[1];
                        tablero[1] = p3.pieza2[0];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p3.pieza3[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza3[0];
                        tablero[1] = p3.pieza3[1];
                    }
                    else if (tablero[1] == p3.pieza3[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza3[1];
                        tablero[1] = p3.pieza3[0];
                    }
                }
                if (pieza == 4){
                    if (tablero[0] == p3.pieza4[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza4[0];
                        tablero[1] = p3.pieza4[1];
                    }
                    else if (tablero[1] == p3.pieza4[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza4[1];
                        tablero[1] = p3.pieza4[0];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p3.pieza5[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza5[0];
                        tablero[1] = p3.pieza5[1];
                    }
                    else if (tablero[1] == p3.pieza5[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza5[1];
                        tablero[1] = p3.pieza5[0];
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p3.pieza6[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza6[0];
                        tablero[1] = p3.pieza6[1];
                    }
                    else if (tablero[1] == p3.pieza6[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza6[1];
                        tablero[1] = p3.pieza6[0];
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p3.pieza7[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza7[0];
                        tablero[1] = p3.pieza7[1];
                    }
                    else if (tablero[1] == p3.pieza7[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p3.pieza7[1];
                        tablero[1] = p3.pieza7[0];
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p3.pieza1[0]){
                        tablero[2] = p3.pieza1[0];
                        tablero[3] = p3.pieza1[1];
                    }
                    else if (tablero[1] == p3.pieza1[1]){
                        tablero[2] = p3.pieza1[1];
                        tablero[3] = p3.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if (tablero[1] == p3.pieza2[0]){
                        tablero[2] = p3.pieza2[0];
                        tablero[3] = p3.pieza2[1];
                    }
                    else if (tablero[1] == p3.pieza2[1]){
                        tablero[2] = p3.pieza2[1];
                        tablero[3] = p3.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if (tablero[1] == p3.pieza3[0]){
                        tablero[2] = p3.pieza3[0];
                        tablero[3] = p3.pieza3[1];
                    }
                    else if (tablero[1] == p3.pieza3[1]){
                        tablero[2] = p3.pieza3[1];
                        tablero[3] = p3.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if (tablero[1] == p3.pieza4[0]){
                        tablero[2] = p3.pieza4[0];
                        tablero[3] = p3.pieza4[1];
                    }
                    else if (tablero[1] == p3.pieza4[1]){
                        tablero[2] = p3.pieza4[1];
                        tablero[3] = p3.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if (tablero[1] == p3.pieza5[0]){
                        tablero[2] = p3.pieza5[0];
                        tablero[3] = p3.pieza5[1];
                    }
                    else if (tablero[1] == p3.pieza5[1]){
                        tablero[2] = p3.pieza5[1];
                        tablero[3] = p3.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if (tablero[1] == p3.pieza6[0]){
                        tablero[2] = p3.pieza6[0];
                        tablero[3] = p3.pieza6[1];
                    }
                    else if (tablero[1] == p3.pieza6[1]){
                        tablero[2] = p3.pieza6[1];
                        tablero[3] = p3.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if (tablero[1] == p3.pieza7[0]){
                        tablero[2] = p3.pieza7[0];
                        tablero[3] = p3.pieza7[1];
                    }
                    else if (tablero[1] == p3.pieza7[1]){
                        tablero[2] = p3.pieza7[1];
                        tablero[3] = p3.pieza7[0];
                    }
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int));
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int));
            }
            //jugda enésima
            else {
                pieza = jugada(&p3,tablero[0],tablero[3]);
                if (pieza == 1){
                    if (tablero[0] == p3.pieza1[0]){
                        tablero[1] = p3.pieza1[0];
                        tablero[0] = p3.pieza1[1];
                    }
                    else if (tablero[0] == p3.pieza1[1]){
                        tablero[0] = p3.pieza1[0];
                        tablero[1] = p3.pieza1[1];
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p3.pieza2[0]){
                        tablero[1] = p3.pieza2[0];
                        tablero[0] = p3.pieza2[1];
                    }
                    else if (tablero[0] == p3.pieza2[1]){
                        tablero[0] = p3.pieza2[0];
                        tablero[1] = p3.pieza2[1];
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p3.pieza3[0]){
                        tablero[1] = p3.pieza3[0];
                        tablero[0] = p3.pieza3[1];
                    }
                    else if (tablero[0] == p3.pieza3[1]){
                        tablero[0] = p3.pieza3[0];
                        tablero[1] = p3.pieza3[1];
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p3.pieza4[0]){
                        tablero[1] = p3.pieza4[0];
                        tablero[0] = p3.pieza4[1];
                    }
                    else if (tablero[0] == p3.pieza4[1]){
                        tablero[0] = p3.pieza4[0];
                        tablero[1] = p3.pieza4[1];
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p3.pieza5[0]){
                        tablero[1] = p3.pieza5[0];
                        tablero[0] = p3.pieza5[1];
                    }
                    else if (tablero[0] == p3.pieza5[1]){
                        tablero[0] = p3.pieza5[0];
                        tablero[1] = p3.pieza5[1];
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p3.pieza6[0]){
                        tablero[1] = p3.pieza6[0];
                        tablero[0] = p3.pieza6[1];
                    }
                    else if (tablero[0] == p3.pieza6[1]){
                        tablero[0] = p3.pieza6[0];
                        tablero[1] = p3.pieza6[1];
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p3.pieza7[0]){
                        tablero[1] = p3.pieza7[0];
                        tablero[0] = p3.pieza7[1];
                    }
                    else if (tablero[0] == p3.pieza7[1]){
                        tablero[0] = p3.pieza7[0];
                        tablero[1] = p3.pieza7[1];
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p3.pieza1[0]){
                        tablero[2] = p3.pieza1[0];
                        tablero[3] = p3.pieza1[1];
                    }
                    else if (tablero[3] == p3.pieza1[1]){
                        tablero[2] = p3.pieza1[1];
                        tablero[3] = p3.pieza1[0];
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p3.pieza2[0]){
                        tablero[2] = p3.pieza2[0];
                        tablero[3] = p3.pieza2[1];
                    }
                    else if (tablero[3] == p3.pieza2[1]){
                        tablero[2] = p3.pieza2[1];
                        tablero[3] = p3.pieza2[0];
                    }
                }
                if (pieza == 10){
                    if (tablero[3] == p3.pieza3[0]){
                        tablero[2] = p3.pieza3[0];
                        tablero[3] = p3.pieza3[1];
                    }
                    else if (tablero[3] == p3.pieza3[1]){
                        tablero[2] = p3.pieza3[1];
                        tablero[3] = p3.pieza3[0];
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p3.pieza4[0]){
                        tablero[2] = p3.pieza4[0];
                        tablero[3] = p3.pieza4[1];
                    }
                    else if (tablero[3] == p3.pieza4[1]){
                        tablero[2] = p3.pieza4[1];
                        tablero[3] = p3.pieza4[0];
                    }
                }
                if (pieza == 12){
                    if (tablero[3] == p3.pieza5[0]){
                        tablero[2] = p3.pieza5[0];
                        tablero[3] = p3.pieza5[1];
                    }
                    else if (tablero[3] == p3.pieza5[1]){
                        tablero[2] = p3.pieza5[1];
                        tablero[3] = p3.pieza5[0];
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p3.pieza6[0]){
                        tablero[2] = p3.pieza6[0];
                        tablero[3] = p3.pieza6[1];
                    }
                    else if (tablero[3] == p3.pieza6[1]){
                        tablero[2] = p3.pieza6[1];
                        tablero[3] = p3.pieza6[0];
                    }
                }
                if (pieza == 14){
                    if (tablero[3] == p3.pieza7[0]){
                        tablero[2] = p3.pieza7[0];
                        tablero[3] = p3.pieza7[1];
                    }
                    else if (tablero[3] == p3.pieza7[1]){
                        tablero[2] = p3.pieza7[1];
                        tablero[3] = p3.pieza7[0];
                    }
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int));
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int));
            }
            
        } if (proceso == 3){

            read(pipe_3p[0], &tablero[0], sizeof(int));
            read(pipe_3p[0], &tablero[1], sizeof(int));
            read(pipe_3p[0], &tablero[2], sizeof(int));
            read(pipe_3p[0], &tablero[3], sizeof(int));
            printf("Tu turno:\n");
            if(p4.pieza1[0]!=-1){
                printf("1.-[%d|%d]",p4.pieza1[0],p4.pieza1[1]);
            }
            if(p4.pieza2[0]!=-1){
                printf("2.-[%d|%d]",p4.pieza2[0],p4.pieza2[1]);
            }
            if(p4.pieza3[0]!=-1){
                printf("3.-[%d|%d]",p4.pieza3[0],p4.pieza3[1]);
            }
            if(p4.pieza4[0]!=-1){
                printf("4.-[%d|%d]",p4.pieza4[0],p4.pieza4[1]);
            }
            if(p4.pieza5[0]!=-1){
                printf("5.-[%d|%d]",p4.pieza5[0],p4.pieza5[1]);
            }
            if(p4.pieza6[0]!=-1){
                printf("6.-[%d|%d]",p4.pieza6[0],p4.pieza6[1]);
            }
            if(p4.pieza7[0]!=-1){
                printf("7.-[%d|%d]",p4.pieza7[0],p4.pieza7[1]);
            }
            printf("ingresa el número de la ficha");
            scanf("%d",&entero);
            //rellenar mañana/////////////////////////////////////////////////////////////////////////////////////
            if(tablero[0]==-1&&tablero[1]==-1&&tablero[2]==-1&&tablero[3]==-1){
                mayor=mayor_pieza(&p3);
                if(mayor==1){
                    tablero[0]=p3.pieza1[0];
                    tablero[1]=p3.pieza1[1];
                }
                else if(mayor==2){
                    tablero[0]=p3.pieza2[0];
                    tablero[1]=p3.pieza2[1];

                }
                else if(mayor==3){
                    tablero[0]=p3.pieza3[0];
                    tablero[1]=p3.pieza3[1];
                }
                else if(mayor==4){
                    tablero[0]=p3.pieza4[0];
                    tablero[1]=p3.pieza4[1];

                }
                else if(mayor==5){
                    tablero[0]=p3.pieza5[0];
                    tablero[1]=p3.pieza5[1];
                }
                else if(mayor==6){
                    tablero[0]=p3.pieza6[0];
                    tablero[1]=p3.pieza6[1];
                }
                else if(mayor==7){
                    tablero[0]=p3.pieza7[0];
                    tablero[1]=p3.pieza7[1];
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int)); 
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int)); 
            }
            //si es la segunda jugada después de la primera pieza
            else if(tablero[2]==-1){
                pieza=jugada(&p3,-1,tablero[1]);
                if (pieza==8){
                    if(tablero[1]==p3.pieza1[0]){
                        tablero[2]=p3.pieza1[0];
                        tablero[3]=p3.pieza1[1];
                    }
                    else if(tablero[1]==p3.pieza1[1]){
                        tablero[2]=p3.pieza1[1];
                        tablero[3]=p3.pieza1[0];
                    }
                }
                if (pieza==9){
                    if(tablero[1]==p3.pieza2[0]){
                        tablero[2]=p3.pieza2[0];
                        tablero[3]=p3.pieza2[1];
                    }
                    else if(tablero[1]==p3.pieza2[1]){
                        tablero[2]=p3.pieza2[1];
                        tablero[3]=p3.pieza2[0];
                    }
                }
                if (pieza==10){
                    if(tablero[1]==p3.pieza3[0]){
                        tablero[2]=p3.pieza3[0];
                        tablero[3]=p3.pieza3[1];
                    }
                    else if(tablero[1]==p3.pieza3[1]){
                        tablero[2]=p3.pieza3[1];
                        tablero[3]=p3.pieza3[0];
                    }
                }
                if (pieza==11){
                    if(tablero[1]==p3.pieza4[0]){
                        tablero[2]=p3.pieza4[0];
                        tablero[3]=p3.pieza4[1];
                    }
                    else if(tablero[1]==p3.pieza4[1]){
                        tablero[2]=p3.pieza4[1];
                        tablero[3]=p3.pieza4[0];
                    }
                }
                if (pieza==12){
                    if(tablero[1]==p3.pieza5[0]){
                        tablero[2]=p3.pieza5[0];
                        tablero[3]=p3.pieza5[1];
                    }
                    else if(tablero[1]==p3.pieza5[1]){
                        tablero[2]=p3.pieza5[1];
                        tablero[3]=p3.pieza5[0];
                    }
                }
                if (pieza==13){
                    if(tablero[1]==p3.pieza6[0]){
                        tablero[2]=p3.pieza6[0];
                        tablero[3]=p3.pieza6[1];
                    }
                    else if(tablero[1]==p3.pieza6[1]){
                        tablero[2]=p3.pieza6[1];
                        tablero[3]=p3.pieza6[0];
                    }
                }
                if (pieza==14){
                    if(tablero[1]==p3.pieza7[0]){
                        tablero[2]=p3.pieza7[0];
                        tablero[3]=p3.pieza7[1];
                    }
                    else if(tablero[1]==p3.pieza7[1]){
                        tablero[2]=p3.pieza7[1];
                        tablero[3]=p3.pieza7[0];
                    }
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int));
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int));
            }
            //jugda enésima
            else{
                pieza=jugada(&p3,tablero[0],tablero[3]);
                if (pieza==1){
                    if(tablero[0]==p3.pieza1[0]){
                        tablero[1]=p3.pieza1[0];
                        tablero[0]=p3.pieza1[1];
                    }
                    else if(tablero[0]==p3.pieza1[1]){
                        tablero[0]=p3.pieza1[0];
                        tablero[1]=p3.pieza1[1];
                    }
                }
                if (pieza==2){
                    if(tablero[0]==p3.pieza2[0]){
                        tablero[1]=p3.pieza2[0];
                        tablero[0]=p3.pieza2[1];
                    }
                    else if(tablero[0]==p3.pieza2[1]){
                        tablero[0]=p3.pieza2[0];
                        tablero[1]=p3.pieza2[1];
                    }
                }
                if (pieza==3){
                    if(tablero[0]==p3.pieza3[0]){
                        tablero[1]=p3.pieza3[0];
                        tablero[0]=p3.pieza3[1];
                    }
                    else if(tablero[0]==p3.pieza3[1]){
                        tablero[0]=p3.pieza3[0];
                        tablero[1]=p3.pieza3[1];
                    }

                }
                if (pieza==4){
                    if(tablero[0]==p3.pieza4[0]){
                        tablero[1]=p3.pieza4[0];
                        tablero[0]=p3.pieza4[1];
                    }
                    else if(tablero[0]==p3.pieza4[1]){
                        tablero[0]=p3.pieza4[0];
                        tablero[1]=p3.pieza4[1];
                    }
                }
                if (pieza==5){
                    if(tablero[0]==p3.pieza5[0]){
                        tablero[1]=p3.pieza5[0];
                        tablero[0]=p3.pieza5[1];
                    }
                    else if(tablero[0]==p3.pieza5[1]){
                        tablero[0]=p3.pieza5[0];
                        tablero[1]=p3.pieza5[1];
                    }
                }
                if (pieza==6){
                    if(tablero[0]==p3.pieza6[0]){
                        tablero[1]=p3.pieza6[0];
                        tablero[0]=p3.pieza6[1];
                    }
                    else if(tablero[0]==p3.pieza6[1]){
                        tablero[0]=p3.pieza6[0];
                        tablero[1]=p3.pieza6[1];
                    }
                }
                if (pieza==7){
                    if(tablero[0]==p3.pieza7[0]){
                        tablero[1]=p3.pieza7[0];
                        tablero[0]=p3.pieza7[1];
                    }
                    else if(tablero[0]==p3.pieza7[1]){
                        tablero[0]=p3.pieza7[0];
                        tablero[1]=p3.pieza7[1];
                    }
                }
                if (pieza==8){
                    if(tablero[3]==p3.pieza1[0]){
                        tablero[2]=p3.pieza1[0];
                        tablero[3]=p3.pieza1[1];
                    }
                    else if(tablero[3]==p3.pieza1[1]){
                        tablero[2]=p3.pieza1[1];
                        tablero[3]=p3.pieza1[0];
                    }
                }
                if (pieza==9){
                    if(tablero[3]==p3.pieza2[0]){
                        tablero[2]=p3.pieza2[0];
                        tablero[3]=p3.pieza2[1];
                    }
                    else if(tablero[3]==p3.pieza2[1]){
                        tablero[2]=p3.pieza2[1];
                        tablero[3]=p3.pieza2[0];
                    }
                }
                if (pieza==10){
                    if(tablero[3]==p3.pieza3[0]){
                        tablero[2]=p3.pieza3[0];
                        tablero[3]=p3.pieza3[1];
                    }
                    else if(tablero[3]==p3.pieza3[1]){
                        tablero[2]=p3.pieza3[1];
                        tablero[3]=p3.pieza3[0];
                    }
                }
                if (pieza==11){
                    if(tablero[3]==p3.pieza4[0]){
                        tablero[2]=p3.pieza4[0];
                        tablero[3]=p3.pieza4[1];
                    }
                    else if(tablero[3]==p3.pieza4[1]){
                        tablero[2]=p3.pieza4[1];
                        tablero[3]=p3.pieza4[0];
                    }
                }
                if (pieza==12){
                    if(tablero[3]==p3.pieza5[0]){
                        tablero[2]=p3.pieza5[0];
                        tablero[3]=p3.pieza5[1];
                    }
                    else if(tablero[3]==p3.pieza5[1]){
                        tablero[2]=p3.pieza5[1];
                        tablero[3]=p3.pieza5[0];
                    }
                }
                if (pieza==13){
                    if(tablero[3]==p3.pieza6[0]){
                        tablero[2]=p3.pieza6[0];
                        tablero[3]=p3.pieza6[1];
                    }
                    else if(tablero[3]==p3.pieza6[1]){
                        tablero[2]=p3.pieza6[1];
                        tablero[3]=p3.pieza6[0];
                    }
                }
                if (pieza==14){
                    if(tablero[3]==p3.pieza7[0]){
                        tablero[2]=p3.pieza7[0];
                        tablero[3]=p3.pieza7[1];
                    }
                    else if(tablero[3]==p3.pieza7[1]){
                        tablero[2]=p3.pieza7[1];
                        tablero[3]=p3.pieza7[0];
                    }
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int));
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int));
            }

                
            
        }
        //la idea es hacer pipes que comuniquen con el padre y con los hijos entre sí el read hace que esperen  
    }
    return 0;
}
