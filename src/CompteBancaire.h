// On commence par une protection d'inclusion pour éviter les problèmes liés à l'inclusion multiple du fichier.
// Cela permet de garantir que ce fichier ne sera inclus qu'une seule fois dans le programme, même si plusieurs fichiers l'incluent. 
// Cette pratique permet d'éviter des erreurs de redéfinition lors de la compilation.
#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

// On inclut la bibliothèque <string> qui permet de travailler avec des chaînes de caractères (std::string).
#include <string>

// Définition de la classe "CompteBancaire" qui représente un compte bancaire générique.
// Cette classe contient des informations générales sur le compte bancaire : le titulaire, le solde, et le numéro de compte.
// Les classes dérivées (comme CompteEpargne, CompteCourant, Banque) hériteront de cette classe et ajouteront leurs propres spécificités.
class CompteBancaire {
protected:
    // Attributs de la classe (membres privés/protégés : Les membres sont accessibles à l'intérieur de cette classe où ils sont définis et dans les classes qui en héritent (CompteEpargne, CompteCourant, Banque), mais pas à l'extérieur de ces classes.) :
    // "titulaire" représente le nom du titulaire du compte sous forme de chaîne de caractères (string).
    std::string titulaire;

    // "solde" représente le solde actuel du compte sous forme de nombre à virgule flottante (double).
    double solde;

    // "numeroCompte" représente le numéro unique attribué au compte sous forme d'entier (int).
    int numeroCompte;

public:
    // Constructeurs de la classe :
    // Un constructeur est une méthode spéciale appelée lors de la création d'un objet de cette classe.
    
    // Le constructeur par défaut : il initialise un compte avec un titulaire vide, un solde de 0.0, et un numéro de compte de 0.
    CompteBancaire();

    // Le constructeur avec paramètres : il permet de créer un compte avec un titulaire, un solde et un numéro de compte spécifiés.
    CompteBancaire(const std::string& titulaire, double solde, int numeroCompte);

    // Le destructeur est une méthode spéciale qui est appelée lors de la destruction d'un objet de cette classe.
    // Elle permet de libérer des ressources si nécessaire (dans ce cas, la classe ne gère pas de ressources dynamiques).
    virtual ~CompteBancaire();

    // Méthodes "getter" et "setter" pour accéder et modifier les valeurs des attributs de la classe :
    
    // Getter pour obtenir le titulaire du compte. Il retourne une copie du nom du titulaire (une chaîne de caractères).
    std::string getTitulaire() const;

    // Setter pour définir le titulaire du compte. Il prend un nom en paramètre et modifie l'attribut "titulaire".
    void setTitulaire(const std::string& titulaire);

    // Getter pour obtenir le solde du compte. Il retourne la valeur du solde sous forme de double.
    double getSolde() const;

    // Setter pour définir le solde du compte. Il prend un montant en paramètre et modifie l'attribut "solde".
    void setSolde(double solde);

    // Getter pour obtenir le numéro de compte. Il retourne le numéro sous forme d'entier.
    int getNumeroCompte() const;

    // Setter pour définir le numéro de compte. Il prend un numéro de compte en paramètre et modifie l'attribut "numeroCompte".
    void setNumeroCompte(int numero);

    // Méthodes d'action sur le compte :
    
    // La méthode afficherInfo affiche les informations du compte (titulaire, solde, et numéro de compte).
    // Cette méthode est virtuelle, ce qui signifie qu'elle peut être redéfinie dans les classes dérivées.
    virtual void afficherInfo() const;

    // La méthode deposer permet de déposer une certaine somme d'argent sur le compte.
    // Elle prend un montant positif en paramètre et ajoute ce montant au solde du compte.
    void deposer(double montant);

    // La méthode retirer permet de retirer une certaine somme d'argent du compte.
    // Elle prend un montant positif en paramètre et le retire du solde du compte si le solde est suffisant.
    // Si le retrait est possible (montant <= solde), la méthode retourne true, sinon elle retourne false.
    // Cette méthode est virtuelle, ce qui signifie qu'elle peut être redéfinie dans les classes dérivées.
    virtual bool retirer(double montant);

    // La méthode transferer permet de transférer de l'argent d'un compte à un autre.
    // Elle prend en paramètre une référence vers un autre objet CompteBancaire (compteDest) et un montant à transférer.
    // Elle effectue d'abord un retrait du montant sur le compte source (l'objet actuel), puis un dépôt sur le compte destinataire.
    // La méthode retourne true si le transfert est effectué avec succès, sinon elle retourne false.
    bool transferer(CompteBancaire& compteDest, double montant);
};

// Fin de la protection d'inclusion : assure que le fichier ne sera inclus qu'une seule fois
#endif // COMPTEBANCAIRE_H
