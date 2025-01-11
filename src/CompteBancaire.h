#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <string>

class CompteBancaire {
protected:
    std::string titulaire;
    double solde;
    int numeroCompte;

public:
    // Constructeurs
    CompteBancaire();
    CompteBancaire(const std::string& titulaire, double solde, int numeroCompte);
    CompteBancaire(const CompteBancaire& autre);
    virtual ~CompteBancaire();

    // Getters et Setters
    std::string getTitulaire() const;
    void setTitulaire(const std::string& titulaire);
    double getSolde() const;
    void setSolde(double solde);
    int getNumeroCompte() const;

    // Méthodes
    virtual void afficherInfo() const;
    void deposer(double montant);
    virtual bool retirer(double montant);
    bool transferer(CompteBancaire& compteDest, double montant);
};

#endif // COMPTEBANCAIRE_H
