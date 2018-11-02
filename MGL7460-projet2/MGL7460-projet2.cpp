// PremierProgramme.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string melangerLettre(string parMot) {
	string nouveauMot;
	int position;

	srand(time(0));

	while (parMot.size() != 0) {
		position = rand() % parMot.size();
		nouveauMot += parMot[position];
		parMot.erase(position, 1);
	}

	return nouveauMot;
}

int main()
{
	//déclaration des variables
	string motMystere;
	string motMelange;
	string motTentative;

	//On demande au joueur 1 d'entrer 1 mot 
	cout << "Entrez un mot :\n";
	cin >> motMystere;

	//On melange le mot
	motMelange = melangerLettre(motMystere);

	//On demande au joueur 2 de trouver le mot
	cout << motMelange + "\n";
	while (motMystere != motTentative) {
		cout << "Quel est ce mot ?\n";
		cin >> motTentative;
		if (motMystere != motTentative) {
			cout << "Ce n'est pas le mot\n";
		}
		else {
			cout << "Bien joue\n";
		}


	}
	return 0;
	//je rajoute une modification pour le git
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
