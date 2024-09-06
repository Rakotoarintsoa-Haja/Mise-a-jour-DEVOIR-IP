#include "prototype.h"
void presentation();
void presentation1(int A, int B, int C, int D);
void comparation(int A, int B, int C, int D);
void compA(int A, int B, int C, int D);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction pour décoder les caractères URL encodés
void decode_url(char *url) {
    char *p = url;
    while (*p) {
        if (*p == '%') {
            int value;
            sscanf(p + 1, "%2x", &value);
            *p = (char)value;
            memmove(p + 1, p + 3, strlen(p + 3) + 1);
        } else if (*p == '+') {
            *p = ' ';
            ++p;
        } else {
            ++p;
        }
    }
}

// Fonction pour décoder les caractères encodés en URL

void enregistrement(char nom[256], char prenom[256], char email[256], char num[256], char id[256], char pwd1[256]) {
    FILE *fichier = fopen("ip_enregistrement.txt", "r+");
    if (fichier == NULL) {
        perror("Erreur d'ouverture de fichier");
        printf("<p class=\"error\">Erreur: Impossible d'ouvrir le fichier pour l'enregistrement.</p>\n");
        return;
    }
    fseek(fichier, 0, SEEK_SET);
    fprintf(fichier, "%s %s %s %s %s %s\n", nom, prenom, email, num, id, pwd1);
    fclose(fichier);
}

void inscription() {
    // En-têtes HTTP
    printf("Content-Type: text/html\n\n");

    // Générer le contenu HTML
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>Inscription</title>\n");
    printf("        <meta charset=\"UTF-8\">\n");
    printf("        <link rel=\"stylesheet\" href=\"inscription.css\">\n");
    printf("    </head>\n");
    printf("    <body>\n");
    printf("        <div class=\"STYLE\">\n");
    printf("            <h2>Inscrivez-vous ici</h2>\n");
    printf("            <form method=\"get\">\n");
    printf("                <input type=\"text\" name=\"Nom\" placeholder=\"Nom\"> <br>\n");
    printf("                <input type=\"text\" name=\"Prenom\" placeholder=\"Prenom\" required> <br>\n");
    printf("                <input type=\"email\" name=\"Email\" placeholder=\"raks@gmail.com\" required><br>\n");
    printf("                <input type=\"text\" name=\"Num\" placeholder=\"Numero Telephonique: +261 329826524\" required><br>\n");
    printf("                <input type=\"text\" name=\"ID\" placeholder=\"Nom du compte\" required><br>\n");
    printf("                <input type=\"password\" name=\"PWD\" placeholder=\"Mode de passe\" required><br>\n");
  //  printf("                <input type=\"password\" name=\"PWD\" placeholder=\"Veuillez confirmer votre mode de passe ici\" required><br>\n");
    printf("<input class=\"Rare\" style=\"background-color: #1877F2; color: azure;\" type=\"Submit\" value=\"Envoyer\">\n");
   // printf("                <a class=\"STYLE\" href=\"connexion.cgi\">Veuillez cliquez ici.</a>\n");
    printf("                <a class=\"STYLE\" href=\"connexion.cgi\" style=\"background-color: #1ade4e; color: azure; text-decoration: none; padding: 5px 100px; border-radius: 15px;\">Veuillez cliquez ici.</a>\n");
    printf("            </form>\n");
    printf("        </div>\n");
    printf("    </body>\n");
    printf("</html>\n");

    char *lien = getenv("QUERY_STRING");
    if (lien != NULL) {
        // Décoder la chaîne URL
        decode_url(lien);

        // Lecture des valeurs du formulaire
        char nom[256], prenom[256], email[256], num[256], id[256], pwd1[256];
        if (sscanf(lien, "Nom=%255[^&]&Prenom=%255[^&]&Email=%255[^&]&Num=%255[^&]&ID=%255[^&]&PWD=%255s", nom, prenom, email, num, id, pwd1) == 6) {
            enregistrement(nom, prenom, email, num, id, pwd1);
        } else {
            //printf("<p class=\"error\">Erreur: Données du formulaire non valides.</p>\n");
        }
    } else {
        printf("<p class=\"error\">Erreur: Pas de données reçues.</p>\n");
    }
}

