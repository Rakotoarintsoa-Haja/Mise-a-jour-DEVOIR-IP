#include "prototype_ip2.h"

int main() {
    // En-tête HTTP pour CGI
    printf("Content-type: text/html\n\n");

    // Affichage du formulaire HTML
    afficher_formulaire();

    // Récupération des données envoyées via GET
    char *query_string = getenv("QUERY_STRING");

    if (query_string != NULL && strlen(query_string) > 0) {
        char ip_input[50] = {0};

        // Extraire la valeur du paramètre "ip" dans QUERY_STRING
        sscanf(query_string, "ip=%49s", ip_input);

        // Remplacer %20 par des espaces dans l'entrée utilisateur
        for (int i = 0; i < strlen(ip_input); i++) {
            if (ip_input[i] == '+') ip_input[i] = ' ';
        }

        // Appeler la fonction de calcul réseau
        calcul_reseau(ip_input);
    }

    // Fin du HTML
    printf("</div>\n");
    printf("</body>\n");
    printf("</html>\n");

    return 0;
}