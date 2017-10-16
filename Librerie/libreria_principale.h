#ifndef MYLIB_LIBRARY_H
#define MYLIB_LIBRARY_H
#define MAX_MAT_R 20
#define MAX_MAT_C 70
#include <stdio.h>

void hello_world();
//Funzioni su FILE
FILE *apri_file(int MAX_FILENAME_SIZE);
int leggi_file(FILE *fp, int r, int c, char mat[MAX_MAT_R][MAX_MAT_C]);
//Funzioni di ricerca
int ricerca_stringa_matrice(const char mat[MAX_MAT_R][MAX_MAT_C], int r, int c, char *s);
//Funzioni su Vettori
void crea_vettore_tastiera(int *v);
//Funzioni su Insiemi
void crea_insieme(int v[],int size);
int intersezione_insiemi(const int *v1, const int *v2, int *res, int size);
void stampa_unione_insiemi(int *v1, int *v2, int size);
//Funzioni di Selezione
int selezione_stringa_2(char string1[], char string2[]);
int selezione_stringa_3(char string1[], char string2[], char string3[]);
int selezione_stringa_4(char string1[], char string2[], char string3[], char string4[]);
int selezione_stringa_5(char string1[], char string2[], char string3[], char string4[], char string5[]);
int selezione_stringa_6(char string1[], char string2[], char string3[], char string4[], char string5[], char string6[]);
int selezione_stringa_7(char string1[], char string2[], char string3[], char string4[], char string5[], char string6[], char string7[]);


#endif