#ifndef COMPTECOURANT_H // Garde conditionnelle pour éviter l'inclusion multiple de ce fichier
#define COMPTECOURANT_H

#include "CompteBancaire.h" // Inclusion de la classe de base CompteBancaire

// Déclaration de la classe CompteCourant
// Héritage : CompteCourant est une classe dérivée de CompteBancaire
class CompteCourant : public CompteBancaire {
private:
    // Attribut privé pour stocker le montant du découvert autorisé
    double decouvertAutorise; // Permet au compte d'avoir un solde négatif jusqu'à une certaine limite

public:
    // Constructeur par défaut :
    // Initialise un compte courant avec des valeurs par défaut
    // - `CompteBancaire()` : Appelle le constructeur par défaut de la classe de base pour initialiser les attributs hérités
    // - `decouvertAutorise(0.0)` : Initialise le découvert autorisé à zéro
    CompteCourant();

    // Constructeur paramétré :
    // Permet de créer un compte courant en définissant un titulaire, un solde, un numéro de compte, et un découvert autorisé
    CompteCourant(const std::string& titulaire, double solde, int numeroCompte, double decouvertAutorise);

    // Destructeur virtuel :
    // Détruit un objet de type CompteCourant
    // Ce destructeur est virtuel pour permettre la destruction correcte des objets dérivés (polymorphisme)
    // Il ne fait rien de spécifique ici, car il n'y a pas d'allocation dynamique de mémoire
    virtual ~CompteCourant();

    // Accesseur pour le découvert autorisé :
    // Retourne la valeur du découvert autorisé
    double getDecouvertAutorise() const;

    // Mutateur pour le découvert autorisé :
    // Modifie la valeur du découvert autorisé
    void setDecouvertAutorise(double montant);

    // Méthode pour retirer un montant du compte (redéfinition de la méthode retirer dans la classe de base) :
    // Cette méthode permet de retirer de l'argent, en prenant en compte le découvert autorisé
    // - Si le montant à retirer dépasse le solde disponible + découvert autorisé, le retrait est refusé
    // - Sinon, le solde est réduit et la méthode retourne `true`
    // - Le mot-clé `override` indique que cette méthode redéfinit une méthode de la classe de base
    virtual bool retirer(double montant) override;

    // Méthode pour afficher les informations du compte courant (redéfinition de la méthode afficherInfo) :
    // - Appelle d'abord la méthode afficherInfo de la classe de base pour afficher les informations générales (titulaire, solde, numéro)
    // - Ajoute ensuite l'affichage spécifique au compte courant, comme le découvert autorisé
    void afficherInfo() const override;
};

#endif // COMPTECOURANT_H
