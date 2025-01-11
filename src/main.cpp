#include <iostream>
#include <memory>
#include <string>
#include <cstdlib> // Pour std::rand() et std::srand()
#include <ctime>   // Pour std::time()
#include <vector>  // Pour stocker plusieurs comptes
#include "CompteBancaire.h"
#include "CompteEpargne.h"
#include "CompteCourant.h"
#include "Banque.h"

void afficherMenu() {
    std::cout << "\n===== Menu Principal =====\n";
    std::cout << "1. Ajouter un compte\n";
    std::cout << "2. Se connecter à un compte\n";
    std::cout << "3. Afficher tous les comptes\n";
    std::cout << "4. Quitter\n";
    std::cout << "==========================\n";
    std::cout << "Choisissez une option : ";
}

void afficherMenuCompte() {
    std::cout << "\n===== Menu Compte =====\n";
    std::cout << "1. Effectuer un dépôt\n";
    std::cout << "2. Effectuer un retrait\n";
    std::cout << "3. Effectuer un transfert\n";
    std::cout << "4. Calculer les intérêts (compte épargne seulement)\n";
    std::cout << "5. Retour au menu principal\n";
    std::cout << "=======================\n";
    std::cout << "Choisissez une option : ";
}

int main() {
    Banque banque;
    std::vector<CompteBancaire*> comptes; // Conteneur pour stocker tous les comptes
    int prochainNumeroCompte = 10000005;   // Numéro de compte initial
    std::srand(static_cast<unsigned>(std::time(0))); // Initialisation du générateur de nombres aléatoires

    int choixPrincipal;
    do {
        afficherMenu();
        std::cin >> choixPrincipal;

        switch (choixPrincipal) {
            case 1: { // Ajouter un compte
                int typeCompte;
                std::cout << "\nType de compte :\n";
                std::cout << "1. Compte Epargne\n";
                std::cout << "2. Compte Courant\n";
                std::cout << "Choisissez une option : ";
                std::cin >> typeCompte;

                std::string titulaire;
                double solde;

                std::cout << "Entrez le titulaire du compte : ";
                std::cin.ignore();
                std::getline(std::cin, titulaire);

                std::cout << "Entrez le solde initial : ";
                std::cin >> solde;

                int numeroCompte = prochainNumeroCompte++;

                if (typeCompte == 1) {
                    auto compte = new CompteEpargne(titulaire, solde, numeroCompte, 1.5); // Taux fixe
                    banque.ajouterCompte(compte);
                    comptes.push_back(compte); // Ajouter le compte à la liste
                    std::cout << "Compte épargne créé avec succès. Numéro de compte : " << numeroCompte << "\n";
                } else if (typeCompte == 2) {
                    auto compte = new CompteCourant(titulaire, solde, numeroCompte, 500.0); // Découvert fixe
                    banque.ajouterCompte(compte);
                    comptes.push_back(compte); // Ajouter le compte à la liste
                    std::cout << "Compte courant créé avec succès. Numéro de compte : " << numeroCompte << "\n";
                } else {
                    std::cout << "Option invalide.\n";
                }
                break;
            }

            case 2: { // Se connecter à un compte
                int numeroCompte;
                std::cout << "Entrez le numéro de compte à connecter : ";
                std::cin >> numeroCompte;

                // Chercher le compte correspondant
                auto compte = banque.rechercherCompteParNumero(numeroCompte);
                if (compte) {
                    // Afficher les détails du compte
                    compte->afficherInfo();  // Affichage des informations du compte (titulaire, solde, etc.)

                    int choixCompte;
                    do {
                        afficherMenuCompte();
                        std::cin >> choixCompte;

                        switch (choixCompte) {
                            case 1: { // Dépôt
                                double montant;
                                std::cout << "Entrez le montant à déposer : ";
                                std::cin >> montant;
                                compte->deposer(montant);
                                break;
                            }
                            case 2: { // Retrait
                                double montant;
                                std::cout << "Entrez le montant à retirer : ";
                                std::cin >> montant;
                                if (compte->retirer(montant)) {
                                    std::cout << "Retrait effectué.\n";
                                } else {
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

                                    if (compte->transferer(*compteDest, montant)) {
                                        std::cout << "Transfert effectué.\n";
                                    } else {
                                        std::cout << "Transfert échoué. Solde insuffisant.\n";
                                    }
                                } else {
                                    std::cout << "Compte destinataire introuvable.\n";
                                }
                                break;
                            }
                            case 4: { // Calculer les intérêts
                                auto compteEpargne = dynamic_cast<CompteEpargne*>(compte);
                                if (compteEpargne) {
                                    compteEpargne->calculerInteret();
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
                    } while (choixCompte != 5);
                } else {
                    std::cout << "Compte introuvable.\n";
                }
                break;
            }

            case 3: // Afficher tous les comptes
                banque.afficherComptes();
                break;

            case 4: // Quitter
                std::cout << "Au revoir !\n";
                break;

            default:
                std::cout << "Option invalide.\n";
        }
    } while (choixPrincipal != 4);

    // Libérer la mémoire allouée pour les comptes
    for (auto compte : comptes) {
        delete compte;
    }

    return 0;
}
