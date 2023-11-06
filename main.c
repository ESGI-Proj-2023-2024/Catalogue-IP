#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IPAddress {
    unsigned int octets[4];
};

// Fonction pour valider la syntaxe d'une chaîne entrée par l'utilisateur, en tant qu'adresse IP
int isValidIP(const char* str, struct IPAddress* ip) {
    int octet1, octet2, octet3, octet4;
    int result = sscanf(str, "%u.%u.%u.%u", &octet1, &octet2, &octet3, &octet4);

    if (result == 4) {
        // Vérification que chaque octet est dans la plage valide, de 0 à 255
        if (octet1 >= 0 && octet1 <= 255 &&
            octet2 >= 0 && octet2 <= 255 &&
            octet3 >= 0 && octet3 <= 255 &&
            octet4 >= 0 && octet4 <= 255) {
            // Stockage des octets dans la structuer
            ip->octets[0] = octet1;
            ip->octets[1] = octet2;
            ip->octets[2] = octet3;
            ip->octets[3] = octet4;
            return 1; // Si 1 est retourné, alors la chaîne (IP) est valide
        }
    }

    return 0; // Si 0 est retourné, la chaîne n'est pas valide 
}


int main() {
    struct IPAddress* addresses = NULL;

    char choice;
    do {
        printf("Menu :\n");
        printf("a - Add a new IP address\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                // Demander à l'utilisateur de saisir une adresse IP
                char userIPStr[20];
                printf("Enter address : ");
                scanf("%s");

                // Valider l'adresse IP saisie par l'utilisateur
                if (isValidIP == 1) {
                    // Convertir la chaîne en une structure IPAddress et l'ajouter au catalogue
                    printf("Adresse IP valide, elle figure désormais dans le catalogue.\n");
                } else {
                    printf("Adresse IP invalide. Faites un effort et veuillez entrer une adresse IP valide.\n");
                }
                break;
            case 'q':
                // Quitter le programme
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (choice != 'q');
    return 0;
}
