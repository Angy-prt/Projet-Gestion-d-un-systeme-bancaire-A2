#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

#include "CompteBancaire.h"

class CompteCourant : public CompteBancaire {
private:
    double decouvertAutorise;

public:
    CompteCourant();
    CompteCourant(const std::string& titulaire, double solde, int numeroCompte, double decouvertAutorise);
    CompteCourant(const CompteCourant& autre);
    virtual ~CompteCourant();

    double getDecouvertAutorise() const;
    void setDecouvertAutorise(double montant);

    virtual bool retirer(double montant) override;
    void afficherInfo() const override;
};

#endif // COMPTECOURANT_H
