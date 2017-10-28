#include "Librerie/libreria_principale.h"
#define MAX_RIGHE 100
#define MAX_RIGA 200
#define forever for(;;)
typedef struct {
    int ore;
    int minuti;
    int secondi;
}Ora;
typedef struct{
    int giorno;
    int mese;
    int anno;
}Data;
typedef struct{
    char codice[MAX_STR];
    char partenza[MAX_STR];
    char destinazione[MAX_STR];
    char vettore[MAX_STR];
    Data data;
    Ora ore;
}Volo;
typedef enum{
    DATA,LOC,DEST,VETT,EXIT,ERR=-1
}Menu;
void stampa_menu();
Menu seleziona_opzione();
int main() {
    FILE *fp;
    char riga [MAX_RIGA];
    Menu sel;
    int n_righe; int continua=-1;
    Volo Voli[MAX_RIGHE];
    printf("Laboratorio 3_2:\n");
    fp=FILE_apri_file(FILENAME_MAX,"r");
    fscanf(fp,"%d",&n_righe);
    for (int i = 0; i < n_righe; ++i) {
        fgets(riga,MAX_RIGA,fp);
        sscanf(riga," %s %s %s %d/%d/%d:%d:%d:%d %s", Voli[i].codice,Voli[i].partenza,Voli[i].destinazione,&Voli[i].data.anno,
               &Voli[i].data.mese,&Voli[i].data.giorno,&Voli[i].ore.ore,&Voli[i].ore.minuti,&Voli[i].ore.secondi, Voli[i].vettore);
    }
    forever{
        stampa_menu();
         sel=seleziona_opzione();
        switch (sel){
            case DATA:

                break;
            case LOC:
                break;
            case DEST:
                break;
            case VETT:
                break;
            case EXIT:
                return 0;
            default: //ERR
                printf("Scelta ERRATA riprovare...\n");
        }
    }
}
void stampa_menu(){
    printf("Selezionare un'opzione:\n");
    printf("[DATA] elencare tutti i voli partiti in un certo intervallo di date\n");
    printf("[LOC]  elencare tutti i voli partiti da una certa località\n");
    printf("[DEST] elencare tutti i voli diretti verso una certa destinazione\n");
    printf("[VETT] elencare tutte le località da cui sia decollato almeno un volo facente uso di un certo vettore.\n");
    printf("[EXIT] Esci dal programma...\n");
}
Menu seleziona_opzione(){
    char string[5][MAX_STR]={"data","loc","dest","vett","exit"};
    char scelta[MAX_STR]; int f=0;
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string[0],scelta)) return DATA;
    else if(!strcmp(string[1],scelta)) return DEST;
    else if(!strcmp(string[2],scelta)) return LOC;
    else if(!strcmp(string[3],scelta)) return VETT;
    else if(!strcmp(string[4],scelta)) return EXIT;
    return ERR;
}

