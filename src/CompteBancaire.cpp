#include "CompteBancaire.h" // Inclusion du fichier d'en-tête contenant la définition de la classe CompteBancaire
#include <iostream>         // Inclusion de la bibliothèque standard pour l'entrée et la sortie

// Constructeur par défaut : initialise un compte bancaire avec des valeurs par défaut
CompteBancaire::CompteBancaire()
    : titulaire(""), solde(0.0), numeroCompte(0) {} // Utilisation d'une liste d'initialisation

// Constructeur paramétré : initialise un compte bancaire avec des valeurs fournies par l'utilisateur
CompteBancaire::CompteBancaire(const std::string& titulaire, double solde, int numeroCompte)
    : titulaire(titulaire), solde(solde), numeroCompte(numeroCompte) {}

// Destructeur : détruit l'objet CompteBancaire. Ici, il n'a pas de rôle spécifique car aucune mémoire dynamique n'est utilisée.
CompteBancaire::~CompteBancaire() {}

// Accesseur pour obtenir le nom du titulaire du compte
std::string CompteBancaire::getTitulaire() const {
    return titulaire;
}

// Mutateur pour définir le nom du titulaire du compte
void CompteBancaire::setTitulaire(const std::string& titulaire) {
    this->titulaire = titulaire; // Utilisation du pointeur implicite `this` pour éviter toute ambiguïté
}

// Accesseur pour obtenir le solde du compte
double CompteBancaire::getSolde() const {
    return solde;
}

// Mutateur pour modifier le solde du compte
void CompteBancaire::setSolde(double solde) {
    this->solde = solde;
}

// Accesseur pour obtenir le numéro de compte
int CompteBancaire::getNumeroCompte() const {
    return numeroCompte;
}

// Mutateur pour définir le numéro de compte
void CompteBancaire::setNumeroCompte(int numero) {
    this->numeroCompte = numero;
}

// Méthode pour afficher les informations complètes du compte bancaire
void CompteBancaire::afficherInfo() const {
    // Affiche les détails du compte : titulaire, numéro et solde
    std::cout << "Titulaire: " << getTitulaire()
              << ", Numero: " << getNumeroCompte()
              << ", Solde: " << getSolde() << " EUR\n";
}

// Méthode pour déposer un montant sur le compte
void CompteBancaire::deposer(double montant) {
    if (montant > 0) { // Vérifie si le montant à déposer est positif
        setSolde(getSolde() + montant); // Met à jour le solde avec le nouveau montant
        std::cout << "Montant validé : " << montant
                  << " EUR. Nouveau solde: " << getSolde() << " EUR\n";
    } else {
        // Message d'erreur pour un montant non valide
        std::cout << "Montant invalide. Impossible de déposer " << montant << " EUR.\n";
    }
}

// Méthode pour retirer un montant du compte
bool CompteBancaire::retirer(double montant) {
    if (montant > 0 && montant <= getSolde()) { // Vérifie que le montant est positif et que le solde est suffisant
        setSolde(getSolde() - montant); // Déduit le montant du solde
        std::cout << "Montant validé : " << montant
                  << " EUR. Nouveau solde: " << getSolde() << " EUR\n";
        return true; // Retrait réussi
    } else {
        // Message d'erreur pour un montant non valide ou un solde insuffisant
        std::cout << "Montant invalide. Solde insuffisant ou montant négatif.\n";
        return false; // Retrait échoué
    }
}

// Méthode pour transférer un montant à un autre compte bancaire
bool CompteBancaire::transferer(CompteBancaire& compteDest, double montant) {
    // Tente de retirer le montant du compte actuel
    if (retirer(montant)) {
        compteDest.deposer(montant); // Dépose le montant dans le compte destinataire si le retrait a réussi
        return true; // Transfert réussi
    }
    return false; // Transfert échoué
}
