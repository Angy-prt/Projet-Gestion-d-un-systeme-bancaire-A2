#ifndef BANQUE_H
#define BANQUE_H

#include "CompteBancaire.h"
#include <vector>

class Banque {
private:
    std::vector<CompteBancaire*> comptes;  // Liste de pointeurs bruts vers CompteBancaire

public:
    Banque();  // Constructeur avec base de données initiale
    ~Banque(); // Destructeur pour gérer la suppression des comptes
    void ajouterCompte(CompteBancaire* compte);
    CompteBancaire* rechercherCompteParNumero(int numero);
    void afficherComptes() const;
};

#endif // BANQUE_H
