#ifndef COMPTEEPEPARGNE_H
#define COMPTEEPEPARGNE_H

// Inclusion de l'en-tête de la classe de base CompteBancaire
#include "CompteBancaire.h"

// Déclaration de la classe CompteEpargne qui hérite de la classe CompteBancaire
// Héritage : CompteEpargne est une spécialisation de CompteBancaire, elle en hérite les propriétés et les méthodes
class CompteEpargne : public CompteBancaire {
private:
    // Attribut privé pour stocker le taux d'intérêt du compte épargne
    double tauxInteret; // Exprimé en pourcentage (exemple : 2.5 pour 2.5%)

public:
    // Constructeur par défaut : initialise un compte épargne avec des valeurs par défaut
    CompteEpargne();

    // Constructeur paramétré : permet de créer un compte épargne en fournissant des données spécifiques
    // Appelle implicitement le constructeur de CompteBancaire pour initialiser le titulaire, le solde et le numéro de compte
    CompteEpargne(const std::string& titulaire, double solde, int numeroCompte, double tauxInteret);


    // Destructeur virtuel : libère les ressources si nécessaire
    // Ici, il n'y a pas d'allocation dynamique de mémoire, donc le destructeur n'effectue aucune opération spécifique
    virtual ~CompteEpargne();

    // Accesseur pour le taux d'intérêt : permet d'obtenir la valeur du taux d'intérêt
    double getTauxInteret() const;

    // Mutateur pour le taux d'intérêt : permet de définir la valeur du taux d'intérêt
    void setTauxInteret(double taux);

    // Méthode pour calculer et appliquer les intérêts :
    // Cette méthode ajoute au solde les intérêts calculés en fonction du taux et du solde actuel
    void calculerInteret();

    // Méthode pour afficher les informations du compte épargne :
    // Elle surcharge la méthode afficherInfo() de la classe CompteBancaire grâce au mot-clé override
    // Elle inclut des détails spécifiques au compte épargne, comme le taux d'intérêt
    void afficherInfo() const override;

    // Méthode statique pour créer un compte épargne :
    // Retourne un pointeur vers un nouvel objet CompteEpargne alloué dynamiquement
    // L'utilisateur devra libérer la mémoire manuellement en utilisant `delete`
    static CompteEpargne* creerCompteEpargne(const std::string& titulaire, double solde, int numeroCompte, double tauxInteret);
};

#endif // COMPTEEPEPARGNE_H
