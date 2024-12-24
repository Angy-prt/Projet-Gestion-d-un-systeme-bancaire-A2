#include "CompteCourant.h"
#include <iostream>

CompteCourant::CompteCourant() : CompteBancaire(), decouvertAutorise(0.0) {}

CompteCourant::CompteCourant(const std::string& titulaire, double solde, int numeroCompte, double decouvertAutorise)
    : CompteBancaire(titulaire, solde, numeroCompte), decouvertAutorise(decouvertAutorise) {}

CompteCourant::CompteCourant(const CompteCourant& autre)
    : CompteBancaire(autre), decouvertAutorise(autre.decouvertAutorise) {}

CompteCourant::~CompteCourant() {}

double CompteCourant::getDecouvertAutorise() const { return decouvertAutorise; }

void CompteCourant::setDecouvertAutorise(double montant) { decouvertAutorise = montant; }

bool CompteCourant::retirer(double montant) {
    if (solde + decouvertAutorise >= montant) {
        solde -= montant;
        std::cout << "Montant validé :  " << montant << " EUR. Nouveau solde: " << solde << " EUR" << std::endl;
        return true;
    }
    std::cout << "Fonds insuffisants (découvert inclus)." << std::endl;
    return false;
}




void CompteCourant::afficherInfo() const {
    CompteBancaire::afficherInfo();
    std::cout << "Decouvert Autorise: " << decouvertAutorise << " EUR" << std::endl;
}
