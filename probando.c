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
    int pipe_p1[2];
    int pipe_1p[2];
    int pipe_p2[2];
    int pipe_2p[2];
    int pipe_p3[2];
    int pipe_3p[2];
    int pipe_p4[2];
    int pipe_4p[2];
    int* ptr = (int*)malloc(4 * sizeof(int));
    ptr[0] = 0;
    ptr[1] = 0;
    ptr[2] = 0;
    ptr[3] = 0;

    //Inicializar PIPES
    pipe(pipe_p1);
    pipe(pipe_1p);
    pipe(pipe_p2);
    pipe(pipe_2p);
    pipe(pipe_p3);
    pipe(pipe_3p);
    pipe(pipe_p4);
    pipe(pipe_4p);

    int pos[28];
    int var = 0;
    int check = 0;
    srand(time(NULL));

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
        proceso=0;
        
    } else {
        pid1 = fork();
        if (pid1 == 0) {
            proceso = 1;
            //idem x=2;

        } else {
            pid2 = fork();
            if (pid2 == 0) {
                proceso = 2;
            } else {
                pid3 = fork();
                if (pid3 == 0) {
                    proceso = 3;
                } // else {
                //     pid4 = fork();
                //     if (pid4 == 0) {
                //         proceso = 4;
                //     }
                //     // proceso=4;
                // }
            
  
                // If value returned from fork()
                // in not zero and >0 that means
                // this is parent process.
            }
        }
    }
    //intento que interactuen entre sí los procesos, mas tarde lo extiendo a los otros$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    for (int i = 1; i < 2; i++){
        //if del proceso padre con whiles para cada hijo vrible que aumenta si todos juegan +1 
        if (proceso == 0){
            close(pipe_p1[0]); // cierro el modo de Lectura del padre al hijo
            close(pipe_1p[1]); // cierro el modo de Escritura del hijo al padre

            int pos1[7];
            memcpy(pos1,pos,sizeof(int)*7);

            crear_piezas(&p1, pos1);

            printf("Creado el mazo del Jugador 1\n");
            printf("%d, %d\n", p1.pieza1[0], p1.pieza1[1]);
            printf("%d, %d\n", p1.pieza2[0], p1.pieza2[1]);
            printf("%d, %d\n", p1.pieza3[0], p1.pieza3[1]);
            printf("%d, %d\n", p1.pieza4[0], p1.pieza4[1]);
            printf("%d, %d\n", p1.pieza5[0], p1.pieza5[1]);
            printf("%d, %d\n", p1.pieza6[0], p1.pieza6[1]);
            printf("%d, %d\n", p1.pieza7[0], p1.pieza7[1]);

            int mensaje = i * 100;
            write(pipe_p1[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            read(pipe_1p[0], &mensaje, sizeof(int));

            // printf("la respuesta de mi hijo es: %d \n", mensaje);
            // juegue
        } else if (proceso == 1){
            //juego
            close(pipe_p1[1]); // cierro el modo de Escritura del padre al hijo
            close(pipe_1p[0]); // cierro el modo de Lectura del hijo al padre

            close(pipe_p2[0]); // cierro el modo de Lectura del padre al hijo
            close(pipe_2p[1]); // cierro el modo de Escritura del hijo al padre

            int mensaje;
            read(pipe_p1[0], &mensaje, sizeof(int));

            int pos2[7];
            memcpy(pos2,pos + 8,sizeof(int)*7);

            crear_piezas(&p2, pos2);

            printf("Creado el mazo del Jugador 2\n");
            printf("%d, %d\n", p2.pieza1[0], p2.pieza1[1]);
            printf("%d, %d\n", p2.pieza2[0], p2.pieza2[1]);
            printf("%d, %d\n", p2.pieza3[0], p2.pieza3[1]);
            printf("%d, %d\n", p2.pieza4[0], p2.pieza4[1]);
            printf("%d, %d\n", p2.pieza5[0], p2.pieza5[1]);
            printf("%d, %d\n", p2.pieza6[0], p2.pieza6[1]);
            printf("%d, %d\n", p2.pieza7[0], p2.pieza7[1]);

            mensaje = mensaje * 2;
            write(pipe_p2[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            read(pipe_2p[0], &mensaje, sizeof(int));
            write(pipe_1p[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            //juegue
        } else if (proceso == 2){
            //juego
            close(pipe_p2[1]); // cierro el modo de Escritura del padre al hijo
            close(pipe_2p[0]); // cierro el modo de Lectura del hijo al padre

            close(pipe_p3[0]); // cierro el modo de Lectura del padre al hijo
            close(pipe_3p[1]); // cierro el modo de Escritura del hijo al padre

            int mensaje;
            read(pipe_p2[0], &mensaje, sizeof(int));

            int pos3[7];
            memcpy(pos3,pos + 15,sizeof(int)*7);

            crear_piezas(&p3, pos3);

            printf("Creado el mazo del Jugador 3\n");
            printf("%d, %d\n", p3.pieza1[0], p3.pieza1[1]);
            printf("%d, %d\n", p3.pieza2[0], p3.pieza2[1]);
            printf("%d, %d\n", p3.pieza3[0], p3.pieza3[1]);
            printf("%d, %d\n", p3.pieza4[0], p3.pieza4[1]);
            printf("%d, %d\n", p3.pieza5[0], p3.pieza5[1]);
            printf("%d, %d\n", p3.pieza6[0], p3.pieza6[1]);
            printf("%d, %d\n", p3.pieza7[0], p3.pieza7[1]);

            mensaje = mensaje * 2;
            write(pipe_p3[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            read(pipe_3p[0], &mensaje, sizeof(int));
            write(pipe_2p[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            //juegue
        } else if (proceso == 3){
            //juego
            close(pipe_p3[1]); // cierro el modo de Escritura del padre al hijo
            close(pipe_3p[0]); // cierro el modo de Lectura del hijo al padre

            close(pipe_p4[0]); // cierro el modo de Lectura del padre al hijo
            close(pipe_4p[1]); // cierro el modo de Escritura del hijo al padre

            int mensaje;
            read(pipe_p3[0], &mensaje, sizeof(int));

            int pos4[7];
            memcpy(pos4,pos + 22,sizeof(int)*7);

            crear_piezas(&p4, pos4);

            printf("Creado el mazo del Jugador 4\n");
            printf("%d, %d\n", p4.pieza1[0], p4.pieza1[1]);
            printf("%d, %d\n", p4.pieza2[0], p4.pieza2[1]);
            printf("%d, %d\n", p4.pieza3[0], p4.pieza3[1]);
            printf("%d, %d\n", p4.pieza4[0], p4.pieza4[1]);
            printf("%d, %d\n", p4.pieza5[0], p4.pieza5[1]);
            printf("%d, %d\n", p4.pieza6[0], p4.pieza6[1]);
            printf("%d, %d\n", p4.pieza7[0], p4.pieza7[1]);

            mensaje = mensaje * 2;
            write(pipe_p3[1], &mensaje, sizeof(int)); // Mensaje puesto en la PIPE del padre al hijo
            //juegue
        }
        //la idea es hacer pipes que comuniquen con el padre y con los hijos entre sí el read hace que esperen 
    }
    free(ptr);
    return 0;
}
