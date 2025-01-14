#include <iostream>    // Pour les entrées/sorties (std::cin, std::cout)
#include <memory>      // Pour les smart pointers (comme std::unique_ptr)
#include <string>      // Pour manipuler les chaînes de caractères (std::string)
#include <cstdlib>     // Pour std::rand() et std::srand(), utilisés pour générer des nombres aléatoires
#include <ctime>       // Pour initialiser std::srand() avec l'heure actuelle
#include <vector>      // Conteneur dynamique (std::vector) pour stocker une collection de comptes
#include "CompteBancaire.h"  // Déclaration de la classe de base pour tous les types de comptes bancaires
#include "CompteEpargne.h"   // Déclaration de la classe pour les comptes épargne (dérivée de CompteBancaire)
#include "CompteCourant.h"   // Déclaration de la classe pour les comptes courants (dérivée de CompteBancaire)
#include "Banque.h"          // Déclaration de la classe Banque, responsable de la gestion des comptes

// Fonction pour afficher le menu principal
// Cette fonction guide l'utilisateur avec les options principales de l'application.
void afficherMenu() {
    std::cout << "\n===== Menu Principal =====\n";
    std::cout << "1. Ajouter un compte\n"; // Permet de créer un nouveau compte bancaire
    std::cout << "2. Se connecter à un compte\n"; // Permet de gérer un compte existant
    std::cout << "3. Afficher tous les comptes\n"; // Affiche tous les comptes enregistrés dans la banque
    std::cout << "4. Quitter\n"; // Quitte l'application
    std::cout << "==========================\n";
    std::cout << "Choisissez une option : ";
}

// Fonction pour afficher le menu des opérations sur un compte
// Affichée lorsque l'utilisateur est connecté à un compte.
void afficherMenuCompte() {
    std::cout << "\n===== Menu Compte =====\n";
    std::cout << "1. Effectuer un dépôt\n"; // Ajouter de l'argent au solde du compte
    std::cout << "2. Effectuer un retrait\n"; // Retirer de l'argent du compte
    std::cout << "3. Effectuer un transfert\n"; // Transférer de l'argent vers un autre compte
    std::cout << "4. Calculer les intérêts (compte épargne seulement)\n"; // Applique les intérêts sur un compte épargne
    std::cout << "5. Retour au menu principal\n"; // Retourne au menu principal
    std::cout << "=======================\n";
    std::cout << "Choisissez une option : ";
}

