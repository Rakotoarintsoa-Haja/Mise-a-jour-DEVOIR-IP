#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Fonction pour convertir un masque de sous-réseau CIDR en format 32 bits
unsigned int cidr_to_netmask(int cidr) {
    return cidr == 0 ? 0 : (~0U << (32 - cidr));
}

// Fonction pour afficher une IP au format d.d.d.d
void print_ip(unsigned int ip) {
    printf("%d.%d.%d.%d", 
           (ip >> 24) & 0xFF, 
           (ip >> 16) & 0xFF, 
           (ip >> 8) & 0xFF, 
           ip & 0xFF);
}

// Fonction principale pour le calcul réseau
void calcul_reseau(char* input) {
    unsigned int ip;
    int cidr;

    // Extraction de l'adresse IP et du masque CIDR
    char *cidr_str = strchr(input, '/');
    if (cidr_str == NULL) {
        printf("Format invalide. Utilisez le format IP/CIDR.\n");
        return;
    }

    *cidr_str = '\0';  // Séparer l'IP et le CIDR
    cidr_str++;        // Avancer pour obtenir la partie CIDR

    // Convertir l'adresse IP et le CIDR en entier
    inet_pton(AF_INET, input, &ip);
    cidr = atoi(cidr_str);

    // Convertir l'adresse en format hôte
    ip = ntohl(ip);

    // Calcul du masque de sous-réseau, de l'adresse réseau et de broadcast
    unsigned int netmask = cidr_to_netmask(cidr);
    unsigned int network = ip & netmask;
    unsigned int broadcast = network | ~netmask;

    // Affichage des résultats en HTML
    printf("<div class='result'>\n");
    printf("<p><strong>Adresse réseau :</strong> ");
    print_ip(network);
    printf("</p>\n");
    printf("<p><strong>Adresse de broadcast :</strong> ");
    print_ip(broadcast);
    printf("</p>\n");
    printf("<p><strong>Masque de sous-réseau :</strong> ");
    print_ip(netmask);
    printf("</p>\n");
    printf("</div>\n");
}

// Fonction pour afficher le formulaire HTML
void afficher_formulaire()p {
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Calcul Réseau</title>\n");
    printf("<style>\n");
    printf("body { font-family: Arial, sans-serif; background-color: #f4f4f9; margin: 0; padding: 0; }\n");
    printf(".container { width: 50%%; margin: 0 auto; padding: 20px; background-color: #fff; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }\n");
    printf("h1 { text-align: center; color: #333; }\n");
    printf("form { text-align: center; }\n");
    printf("input[type='text'] { padding: 10px; width: 80%%; margin-bottom: 20px; border-radius: 5px; border: 1px solid #ccc; }\n");
    printf("input[type='submit'] { padding: 10px 20px; background-color: #28a745; color: white; border: none; border-radius: 5px; cursor: pointer; }\n");
    printf(".result { margin-top: 20px; font-size: 18px; color: #333; }\n");
    printf("p { margin: 10px 0; }\n");
    printf("</style>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<div class='container'>\n");
        printf("<form method='GET'>\n");
    printf("<input type='text' name='ip' placeholder='Entrez l'adresse IP/CIDR (ex: 123.12.12.1/23)' required />\n");
    printf("<input type='submit' value='Calculer' />\n");
    printf("</form>\n");
}

