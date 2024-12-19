# 💳 Projet - Gestion de Comptes Bancaires en C++

## 📖 Description

Ce projet implémente un système de gestion bancaire en C++ en utilisant la programmation orientée objet (POO). Le système permet de créer des comptes bancaires, effectuer des dépôts, retraits, transferts et gérer les comptes courants, d'épargne et bancaires avec des fonctionnalités spécifiques pour chaque type de compte.

Il inclut également des tests unitaires pour assurer la robustesse du code, en utilisant **Google Test**.

## 🚀 Fonctionnalités

- **Gestion de comptes bancaires** : Création et gestion de comptes avec possibilité de retirer, déposer et transférer des fonds.
- **Comptes courants** : Possibilité de gérer un découvert autorisé lors des retraits.
- **Comptes épargne** : Calcul des intérêts sur le solde.
- **Recherche de comptes** : Recherche d'un compte par son numéro.
- **Affichage des informations de comptes** : Affichage des informations détaillées des comptes dans la banque.
- **Tests unitaires** : Tests complets des fonctionnalités (dépôt, retrait, transfert, recherche de compte, etc.).

## 🛠 Technologies utilisées

- **Langage** : C++
- **Framework de tests** : Google Test
- **Environnement de développement** : WSL Ubuntu
- **Compilateur** : g++
- **Bibliothèque de gestion des comptes bancaires** : POO en C++

## 📦 Installation et utilisation

### Prérequis

- C++17 ou plus récent
- Google Test pour les tests unitaires

### Instructions

#### 1. Cloner le projet

```bash
git clone https://github.com/Angy-prt/Projet-Gestion-d-un-syteme-bancaire-A2
cd Projet-Gestion-d-un-syteme-bancaire-A2
```
#### 2. Compiler le projet
Dans le répertoire src/, compilez le projet :
```bash
cd src/ && make
```
#### 3. Lancer l'application
Lancez le programme principal avec la commande suivante :
```bash
./main
```
#### 4. Executer les tests unitaires
Si les tests unitaires sont dans un fichier séparé (par exemple, tests.cpp), compilez et exécutez-les comme suit :
```bash
g++ ../src/*.cpp tests.cpp -o tests.exe -lgtest -lgtest_main -pthread
./tests
```
## 🚧 Améliorations possibles

- Ajouter des fonctionnalités pour gérer des prêts ou des cartes de crédit 💳
- Améliorer l'interface graphique pour une gestion plus intuitive des comptes 🖥️
- Ajouter une fonctionnalité pour envoyer des relevés bancaires par email 📧
- Ajouter des alertes pour les transactions importantes ou les soldes faibles 📉

## 👨‍💻 Auteurs

Projet réalisé dans le cadre de la deuxième année à CESI.

**Angy** - Étudiante en développement logiciel 💼
