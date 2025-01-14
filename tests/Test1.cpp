// Inclusion des fichiers nécessaires pour tester les classes que nous avons définies précédemment.
#include "CompteBancaire.h"  // Inclut la classe CompteBancaire
#include "CompteEpargne.h"   // Inclut la classe CompteEpargne (hérite de CompteBancaire)
#include "CompteCourant.h"   // Inclut la classe CompteCourant (hérite de CompteBancaire)
#include "Banque.h"          // Inclut la classe Banque qui gère les comptes
#include <gtest/gtest.h>     // Inclusion de la bibliothèque Google Test pour l'écriture de tests unitaires

// Définition du premier test : Test de création d'un compte bancaire
TEST(CompteBancaireTest, CreationCompte) {
    // Création d'un compte bancaire avec un titulaire, un solde et un numéro de compte
    CompteBancaire compte("John Doe", 1000.0, 12345);
    
    // Vérifie que le titulaire du compte est bien "John Doe"
    EXPECT_EQ(compte.getTitulaire(), "John Doe");
    // Vérifie que le solde du compte est bien 1000.0
    EXPECT_EQ(compte.getSolde(), 1000.0);
    // Vérifie que le numéro de compte est bien 12345
    EXPECT_EQ(compte.getNumeroCompte(), 12345);
}

// Test pour vérifier le fonctionnement des setters et getters
TEST(CompteBancaireTest, SettersGetters) {
    // Création d'un compte bancaire avec un titulaire, un solde et un numéro
    CompteBancaire compte("Jane Doe", 500.0, 67890);
    
    // Modification des informations du compte via les setters
    compte.setTitulaire("Jack Doe"); // Change le titulaire
    compte.setSolde(1000.0);         // Change le solde
    compte.setNumeroCompte(54321);   // Change le numéro de compte
    
    // Vérification que les informations ont bien été modifiées
    EXPECT_EQ(compte.getTitulaire(), "Jack Doe");
    EXPECT_EQ(compte.getSolde(), 1000.0);
    EXPECT_EQ(compte.getNumeroCompte(), 54321);
}

// Test de la méthode de dépôt sur un compte bancaire
TEST(CompteBancaireTest, Depot) {
    // Création d'un compte bancaire
    CompteBancaire compte("Jane Doe", 500.0, 67890);
    
    // Dépôt valide de 200.0 sur le compte
    compte.deposer(200.0);
    EXPECT_EQ(compte.getSolde(), 700.0);  // Le solde devrait être 700.0

    // Tentative de dépôt d'un montant invalide (-100.0), cela ne doit pas affecter le solde
    compte.deposer(-100.0);
    EXPECT_EQ(compte.getSolde(), 700.0);  // Le solde ne change pas
}

// Test de la méthode de retrait d'un compte bancaire
TEST(CompteBancaireTest, Retrait) {
    // Création d'un compte bancaire
    CompteBancaire compte("Jane Doe", 500.0, 67890);
    
    // Retrait valide de 300.0, le solde devient 200.0
    EXPECT_TRUE(compte.retirer(300.0));
    EXPECT_EQ(compte.getSolde(), 200.0);
    
    // Tentative de retrait d'un montant supérieur au solde, ce qui échoue
    EXPECT_FALSE(compte.retirer(1000.0));  // Solde insuffisant
}

// Test de la méthode de transfert entre comptes bancaires
TEST(CompteBancaireTest, Transfert) {
    // Création de deux comptes bancaires
    CompteBancaire compte1("Alice", 1000.0, 1);
    CompteBancaire compte2("Bob", 500.0, 2);
    
    // Transfert de 300.0 du compte1 vers le compte2
    EXPECT_TRUE(compte1.transferer(compte2, 300.0));
    EXPECT_EQ(compte1.getSolde(), 700.0);  // Solde de Alice après transfert
    EXPECT_EQ(compte2.getSolde(), 800.0);  // Solde de Bob après réception
    
    // Tentative de transfert d'un montant supérieur au solde, ce qui échoue
    EXPECT_FALSE(compte1.transferer(compte2, 1000.0));  // Solde insuffisant
}

// Test de calcul des intérêts pour un compte épargne
TEST(CompteEpargneTest, CalculInteret) {
    // Création d'un compte épargne avec un taux d'intérêt de 5%
    CompteEpargne compte("Charlie", 1000.0, 3, 5.0);
    
    // Calcul des intérêts et ajout au solde
    compte.calculerInteret();
    EXPECT_EQ(compte.getSolde(), 1050.0);  // Solde après ajout des intérêts
}

// Test des setters et getters pour un compte épargne
TEST(CompteEpargneTest, SettersGettersCompteEpargne) {
    // Création d'un compte épargne avec un taux d'intérêt initial de 3%
    CompteEpargne compte("Alice", 5000.0, 1, 3.0);
    
    // Modification du taux d'intérêt
    compte.setTauxInteret(4.0);
    
    // Vérification que le taux d'intérêt a bien été modifié
    EXPECT_EQ(compte.getTauxInteret(), 4.0);
}

