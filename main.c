#include "Librerie/libreria_principale.h"
#ifdef MAX_VETT
#undef MAX_VETT
#define MAX_VETT 100000
//NON FUNZIONA NELLA LIBRERIA
#endif
int main() {
    hello_world();
    return 0;
}
/*Domande sono:
1) Ho fatto bene ?
2) I Macro come funzionano
3) Funzioni che accettano parametri deiversi
4) Come fare LOG
5) Come modificare le costanti anche nella libreria? */

