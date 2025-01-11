#include "Banque.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include <iostream>

Banque::Banque() {
    initialiserComptes();
}

Banque::~Banque() {
    for (auto compte : comptes) {
        delete compte;
    }
}

void Banque::ajouterCompte(CompteBancaire* compte) {
    comptes.push_back(compte);
}

CompteBancaire* Banque::rechercherCompteParNumero(int numero) const {
    for (auto compte : comptes) {
        if (compte->getNumeroCompte() == numero) {
            return compte;
        }
    }
    return nullptr;
}

void Banque::afficherComptes() const {
    if (comptes.empty()) {
        std::cout << "Aucun compte dans la banque.\n";
        return;
    }

    for (auto compte : comptes) {
        compte->afficherInfo();
    }
}

void Banque::initialiserComptes() {
    comptes.push_back(new CompteCourant("Alice Dupont", 1500.0, 10000001, 500.0));
    comptes.push_back(new CompteEpargne("Alice Dupont", 5000.0, 10000002, 3.0));
    comptes.push_back(new CompteCourant("Bob Martin", 1200.0, 10000003, 300.0));
    comptes.push_back(new CompteEpargne("Bob Martin", 3000.0, 10000004, 2.5));
}
