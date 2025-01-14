#include "CompteEpargne.h"  // Inclusion du fichier d'en-tête pour la classe CompteEpargne
#include <iostream>         // Inclusion de la bibliothèque standard pour les entrées/sorties

// Constructeur par défaut :
// Ce constructeur initialise un compte épargne avec des valeurs par défaut.
// - `CompteBancaire()` : Appelle le constructeur par défaut de la classe de base pour initialiser les attributs hérités.
// - `tauxInteret(0.0)` : Initialise le taux d'intérêt à 0%.
CompteEpargne::CompteEpargne()
    : CompteBancaire(), tauxInteret(0.0) {}

// Constructeur paramétré :
// Ce constructeur permet de créer un compte épargne avec des valeurs spécifiques.
// - `CompteBancaire(titulaire, solde, numeroCompte)` : Appelle le constructeur paramétré de la classe de base pour initialiser les attributs hérités (`titulaire`, `solde`, et `numeroCompte`).
// - `tauxInteret(tauxInteret)` : Initialise l'attribut spécifique `tauxInteret`.
CompteEpargne::CompteEpargne(const std::string& titulaire, double solde, int numeroCompte, double tauxInteret)
    : CompteBancaire(titulaire, solde, numeroCompte), tauxInteret(tauxInteret) {}


// Destructeur :
// Détruit l'objet CompteEpargne. Ici, il n'y a pas d'allocation dynamique de mémoire, donc ce destructeur ne fait rien de spécifique.
// Le destructeur de la classe de base est appelé automatiquement pour nettoyer les ressources associées à `CompteBancaire`.
CompteEpargne::~CompteEpargne() {}

// Accesseur : `getTauxInteret`
// Retourne la valeur du taux d'intérêt sous forme de pourcentage (exemple : 2.5 pour 2,5%).
double CompteEpargne::getTauxInteret() const {
    return tauxInteret;
}

// Mutateur : `setTauxInteret`
// Permet de définir une nouvelle valeur pour le taux d'intérêt.
// - `taux` : Le nouveau taux d'intérêt (en pourcentage).
void CompteEpargne::setTauxInteret(double taux) {
    tauxInteret = taux; // Mise à jour de l'attribut `tauxInteret`
}

// Méthode : `calculerInteret`
// Cette méthode calcule les intérêts en fonction du taux d'intérêt actuel et du solde du compte, puis les ajoute au solde.
// - Le calcul se fait en multipliant le solde par le taux d'intérêt divisé par 100.
// - L'intérêt calculé est ajouté au solde via `setSolde`.
// - La méthode affiche les détails de l'intérêt calculé et le nouveau solde.
void CompteEpargne::calculerInteret() {
    double interet = getSolde() * (getTauxInteret() / 100.0); // Calcul des intérêts
    setSolde(getSolde() + interet); // Mise à jour du solde avec les intérêts
    std::cout << "Intérêts calculés: " << interet
              << " EUR. Nouveau solde: " << getSolde() << " EUR\n";
}

// Méthode : `afficherInfo`
// Cette méthode redéfinit (`override`) la méthode `afficherInfo` de la classe de base.
// - Elle appelle d'abord la méthode `afficherInfo` de la classe `CompteBancaire` pour afficher les informations générales du compte.
// - Elle ajoute ensuite l'affichage du taux d'intérêt spécifique au compte épargne.
void CompteEpargne::afficherInfo() const {
    CompteBancaire::afficherInfo(); // Appel à la méthode de la classe de base pour afficher le titulaire, le solde et le numéro
    std::cout << "Taux d'Interet: " << getTauxInteret() << "%\n"; // Affichage du taux d'intérêt
}
