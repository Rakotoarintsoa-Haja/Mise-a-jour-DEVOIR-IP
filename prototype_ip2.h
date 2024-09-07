include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
unsigned int cidr_to_netmask(int cidr);
void calcul_reseau(char* input);
void print_ip(unsigned int ip);
void afficher_formulaire();