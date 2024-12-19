#ifndef COMPTEEPEPARGNE_H
#define COMPTEEPEPARGNE_H

#include "CompteBancaire.h"

class CompteEpargne : public CompteBancaire {
private:
    double tauxInteret;

public:
    CompteEpargne();
    CompteEpargne(const std::string& titulaire, double solde, int numeroCompte, double tauxInteret);
    CompteEpargne(const CompteEpargne& autre);
    virtual ~CompteEpargne();

    double getTauxInteret() const;
    void setTauxInteret(double taux);

    void calculerInteret();
    void afficherInfo() const override;
};

#endif // COMPTEEPEPARGNE_H
