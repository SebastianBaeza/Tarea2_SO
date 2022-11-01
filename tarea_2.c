#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
  #include <sys/types.h>
  #include <sys/wait.h>

int piezas[28][2] = {{6,6},{6,5},{5,5},{6,4},{5,4},{4,4},{6,3},{5,3},{4,3},{3,3},{6,2},{5,2},{4,2},{3,2},{2,2},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,6},{0,5},{0,4},{0,3},{0,2},{0,1},{0,0}};

struct mazo{
    int pieza1[2];
    int pieza2[2];
    int pieza3[2];
    int pieza4[2];
    int pieza5[2];
    int pieza6[2];
    int pieza7[2];
};

/*
int mayor_pieza(struct mazo *jugador)
//////////////
Funcion que retorna un entero representando a la pieza del mazo (1-7) cuya suma es mayor
//////////////
- Jugador: Mazo del jugador
*/
int mayor_pieza(struct mazo *jugador){
    int actual;
    int pos = 1;
    int sum1 = (jugador->pieza1[0]) + (jugador->pieza1[1]);
    actual = sum1;
    int sum2 = (jugador->pieza2[0]) + (jugador->pieza2[1]);
    if (sum2 > actual){
        actual = sum2;
        pos = 2;
    }
    int sum3 = (jugador->pieza3[0]) + (jugador->pieza3[1]);
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
        if (sum7 > actual){
        actual = sum7;
        pos = 7;
    }
    return pos;
}