// Test de la gestion du découvert autorisé pour un compte courant
TEST(CompteCourantTest, DecouvertAutorise) {
    // Création d'un compte courant avec un découvert autorisé de 200.0
    CompteCourant compte("David", 500.0, 4, 200.0);
    
    // Retrait valide avec le découvert autorisé, le solde devient -100.0
    EXPECT_TRUE(compte.retirer(600.0));
    EXPECT_EQ(compte.getSolde(), -100.0);
    
    // Tentative de retrait qui dépasse le découvert autorisé, échoue
    EXPECT_FALSE(compte.retirer(700.0));  // Dépassement du découvert
}

// Test de création d'un compte courant
TEST(CompteCourantTest, CreationCompteCourant) {
    // Création d'un compte courant avec un solde initial de 1500.0 et un découvert autorisé de 500.0
    CompteCourant compte("Eve", 1500.0, 5, 500.0);
    
    // Vérification des informations du compte courant
    EXPECT_EQ(compte.getTitulaire(), "Eve");
    EXPECT_EQ(compte.getSolde(), 1500.0);
    EXPECT_EQ(compte.getNumeroCompte(), 5);
    EXPECT_EQ(compte.getDecouvertAutorise(), 500.0);
}

// Test d'affichage des informations d'un compte courant
TEST(CompteCourantTest, AffichageInfoCompteCourant) {
    // Création d'un compte courant
    CompteCourant compte("Eve", 1500.0, 5, 500.0);
    
    // Capture de la sortie standard pour vérifier l'affichage
    testing::internal::CaptureStdout();
    compte.afficherInfo();
    
    // Récupération de la sortie capturée
    std::string output = testing::internal::GetCapturedStdout();
    
    // Vérification que l'information sur le découvert autorisé est présente dans la sortie
    EXPECT_TRUE(output.find("Decouvert Autorise: 500") != std::string::npos);
}

// Test de la gestion des comptes dans la Banque
TEST(BanqueTest, GestionComptes) {
    Banque banque;

    // Création et ajout de comptes
    CompteEpargne* compteEpargne = new CompteEpargne("Alice", 2000.0, 1, 3.5);
    CompteCourant* compteCourant = new CompteCourant("Bob", 1000.0, 2, 500.0);
    banque.ajouterCompte(compteEpargne);
    banque.ajouterCompte(compteCourant);

    // Recherche d'un compte par numéro
    CompteBancaire* compteTrouve = banque.rechercherCompteParNumero(1);
    EXPECT_EQ(compteTrouve->getTitulaire(), "Alice");

    // Affichage de tous les comptes
    testing::internal::CaptureStdout();
    banque.afficherComptes();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Alice") != std::string::npos);
    EXPECT_TRUE(output.find("Bob") != std::string::npos);
}

// Test de l'initialisation des comptes dans la Banque
TEST(BanqueTest, InitialisationComptes) {
    Banque banque;
    // La banque initialise déjà des comptes avec la fonction initialiserComptes
    testing::internal::CaptureStdout();
    banque.afficherComptes();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Alice Dupont") != std::string::npos);
    EXPECT_TRUE(output.find("Bob Martin") != std::string::npos);
}

// Test de l'ajout d'un compte avec un solde et un titulaire
TEST(BanqueTest, AjouterCompte) {
    Banque banque;
    CompteBancaire* compte = new CompteBancaire("John Doe", 5000.0, 99999);
    banque.ajouterCompte(compte);
    CompteBancaire* compteTrouve = banque.rechercherCompteParNumero(99999);
    EXPECT_EQ(compteTrouve->getTitulaire(), "John Doe");
    EXPECT_EQ(compteTrouve->getSolde(), 5000.0);
}

// Test de la destruction des comptes dans la Banque (vérification de la suppression)
TEST(BanqueTest, DestructionBanque) {
    {
        Banque banque;
        CompteBancaire* compte1 = new CompteBancaire("Alice", 1000.0, 1);
        banque.ajouterCompte(compte1);
    } // Le destructeur de la banque sera appelé ici et les comptes doivent être supprimés
}

int main(int argc, char **argv) {
    // Déclare une fonction principale standard pour un programme C++.
    // `argc` : le nombre d'arguments passés au programme depuis la ligne de commande.
    // `argv` : un tableau de chaînes de caractères contenant les arguments.

    ::testing::InitGoogleTest(&argc, argv);
    // Cette ligne initialise Google Test, une bibliothèque de tests unitaires pour C++.
    // `&argc` et `argv` sont transmis pour permettre à Google Test de traiter les arguments de ligne de commande spécifiques à ses options.
    // Cela configure correctement l'environnement de test.

    return RUN_ALL_TESTS();
    // Cette fonction exécute tous les tests définis dans le programme.
    // Elle retourne un code de sortie :
    // - 0 si tous les tests réussissent.
    // Cela permet de déterminer rapidement si le programme passe tous ses tests.

}
