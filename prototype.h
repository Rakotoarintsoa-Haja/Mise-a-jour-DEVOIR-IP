#ifndef FONCTION_H
#define FONCTION_H

// Les bibliothèques :
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Mes fonctions :
void comparation(int A, int B, int C, int D);
void compA(int A, int B, int C, int D);
void presentation();
void presentation1(int A, int B, int C, int D);
void displayHTML();
//void displayHTML1();
void connexion();
void inscription();
void enregistrement(char nom[256], char prenom[256], char email[256], char num[256], char id[256], char pwd1[256]);
int test_acces(const char *id, const char *pwd);
int calculer_somme_puissances(int bits);
void masqueReseau(int A, int B, int C, int D, int E);
//void afficherDetailsIP(int A, int B, int C, int D, int prefixLength);
//void trim_whitespace(char *str);
void trim_whitespace(char *str);

//int test_acces(char id[256], char pwd1[256]);
void reussie();
void decode_url(char *url);
void decode_url(char *url);

#endif
