#include "Banque.h"
#include <iostream>

void Banque::ajouterCompte(const std::shared_ptr<CompteBancaire>& compte) {
    comptes.push_back(compte);
}

std::shared_ptr<CompteBancaire> Banque::rechercherCompteParNumero(int numero) {
    for (const auto& compte : comptes) {
        if (compte->getNumeroCompte() == numero) {
            return compte;
        }
    }
    return nullptr;
}

void Banque::afficherComptes() const {
    for (const auto& compte : comptes) {
        compte->afficherInfo();
        std::cout << "-------------------" << std::endl;
    }
}
