#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction pour supprimer les espaces superflus
void trim_whitespace(char *str) {
    char *end;

    // Supprimer les espaces en début
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return; // Toute la chaîne était des espaces

    // Supprimer les espaces en fin
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
}

// Fonction de test d'accès
int test_acces(const char *id, const char *pwd) {
    FILE *fichier = NULL;
    int resultat1 = -1;
    char ligne[1024];

    // Ouvrir le fichier en mode lecture
    fichier = fopen("ip_enregistrement.txt", "r");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return resultat1; // Retourner -1 en cas d'échec
    }

    // Lire le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier)) {
        char fichier_id[256], fichier_pwd[256];
        // Extraire les ID et mots de passe de la ligne lue
        if (sscanf(ligne, "%*s %*s %*s %*s %*s %*s %255s %255s", fichier_id, fichier_pwd) == 2) {
            // Afficher les valeurs pour débogage
          /* printf("ID du fichier: '%s'\n", fichier_id);
            printf("Mot de passe du fichier: '%s'\n", fichier_pwd);
            printf("ID entré: '%s'\n", id);
            printf("Mot de passe entré: '%s'\n", pwd);*/

            // Comparer l'ID et le mot de passe
            trim_whitespace(fichier_id);
            trim_whitespace(fichier_pwd);
            trim_whitespace(id);
            trim_whitespace(pwd);

            if (strcmp(fichier_id, id) == 0 && strcmp(fichier_pwd, pwd) == 0) {
                resultat1 = 1; // Identifiant et mot de passe trouvés
                break;
            }
        }
    }
    fclose(fichier);
    return resultat1; // Retourner le résultat
}

// Exemple d'utilisation dans la fonction connexion
void connexion() {
    printf("Content-Type: text/html\n\n");

    // Corps du HTML
    printf("<!DOCTYPE html>\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>Connection</title>\n");
    printf("        <meta charset=\"UTF-8\">\n");
    printf("        <link rel=\"stylesheet\" href=\"inscription.css\">\n");
    printf("    </head>\n");
    printf("    <body>\n");
    printf("        <div class=\"STYLE\">\n");
   // printf("            <h2>Se connecter</h2>\n");
    printf("            <form method=\"get\">\n");
    printf("                <h2>Votre ID</h2>\n");
    printf("                <input type=\"text\" name=\"ID\" placeholder=\"Nom du compte\" required> <br>\n");
    printf("                <h2>Mode de passe</h2>\n");
    printf("                <input type=\"password\" name=\"PWD\" placeholder=\"Mode de passe\" required><br>\n");
    printf("                <input class=\"STYLE\" style=\"background-color: #1877F2; color: azure;\" type=\"submit\" value=\"Se connecter\">\n");
    printf("                <h2>Si vous êtes nouveau ici, faites d'abord l'inscription.</h2>\n");
    printf("                <a class=\"STYLE\" href=\"inscription.cgi\" style=\"background-color: #1ade4e; color: azure; text-decoration: none; padding: 5px 250px; border-radius: 15px;\">Cliquez-ici</a>\n");
    printf("            </form>\n");

    char *lien = getenv("QUERY_STRING");
    if (lien != NULL) {
        decode_url(lien);

        char id[256] = {0};
        char pwd[256] = {0};

        // Extraction des valeurs ID et PWD
        if (sscanf(lien, "ID=%255[^&]&PWD=%255s", id, pwd) == 2) {
            trim_whitespace(id);
            trim_whitespace(pwd);

            int resu = test_acces(id, pwd);
            if (resu == 1) {
                printf("<p class=\"success\">Connexion réussie !</p>\n");
                printf("<a class=\"STYLE\" href=\"interface-fin.cgi\" style=\"background-color: #1ade4e; color: azure; text-decoration: none; padding: 5px 250px; border-radius: 15px;\">Tapez-ici</a>\n");
            } else {
                printf("<h2 class=\"error\" style=\"color: red;\">Erreur: Identifiant ou mot de passe incorrect.</h2>\n");
            }
        } else {
            printf("<p class=\"error\">Erreur: Données du formulaire non valides.</p>\n");
        }
    } else {
        printf("<p class=\"error\">Erreur: Pas de données reçues.</p>\n");
    }

    printf("        </div>\n");
    printf("    </body>\n");
    printf("</html>\n");
}