int main() {
    // Création de l'objet Banque qui gère tous les comptes bancaires.
    Banque banque;

    // Vecteur pour stocker des pointeurs vers les objets CompteBancaire.
    // Ce vecteur permet d'avoir une référence locale à tous les comptes créés.
    std::vector<CompteBancaire*> comptes;

    // Initialisation du numéro unique des comptes bancaires.
    // Chaque nouveau compte se verra attribuer un numéro unique, à partir de cette valeur.
    int prochainNumeroCompte = 10000005;

    // Initialisation du générateur de nombres aléatoires.
    // Utilisation de l'heure actuelle comme graine pour obtenir des résultats différents à chaque exécution.
    std::srand(static_cast<unsigned>(std::time(0)));

    // Variable pour stocker le choix principal de l'utilisateur dans le menu.
    int choixPrincipal;

    // Boucle principale du programme.
    // Continue tant que l'utilisateur ne choisit pas l'option "Quitter" (choixPrincipal != 4).
    do {
        afficherMenu(); // Affiche le menu principal
        std::cin >> choixPrincipal; // Lit le choix de l'utilisateur

        switch (choixPrincipal) {
            case 1: { // Option 1 : Ajouter un nouveau compte bancaire
                int typeCompte; // Stocke le type de compte à créer (épargne ou courant)

                // Demande à l'utilisateur de choisir un type de compte
                std::cout << "\nType de compte :\n";
                std::cout << "1. Compte Epargne\n"; // Compte épargne : possibilité de calculer des intérêts
                std::cout << "2. Compte Courant\n"; // Compte courant : possibilité de découvert
                std::cout << "Choisissez une option : ";
                std::cin >> typeCompte;

                std::string titulaire; // Stocke le nom du titulaire du compte
                double solde;          // Stocke le solde initial du compte

                // Demande les informations du titulaire du compte
                std::cout << "Entrez le titulaire du compte : ";
                std::cin.ignore(); // Élimine le caractère résiduel de la précédente entrée utilisateur
                std::getline(std::cin, titulaire); // Permet d'inclure des espaces dans le nom

                // Demande le solde initial
                std::cout << "Entrez le solde initial : ";
                std::cin >> solde;

                // Génère un numéro unique pour le nouveau compte
                int numeroCompte = prochainNumeroCompte++;

                // Création et enregistrement du compte en fonction du type choisi
                if (typeCompte == 1) { // Compte épargne
                    // Création d'un compte épargne avec un taux d'intérêt fixe (1.5%)
                    auto compte = new CompteEpargne(titulaire, solde, numeroCompte, 1.5);
                    banque.ajouterCompte(compte); // Ajoute le compte à la liste dans la banque
                    comptes.push_back(compte);   // Ajoute le compte au vecteur local
                    std::cout << "Compte épargne créé avec succès. Numéro de compte : " << numeroCompte << "\n";
                } else if (typeCompte == 2) { // Compte courant
                    // Création d'un compte courant avec un découvert autorisé (500.0 EUR)
                    auto compte = new CompteCourant(titulaire, solde, numeroCompte, 500.0);
                    banque.ajouterCompte(compte);
                    comptes.push_back(compte);
                    std::cout << "Compte courant créé avec succès. Numéro de compte : " << numeroCompte << "\n";
                } else {
                    // Si l'utilisateur entre un choix invalide
                    std::cout << "Option invalide.\n";
                }
                break;
            }

            case 2: { // Option 2 : Connexion à un compte existant
                int numeroCompte; // Stocke le numéro du compte à connecter
                std::cout << "Entrez le numéro de compte à connecter : ";
                std::cin >> numeroCompte;

                // Recherche du compte dans la liste de la banque
                auto compte = banque.rechercherCompteParNumero(numeroCompte);
                if (compte) {
                    compte->afficherInfo(); // Affiche les informations du compte

                    int choixCompte; // Variable pour stocker le choix utilisateur dans le menu secondaire
                    do {
                        afficherMenuCompte(); // Affiche le menu secondaire
                        std::cin >> choixCompte; // Lit le choix de l'utilisateur

                        switch (choixCompte) {
                            case 1: { // Dépôt
                                double montant;
                                std::cout << "Entrez le montant à déposer : ";
                                std::cin >> montant;
                                compte->deposer(montant); // Ajoute le montant au compte
                                break;
                            }
                            case 2: { // Retrait
                                double montant;
                                std::cout << "Entrez le montant à retirer : ";
                                std::cin >> montant;
                                if (!compte->retirer(montant)) {
                                    std::cout << "Retrait échoué. Solde insuffisant.\n";
                                }
                                break;
                            }
                            case 3: { // Transfert
                                int numeroCompteDest;
                                double montant;
                                std::cout << "Entrez le numéro du compte destinataire : ";
                                std::cin >> numeroCompteDest;

                                auto compteDest = banque.rechercherCompteParNumero(numeroCompteDest);
                                if (compteDest) {
                                    std::cout << "Entrez le montant à transférer : ";
                                    std::cin >> montant;
                                    if (!compte->transferer(*compteDest, montant)) {
                                        std::cout << "Transfert échoué. Solde insuffisant.\n";
                                    }
                                } else {
                                    std::cout << "Compte destinataire introuvable.\n";
                                }
                                break;
                            }
                            case 4: { // Calcul des intérêts
                                auto compteEpargne = dynamic_cast<CompteEpargne*>(compte);
                                if (compteEpargne) {
                                    compteEpargne->calculerInteret(); // Calcule et ajoute les intérêts
                                    std::cout << "Intérêts calculés et ajoutés au solde.\n";
                                } else {
                                    std::cout << "Cette opération est uniquement disponible pour les comptes épargne.\n";
                                }
                                break;
                            }
                            case 5: // Retour au menu principal
                                std::cout << "Retour au menu principal.\n";
                                break;
                            default:
                                std::cout << "Option invalide.\n";
                        }
                    } while (choixCompte != 5); // Tant que l'utilisateur ne choisit pas de revenir au menu principal
                } else {
                    std::cout << "Compte introuvable.\n"; // Si le compte n'existe pas
                }
                break;
            }

            case 3: { // Option 3 : Afficher tous les comptes
                banque.afficherComptes(); // Affiche les informations de tous les comptes enregistrés
                break;
            }

            case 4: { // Option 4 : Quitter l'application
                std::cout << "Au revoir !\n"; // Message d'adieu
                break;
            }

            default:
                std::cout << "Option invalide.\n"; // Si l'utilisateur entre un choix non valide
        }
    } while (choixPrincipal != 4); // Fin de la boucle principale lorsque l'utilisateur choisit de quitter

    // Libération de la mémoire allouée dynamiquement pour les comptes
    for (auto compte : comptes) {
        delete compte;
    }
    comptes.clear(); // Vide le vecteur local

    return 0; // Fin normale du programme
}