void reussie(){
     // Indique que la sortie est en HTML
    printf("Content-Type: text/html\n\n");
    
    // Affiche le contenu HTML
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>Connection</title>\n");
    printf("        <meta charset=\"UTF-8\">\n");
    printf("         <link rel=\"stylesheet\" href=\"inscription.css\">\n");
    printf("    </head>\n");
    printf("    \n");
    printf("    <body>\n");
    printf("        <div class=\"STYLE\">\n");
    printf("        <!--<h2>Se connecter</h2>-->\n");    
    printf("            <form method=\"get\">\n");
    printf("                <h2>Bravo, Connection reussie.</h2>\n");
    printf("<h2>Ici cliquez ci-dessous vous pouvez acceder a l'autre page.<h2>\n");
  //  printf("<h2>Votre compte a ete creer avec succes.</h2>\n");
    printf("                <a class=\"STYLE\" href=\"ip.cgi\" style=\"background-color: #1ade4e; color: azure; text-decoration: none; padding: 5px 250px; border-radius: 15px;\">IP-page</a>\n");
    printf("             <!--<input class=\"Rare\" style=\"background-color: #1ade4e; color: azure;\" type=\"Submit\" value=\"Creer un compte\" href=\"mkdir.cgi\"> -->\n");
    printf("<h2>Merci d'avoir utiliser mon page.</h2>\n");
    printf("            </form>\n");
    printf("        </div>\n");
    printf("    </body>\n");
    printf("</html>\n");

}

