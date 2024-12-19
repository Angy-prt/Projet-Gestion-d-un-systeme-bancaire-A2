#ifndef BANQUE_H
#define BANQUE_H

#include <vector>
#include <memory>
#include "CompteBancaire.h"

class Banque {
private:
    std::vector<std::shared_ptr<CompteBancaire>> comptes;

public:
    // Méthodes
    void ajouterCompte(const std::shared_ptr<CompteBancaire>& compte);
    std::shared_ptr<CompteBancaire> rechercherCompteParNumero(int numero);
    void afficherComptes() const;
};

#endif // BANQUE_H
