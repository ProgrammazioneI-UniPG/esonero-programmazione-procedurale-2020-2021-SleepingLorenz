#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void caso1();
void caso2();

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
    opzione = strtol(str_opzione, NULL, 0); //strtol converte la stringa in int in modo che posso poi confrontarla con il while
    
    while(opzione != 1 && opzione != 2) {
        printf("ERRORE : Digita 1 o 2...\n");
        fgets(str_opzione, 20, stdin);
        opzione = strtol(str_opzione, NULL, 0);
    }

    switch(opzione) {
        case 1 :
            caso1();
        break;

        case 2 :
            caso2();
        break;

        default : 
            printf("Errore");
            exit(0);
        break;
    }

}

void caso1() { 

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n");
    printf("OPZIONE 1\n");
    printf("Inserisci una stringa di lunghezza uguale o superiore per cifrare il testo \n");
   
    fgets(chiave_K, 128, stdin);

    while (strlen(chiave_K) < strlen(stringa_M)) { //controllo se la chiave e' utilizzabile per cifrare
        printf("Errore :\n");
        printf("La stringa che hai inserito non e' di lunghezza uguale o superiore al testo da cifrare \n");
        fgets(chiave_K, 128, stdin);
    }

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n");
    printf("Stringa da cifrare : %s\n", stringa_M);
    printf("Chiave per cifrare : %s\n", chiave_K);

    for(int i = 0; i < strlen(chiave_K); i++) { // Cifro la stringa iniziale con lo XOR
        cifrato_C[i] = stringa_M[i]^chiave_K[i];
    }

    printf("Cifrato M-K : %s\n", cifrato_C);

    for(int i = 0; i < strlen(chiave_K); i++) { // Decifro il cifrato con la chiave usata per fare la prova
        decifrato[i] = chiave_K[i]^cifrato_C[i];
    }

    printf("Decifrato C-K : %s  \n", decifrato);
    printf("Stringa iniziale : %s \n", stringa_M);

}

void caso2() {

    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx \n");
    printf("OPZIONE 2\n");

    time_t t;

    srand((unsigned) time(&t)); //si chiama una volta sola nel programma

    for(int i = 0; i < strlen(stringa_M); i++) { //riempo la stringa con caratteri generati randomicamente
        chiave_K[i] = rand() % 128;
    }

    printf("E' stata generata una chiave randomica : %s\n", chiave_K);
    printf("Stringa da cifrare : %s", stringa_M);

    for(int i = 0; i < strlen(chiave_K); i++) { //Cifratura XOR
        cifrato_C[i] = stringa_M[i]^chiave_K[i];
    }

    printf("Cifrato : %s\n", cifrato_C);

    for(int i = 0; i < strlen(chiave_K); i++) { //Decifratura per la prova
        decifrato[i] = chiave_K[i]^cifrato_C[i];
    }

    printf("Decifrato C-K : %s\n", decifrato);
    printf("Stringa iniziale : %s\n", stringa_M);

}