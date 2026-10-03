#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    for(int i = 0; i < 3; i++){
        int f = fork();

        if(f == -1){
            perror("errore fork");
            exit(-1);
        }
        if(!f){
            printf("figlio. Il mio PID è %d\n", getpid());
            sleep(2);
            return 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("tutti i processi figli sono terminati\n");


    return 0;
}