/*
int jugada(struct mazo *jugador, int izquierda, int derecha)
//////////////
Funcion que retorna cual pieza esta disponible para el juego (por medio de un entero), y su posición posible en el tablero (de 1 a 7 para la izquierda y de 8 a 14 a la derecha)
ej. retornar 6 significa que la pieza 6 del mazo puede ser colocada a la izq y si retorna 12, la pieza 6 del mazo puede ser colocada a la derecha.
//////////////
- Jugador: Mazo del jugador
- Izquierda: Valor de la pieza relevante a la izquierda del tablero
- Derecha: Valor de la pieza relevante a la derecha del tablero
*/
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
    if (jugador->pieza1[0]==derecha){
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

/*
void crear_piezas(struct mazo *jugador, int posicion[7])
//////////////
Funcion que rellena el mazo del jugador, rellena con las fichas del arreglo piezas indicadas por los valores de posicion[7]. El arreglo
piezas contiene a todas las fichas del Dominó
//////////////
- Jugador: Mazo del jugador
- posicion[7]: Arreglo con posiciones al azar del 0-27 
*/
void crear_piezas(struct mazo *jugador, int posicion[7]){
    int numero = 0;
    int flag = 0;
    while (flag == 0){
        if (numero == 0) {
            jugador->pieza1[0] = piezas[posicion[0]][0];
            jugador->pieza1[1] = piezas[posicion[0]][1];
            numero++;
        }
        else if (numero == 1) {
            jugador->pieza2[0] = piezas[posicion[1]][0];
            jugador->pieza2[1] = piezas[posicion[1]][1];
            numero++;
        }
        else if (numero == 2) {
            jugador->pieza3[0] = piezas[posicion[2]][0];
            jugador->pieza3[1] = piezas[posicion[2]][1];
            numero++;
        }
        else if (numero == 3){
            jugador->pieza4[0] = piezas[posicion[3]][0];
            jugador->pieza4[1] = piezas[posicion[3]][1];
            numero++;
        }
        else if (numero == 4){
            jugador->pieza5[0] = piezas[posicion[4]][0];
            jugador->pieza5[1] = piezas[posicion[4]][1];
            numero++;
        }
        else if (numero == 5){
            jugador->pieza6[0] = piezas[posicion[5]][0];
            jugador->pieza6[1] = piezas[posicion[5]][1];
            numero++;
        }
        else if (numero == 6){
            jugador->pieza7[0] = piezas[posicion[6]][0];
            jugador->pieza7[1] = piezas[posicion[6]][1];
            numero++;
            flag = 1;
        }

    }
}

/*
int main()
//////////////
Juego principal, ejecuta el juego, creando 4 procesos hijos, de los cuales 3 juegan automaticamente (los jugadores 1, 2 y 3)
y el 4to es controlado por el usuario mediante inputs, permitiendo poner piezas en la izquierda o la derecha (ubicandose al 
derecho o al reves automaticamente)
//////////////
No tiene inputs
*/
int main(){
    int proceso;
    int pid, pid1, pid2, pid3;

    int pipe_p0[2];
    int pipe_0p[2];
    int pipe_p1[2];
    int pipe_1p[2];
    int pipe_p2[2];
    int pipe_2p[2];
    int pipe_p3[2];
    int pipe_3p[2];

    int tablero[4] = {-1,-1,-1,-1};

    pipe(pipe_p0);
    pipe(pipe_0p);
    pipe(pipe_p1);
    pipe(pipe_1p);
    pipe(pipe_p2);
    pipe(pipe_2p);
    pipe(pipe_p3);
    pipe(pipe_3p);
    int temp1 = 10;
    int temp2 = 10;
    int temp3 = 10;
    int temp4 = 10;

    int parte;
    int mayor;
    int pieza;
    int sentido;
    int sum1;
    int sum2;
    int sum3;
    int sum4;
    int menor;
    int sumactual;
    int ganador;
    int sumap1;
    int sumap2;
    int sumap3;
    int sumap4;
    int sumap5;
    int sumap6;
    int sumap7;
    int termino;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;
    int pos[28];
    int var = 0;
    int check = 0;
    srand(time(NULL));
    parte = rand()%4;
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
            a++;
        }
    }
    struct mazo p1;
    struct mazo p2;
    struct mazo p3;
    struct mazo p4;

    int pos1[7];
    memcpy(pos1, pos, sizeof(int) * 7);
    crear_piezas(&p1, pos1);

    int pos2[7];
    memcpy(pos2,pos + 7,sizeof(int)*7);
    crear_piezas(&p2, pos2);

    int pos3[7];
    memcpy(pos3,pos + 14,sizeof(int)*7);
    crear_piezas(&p3, pos3);

    int pos4[7];
    memcpy(pos4,pos + 21,sizeof(int)*7);
    crear_piezas(&p4, pos4);

    pid = fork();
  
    if (pid == 0) {
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
    while (1) {
        if (proceso == 4){
            if (parte == 0){
                printf("Turno del 1er jugador\n");
                write(pipe_0p[1], &tablero[0], sizeof(int));
                write(pipe_0p[1], &tablero[1], sizeof(int));
                write(pipe_0p[1], &tablero[2], sizeof(int));
                write(pipe_0p[1], &tablero[3], sizeof(int));
                temp1 = tablero[0];
                temp2 = tablero[1];
                temp3 = tablero[2];
                temp4 = tablero[3];
                read(pipe_p0[0], &tablero[0], sizeof(int));
                read(pipe_p0[0], &tablero[1], sizeof(int));
                read(pipe_p0[0], &tablero[2], sizeof(int));
                read(pipe_p0[0], &tablero[3], sizeof(int));
                if (temp1 == tablero[0] && temp2 == tablero[1] && temp3 == tablero[2] && temp4 == tablero[3]){
                    flag1 = 1;
                }
                else {
                    flag1 = 0;
                }
                if (tablero[0] == 11){
                    printf("Gana el jugador 1\n");
                    termino=100;
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    break;
                }
                printf("Estado actual del tablero: [%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 1;
            }
            if (parte == 1){
                printf("Turno del 2do jugador\n");
                write(pipe_1p[1], &tablero[0], sizeof(int));
                write(pipe_1p[1], &tablero[1], sizeof(int));
                write(pipe_1p[1], &tablero[2], sizeof(int));
                write(pipe_1p[1], &tablero[3], sizeof(int));
                temp1 = tablero[0];
                temp2 = tablero[1];
                temp3 = tablero[2];
                temp4 = tablero[3];
                read(pipe_p1[0], &tablero[0], sizeof(int));
                read(pipe_p1[0], &tablero[1], sizeof(int));
                read(pipe_p1[0], &tablero[2], sizeof(int));
                read(pipe_p1[0], &tablero[3], sizeof(int));
                if (temp1 == tablero[0] && temp2 == tablero[1] && temp3 == tablero[2] && temp4 == tablero[3]){
                    flag2 = 1;
                }
                else {
                    flag2 = 0;
                }
                if (tablero[0] == 12){
                    printf("Gana el jugador 2\n");
                    termino=100;
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    break;
                }
                printf("Estado actual del tablero: [%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 2;
            }
            if (parte == 2){
                printf("Turno del 3er jugador\n");
                write(pipe_2p[1], &tablero[0], sizeof(int));
                write(pipe_2p[1], &tablero[1], sizeof(int));
                write(pipe_2p[1], &tablero[2], sizeof(int));
                write(pipe_2p[1], &tablero[3], sizeof(int));
                temp1 = tablero[0];
                temp2 = tablero[1];
                temp3 = tablero[2];
                temp4 = tablero[3];
                read(pipe_p2[0], &tablero[0], sizeof(int));
                read(pipe_p2[0], &tablero[1], sizeof(int));
                read(pipe_p2[0], &tablero[2], sizeof(int));
                read(pipe_p2[0], &tablero[3], sizeof(int));
                if (temp1 == tablero[0] && temp2 == tablero[1] && temp3 == tablero[2] && temp4 == tablero[3]){
                    flag3 = 1;
                }
                else {
                    flag3 = 0;
                }
                if (tablero[0] == 13){
                    printf("Gana el jugador 3\n");
                    termino=100;
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    write(pipe_3p[1], &termino, sizeof(int));
                    break;
                }
                printf("Estado actual del tablero: [%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                parte = 3;
            }
            if (parte == 3){
                printf("Tu turno:\n");
                if (p4.pieza1[0] != -2){
                    printf("1.-[%d|%d]\n",p4.pieza1[0],p4.pieza1[1]);
                }
                if (p4.pieza2[0] != -2){
                    printf("2.-[%d|%d]\n",p4.pieza2[0],p4.pieza2[1]);
                }
                if (p4.pieza3[0] != -2){
                    printf("3.-[%d|%d]\n",p4.pieza3[0],p4.pieza3[1]);
                }
                if (p4.pieza4[0] != -2){
                    printf("4.-[%d|%d]\n",p4.pieza4[0],p4.pieza4[1]);
                }
                if (p4.pieza5[0] != -2){
                    printf("5.-[%d|%d]\n",p4.pieza5[0],p4.pieza5[1]);
                }
                if (p4.pieza6[0] != -2){
                    printf("6.-[%d|%d]\n",p4.pieza6[0],p4.pieza6[1]);
                }
                if (p4.pieza7[0] != -2){
                    printf("7.-[%d|%d]\n",p4.pieza7[0],p4.pieza7[1]);
                }
                printf("Ingresa el número de la ficha a elegir, o -1 para pasar el turno\n");
                scanf("%d",&pieza);
                printf("Quieres ponerla a la izquierda (0) o a la derecha (1)?\n");
                scanf("%d",&sentido);
                if (pieza == 1){
                    p4.pieza1[0] = -2;
                    p4.pieza1[1] = -2;
                }
                if (pieza == 2){
                    p4.pieza2[0] = -2;
                    p4.pieza2[1] = -2;
                }
                if (pieza == 3){
                    p4.pieza3[0] = -2;
                    p4.pieza3[1] = -2;
                }
                if (pieza == 4){
                    p4.pieza4[0] = -2;
                    p4.pieza4[1] = -2;
                }
                if (pieza == 5){
                    p4.pieza5[0] = -2;
                    p4.pieza5[1] = -2;
                }
                if (pieza == 6){
                    p4.pieza6[0] = -2;
                    p4.pieza6[1] = -2;
                }
                if (pieza == 7){
                    p4.pieza7[0] = -2;
                    p4.pieza7[1] = -2;
                }
                sumap1 = p4.pieza1[0]+p4.pieza1[1];
                if (sumap1 < 0){
                    sumap1 = 99;

                }
                sum4 = sumap1;
                sumap2 = p4.pieza2[0]+p4.pieza2[1];
                if (sumap2 < 0){
                    sumap2 = 99;
                }
                if (sumap2 < menor){
                    sum4 = sumap2;
                }
                sumap3 = p4.pieza3[0]+p4.pieza3[1];
                if (sumap3 < 0){
                    sumap3 = 99;
                }
                if (sumap3 < menor){
                    sum4 = sumap3;
                }
                sumap4 = p4.pieza4[0]+p4.pieza4[1];
                if (sumap4 < 0){
                    sumap4 = 99;
                }
                if (sumap4 < menor){
                    sum4 = sumap4;
                }
                sumap5 = p4.pieza5[0]+p4.pieza5[1];
                if (sumap5 < 0){
                    sumap5 = 99;
                }
                if (sumap5 < menor){
                    sum4 = sumap5;
                }
                sumap6 = p4.pieza6[0]+p4.pieza6[1];
                if (sumap6 < 0){
                    sumap6 = 99;
                }
                if (sumap6 < menor){
                    sum4 = sumap6;
                }
                sumap7 = p4.pieza7[0]+p4.pieza7[1];
                if (sumap7 < 0){
                    sumap7 = 99;
                }
                if (sumap7 < menor){
                    sum4 = sumap7;
                }
                if (p4.pieza1[0] == -2 && p4.pieza2[0] == -2 && p4.pieza3[0] == -2 && p4.pieza4[0] == -2 && p4.pieza5[0] == -2 && p4.pieza6[0] == -2 && p4.pieza7[0] == -2){
                    menor = 14;
                    write(pipe_p3[1], &menor, sizeof(int));
                    write(pipe_p3[1], &menor, sizeof(int)); 
                    write(pipe_p3[1], &menor, sizeof(int));
                    write(pipe_p3[1], &menor, sizeof(int));
                    write(pipe_p3[1], &menor, sizeof(int));
                    write(pipe_p3[1], &menor, sizeof(int));
                }
                else{
                write(pipe_3p[1], &tablero[0], sizeof(int));
                write(pipe_3p[1], &tablero[1], sizeof(int));
                write(pipe_3p[1], &tablero[2], sizeof(int));
                write(pipe_3p[1], &tablero[3], sizeof(int));
                write(pipe_3p[1], &pieza, sizeof(int));
                write(pipe_3p[1], &sentido, sizeof(int));
                }
                temp1 = tablero[0];
                temp2 = tablero[1];
                temp3 = tablero[2];
                temp4 = tablero[3];
                read(pipe_p3[0], &tablero[0], sizeof(int));
                read(pipe_p3[0], &tablero[1], sizeof(int));
                read(pipe_p3[0], &tablero[2], sizeof(int));
                read(pipe_p3[0], &tablero[3], sizeof(int));
                if (temp1 == tablero[0] && temp2 == tablero[1] && temp3 == tablero[2] && temp4 == tablero[3]){
                    flag4 = 1;
                }
                else {
                    flag4 = 0;
                }
                if (tablero[0] == 14){
                    printf("Ganaste jugador 4!");
                    termino=100;
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_1p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_2p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    write(pipe_0p[1], &termino, sizeof(int));
                    break;
                }
                printf("Estado actual del tablero: [%d|%d][%d|%d]\n",tablero[0],tablero[1],tablero[2],tablero[3]);
                
                if (flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1){
                    tablero[0] = 99;
                    tablero[1] = 99;
                    tablero[2] = 99;
                    tablero[3] = 99;
                    write(pipe_0p[1], &tablero[0], sizeof(int));
                    write(pipe_0p[1], &tablero[1], sizeof(int));
                    write(pipe_0p[1], &tablero[2], sizeof(int));
                    write(pipe_0p[1], &tablero[3], sizeof(int));
                    read(pipe_p0[0], &tablero[0], sizeof(int));
                    read(pipe_p0[0], &tablero[1], sizeof(int));
                    read(pipe_p0[0], &tablero[2], sizeof(int));
                    read(pipe_p0[0], &tablero[3], sizeof(int));
                    sum1 = tablero[0];
                    sumactual = sum1;
                    ganador = 1;
                    write(pipe_1p[1], &tablero[0], sizeof(int));
                    write(pipe_1p[1], &tablero[1], sizeof(int));
                    write(pipe_1p[1], &tablero[2], sizeof(int));
                    write(pipe_1p[1], &tablero[3], sizeof(int));
                    read(pipe_p1[0], &tablero[0], sizeof(int));
                    read(pipe_p1[0], &tablero[1], sizeof(int));
                    read(pipe_p1[0], &tablero[2], sizeof(int));
                    read(pipe_p1[0], &tablero[3], sizeof(int));
                    sum2 = tablero[0];
                    if (sum2 < sumactual){
                        sumactual = sum2;
                        ganador = 2;
                    }
                    write(pipe_2p[1], &tablero[0], sizeof(int));
                    write(pipe_2p[1], &tablero[1], sizeof(int));
                    write(pipe_2p[1], &tablero[2], sizeof(int));
                    write(pipe_2p[1], &tablero[3], sizeof(int));
                    read(pipe_p2[0], &tablero[0], sizeof(int));
                    read(pipe_p2[0], &tablero[1], sizeof(int));
                    read(pipe_p2[0], &tablero[2], sizeof(int));
                    read(pipe_p2[0], &tablero[3], sizeof(int));
                    sum3 = tablero[0];
                    if (sum3 < sumactual){
                        sumactual = sum3;
                        ganador = 3;
                    }
                    if (sum4 < sumactual){
                        sumactual = sum4;
                        ganador = 4;
                    }
                    printf("Gana el jugador %d\n", ganador);
                    break;
                }
                parte = 0;
            }

        } 

        if (proceso == 0){
            read(pipe_0p[0], &tablero[0], sizeof(int));
            read(pipe_0p[0], &tablero[1], sizeof(int));
            read(pipe_0p[0], &tablero[2], sizeof(int));
            read(pipe_0p[0], &tablero[3], sizeof(int));
            if(tablero[0]==100){
                break;
            }
            if (tablero[0] == 99){
                sumap1 = p1.pieza1[0] + p1.pieza1[1];
                if (sumap1 < 0){
                    sumap1 = 99;

                }
                menor = sumap1;
                sumap2 = p1.pieza2[0] + p1.pieza2[1];
                if (sumap2 < 0){
                    sumap2 = 99;
                }
                if (sumap2 < menor){
                    menor = sumap2;
                }
                sumap3 = p1.pieza3[0] + p1.pieza3[1];
                if (sumap3 < 0){
                    sumap3 = 99;
                }
                if (sumap3 < menor){
                    menor = sumap3;
                }
                sumap4 = p1.pieza4[0] + p1.pieza4[1];
                if (sumap4 < 0){
                    sumap4 = 99;
                }
                if (sumap4 < menor){
                    menor = sumap4;
                }
                sumap5 = p1.pieza5[0] + p1.pieza5[1];
                if (sumap5 < 0){
                    sumap5 = 99;
                }
                if (sumap5 < menor){
                    menor = sumap5;
                }
                sumap6 = p1.pieza6[0] + p1.pieza6[1];
                if (sumap6 < 0){
                    sumap6 = 99;
                }
                if (sumap6 < menor){
                    menor = sumap6;
                }
                sumap7 = p1.pieza7[0] + p1.pieza7[1];
                if (sumap7 < 0){
                    sumap7 = 99;
                }
                if (sumap7 < menor){
                    menor = sumap7;
                }
                write(pipe_p0[1], &menor, sizeof(int));
                write(pipe_p0[1], &menor, sizeof(int)); 
                write(pipe_p0[1], &menor, sizeof(int));
                write(pipe_p0[1], &menor, sizeof(int));                 
                break;
            
            }
            
            else if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p1);
                if (mayor == 1){
                    tablero[0] = p1.pieza1[0];
                    tablero[1] = p1.pieza1[1];
                    p1.pieza1[0] = -2;
                    p1.pieza1[1] = -2;
                }
                else if (mayor == 2){
                    tablero[0] = p1.pieza2[0];
                    tablero[1] = p1.pieza2[1];
                    p1.pieza2[0] = -2;
                    p1.pieza2[1] = -2;

                }
                else if (mayor == 3){
                    tablero[0] = p1.pieza3[0];
                    tablero[1] = p1.pieza3[1];
                    p1.pieza3[0] = -2;
                    p1.pieza3[1] = -2;
                }
                else if (mayor == 4){
                    tablero[0] = p1.pieza4[0];
                    tablero[1] = p1.pieza4[1];
                    p1.pieza4[0] = -2;
                    p1.pieza4[1] = -2;
                }
                else if (mayor == 5){
                    tablero[0] = p1.pieza5[0];
                    tablero[1] = p1.pieza5[1];
                    p1.pieza5[0] = -2;
                    p1.pieza5[1] = -2;
                }
                else if (mayor == 6){
                    tablero[0] = p1.pieza6[0];
                    tablero[1] = p1.pieza6[1];
                    p1.pieza6[0] = -2;
                    p1.pieza6[1] = -2;
                }
                else if (mayor == 7){
                    tablero[0] = p1.pieza7[0];
                    tablero[1] = p1.pieza7[1];
                    p1.pieza7[0] = -2;
                    p1.pieza7[1] = -2;
                }
                write(pipe_p0[1], &tablero[0], sizeof(int));
                write(pipe_p0[1], &tablero[1], sizeof(int)); 
                write(pipe_p0[1], &tablero[2], sizeof(int));
                write(pipe_p0[1], &tablero[3], sizeof(int)); 
            }
            // Jugada N° 2
            else if (tablero[2] == -1){
                pieza = jugada(&p1,tablero[0],tablero[1]);
                if (pieza == 1){
                    if (tablero[0] == p1.pieza1[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[1];
                        tablero[1] = p1.pieza1[0];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza1[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p1.pieza2[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza2[1];
                        tablero[1] = p1.pieza2[0];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza2[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza2[0];
                        tablero[1] = p1.pieza2[1];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p1.pieza3[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza3[1];
                        tablero[1] = p1.pieza3[0];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza3[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza3[0];
                        tablero[1] = p1.pieza3[1];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                }
                if (pieza == 4){
                    if (tablero[0] == p1.pieza4[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza4[1];
                        tablero[1] = p1.pieza4[0];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza4[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza4[0];
                        tablero[1] = p1.pieza4[1];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p1.pieza5[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza5[1];
                        tablero[1] = p1.pieza5[0];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza5[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza5[0];
                        tablero[1] = p1.pieza5[1];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p1.pieza6[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza6[1];
                        tablero[1] = p1.pieza6[0];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza6[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza6[0];
                        tablero[1] = p1.pieza6[1];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p1.pieza7[0]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza7[1];
                        tablero[1] = p1.pieza7[0];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza7[1]){
                        tablero[2] = tablero[0];
                        tablero[3] = tablero[1];
                        tablero[0] = p1.pieza7[0];
                        tablero[1] = p1.pieza7[1];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p1.pieza1[0]){
                        tablero[2]  =  p1.pieza1[0];
                        tablero[3]  =  p1.pieza1[1];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza1[1]){
                        tablero[2] = p1.pieza1[1];
                        tablero[3] = p1.pieza1[0];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[1] == p1.pieza2[0]){
                        tablero[2] = p1.pieza2[0];
                        tablero[3] = p1.pieza2[1];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza2[1]){
                        tablero[2] = p1.pieza2[1];
                        tablero[3] = p1.pieza2[0];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[1] == p1.pieza3[0]){
                        tablero[2] = p1.pieza3[0];
                        tablero[3] = p1.pieza3[1];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza3[1]){
                        tablero[2] = p1.pieza3[1];
                        tablero[3] = p1.pieza3[0];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                }
                if (pieza == 11){
                    if (tablero[1] == p1.pieza4[0]){
                        tablero[2] = p1.pieza4[0];
                        tablero[3] = p1.pieza4[1];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza4[1]){
                        tablero[2] = p1.pieza4[1];
                        tablero[3] = p1.pieza4[0];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[1] == p1.pieza5[0]){
                        tablero[2] = p1.pieza5[0];
                        tablero[3] = p1.pieza5[1];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza5[1]){
                        tablero[2] = p1.pieza5[1];
                        tablero[3] = p1.pieza5[0];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[1] == p1.pieza6[0]){
                        tablero[2] = p1.pieza6[0];
                        tablero[3] = p1.pieza6[1];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza6[1]){
                        tablero[2] = p1.pieza6[1];
                        tablero[3] = p1.pieza6[0];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[1] == p1.pieza7[0]){
                        tablero[2] = p1.pieza7[0];
                        tablero[3] = p1.pieza7[1];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                    else if (tablero[1] == p1.pieza7[1]){
                        tablero[2] = p1.pieza7[1];
                        tablero[3] = p1.pieza7[0];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                }
                write(pipe_p0[1], &tablero[0], sizeof(int));
                write(pipe_p0[1], &tablero[1], sizeof(int));
                write(pipe_p0[1], &tablero[2], sizeof(int));
                write(pipe_p0[1], &tablero[3], sizeof(int));
            }
            // Proximas jugadas 
            else {
                pieza = jugada(&p1,tablero[0],tablero[3]);
                if (pieza == 1){
                    if (tablero[0] == p1.pieza1[0]){
                        tablero[1] = p1.pieza1[0];
                        tablero[0] = p1.pieza1[1];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza1[1]){
                        tablero[0] = p1.pieza1[0];
                        tablero[1] = p1.pieza1[1];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p1.pieza2[0]){
                        tablero[1] = p1.pieza2[0];
                        tablero[0] = p1.pieza2[1];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza2[1]){
                        tablero[0] = p1.pieza2[0];
                        tablero[1] = p1.pieza2[1];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p1.pieza3[0]){
                        tablero[1] = p1.pieza3[0];
                        tablero[0] = p1.pieza3[1];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza3[1]){
                        tablero[0] = p1.pieza3[0];
                        tablero[1] = p1.pieza3[1];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p1.pieza4[0]){
                        tablero[1] = p1.pieza4[0];
                        tablero[0] = p1.pieza4[1];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza4[1]){
                        tablero[0] = p1.pieza4[0];
                        tablero[1] = p1.pieza4[1];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p1.pieza5[0]){
                        tablero[1] = p1.pieza5[0];
                        tablero[0] = p1.pieza5[1];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza5[1]){
                        tablero[0] = p1.pieza5[0];
                        tablero[1] = p1.pieza5[1];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p1.pieza6[0]){
                        tablero[1] = p1.pieza6[0];
                        tablero[0] = p1.pieza6[1];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza6[1]){
                        tablero[0] = p1.pieza6[0];
                        tablero[1] = p1.pieza6[1];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                }
                if (pieza ==7){
                    if (tablero[0] == p1.pieza7[0]){
                        tablero[1] = p1.pieza7[0];
                        tablero[0] = p1.pieza7[1];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p1.pieza7[1]){
                        tablero[0] = p1.pieza7[0];
                        tablero[1] = p1.pieza7[1];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p1.pieza1[0]){
                        tablero[2] = p1.pieza1[0];
                        tablero[3] = p1.pieza1[1];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza1[1]){
                        tablero[2] = p1.pieza1[1];
                        tablero[3] = p1.pieza1[0];
                        p1.pieza1[0] = -2;
                        p1.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p1.pieza2[0]){
                        tablero[2] = p1.pieza2[0];
                        tablero[3] = p1.pieza2[1];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza2[1]){
                        tablero[2] = p1.pieza2[1];
                        tablero[3] = p1.pieza2[0];
                        p1.pieza2[0] = -2;
                        p1.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[3] == p1.pieza3[0]){
                        tablero[2] = p1.pieza3[0];
                        tablero[3] = p1.pieza3[1];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza3[1]){
                        tablero[2] = p1.pieza3[1];
                        tablero[3] = p1.pieza3[0];
                        p1.pieza3[0] = -2;
                        p1.pieza3[1] = -2;                        
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p1.pieza4[0]){
                        tablero[2] = p1.pieza4[0];
                        tablero[3] = p1.pieza4[1];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza4[1]){
                        tablero[2] = p1.pieza4[1];
                        tablero[3] = p1.pieza4[0];
                        p1.pieza4[0] = -2;
                        p1.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[3] == p1.pieza5[0]){
                        tablero[2] = p1.pieza5[0];
                        tablero[3] = p1.pieza5[1];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza5[1]){
                        tablero[2] = p1.pieza5[1];
                        tablero[3] = p1.pieza5[0];
                        p1.pieza5[0] = -2;
                        p1.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p1.pieza6[0]){
                        tablero[2] = p1.pieza6[0];
                        tablero[3] = p1.pieza6[1];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza6[1]){
                        tablero[2] = p1.pieza6[1];
                        tablero[3] = p1.pieza6[0];
                        p1.pieza6[0] = -2;
                        p1.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[3] == p1.pieza7[0]){
                        tablero[2] = p1.pieza7[0];
                        tablero[3] = p1.pieza7[1];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                    else if (tablero[3] == p1.pieza7[1]){
                        tablero[2] = p1.pieza7[1];
                        tablero[3] = p1.pieza7[0];
                        p1.pieza7[0] = -2;
                        p1.pieza7[1] = -2;
                    }
                }
                if (p1.pieza1[0] == -2 && p1.pieza2[0] == -2 && p1.pieza3[0] == -2 && p1.pieza4[0] == -2 && p1.pieza5[0] == -2 && p1.pieza6[0] == -2 && p1.pieza7[0] == -2){
                    menor=11;
                    write(pipe_p0[1], &menor, sizeof(int));
                    write(pipe_p0[1], &menor, sizeof(int)); 
                    write(pipe_p0[1], &menor, sizeof(int));
                    write(pipe_p0[1], &menor, sizeof(int));
                    break;       
                }
                else {
                    write(pipe_p0[1], &tablero[0], sizeof(int));
                    write(pipe_p0[1], &tablero[1], sizeof(int));
                    write(pipe_p0[1], &tablero[2], sizeof(int));
                    write(pipe_p0[1], &tablero[3], sizeof(int));
                }
            }

           
        } if (proceso == 1){
            read(pipe_1p[0], &tablero[0], sizeof(int));
            read(pipe_1p[0], &tablero[1], sizeof(int));
            read(pipe_1p[0], &tablero[2], sizeof(int));
            read(pipe_1p[0], &tablero[3], sizeof(int));
            if (tablero[0] == 99){
                sumap1 = p2.pieza1[0]+p2.pieza1[1];
                if (sumap1<0){
                    sumap1=99;

                }
                menor=sumap1;
                sumap2 = p2.pieza2[0]+p2.pieza2[1];
                if (sumap2<0){
                    sumap2=99;
                }
                if (sumap2<menor){
                    menor=sumap2;
                }
                sumap3 = p2.pieza3[0]+p2.pieza3[1];
                if (sumap3<0){
                    sumap3=99;
                }
                if (sumap3<menor){
                    menor=sumap3;
                }
                sumap4 = p2.pieza4[0]+p2.pieza4[1];
                if (sumap4<0){
                    sumap4=99;
                }
                if (sumap4<menor){
                    menor=sumap4;
                }
                sumap5 = p2.pieza5[0]+p2.pieza5[1];
                if (sumap5<0){
                    sumap5=99;
                }
                if (sumap5<menor){
                    menor=sumap5;
                }
                sumap6 = p2.pieza6[0]+p2.pieza6[1];
                if (sumap6<0){
                    sumap6=99;
                }
                if (sumap6<menor){
                    menor=sumap6;
                }
                sumap7 = p2.pieza7[0]+p2.pieza7[1];
                if (sumap7<0){
                    sumap7=99;
                }
                if (sumap7<menor){
                    menor=sumap7;
                }
                write(pipe_p1[1], &menor, sizeof(int));
                write(pipe_p1[1], &menor, sizeof(int)); 
                write(pipe_p1[1], &menor, sizeof(int));
                write(pipe_p1[1], &menor, sizeof(int));
                break;                 
            
            }
            else if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p2);
                if (mayor == 1){
                    tablero[0] = p2.pieza1[0];
                    tablero[1] = p2.pieza1[1];
                    p2.pieza1[0] = -2;
                    p2.pieza1[1] = -2;
                }
                else if (mayor == 2){
                    tablero[0] = p2.pieza2[0];
                    tablero[1] = p2.pieza2[1];
                    p2.pieza2[0] = -2;
                    p2.pieza2[1] = -2;

                }
                else if (mayor == 3){
                    tablero[0] = p2.pieza3[0];
                    tablero[1] = p2.pieza3[1];
                    p2.pieza3[0] = -2;
                    p2.pieza3[1] = -2;
                }
                else if (mayor == 4){
                    tablero[0] = p2.pieza4[0];
                    tablero[1] = p2.pieza4[1];
                    p2.pieza4[0] = -2;
                    p2.pieza4[1] = -2;

                }
                else if (mayor == 5){
                    tablero[0] = p2.pieza5[0];
                    tablero[1] = p2.pieza5[1];
                    p2.pieza5[0] = -2;
                    p2.pieza5[1] = -2;
                }
                else if (mayor == 6){
                    tablero[0] = p2.pieza6[0];
                    tablero[1] = p2.pieza6[1];
                    p2.pieza6[0] = -2;
                    p2.pieza6[1] = -2;
                }
                else if (mayor == 7){
                    tablero[0] = p2.pieza7[0];
                    tablero[1] = p2.pieza7[1];
                    p2.pieza7[0] = -2;
                    p2.pieza7[1] = -2;
                }
                write(pipe_p1[1], &tablero[0], sizeof(int));
                write(pipe_p1[1], &tablero[1], sizeof(int)); 
                write(pipe_p1[1], &tablero[2], sizeof(int));
                write(pipe_p1[1], &tablero[3], sizeof(int)); 
            }
            // Jugada N° 2
            else if (tablero[2] == -1){
                pieza = jugada(&p2,-1,tablero[1]);
                if (pieza ==1){
                    if (tablero[0] == p2.pieza1[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza1[1];
                        tablero[1] = p2.pieza1[0];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza1[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza1[0];
                        tablero[1] = p2.pieza1[1];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                }
                if (pieza ==2){
                    if (tablero[0] == p2.pieza2[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza2[1];
                        tablero[1] = p2.pieza2[0];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza2[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza2[0];
                        tablero[1] = p2.pieza2[1];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                }
                if (pieza ==3){
                    if (tablero[0] == p2.pieza3[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza3[1];
                        tablero[1] = p2.pieza3[0];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza3[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza3[0];
                        tablero[1] = p2.pieza3[1];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                }
                if (pieza ==4){
                    if (tablero[0] == p2.pieza4[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza4[1];
                        tablero[1] = p2.pieza4[0];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza4[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza4[0];
                        tablero[1] = p2.pieza4[1];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                }
                if (pieza ==5){
                    if (tablero[0] == p2.pieza5[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza5[1];
                        tablero[1] = p2.pieza5[0];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza5[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza5[0];
                        tablero[1] = p2.pieza5[1];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                }
                if (pieza ==6){
                    if (tablero[0] == p2.pieza6[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza6[1];
                        tablero[1] = p2.pieza6[0];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza6[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza6[0];
                        tablero[1] = p2.pieza6[1];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                }
                if (pieza ==7){
                    if (tablero[0] == p2.pieza7[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza7[1];
                        tablero[1] = p2.pieza7[0];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza7[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p2.pieza7[0];
                        tablero[1] = p2.pieza7[1];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p2.pieza1[0]){
                        tablero[2] = p2.pieza1[0];
                        tablero[3] = p2.pieza1[1];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza1[1]){
                        tablero[2] = p2.pieza1[1];
                        tablero[3] = p2.pieza1[0];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[1] == p2.pieza2[0]){
                        tablero[2] = p2.pieza2[0];
                        tablero[3] = p2.pieza2[1];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza2[1]){
                        tablero[2] = p2.pieza2[1];
                        tablero[3] = p2.pieza2[0];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[1] == p2.pieza3[0]){
                        tablero[2] = p2.pieza3[0];
                        tablero[3] = p2.pieza3[1];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza3[1]){
                        tablero[2] = p2.pieza3[1];
                        tablero[3] = p2.pieza3[0];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                }
                if (pieza == 11){
                    if (tablero[1] == p2.pieza4[0]){
                        tablero[2] = p2.pieza4[0];
                        tablero[3] = p2.pieza4[1];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza4[1]){
                        tablero[2] = p2.pieza4[1];
                        tablero[3] = p2.pieza4[0];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[1] == p2.pieza5[0]){
                        tablero[2] = p2.pieza5[0];
                        tablero[3] = p2.pieza5[1];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza5[1]){
                        tablero[2] = p2.pieza5[1];
                        tablero[3] = p2.pieza5[0];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[1] == p2.pieza6[0]){
                        tablero[2] = p2.pieza6[0];
                        tablero[3] = p2.pieza6[1];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza6[1]){
                        tablero[2] = p2.pieza6[1];
                        tablero[3] = p2.pieza6[0];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[1] == p2.pieza7[0]){
                        tablero[2] = p2.pieza7[0];
                        tablero[3] = p2.pieza7[1];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                    else if (tablero[1] == p2.pieza7[1]){
                        tablero[2] = p2.pieza7[1];
                        tablero[3] = p2.pieza7[0];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                }
                write(pipe_p1[1], &tablero[0], sizeof(int));
                write(pipe_p1[1], &tablero[1], sizeof(int));
                write(pipe_p1[1], &tablero[2], sizeof(int));
                write(pipe_p1[1], &tablero[3], sizeof(int));
            }
            // Proximas jugadas 
            else {
                pieza = jugada(&p2,tablero[0],tablero[3]);
                if (pieza == 1){
                    if (tablero[0] == p2.pieza1[0]){
                        tablero[1] = p2.pieza1[0];
                        tablero[0] = p2.pieza1[1];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza1[1]){
                        tablero[0] = p2.pieza1[0];
                        tablero[1] = p2.pieza1[1];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;                       
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p2.pieza2[0]){
                        tablero[1] = p2.pieza2[0];
                        tablero[0] = p2.pieza2[1];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza2[1]){
                        tablero[0] = p2.pieza2[0];
                        tablero[1] = p2.pieza2[1];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p2.pieza3[0]){
                        tablero[1] = p2.pieza3[0];
                        tablero[0] = p2.pieza3[1];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza3[1]){
                        tablero[0] = p2.pieza3[0];
                        tablero[1] = p2.pieza3[1];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p2.pieza4[0]){
                        tablero[1] = p2.pieza4[0];
                        tablero[0] = p2.pieza4[1];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza4[1]){
                        tablero[0] = p2.pieza4[0];
                        tablero[1] = p2.pieza4[1];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p2.pieza5[0]){
                        tablero[1] = p2.pieza5[0];
                        tablero[0] = p2.pieza5[1];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza5[1]){
                        tablero[0] = p2.pieza5[0];
                        tablero[1] = p2.pieza5[1];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p2.pieza6[0]){
                        tablero[1] = p2.pieza6[0];
                        tablero[0] = p2.pieza6[1];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza6[1]){
                        tablero[0] = p2.pieza6[0];
                        tablero[1] = p2.pieza6[1];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p2.pieza7[0]){
                        tablero[1] = p2.pieza7[0];
                        tablero[0] = p2.pieza7[1];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p2.pieza7[1]){
                        tablero[0] = p2.pieza7[0];
                        tablero[1] = p2.pieza7[1];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p2.pieza1[0]){
                        tablero[2] = p2.pieza1[0];
                        tablero[3] = p2.pieza1[1];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza1[1]){
                        tablero[2] = p2.pieza1[1];
                        tablero[3] = p2.pieza1[0];
                        p2.pieza1[0] = -2;
                        p2.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p2.pieza2[0]){
                        tablero[2] = p2.pieza2[0];
                        tablero[3] = p2.pieza2[1];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza2[1]){
                        tablero[2] = p2.pieza2[1];
                        tablero[3] = p2.pieza2[0];
                        p2.pieza2[0] = -2;
                        p2.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[3] == p2.pieza3[0]){
                        tablero[2] = p2.pieza3[0];
                        tablero[3] = p2.pieza3[1];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza3[1]){
                        tablero[2] = p2.pieza3[1];
                        tablero[3] = p2.pieza3[0];
                        p2.pieza3[0] = -2;
                        p2.pieza3[1] = -2;
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p2.pieza4[0]){
                        tablero[2] = p2.pieza4[0];
                        tablero[3] = p2.pieza4[1];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza4[1]){
                        tablero[2] = p2.pieza4[1];
                        tablero[3] = p2.pieza4[0];
                        p2.pieza4[0] = -2;
                        p2.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[3] == p2.pieza5[0]){
                        tablero[2] = p2.pieza5[0];
                        tablero[3] = p2.pieza5[1];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza5[1]){
                        tablero[2] = p2.pieza5[1];
                        tablero[3] = p2.pieza5[0];
                        p2.pieza5[0] = -2;
                        p2.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p2.pieza6[0]){
                        tablero[2] = p2.pieza6[0];
                        tablero[3] = p2.pieza6[1];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza6[1]){
                        tablero[2] = p2.pieza6[1];
                        tablero[3] = p2.pieza6[0];
                        p2.pieza6[0] = -2;
                        p2.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[3] == p2.pieza7[0]){
                        tablero[2] = p2.pieza7[0];
                        tablero[3] = p2.pieza7[1];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                    else if (tablero[3] == p2.pieza7[1]){
                        tablero[2] = p2.pieza7[1];
                        tablero[3] = p2.pieza7[0];
                        p2.pieza7[0] = -2;
                        p2.pieza7[1] = -2;
                    }
                }
                if (p2.pieza1[0] == -2 && p2.pieza2[0] == -2 && p2.pieza3[0] == -2 && p2.pieza4[0] == -2 && p2.pieza5[0] == -2 && p2.pieza6[0] == -2 && p2.pieza7[0] == -2){
                    menor=12;
                    write(pipe_p1[1], &menor, sizeof(int));
                    write(pipe_p1[1], &menor, sizeof(int)); 
                    write(pipe_p1[1], &menor, sizeof(int));
                    write(pipe_p1[1], &menor, sizeof(int));
                    break;   
                }
                else {
                    write(pipe_p1[1], &tablero[0], sizeof(int));
                    write(pipe_p1[1], &tablero[1], sizeof(int));
                    write(pipe_p1[1], &tablero[2], sizeof(int));
                    write(pipe_p1[1], &tablero[3], sizeof(int));
                }
            }

         


        } if (proceso == 2){
            read(pipe_2p[0], &tablero[0], sizeof(int));
            read(pipe_2p[0], &tablero[1], sizeof(int));
            read(pipe_2p[0], &tablero[2], sizeof(int));
            read(pipe_2p[0], &tablero[3], sizeof(int));
            if(tablero[0]==100){
                break;
            }
            if (tablero[0] == 99){
                sumap1 = p3.pieza1[0]+p3.pieza1[1];
                if (sumap1<0){
                    sumap1=99;

                }
                menor=sumap1;
                sumap2 = p3.pieza2[0]+p3.pieza2[1];
                if (sumap2<0){
                    sumap2=99;
                }
                if (sumap2<menor){
                    menor=sumap2;
                }
                sumap3 = p3.pieza3[0]+p3.pieza3[1];
                if (sumap3<0){
                    sumap3=99;
                }
                if (sumap3<menor){
                    menor=sumap3;
                }
                sumap4 = p3.pieza4[0]+p3.pieza4[1];
                if (sumap4<0){
                    sumap4=99;
                }
                if (sumap4<menor){
                    menor=sumap4;
                }
                sumap5 = p3.pieza5[0]+p3.pieza5[1];
                if (sumap5<0){
                    sumap5=99;
                }
                if (sumap5<menor){
                    menor=sumap5;
                }
                sumap6 = p3.pieza6[0]+p3.pieza6[1];
                if (sumap6<0){
                    sumap6=99;
                }
                if (sumap6<menor){
                    menor=sumap6;
                }
                sumap7 = p3.pieza7[0]+p3.pieza7[1];
                if (sumap7<0){
                    sumap7=99;
                }
                if (sumap7<menor){
                    menor=sumap7;
                }
                write(pipe_p2[1], &menor, sizeof(int));
                write(pipe_p2[1], &menor, sizeof(int)); 
                write(pipe_p2[1], &menor, sizeof(int));
                write(pipe_p2[1], &menor, sizeof(int));
                break;                 
            
            }
            else if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor = mayor_pieza(&p3);
                if (mayor == 1){
                    tablero[0] = p3.pieza1[0];
                    tablero[1] = p3.pieza1[1];
                    p3.pieza1[0] = -2;
                    p3.pieza1[1] = -2;
                }
                else if (mayor == 2){
                    tablero[0] = p3.pieza2[0];
                    tablero[1] = p3.pieza2[1];
                    p3.pieza2[0] = -2;
                    p3.pieza2[1] = -2;

                }
                else if (mayor == 3){
                    tablero[0] = p3.pieza3[0];
                    tablero[1] = p3.pieza3[1];
                    p3.pieza3[0] = -2;
                    p3.pieza3[1] = -2;
                }
                else if (mayor == 4){
                    tablero[0] = p3.pieza4[0];
                    tablero[1] = p3.pieza4[1];
                    p3.pieza4[0] = -2;
                    p3.pieza4[1] = -2;
                }
                else if (mayor == 5){
                    tablero[0] = p3.pieza5[0];
                    tablero[1] = p3.pieza5[1];
                    p3.pieza5[0] = -2;
                    p3.pieza5[1] = -2;
                }
                else if (mayor == 6){
                    tablero[0] = p3.pieza6[0];
                    tablero[1] = p3.pieza6[1];
                    p3.pieza6[0] = -2;
                    p3.pieza6[1] = -2;
                }
                else if (mayor == 7){
                    tablero[0] = p3.pieza7[0];
                    tablero[1] = p3.pieza7[1];
                    p3.pieza7[0] = -2;
                    p3.pieza7[1] = -2;
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int)); 
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int)); 
            }
            // Jugada N° 2
            else if (tablero[2] == -1){
                pieza = jugada(&p3, -1, tablero[1]);
                if (pieza ==1){
                    if (tablero[0] == p3.pieza1[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza1[1];
                        tablero[1] = p3.pieza1[0];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza1[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza1[0];
                        tablero[1] = p3.pieza1[1];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                }
                if (pieza ==2){
                    if (tablero[0] == p3.pieza2[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza2[1];
                        tablero[1] = p3.pieza2[0];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza2[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza2[0];
                        tablero[1] = p3.pieza2[1];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                }
                if (pieza ==3){
                    if (tablero[0] == p3.pieza3[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza3[1];
                        tablero[1] = p3.pieza3[0];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza3[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza3[0];
                        tablero[1] = p3.pieza3[1];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                }
                if (pieza ==4){
                    if (tablero[0] == p3.pieza4[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza4[1];
                        tablero[1] = p3.pieza4[0];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza4[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza4[0];
                        tablero[1] = p3.pieza4[1];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                }
                if (pieza ==5){
                    if (tablero[0] == p3.pieza5[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza5[1];
                        tablero[1] = p3.pieza5[0];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza5[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza5[0];
                        tablero[1] = p3.pieza5[1];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                }
                if (pieza ==6){
                    if (tablero[0] == p3.pieza6[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza6[1];
                        tablero[1] = p3.pieza6[0];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza6[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza6[0];
                        tablero[1] = p3.pieza6[1];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                }
                if (pieza ==7){
                    if (tablero[0] == p3.pieza7[0]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza7[1];
                        tablero[1] = p3.pieza7[0];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza7[1]){
                        tablero[2]=tablero[0];
                        tablero[3]=tablero[1];
                        tablero[0] = p3.pieza7[0];
                        tablero[1] = p3.pieza7[1];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[1] == p3.pieza1[0]){
                        tablero[2] = p3.pieza1[0];
                        tablero[3] = p3.pieza1[1];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza1[1]){
                        tablero[2] = p3.pieza1[1];
                        tablero[3] = p3.pieza1[0];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[1] == p3.pieza2[0]){
                        tablero[2] = p3.pieza2[0];
                        tablero[3] = p3.pieza2[1];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza2[1]){
                        tablero[2] = p3.pieza2[1];
                        tablero[3] = p3.pieza2[0];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[1] == p3.pieza3[0]){
                        tablero[2] = p3.pieza3[0];
                        tablero[3] = p3.pieza3[1];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza3[1]){
                        tablero[2] = p3.pieza3[1];
                        tablero[3] = p3.pieza3[0];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                }
                if (pieza == 11){
                    if (tablero[1] == p3.pieza4[0]){
                        tablero[2] = p3.pieza4[0];
                        tablero[3] = p3.pieza4[1];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza4[1]){
                        tablero[2] = p3.pieza4[1];
                        tablero[3] = p3.pieza4[0];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[1] == p3.pieza5[0]){
                        tablero[2] = p3.pieza5[0];
                        tablero[3] = p3.pieza5[1];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza5[1]){
                        tablero[2] = p3.pieza5[1];
                        tablero[3] = p3.pieza5[0];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[1] == p3.pieza6[0]){
                        tablero[2] = p3.pieza6[0];
                        tablero[3] = p3.pieza6[1];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza6[1]){
                        tablero[2] = p3.pieza6[1];
                        tablero[3] = p3.pieza6[0];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[1] == p3.pieza7[0]){
                        tablero[2] = p3.pieza7[0];
                        tablero[3] = p3.pieza7[1];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                    else if (tablero[1] == p3.pieza7[1]){
                        tablero[2] = p3.pieza7[1];
                        tablero[3] = p3.pieza7[0];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                }
                write(pipe_p2[1], &tablero[0], sizeof(int));
                write(pipe_p2[1], &tablero[1], sizeof(int));
                write(pipe_p2[1], &tablero[2], sizeof(int));
                write(pipe_p2[1], &tablero[3], sizeof(int));
            }
            // Proximas jugadas
            else {
                pieza = jugada(&p3,tablero[0],tablero[3]);
                if (pieza == 1){
                    if (tablero[0] == p3.pieza1[0]){
                        tablero[1] = p3.pieza1[0];
                        tablero[0] = p3.pieza1[1];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza1[1]){
                        tablero[0] = p3.pieza1[0];
                        tablero[1] = p3.pieza1[1];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                }
                if (pieza == 2){
                    if (tablero[0] == p3.pieza2[0]){
                        tablero[1] = p3.pieza2[0];
                        tablero[0] = p3.pieza2[1];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza2[1]){
                        tablero[0] = p3.pieza2[0];
                        tablero[1] = p3.pieza2[1];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                }
                if (pieza == 3){
                    if (tablero[0] == p3.pieza3[0]){
                        tablero[1] = p3.pieza3[0];
                        tablero[0] = p3.pieza3[1];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza3[1]){
                        tablero[0] = p3.pieza3[0];
                        tablero[1] = p3.pieza3[1];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }

                }
                if (pieza == 4){
                    if (tablero[0] == p3.pieza4[0]){
                        tablero[1] = p3.pieza4[0];
                        tablero[0] = p3.pieza4[1];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza4[1]){
                        tablero[0] = p3.pieza4[0];
                        tablero[1] = p3.pieza4[1];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                }
                if (pieza == 5){
                    if (tablero[0] == p3.pieza5[0]){
                        tablero[1] = p3.pieza5[0];
                        tablero[0] = p3.pieza5[1];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza5[1]){
                        tablero[0] = p3.pieza5[0];
                        tablero[1] = p3.pieza5[1];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                }
                if (pieza == 6){
                    if (tablero[0] == p3.pieza6[0]){
                        tablero[1] = p3.pieza6[0];
                        tablero[0] = p3.pieza6[1];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza6[1]){
                        tablero[0] = p3.pieza6[0];
                        tablero[1] = p3.pieza6[1];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                }
                if (pieza == 7){
                    if (tablero[0] == p3.pieza7[0]){
                        tablero[1] = p3.pieza7[0];
                        tablero[0] = p3.pieza7[1];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                    else if (tablero[0] == p3.pieza7[1]){
                        tablero[0] = p3.pieza7[0];
                        tablero[1] = p3.pieza7[1];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                }
                if (pieza == 8){
                    if (tablero[3] == p3.pieza1[0]){
                        tablero[2] = p3.pieza1[0];
                        tablero[3] = p3.pieza1[1];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza1[1]){
                        tablero[2] = p3.pieza1[1];
                        tablero[3] = p3.pieza1[0];
                        p3.pieza1[0] = -2;
                        p3.pieza1[1] = -2;
                    }
                }
                if (pieza == 9){
                    if (tablero[3] == p3.pieza2[0]){
                        tablero[2] = p3.pieza2[0];
                        tablero[3] = p3.pieza2[1];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza2[1]){
                        tablero[2] = p3.pieza2[1];
                        tablero[3] = p3.pieza2[0];
                        p3.pieza2[0] = -2;
                        p3.pieza2[1] = -2;
                    }
                }
                if (pieza == 10){
                    if (tablero[3] == p3.pieza3[0]){
                        tablero[2] = p3.pieza3[0];
                        tablero[3] = p3.pieza3[1];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza3[1]){
                        tablero[2] = p3.pieza3[1];
                        tablero[3] = p3.pieza3[0];
                        p3.pieza3[0] = -2;
                        p3.pieza3[1] = -2;
                    }
                }
                if (pieza == 11){
                    if (tablero[3] == p3.pieza4[0]){
                        tablero[2] = p3.pieza4[0];
                        tablero[3] = p3.pieza4[1];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza4[1]){
                        tablero[2] = p3.pieza4[1];
                        tablero[3] = p3.pieza4[0];
                        p3.pieza4[0] = -2;
                        p3.pieza4[1] = -2;
                    }
                }
                if (pieza == 12){
                    if (tablero[3] == p3.pieza5[0]){
                        tablero[2] = p3.pieza5[0];
                        tablero[3] = p3.pieza5[1];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza5[1]){
                        tablero[2] = p3.pieza5[1];
                        tablero[3] = p3.pieza5[0];
                        p3.pieza5[0] = -2;
                        p3.pieza5[1] = -2;
                    }
                }
                if (pieza == 13){
                    if (tablero[3] == p3.pieza6[0]){
                        tablero[2] = p3.pieza6[0];
                        tablero[3] = p3.pieza6[1];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza6[1]){
                        tablero[2] = p3.pieza6[1];
                        tablero[3] = p3.pieza6[0];
                        p3.pieza6[0] = -2;
                        p3.pieza6[1] = -2;
                    }
                }
                if (pieza == 14){
                    if (tablero[3] == p3.pieza7[0]){
                        tablero[2] = p3.pieza7[0];
                        tablero[3] = p3.pieza7[1];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                    else if (tablero[3] == p3.pieza7[1]){
                        tablero[2] = p3.pieza7[1];
                        tablero[3] = p3.pieza7[0];
                        p3.pieza7[0] = -2;
                        p3.pieza7[1] = -2;
                    }
                }
                if (p3.pieza1[0] == -2 && p3.pieza2[0] == -2 && p3.pieza3[0] == -2 && p3.pieza4[0] == -2 && p3.pieza5[0] == -2 && p3.pieza6[0] == -2 && p3.pieza7[0] == -2){
                    menor=13;
                    write(pipe_p2[1], &menor, sizeof(int));
                    write(pipe_p2[1], &menor, sizeof(int)); 
                    write(pipe_p2[1], &menor, sizeof(int));
                    write(pipe_p2[1], &menor, sizeof(int));       
                }
                else {
                    write(pipe_p2[1], &tablero[0], sizeof(int));
                    write(pipe_p2[1], &tablero[1], sizeof(int));
                    write(pipe_p2[1], &tablero[2], sizeof(int));
                    write(pipe_p2[1], &tablero[3], sizeof(int));
                }
            }
            
        } if (proceso == 3){

            read(pipe_3p[0], &tablero[0], sizeof(int));
            read(pipe_3p[0], &tablero[1], sizeof(int));
            read(pipe_3p[0], &tablero[2], sizeof(int));
            read(pipe_3p[0], &tablero[3], sizeof(int));
            read(pipe_3p[0], &pieza, sizeof(int));
            read(pipe_3p[0], &sentido, sizeof(int));
            if(tablero[0]==100){
                break;
            }
            if(tablero[0]==14){
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[0], sizeof(int));
                break;
            }
            if (tablero[0] == -1 && tablero[1] == -1 && tablero[2] == -1 && tablero[3] == -1){
                mayor=mayor_pieza(&p4);
                if (mayor==1){
                    tablero[0] = p4.pieza1[0];
                    tablero[1] = p4.pieza1[1];
                }
                else if (mayor==2){
                    tablero[0] = p4.pieza2[0];
                    tablero[1] = p4.pieza2[1];

                }
                else if (mayor==3){
                    tablero[0] = p4.pieza3[0];
                    tablero[1] = p4.pieza3[1];
                }
                else if (mayor==4){
                    tablero[0] = p4.pieza4[0];
                    tablero[1] = p4.pieza4[1];

                }
                else if (mayor==5){
                    tablero[0] = p4.pieza5[0];
                    tablero[1] = p4.pieza5[1];
                }
                else if (mayor==6){
                    tablero[0] = p4.pieza6[0];
                    tablero[1] = p4.pieza6[1];
                }
                else if (mayor==7){
                    tablero[0] = p4.pieza7[0];
                    tablero[1] = p4.pieza7[1];
                }
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[1], sizeof(int)); 
                write(pipe_p3[1], &tablero[2], sizeof(int));
                write(pipe_p3[1], &tablero[3], sizeof(int)); 
            }
            // Jugada N° 2
            else if (tablero[2] == -1){
                if (sentido==0){
                    if (pieza ==1){
                        if (tablero[0] == p4.pieza1[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza1[1];
                            tablero[1] = p4.pieza1[0];
                        }
                        else if (tablero[0] == p4.pieza1[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza1[0];
                            tablero[1] = p4.pieza1[1];
                        }
                    }
                    if (pieza ==2){
                        if (tablero[0] == p4.pieza2[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza2[1];
                            tablero[1] = p4.pieza2[0];
                        }
                        else if (tablero[0] == p4.pieza2[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza2[0];
                            tablero[1] = p4.pieza2[1];
                        }
                    }
                    if (pieza ==3){
                        if (tablero[0] == p4.pieza3[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza3[1];
                            tablero[1] = p4.pieza3[0];
                        }
                        else if (tablero[0] == p4.pieza3[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza3[0];
                            tablero[1] = p4.pieza3[1];
                        }
                    }
                    if (pieza ==4){
                        if (tablero[0] == p4.pieza4[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza4[1];
                            tablero[1] = p4.pieza4[0];
                        }
                        else if (tablero[0] == p4.pieza4[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza4[0];
                            tablero[1] = p4.pieza4[1];
                        }
                    }
                    if (pieza ==5){
                        if (tablero[0] == p4.pieza5[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza5[1];
                            tablero[1] = p4.pieza5[0];
                        }
                        else if (tablero[0] == p4.pieza5[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza5[0];
                            tablero[1] = p4.pieza5[1];
                        }
                    }
                    if (pieza ==6){
                        if (tablero[0] == p4.pieza6[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza6[1];
                            tablero[1] = p4.pieza6[0];
                        }
                        else if (tablero[0] == p4.pieza6[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza6[0];
                            tablero[1] = p4.pieza6[1];
                        }
                    }
                    if (pieza ==7){
                        if (tablero[0] == p4.pieza7[0]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza7[1];
                            tablero[1] = p4.pieza7[0];
                        }
                        else if (tablero[0] == p4.pieza7[1]){
                            tablero[2]=tablero[0];
                            tablero[3]=tablero[1];
                            tablero[0] = p4.pieza7[0];
                            tablero[1] = p4.pieza7[1];
                        }
                    }
                }
                if (sentido==1){
                    if (pieza ==1){
                        if (tablero[1] == p4.pieza1[0]){
                            tablero[2] = p4.pieza1[0];
                            tablero[3] = p4.pieza1[1];
                        }
                        else if (tablero[1] == p4.pieza1[1]){
                            tablero[2] = p4.pieza1[1];
                            tablero[3] = p4.pieza1[0];
                        }
                    }
                    if (pieza ==2){
                        if (tablero[1] == p4.pieza2[0]){
                            tablero[2] = p4.pieza2[0];
                            tablero[3] = p4.pieza2[1];
                        }
                        else if (tablero[1] == p4.pieza2[1]){
                            tablero[2] = p4.pieza2[1];
                            tablero[3] = p4.pieza2[0];
                        }
                    }
                    if (pieza ==3){
                        if (tablero[1] == p4.pieza3[0]){
                            tablero[2] = p4.pieza3[0];
                            tablero[3] = p4.pieza3[1];
                        }
                        else if (tablero[1] == p4.pieza3[1]){
                            tablero[2] = p4.pieza3[1];
                            tablero[3] = p4.pieza3[0];
                        }
                    }
                    if (pieza ==4){
                        if (tablero[1] == p4.pieza4[0]){
                            tablero[2] = p4.pieza4[0];
                            tablero[3] = p4.pieza4[1];
                        }
                        else if (tablero[1] == p4.pieza4[1]){
                            tablero[2] = p4.pieza4[1];
                            tablero[3] = p4.pieza4[0];
                        }
                    }
                    if (pieza ==5){
                        if (tablero[1] == p4.pieza5[0]){
                            tablero[2] = p4.pieza5[0];
                            tablero[3] = p4.pieza5[1];
                        }
                        else if (tablero[1] == p4.pieza5[1]){
                            tablero[2] = p4.pieza5[1];
                            tablero[3] = p4.pieza5[0];
                        }
                    }
                    if (pieza ==6){
                        if (tablero[1] == p4.pieza6[0]){
                            tablero[2] = p4.pieza6[0];
                            tablero[3] = p4.pieza6[1];
                        }
                        else if (tablero[1] == p4.pieza6[1]){
                            tablero[2] = p4.pieza6[1];
                            tablero[3] = p4.pieza6[0];
                        }
                    }
                    if (pieza ==7){
                        if (tablero[1] == p4.pieza7[0]){
                            tablero[2] = p4.pieza7[0];
                            tablero[3] = p4.pieza7[1];
                        }
                        else if (tablero[1] == p4.pieza7[1]){
                            tablero[2] = p4.pieza7[1];
                            tablero[3] = p4.pieza7[0];
                        }
                    }
                }
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[1], sizeof(int));
                write(pipe_p3[1], &tablero[2], sizeof(int));
                write(pipe_p3[1], &tablero[3], sizeof(int));
            }
            // Proximas Jugadas
            else {
                if (sentido==0){
                    if (pieza ==1){
                        if (tablero[0] == p4.pieza1[0]){
                            tablero[0] = p4.pieza1[1];
                            tablero[1] = p4.pieza1[0];
                        }
                        else if (tablero[0] == p4.pieza1[1]){
                            tablero[0] = p4.pieza1[0];
                            tablero[1] = p4.pieza1[1];
                        }
                    }
                    if (pieza ==2){
                        if (tablero[0] == p4.pieza2[0]){
                            tablero[0] = p4.pieza2[1];
                            tablero[1] = p4.pieza2[0];
                        }
                        else if (tablero[0] == p4.pieza2[1]){
                            tablero[0] = p4.pieza2[0];
                            tablero[1] = p4.pieza2[1];
                        }
                    }
                    if (pieza ==3){
                        if (tablero[0] == p4.pieza3[0]){
                            tablero[0] = p4.pieza3[1];
                            tablero[1] = p4.pieza3[0];
                        }
                        else if (tablero[0] == p4.pieza3[1]){
                            tablero[0] = p4.pieza3[0];
                            tablero[1] = p4.pieza3[1];
                        }
                    }
                    if (pieza ==4){
                        if (tablero[0] == p4.pieza4[0]){
                            tablero[0] = p4.pieza4[1];
                            tablero[1] = p4.pieza4[0];
                        }
                        else if (tablero[0] == p4.pieza4[1]){
                            tablero[0] = p4.pieza4[0];
                            tablero[1] = p4.pieza4[1];
                        }
                    }
                    if (pieza ==5){
                        if (tablero[0] == p4.pieza5[0]){
                            tablero[0] = p4.pieza5[1];
                            tablero[1] = p4.pieza5[0];
                        }
                        else if (tablero[0] == p4.pieza5[1]){
                            tablero[0] = p4.pieza5[0];
                            tablero[1] = p4.pieza5[1];
                        }
                    }
                    if (pieza ==6){
                        if (tablero[0] == p4.pieza6[0]){
                            tablero[0] = p4.pieza6[1];
                            tablero[1] = p4.pieza6[0];
                        }
                        else if (tablero[0] == p4.pieza6[1]){
                            tablero[0] = p4.pieza6[0];
                            tablero[1] = p4.pieza6[1];
                        }
                    }
                    if (pieza ==7){
                        if (tablero[0] == p4.pieza7[0]){
                            tablero[0] = p4.pieza7[1];
                            tablero[1] = p4.pieza7[0];
                        }
                        else if (tablero[0] == p4.pieza7[1]){
                            tablero[0] = p4.pieza7[0];
                            tablero[1] = p4.pieza7[1];
                        }
                    }
                }
                if (sentido == 1){
                    if (pieza == 1){
                        if (tablero[3] == p4.pieza1[0]){
                            tablero[2] = p4.pieza1[0];
                            tablero[3] = p4.pieza1[1];
                        }
                        else if (tablero[3] == p4.pieza1[1]){
                            tablero[2] = p4.pieza1[1];
                            tablero[3] = p4.pieza1[0];
                        }
                    }
                    if (pieza ==2){
                        if (tablero[3] == p4.pieza2[0]){
                            tablero[2] = p4.pieza2[0];
                            tablero[3] = p4.pieza2[1];
                        }
                        else if (tablero[3] == p4.pieza2[1]){
                            tablero[2] = p4.pieza2[1];
                            tablero[3] = p4.pieza2[0];
                        }
                    }
                    if (pieza ==3){
                        if (tablero[3] == p4.pieza3[0]){
                            tablero[2] = p4.pieza3[0];
                            tablero[3] = p4.pieza3[1];
                        }
                        else if (tablero[3] == p4.pieza3[1]){
                            tablero[2] = p4.pieza3[1];
                            tablero[3] = p4.pieza3[0];
                        }
                    }
                    if (pieza ==4){
                        if (tablero[3] == p4.pieza4[0]){
                            tablero[2] = p4.pieza4[0];
                            tablero[3] = p4.pieza4[1];
                        }
                        else if (tablero[3] == p4.pieza4[1]){
                            tablero[2] = p4.pieza4[1];
                            tablero[3] = p4.pieza4[0];
                        }
                    }
                    if (pieza ==5){
                        if (tablero[3] == p4.pieza5[0]){
                            tablero[2] = p4.pieza5[0];
                            tablero[3] = p4.pieza5[1];
                        }
                        else if (tablero[3] == p4.pieza5[1]){
                            tablero[2] = p4.pieza5[1];
                            tablero[3] = p4.pieza5[0];
                        }
                    }
                    if (pieza ==6){
                        if (tablero[3] == p4.pieza6[0]){
                            tablero[2] = p4.pieza6[0];
                            tablero[3] = p4.pieza6[1];
                        }
                        else if (tablero[3] == p4.pieza6[1]){
                            tablero[2] = p4.pieza6[1];
                            tablero[3] = p4.pieza6[0];
                        }
                    }
                    if (pieza ==7){
                        if (tablero[3] == p4.pieza7[0]){
                            tablero[2] = p4.pieza7[0];
                            tablero[3] = p4.pieza7[1];
                        }
                        else if (tablero[3] == p4.pieza7[1]){
                            tablero[2] = p4.pieza7[1];
                            tablero[3] = p4.pieza7[0];
                        }
                    }
                }
                
                write(pipe_p3[1], &tablero[0], sizeof(int));
                write(pipe_p3[1], &tablero[1], sizeof(int));
                write(pipe_p3[1], &tablero[2], sizeof(int));
                write(pipe_p3[1], &tablero[3], sizeof(int));
                
            }
        }
    }
    wait(NULL);
    return 0;
}

