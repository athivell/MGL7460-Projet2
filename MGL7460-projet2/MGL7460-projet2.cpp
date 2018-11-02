#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

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

vector<string> recupererListeMot(string chemin) {
	string iterateur;
	vector<string> listeMot;
	ifstream dictionnaire(chemin);
	if (dictionnaire) {
		while (dictionnaire >> iterateur) {
			listeMot.push_back(iterateur);
		}
	}
	else {
		cout << "ERREUR : impossible d'ouvrir le fichier";
	}
	return listeMot;
}

string choisirMot(int numeroLigne) {
	vector<string> listeMot = recupererListeMot("Dictionnaire.txt");
	return listeMot[numeroLigne];
}

int main()
{
	//déclaration des variables
	string motMystere;
	string motMelange;
	string motTentative;
	int tailleListe(recupererListeMot("Dictionnaire.txt").size());
	int sauvegarde(0);

	while (sauvegarde < tailleListe){
		
		motMystere = choisirMot(sauvegarde);
		motMelange = melangerLettre(motMystere);
		
		cout << "Vous etes au niveau " << sauvegarde << " sur " << tailleListe << "\n";
		cout << "Quel est ce mot : " << motMelange << "\n";
		
		while (motMystere != motTentative) {
			cin >> motTentative;
			if (motMystere != motTentative) {
				cout << "Ce n'est pas ca, reessayez !\n";
			}
			else {
				cout << "Bien joue\n";
			}
		}
		sauvegarde++;
	}

	return 0;
}
