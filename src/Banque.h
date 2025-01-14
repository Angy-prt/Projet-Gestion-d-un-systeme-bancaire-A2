#ifndef BANQUE_H 
#define BANQUE_H

#include <vector>                // Inclusion de la classe standard std::vector pour gérer une collection d'objets
#include "CompteBancaire.h"      // Inclusion de la classe de base CompteBancaire, utilisée pour gérer les comptes

// Classe Banque
// Cette classe gère une collection de comptes bancaires. Elle illustre les concepts suivants :
// - Utilisation de pointeurs pour gérer les objets dynamiques (`CompteBancaire*`).
// - Allocation dynamique de mémoire (création des comptes).
// - Désallocation explicite dans le destructeur pour éviter les fuites mémoire.
// - Encapsulation pour sécuriser les données internes (attribut privé `comptes`).
class Banque {
private:
    std::vector<CompteBancaire*> comptes; 
    // Attribut privé : comptes
    // - Stocke des pointeurs vers des objets `CompteBancaire`.
    // - Utilisation de pointeurs permet de gérer différents types d'objets hérités de `CompteBancaire`
    //   (exemple : `CompteCourant`, `CompteEpargne`), grâce au polymorphisme.

public:
    // Constructeur par défaut
    // - Initialise une instance de la classe Banque sans compte.
    Banque();

    // Destructeur
    // - Libère la mémoire allouée dynamiquement pour les comptes ajoutés.
    // - Important pour éviter les fuites mémoire, car les objets pointés par les pointeurs dans `comptes` doivent être détruits explicitement.
    ~Banque();

    // Méthode : ajouterCompte
    // - Ajoute un nouveau compte à la collection.
    // - Le paramètre est un pointeur vers un objet `CompteBancaire` ou un de ses dérivés.
    // - Ce pointeur est stocké directement dans le vecteur `comptes` (pas de copie de l'objet).
    void ajouterCompte(CompteBancaire* compte);

    // Méthode : rechercherCompteParNumero
    // - Recherche un compte en fonction de son numéro unique.
    // - Parcourt la collection `comptes` pour trouver un compte avec le numéro spécifié.
    // - Retourne un pointeur vers le compte trouvé, ou `nullptr` si aucun compte ne correspond.
    // - La méthode est `const` car elle ne modifie pas l'état de l'objet.
    CompteBancaire* rechercherCompteParNumero(int numero) const;

    // Méthode : afficherComptes
    // - Affiche les informations de tous les comptes bancaires gérés par la banque.
    // - Appelle la méthode `afficherInfo` sur chaque compte (polymorphisme dynamique).
    // - La méthode est `const` car elle ne modifie pas la collection `comptes`.
    void afficherComptes() const;

    // Méthode : initialiserComptes
    // - Permet d'ajouter des comptes avec des données par défaut.
    // - Utilisée pour tester rapidement la classe ou initialiser un état de base.
    void initialiserComptes();
};

#endif // BANQUE_H
