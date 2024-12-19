#include "CompteEpargne.h"
#include <iostream>

CompteEpargne::CompteEpargne() : CompteBancaire(), tauxInteret(0.0) {}

CompteEpargne::CompteEpargne(const std::string& titulaire, double solde, int numeroCompte, double tauxInteret)
    : CompteBancaire(titulaire, solde, numeroCompte), tauxInteret(tauxInteret) {}

CompteEpargne::CompteEpargne(const CompteEpargne& autre)
    : CompteBancaire(autre), tauxInteret(autre.tauxInteret) {}

CompteEpargne::~CompteEpargne() {}

double CompteEpargne::getTauxInteret() const { return tauxInteret; }

void CompteEpargne::setTauxInteret(double taux) { tauxInteret = taux; }

void CompteEpargne::calculerInteret() {
    solde += solde * (tauxInteret / 100.0);
}

void CompteEpargne::afficherInfo() const {
    CompteBancaire::afficherInfo();
    std::cout << "Taux d'Interet: " << tauxInteret << "%" << std::endl;
}
