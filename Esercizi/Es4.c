#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrimo(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return 0;

    return 1;
}

int main(void) {
    int status;
    int f = fork();

    if(f == -1){
        perror("errore fork");
        exit(-1);
    }

    if(!f){
        int n;
        printf("Inserisci numero\n");
        scanf("%d", &n);
        if(isPrimo(n)) return 1;
        if(n % 2 == 0) return 2;
        return 3;
    }

    wait(&status);

    if (WIFEXITED(status)) {
        int codice_uscita = WEXITSTATUS(status);
        if(codice_uscita == 1){
            printf("codice uscita: %d.Il numero è primo\n", codice_uscita);
            return 0;
        }
        if(codice_uscita == 2){
            printf("codice uscita: %d.Il numero è pari e non primo\n", codice_uscita);
            return 0;
        }

        printf("codice uscita: %d.Il numero è dispari e non primo\n", codice_uscita);
        return 0;
    }


    return 0;
}