void displayHTML() {
    int A = 0, B = 0, C = 0, D = 0, E=0;
    
    printf("Content-Type: text/html\n\n");
    printf("<html>\n"); 
    // En-tete:
    printf("<head>\n"); 
    printf("<title>Ma page web</title>\n");
    printf("<style>\n");
    printf("body {\n");
    printf("    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n");
    printf("    background-color: #e0f7fa;\n");
    printf("    margin: 0;\n");
    printf("    padding: 0;\n");
    printf("    display: flex;\n");
    printf("    justify-content: center;\n");
    printf("    align-items: center;\n");
    printf("    height: 100vh;\n");
    printf("}\n");
    printf(".container {\n");
    printf("    background: #ffffff;\n");
    printf("    padding: 30px;\n");
    printf("    border-radius: 12px;\n");
    printf("    box-shadow: 0 4px 8px rgba(0,0,0,0.2);\n");
    printf("    width: 100%;\n");
    printf("    max-width: 500px;\n");
    printf("    text-align: center;\n");
    printf("    margin-left-style: 100%");
    printf("    margin-right-style: 100%");
    printf("}\n");
    printf("h2 {\n");
    printf("    color: #00796b;\n");
    printf("    font-size: 22px;\n");
    printf("    margin-bottom: 20px;\n");
    printf("}\n");
    printf("label {\n");
    printf("    display: block;\n");
    printf("    margin-bottom: 8px;\n");
    printf("    font-weight: bold;\n");
    printf("}\n");
    printf("input[type=text] {\n");
    printf("    padding: 12px;\n");
    printf("    margin-bottom: 15px;\n");
    printf("    border: 2px solid #00796b;\n");
    printf("    border-radius: 8px;\n");
    printf("    font-size: 16px;\n");
    printf("    width: calc(100% - 26px);\n");
    printf("    box-sizing: border-box;\n");
    printf("}\n");
    printf("input[type=submit] {\n");
    printf("    padding: 12px;\n");
    printf("    background-color: #00796b;\n");
    printf("    border: none;\n");
    printf("    border-radius: 8px;\n");
    printf("    color: #ffffff;\n");
    printf("    cursor: pointer;\n");
    printf("    font-size: 18px;\n");
    printf("    transition: background-color 0.3s;\n");
    printf("}\n");
    printf("input[type=submit]:hover {\n");
    printf("    background-color: #004d40;\n");
    printf("}\n");
    printf("p.error {\n");
    printf("    color: #d32f2f;\n");
    printf("    font-weight: bold;\n");
    printf("}\n");
    printf("</style>\n");
    printf("</head>\n");
    // Corps:
    printf("<body>\n");
    printf("<div class=\"container\">\n");
    printf("<h2>Entrez votre adresse IP</h2>\n");
    printf("<h3>Mode d'emploi: IP-nombre de coupage.</h3>");
         printf("<h4>Par ex: 123.0.0.0-23; On coupe cet IP en 23 sous-reseaux</h4>");
    printf("<form method=\"GET\">\n");
    printf("    <label for=\"ip\">Adresse IP:</label>\n");
    printf("    <input type=\"text\" id=\"ip\" name=\"A\" placeholder=\"Ex: 0.0.0.0-4\" />\n");
  ///  printf("<br>");
   // printf("    <input type=\"text\" id=\"ip\" name=\"B\" placeholder=\"Vous voulez couper en combien de reseaux? Entre ici\" />\n");
    printf("    <input type=\"submit\" value=\"Envoyer\" />\n");
    printf("</form>\n");
    
    char *lien = getenv("QUERY_STRING");
    if (lien == NULL) {
        printf("<p class=\"error\">Erreur: Pas de données reçues.</p>\n");
    } else {
        // Extraction des paramètres de la chaîne QUERY_STRING
        if (sscanf(lien, "A=%d.%d.%d.%d-%d", &A, &B, &C, &D, &E) == 5) {
            //sscanf(lien, "Nom=%255[^&]&Prenom=%255[^&]&Email=%255[^&]&Num=%255[^&]&ID=%255[^&]&PWD=%255s"
            presentation();
            presentation1(A, B, C, D);
            comparation(A, B, C, D);
            int resu=0;
            resu=calculer_bits_pour_sous_reseaux(E);
            masqueReseau(A, B, C, D, resu);
            printf(" <a class=\"STYLE\" href=\"ip1.cgi\" style=\"background-color: #1ade4e; color: azure; text-decoration: none; padding: 5px 100px; border-radius: 15px;\">Autre Methode..</a>\n");
            
        } else {
            printf("<p class=\"error\">Format de l'adresse IP invalide.</p>\n");
        }
    }
    printf("</div>\n");
    printf("</body>\n");
    printf("</html>\n");
}
void presentation() {
    printf("<h2>Ceci est un program creer par Haja</h2>\n");
   // printf("<h2>Entrez votre adresse IP ci-dessous (format A-B-C-D):</h2>\n");
    printf("<h2>Votre donne doit-etre au format 8 bits</h2>\n");
}

void presentation1(int A, int B, int C, int D){
    // Afficher les valeurs
    printf("<h2>Votre IP: %d-%d-%d-%d</h2>\n", A, B, C, D);
}

void comparation(int A, int B, int C, int D){
    if (A < 1000) {
        compA(A, B, C, D);
    } else {
        printf("<h2>Votre adresse IP est invalide !!</h2>\n");
    }
}

