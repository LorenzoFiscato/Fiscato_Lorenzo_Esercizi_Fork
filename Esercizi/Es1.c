#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    int f = fork();

    if(f == -1){
        perror("errore fork");
        exit(-1);
    }

    if(!f){
        printf("figlio\n");
        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
            sleep(1);
        }
        return 0;
    }

    wait(NULL);

    printf("padre\n");
    for (int i = 5; i <= 10; i++) {
        printf("%d\n", i);
    }

    return 0;
}
