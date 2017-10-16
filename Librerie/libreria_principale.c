#include "libreria_principale.h"
#include <string.h>
#define MAX_VETT 1000

void hello_world(void) {
    printf("Hello, World!\n");
}
//Funzioni su FILE
FILE *apri_file(int MAX_FILENAME_SIZE) {
    FILE *fp=NULL;
    char nomefile[MAX_FILENAME_SIZE];
    do{
        printf("Inserire il nome del file da aprire:...\n");
        scanf("%s",nomefile);
        fp=fopen(nomefile,"r");
        if (fp==NULL){
            printf("File non aperto correttamente... Riprovare");
        }
    }   while (fp==NULL);
    return fp;
}
int leggi_file(FILE *fp, int r, int c, char mat[MAX_MAT_R][MAX_MAT_C]) {
    char ch; //Carattere di debug
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (feof(fp))
                return 1;
            ch=fgetc(fp);
            mat[i][j]=ch;
            ch=fgetc(fp); //Legge spazio o /n
        }
        fgetc(fp); //Legge /r
    }
    return 0;
}
//Funzioni di ricerca
int ricerca_matrice_carattere(const char mat[MAX_MAT_R][MAX_MAT_C], int r, int c, char *s) {
    int t=0; int k=0; int grandezza=strlen(s);
    //Ricerca per Righe
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mat[i][j]==s[k]){
                k++;
                if (k==grandezza){
                    t++; k=0;
                }
            }
            else{
                k=0;
                if(mat[i][j]==s[0]) //Se il primo elemento è giusto...
                    k=1;
            }
        }
    }
    //Ricerca per Colonne
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (mat[j][i]==s[k]){
                k++;
                if (k==grandezza){
                    t++; k=0;
                }
            }
            else{
                k=0;
                if(mat[j][i]==s[0]) //Se il primo elemento è giusto...
                    k=1;
            }
        }
    }
    return t;
}
//Funzioni su Vettori
void crea_vettore_tastiera(int *v) {
    int d; //Dimensione del vettore da inserire
    do{
        printf("Inserire la dimensione del vettore:\n");
        scanf("%d",&d);
        if(d<0) printf("Dimensione Errata! Riprovare...\n");
    } while (d<0);
    printf("Inserire i dati del vettore:\n");
    for (int i = 0; i < d; ++i) {
        scanf("%d",&v[i]);
    }
    //Debug
    printf("Il vettore acquisito e'...:\n");
    for (int i = 0; i < d; ++i) {
        printf("%d ",v[i]);
    }
    printf("\n");
}
//Funzioni su Insiemi
void crea_insieme(int v[],int size) {
    int v1[MAX_VETT];
    int insieme[MAX_VETT]={0};
    int f=0,k=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(v[i]==insieme[j]) f=1;
        }
        if (v[i]!=0&&f!=1){
            insieme[k]=v[i];
            k++;
        }
        f=0;
    }
    for (int l = 0; l < size; ++l) {
        v[l]=insieme[l];
    }
}
int intersezione_insiemi(const int *v1, const int *v2, int *res, int size) { //Funzione usata nelle altre funzioni
    int k=0; //Usato per res
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (v1[i] == v2[j] && v1[i] != 0) {
                res[k] = v1[i];
                k++;
            }
        }
    }
    if(k==0){ return 1;}
    else {return 0;}
}
void stampa_unione_insiemi(int *v1, int *v2, int size) { //Dato che non richiesto, la stampa avviene non in ordine, ma un sort è facilmente implementabile con l'utilizzo di un vettore all'interno di questa funzione
    int inter[MAX_VETT]={0}; //Vettore Intersezione
    int f=0; //Flag
    printf("L'unione di A e B e'...:\n");
    if(intersezione_insiemi(v1,v2,inter,size)==1){ //Trova A int. B in inter. Se l'int. è vuota passa subito all'unione
        for (int i = 0; i < size; ++i) {
            if (v1[i]!=0) printf("%d",v1[i]);
        }
        for (int i = 0; i < size; ++i) {
            if (v2[i]!=0)   printf("%d",v2[i]);
        }
    }
    else {  //Se l'int. non è vuota ...
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(v1[i]==inter[j]) f=1;
            }
            if (f!=1)   printf("%d ",v1[i]);
            f=0; //Reset Flag
            for (int j = 0; j < size; ++j) {
                if(v2[i]==inter[j]) f=1;
            }
            if (f!=1)   printf("%d ",v2[i]);
            f=0; //Reset Flag
        }
        for (int k = 0; k < size && inter[k]!=0; ++k) { //Stampa gli elementi dell'intersezione
            printf("%d ",inter[k]);
        }
    }
    printf("\n");
    return;
}
//Funzioni di selezione
int selezione_stringa_2(char *string1, char *string2) {
    return 0;
}

int selezione_stringa_3(char *string1, char *string2, char *string3) {
    return 0;
}

int selezione_stringa_4(char *string1, char *string2, char *string3, char *string4) {
    return 0;
}

int selezione_stringa_5(char *string1, char *string2, char *string3, char *string4, char *string5) {
    return 0;
}

int selezione_stringa_6(char *string1, char *string2, char *string3, char *string4, char *string5, char *string6) {
    return 0;
}

int selezione_stringa_7(char *string1, char *string2, char *string3, char *string4, char *string5, char *string6,
                        char *string7) {
    return 0;
}