void compA(int A, int B, int C, int D){
    if (A >= 0 && A <= 127) {
        // Classe A
        if (B <= 255 && C <= 255 && D <= 255) {
            printf("<h3>Votre IP: %d-%d-%d-%d est appartient au classe A</h3>\n", A, B, C, D);
           // printf("<h3>Son masque sous-reseaux par defaut est 255.0.0.0<h3>\n");
        } else {
            printf("<h2>Votre adresse IP est invalide!</h2>\n");
        }
    } else if (A >= 128 && A <= 191) {
        // Classe B
        if (B <= 255 && C <= 255 && D <= 255) {
            printf("<h3>Votre IP: %d-%d-%d-%d est appartient au classe B</h3>\n", A, B, C, D);
            //printf("<h3>Son masque sous-reseaux par defaut est 255.255.0.0<h3>\n");
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
        }
    } else if (A >= 192 && A <= 223) {
        // Classe C
        if (B <= 255 && C <= 255 && D <= 255) {
            printf("<h3>Votre IP: %d-%d-%d-%d est appartient au classe C</h3>\n", A, B, C, D);
          //  printf("<h3>Son masque sous-reseaux par defaut est 255.255.255.0<h3>\n");
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
        }
    } else if (A >= 224 && A <= 239) {
        // Classe D
        if (B <= 255 && C <= 255 && D <= 255) {
            printf("<h3>Votre IP: %d-%d-%d-%d est appartient au classe D</h3>\n", A, B, C, D);
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
        }
    } else if (A >= 240 && A <= 255) {
        // Classe E
        if (B <= 255 && C <= 255 && D <= 255) {
            printf("<h3>Votre IP: %d-%d-%d-%d est appartient au classe E</h3>\n", A, B, C, D);
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
    }
    } else {
        printf("<h3>Votre adresse IP est invalide!</h3>\n");
    }
}

int calculer_bits_pour_sous_reseaux(int sous_reseaux) {
    int n = 0;
    int puissance_de_2 = 1;

    // Trouver le plus petit n tel que 2^n >= sous_reseaux
    while (puissance_de_2 < sous_reseaux) {
        puissance_de_2 *= 2;
        n++;
    }
    return n;
}
int calculer_somme_puissances(int bits) {
    int somme = 0;
    
   // printf("Calcul des puissances de 2 pour %d bits nécessaires :\n", bits);

    for (int i = 0; i < bits; i++) {
        int puissance = (int)pow(2, 7 - i); // Calculer 2^(7-i)
        somme += puissance;
        //printf("2^%d = %d\n", 7 - i, puissance);
    }
    return somme;
   // printf("Somme des puissances de 2 : %d\n", somme);
}
void masqueReseau(int A, int B, int C, int D, int E){
     if (A >= 0 && A <= 127) {
        // Classe A
        if (B <= 255 && C <= 255 && D <= 255) {
            B=0, C=0, D=0;
             printf("<h3>-Adresse de reseau: %d-%d-%d-%d</h3>\n", A, B, C, D);
              B=255, C=255, D=255;
            printf("<h3>-Son broadcast: %d-%d-%d-%d</h3>\n", A, B, C, D);
              B=calculer_somme_puissances(E);
              C=0, D=0;
            printf("<h3>-Votre masque sous-reseaux personnaliser: %d-%d-%d-%d</h3>\n", A, B, C, D);
                
        } else {
            printf("<h2>Votre adresse IP est invalide!</h2>\n");
        }
    } else if (A >= 128 && A <= 191) {
        // Classe B
        if (B <= 255 && C <= 255 && D <= 255) {
           C=0, D=0;
             printf("<h3>-Adresse de reseau: %d-%d-%d-%d</h3>\n", A, B, C, D);
              C=255, D=255;
            printf("<h3>-Son broadcast: %d-%d-%d-%d</h3>\n", A, B, C, D);
              C=calculer_somme_puissances(E);
             D=0;
            printf("<h3>-Votre masque sous-reseaux personnaliser: %d-%d-%d-%d</h3>\n", A, B, C, D);
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
        }
    } else if (A >= 192 && A <= 223) {
        // Classe C
        if (B <= 255 && C <= 255 && D <= 255) {
            D=0;
             printf("<h3>-Adresse de reseau: %d-%d-%d-%d</h3>\n", A, B, C, D);
              D=255;
            printf("<h3>-Son broadcast: %d-%d-%d-%d</h3>\n", A, B, C, D);
              D=calculer_somme_puissances(E);
            printf("<h3>-Votre masque sous-reseaux personnaliser: %d-%d-%d-%d</h3>\n", A, B, C, D);
        } else {
            printf("<h3>Votre adresse IP est invalide!</h3>\n");
        }
}
}

