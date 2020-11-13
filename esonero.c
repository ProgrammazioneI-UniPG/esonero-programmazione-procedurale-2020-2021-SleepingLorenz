#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void caso2();
void caso1();

char stringa_M[128];
char chiave_K[128];
char cifrato_C[128];
char decifrato[128];

int main() {

    char str_opzione[20];
    int opzione;

    printf("Inserisci testo da cifrare : \n");

    fgets(stringa_M, 128, stdin);

    printf("1. Inserisci una stringa  di lunghezza uguale o superiore per cifrare il testo \n");
    printf("2. Usa una stringa generata randomicamente \n");
    printf("Digita 1 o 2...\n");
        
    fgets(str_opzione, 20, stdin);
    opzione = strtol(str_opzione, NULL, 0);

    switch(opzione) {
        case 1 :
            caso1();
        break;

        case 2 :
            caso2();
        break;

        default : 
            while(opzione != 1 && opzione !=2) {
                printf("ERRORE : Digita 1 o 2...\n");
                fgets(str_opzione, 20, stdin);
                opzione = strtol(str_opzione, NULL, 0);
            }
            if (opzione == 1)
                caso1();
            else
                caso2();
        break;
    }

}

void caso1() { 

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n");

    printf("OPZIONE 1\n");
    printf("Inserisci una stringa di lunghezza uguale o superiore per cifrare il testo \n");
   
    fgets(chiave_K, 128, stdin);

    while (strlen(chiave_K) < strlen(stringa_M)) {  
    
        printf("Errore :\n");
        printf("La stringa che hai inserito non e' di lunghezza uguale o superiore al testo da cifrare \n");
        fgets(chiave_K, 128, stdin);

    }

    printf("\n");

    printf("Stringa da cifrare : %s", stringa_M);
    printf("Chiave per cifrare : %s", chiave_K);


    for(int i = 0; i < strlen(chiave_K); i++) {
        cifrato_C[i] = stringa_M[i]^chiave_K[i];
    }

    printf("Cifrato : \n");
    printf("%s", cifrato_C);

    printf("\n");

    printf("Decifro C-K \n");

    for(int i = 0; i < strlen(chiave_K); i++) {
        decifrato[i] = chiave_K[i]^cifrato_C[i];
    }

    printf("Decifrato : %s  \n", decifrato);
    printf("Stringa iniziale : %s \n", stringa_M);


}

void caso2() {

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n");

    printf("OPZIONE 2\n");

    time_t t;

    srand((unsigned) time(&t)); //si chiama una volta sola nel programma

    for(int i = 0; i < strlen(stringa_M); i++) {
        chiave_K[i] = rand() % 128;
    }

    printf("E' stata generata una chiave randomica :");
    printf("%s", chiave_K); 

    printf("\n");

    printf("Stringa da cifrare : %s", stringa_M);

    for(int i = 0; i < strlen(chiave_K); i++) {
        cifrato_C[i] = stringa_M[i]^chiave_K[i];
    }

    printf("Cifrato : \n");
    printf("%s \n", cifrato_C);

    printf("\n");

    printf("Decifro C-K \n");

    for(int i = 0; i < strlen(chiave_K); i++) {
        decifrato[i] = chiave_K[i]^cifrato_C[i];
    }

    printf("Decifrato : %s  \n", decifrato);
    printf("Stringa iniziale : %s \n", stringa_M);

}
