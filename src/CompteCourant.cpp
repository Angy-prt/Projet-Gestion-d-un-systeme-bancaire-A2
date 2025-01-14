#include "CompteCourant.h" // Inclusion du fichier d'en-tête correspondant
#include <iostream>        // Inclusion pour utiliser std::cout et std::endl

// Constructeur par défaut
// - Initialise un compte courant avec des valeurs par défaut :
//   - `CompteBancaire()` : Appelle le constructeur par défaut de la classe de base pour initialiser les attributs hérités (titulaire, solde, numéro de compte).
//   - `decouvertAutorise(0.0)` : Initialise le découvert autorisé à zéro.
CompteCourant::CompteCourant() 
    : CompteBancaire(), decouvertAutorise(0.0) {}

// Constructeur paramétré
// - Permet de créer un compte courant avec des valeurs personnalisées pour :
//   - Le titulaire du compte.
//   - Le solde initial.
//   - Le numéro de compte.
//   - Le découvert autorisé.
// - Le constructeur de la classe de base (`CompteBancaire`) est appelé avec les paramètres pertinents.
CompteCourant::CompteCourant(const std::string& titulaire, double solde, int numeroCompte, double decouvertAutorise)
    : CompteBancaire(titulaire, solde, numeroCompte), decouvertAutorise(decouvertAutorise) {}


// Destructeur
// - Détruit un objet de type `CompteCourant`.
// - Aucun nettoyage explicite n'est nécessaire ici, car il n'y a pas d'allocation dynamique de mémoire.
// - Ce destructeur virtuel garantit une destruction correcte en cas de polymorphisme.
CompteCourant::~CompteCourant() {}

// Accesseur : getDecouvertAutorise
// - Retourne la valeur actuelle du découvert autorisé.
// - Cette méthode est `const` car elle ne modifie pas l'état de l'objet.
double CompteCourant::getDecouvertAutorise() const {
    return decouvertAutorise;
}

// Mutateur : setDecouvertAutorise
// - Permet de définir une nouvelle valeur pour le découvert autorisé.
// - Aucun contrôle sur la validité de la valeur n'est effectué ici.
void CompteCourant::setDecouvertAutorise(double montant) {
    decouvertAutorise = montant;
}

// Méthode : retirer
// - Permet de retirer un montant du compte en tenant compte du découvert autorisé.
// - Vérifie si le solde disponible (solde actuel + découvert autorisé) est suffisant pour couvrir le montant à retirer.
//   - Si oui : Le solde est déduit du montant spécifié, et la méthode retourne `true`.
//   - Sinon : Un message est affiché, et la méthode retourne `false`.
// - Appelle `getSolde()` et `setSolde()` pour accéder et modifier le solde (encapsulation).
bool CompteCourant::retirer(double montant) {
    // Vérification du solde disponible (solde actuel + découvert autorisé)
    if (getSolde() + getDecouvertAutorise() >= montant) {
        setSolde(getSolde() - montant); // Réduction du solde
        std::cout << "Montant validé : " << montant
                  << " EUR. Nouveau solde: " << getSolde() << " EUR\n";
        return true; // Retrait réussi
    }

    // Si les fonds sont insuffisants
    std::cout << "Fonds insuffisants (découvert inclus).\n";
    return false; // Retrait échoué
}

// Méthode : afficherInfo
// - Affiche les informations du compte courant :
//   - Les informations générales (titulaire, solde, numéro de compte) sont affichées en appelant `afficherInfo` de la classe de base.
//   - Ajoute ensuite l'affichage spécifique au compte courant, comme le découvert autorisé.
void CompteCourant::afficherInfo() const {
    CompteBancaire::afficherInfo(); // Appel à la méthode de la classe de base
    std::cout << "Decouvert Autorise: " << getDecouvertAutorise() << " EUR\n";
}
