#include "CompteBancaire.h"
#include <iostream>

CompteBancaire::CompteBancaire() : titulaire(""), solde(0.0), numeroCompte(0) {}

CompteBancaire::CompteBancaire(const std::string& titulaire, double solde, int numeroCompte)
    : titulaire(titulaire), solde(solde), numeroCompte(numeroCompte) {}

CompteBancaire::CompteBancaire(const CompteBancaire& autre)
    : titulaire(autre.titulaire), solde(autre.solde), numeroCompte(autre.numeroCompte) {}

CompteBancaire::~CompteBancaire() {}

std::string CompteBancaire::getTitulaire() const { return titulaire; }

void CompteBancaire::setTitulaire(const std::string& titulaire) { this->titulaire = titulaire; }

double CompteBancaire::getSolde() const { return solde; }

void CompteBancaire::setSolde(double solde) { this->solde = solde; }

int CompteBancaire::getNumeroCompte() const { return numeroCompte; }

void CompteBancaire::afficherInfo() const {
    std::cout << "Titulaire: " << titulaire << ", Numero: " << numeroCompte
              << ", Solde: " << solde << " EUR" << std::endl;
}

void CompteBancaire::deposer(double montant) {
    if (montant > 0) {
        solde += montant;
        std::cout << "Montant validé :  " << montant << " EUR. Nouveau solde: " << solde << " EUR" << std::endl;
    } else {
        std::cout << "Montant invalide. Impossible de déposer " << montant << " EUR." << std::endl;
    }
}



bool CompteBancaire::retirer(double montant) {
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        return true;
    }
    std::cout << "Fonds insuffisants." << std::endl;
    return false;
}

bool CompteBancaire::transferer(CompteBancaire& compteDest, double montant) {
    if (retirer(montant)) {
        compteDest.deposer(montant);
        return true;
    }
    return false;
}
