#include "Banque.h"               // Inclusion de l'en-tête Banque pour implémenter les méthodes de la classe
#include "CompteCourant.h"        // Inclusion de CompteCourant pour créer des objets spécifiques
#include "CompteEpargne.h"        // Inclusion de CompteEpargne pour créer des objets spécifiques
#include <iostream>               // Inclusion pour utiliser std::cout et std::endl

// Constructeur par défaut
// - Ce constructeur initialise la banque en appelant `initialiserComptes`.
// - Les comptes sont créés dynamiquement et ajoutés à la collection.
Banque::Banque() {
    initialiserComptes();
}

// Destructeur
// - Libère la mémoire allouée dynamiquement pour tous les comptes.
// - La boucle `for` parcourt chaque pointeur dans le vecteur `comptes` et libère la mémoire avec `delete`.
// - `comptes.clear()` vide le vecteur après avoir supprimé les comptes.
Banque::~Banque() {
    for (auto compte : comptes) {  // Parcourt chaque pointeur dans le vecteur
        delete compte;             // Libère la mémoire allouée dynamiquement pour chaque compte (Désallocation dynamique)
    }
    comptes.clear();               // Vide la collection pour éviter les références pendantes
}

// ajouterCompte
// - Ajoute un pointeur vers un compte bancaire (ou un dérivé) au vecteur `comptes`.
// - La méthode ne crée pas le compte, elle ne fait que le stocker dans la collection.
void Banque::ajouterCompte(CompteBancaire* compte) {
    comptes.push_back(compte); // Ajoute le pointeur au vecteur (Utilisation de pointeur)
}

// rechercherCompteParNumero
// - Recherche un compte en fonction de son numéro unique.
// - Parcourt tous les comptes dans le vecteur `comptes`.
// - Si un compte avec le numéro spécifié est trouvé, retourne un pointeur vers ce compte.
// - Si aucun compte ne correspond, retourne `nullptr`.
CompteBancaire* Banque::rechercherCompteParNumero(int numero) const {
    for (auto compte : comptes) {                  // Parcourt tous les comptes
        if (compte->getNumeroCompte() == numero) { // Vérifie si le numéro correspond
            return compte;                         // Retourne le pointeur si trouvé (Utilisation de pointeur)
        }
    }
    return nullptr; // Retourne nullptr si aucun compte ne correspond
}

// afficherComptes
// - Affiche les informations de tous les comptes dans la banque.
// - Si la banque ne contient aucun compte, affiche un message indiquant que la collection est vide.
// - Utilise le polymorphisme pour appeler la méthode `afficherInfo` des classes dérivées.
void Banque::afficherComptes() const {
    if (comptes.empty()) { // Vérifie si le vecteur est vide
        std::cout << "Aucun compte dans la banque.\n";
        return;
    }

    for (auto compte : comptes) { // Parcourt tous les comptes
        compte->afficherInfo();   // Appelle la méthode afficherInfo de chaque compte (polymorphisme)
    }
}

// initialiserComptes
// - Crée des comptes avec des données par défaut pour tester ou initialiser la banque.
// - Utilise `new` pour allouer dynamiquement chaque compte.
// - Les comptes sont ajoutés à la collection avec `ajouterCompte`.
// - La mémoire allouée est gérée dans le destructeur de la classe `Banque`.
void Banque::initialiserComptes() {
    // Création d'un compte courant avec un titulaire, un solde, un numéro de compte et un découvert autorisé
    auto compte1 = new CompteCourant("Alice Dupont", 1500.0, 10000001, 50.0); // Allocation dynamique (Utilisation de new)
    ajouterCompte(compte1); // Ajoute le compte à la collection

    // Création d'un compte épargne avec un titulaire, un solde, un numéro de compte et un taux d'intérêt
    auto compte2 = new CompteEpargne("Alice Dupont", 5000.0, 10000002, 3.0);  // Allocation dynamique (Utilisation de new)
    ajouterCompte(compte2);

    // Création d'un autre compte courant
    auto compte3 = new CompteCourant("Bob Martin", 1200.0, 10000003, 100.0); // Allocation dynamique (Utilisation de new)
    ajouterCompte(compte3);

    // Création d'un autre compte épargne
    auto compte4 = new CompteEpargne("Bob Martin", 3000.0, 10000004, 2.5);  // Allocation dynamique (Utilisation de new)
    ajouterCompte(compte4);
}
