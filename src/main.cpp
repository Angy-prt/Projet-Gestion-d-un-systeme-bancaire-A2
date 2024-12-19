#include <iostream>
#include <memory>
#include "CompteBancaire.h"
#include "CompteEpargne.h"
#include "CompteCourant.h"
#include "Banque.h"

int main() {
    Banque banque;

    // Création de comptes
    auto compte1 = std::make_shared<CompteBancaire>("Alice", 5000, 12345678);
    auto compte2 = std::make_shared<CompteEpargne>("Bob", 3000, 23456789, 2.5);
    auto compte3 = std::make_shared<CompteCourant>("Charlie", 1000, 34567890, 500);

    // Ajout des comptes à la banque
    banque.ajouterCompte(compte1);
    banque.ajouterCompte(compte2);
    banque.ajouterCompte(compte3);

    // Affichage des comptes
    std::cout << "Liste des comptes dans la banque :\n";
    banque.afficherComptes();

    // Dépôt et retrait
    std::cout << "\nDépôt de 1000 EUR sur le compte de Alice.\n";
    compte1->deposer(1000);

    std::cout << "Retrait de 500 EUR sur le compte de Charlie.\n";
    compte3->retirer(500);

    // Calcul des intérêts
    std::cout << "\nCalcul des intérêts pour le compte épargne de Bob.\n";
    auto epargne = std::dynamic_pointer_cast<CompteEpargne>(compte2);
    if (epargne) {
        epargne->calculerInteret();
    }

    // Transfert
    std::cout << "\nTransfert de 200 EUR de Alice à Bob.\n";
    compte1->transferer(*compte2, 200);

    // Affichage après opérations
    std::cout << "\nListe des comptes après opérations :\n";
    banque.afficherComptes();

    // Recherche d'un compte
    std::cout << "\nRecherche du compte avec le numéro 23456789 :\n";
    auto compteRecherche = banque.rechercherCompteParNumero(23456789);
    if (compteRecherche) {
        compteRecherche->afficherInfo();
    } else {
        std::cout << "Compte non trouvé.\n";
    }

    return 0;
}
