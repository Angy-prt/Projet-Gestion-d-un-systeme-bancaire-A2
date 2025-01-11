#ifndef BANQUE_H
#define BANQUE_H

#include <vector>
#include "CompteBancaire.h"

class Banque {
private:
    std::vector<CompteBancaire*> comptes; // Collection des comptes bancaires

public:
    Banque();                              // Constructeur
    ~Banque();                             // Destructeur
    void ajouterCompte(CompteBancaire* compte); // Ajouter un compte à la banque
    CompteBancaire* rechercherCompteParNumero(int numero) const; // Rechercher un compte par son numéro
    void afficherComptes() const;          // Afficher tous les comptes
    void initialiserComptes();             // Initialiser les comptes avec des données par défaut
};

#endif // BANQUE_H
