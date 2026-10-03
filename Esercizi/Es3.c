#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

	int f1 = fork();

	if(f1 == -1){
        perror("errore fork");
        exit(-1);
    }

    if(!f1){
    	int f2 = fork();

    	if(f2 == -1){
        	perror("errore fork");
    		exit(-1);
    	}

    	if(!f2){
    		printf("nipote\n");
    		return 0;
    	}

    	wait(NULL);
    	printf("figlio\n");
    	return 0;
    }

    printf("nonno\n");
    wait(NULL);

	return 0;
}