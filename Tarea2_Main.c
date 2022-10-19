#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int tablero[29][2]; // posición del medio == 14 == inicio

    //apertura de los procesos hijos
    int J1 = fork();
    if (J1 != 0){
        int J2 = fork();
        if (J2 != 0){
            int J3 = fork();
            if (J3 != 0){
                int J4 = fork();
            }
        }
    }
    
    //creacion de pipes
    int pipe01[2];
    int pipe10[2];
    int pipe02[2];
    int pipe20[2];
    int pipe03[2];
    int pipe30[2];
    int pipe04[2];
    int pipe40[2];
    int pipe12[2];
    //int pipe21[2];
    int pipe23[2];
    //int pipe32[2];
    int pipe34[2];
    //int pipe43[2];
    int pipe41[2];
    //int pipe14[2];

    //inicia el juego



    return 0;
}