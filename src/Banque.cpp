#include "Banque.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Banque::Banque() {
    std::srand(static_cast<unsigned>(std::time(0)));  // Initialisation pour les taux aléatoires

    // Base de données initiale
    auto compte1 = new CompteCourant("Alice Dupont", 1500.0, 10000001, 500.0);
    auto compte2 = new CompteEpargne("Alice Dupont", 5000.0, 10000002, 3.0);

    auto compte3 = new CompteCourant("Bob Martin", 1200.0, 10000003, 300.0);
    auto compte4 = new CompteEpargne("Bob Martin", 3000.0, 10000004, 2.5);

    auto compte5 = new CompteCourant("Claire Fontaine", 2000.0, 10000005, 000.0);
    auto compte6 = new CompteEpargne("Claire Fontaine", 8000.0, 10000006, 4.0);

    // Ajouter les comptes à la banque
    comptes.push_back(compte1);
    comptes.push_back(compte2);
    comptes.push_back(compte3);
    comptes.push_back(compte4);
    comptes.push_back(compte5);
    comptes.push_back(compte6);
}

Banque::~Banque() {
    // Supprimer tous les comptes bancaires pour éviter les fuites mémoire
    for (auto compte : comptes) {
        delete compte;  // Suppression des pointeurs bruts
    }
}

void Banque::ajouterCompte(CompteBancaire* compte) {
    comptes.push_back(compte);  // Ajout d'un pointeur brut à la liste
}

CompteBancaire* Banque::rechercherCompteParNumero(int numero) {
    for (auto compte : comptes) {
        if (compte->getNumeroCompte() == numero) {
            return compte;  // Retourne le pointeur brut
        }
    }
    return nullptr;  // Si le compte n'est pas trouvé
}

void Banque::afficherComptes() const {
    for (auto compte : comptes) {
        compte->afficherInfo();  // Appel de afficherInfo() pour chaque compte
    }
}
