#ifndef BANQUE_H
#define BANQUE_H

#include <vector>
#include "CompteBancaire.h"

class Banque {
private:
    std::vector<CompteBancaire*> comptes;

public:
    Banque();
    ~Banque();
    void ajouterCompte(CompteBancaire* compte);
    CompteBancaire* rechercherCompteParNumero(int numero);
    void afficherComptes() const;
    void initialiserComptes();
};

#endif // BANQUE_H
