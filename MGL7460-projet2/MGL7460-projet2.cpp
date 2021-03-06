#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stdlib.h>

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

int lectureSauvegarde() {
	int sauvegarde;

	ifstream fichier("sauvegarde.txt", ios::in);

	if (fichier){
		string contenu;
		getline(fichier, contenu);
		sauvegarde = atoi(contenu.c_str());
	}
	else {
		cout << "Impossible d'ouvrir le fichier !" << endl;
	}

	return sauvegarde;
}

void ecritureSauvegarde(int sauvegarde) {
	ofstream fichier("sauvegarde.txt", ios::out | ios::trunc);

	if (fichier) {
		fichier << sauvegarde;
		fichier.close();
	}
	else
		cout << "Impossible d'ouvrir le fichier !" << endl;
}

void jeu(int sauvegarde) {
	string motMystere;
	string motMelange;
	string motTentative;
	int tailleListe(recupererListeMot("Dictionnaire.txt").size());

	while (sauvegarde < tailleListe) {

		motMystere = choisirMot(sauvegarde);
		motMelange = melangerLettre(motMystere);

		cout << "Vous etes au niveau " << sauvegarde+1 << " sur " << tailleListe << endl;
		cout << "Quel est ce mot : " << motMelange << endl;

		while (motMystere != motTentative) {
			cin >> motTentative;
			if (motMystere != motTentative) {
				cout << "" << endl;
				cout << "Ce n'est pas ca, reessayez !" << endl;
				cout << "" << endl;
			}
			else {
				cout << "" << endl;
				cout << "Bien joue" << endl;
				cout << "" << endl;
			}
		}
		sauvegarde++;
		ecritureSauvegarde(sauvegarde);
	}
	cout << "Vous avez finis le jeu BRAVO !!!" << endl;
}

void switchMenu(int choixUtilisateur) {
	switch (choixUtilisateur) {
	case 1:
		system("cls");
		jeu(0);
		break;
	case 2:
		system("cls");
		jeu(lectureSauvegarde());

	case 3:
		system("exit");
		break;

	default:
		cout << "Vous n'avez pas entrez un choix valide fermeture de la fenetre" << endl;	
	}
}

void menu() {

	int choixUtilisateur;

	cout << "*****************************  JEU  ***************************" << endl;
	cout << "" << endl;
	cout << "***************************  MOT Mystere  *********************" << endl;
	cout << "" << endl;
	cout << "***************************************************************" << endl;

	cout << "DESCRIPTION DU JEU :" << endl;
	cout << "Le jeu consiste a retrouver un mot dont les lettres ont ete melangees" << endl;
	cout << "Remarque : Les accent ne sont pas pris en compte" << endl;

	cout << "" << endl;
	cout << " Entrez une option au clavier et appuyer sur entree:" << endl;
	cout << " 1- Nouvelle partie" << endl;
	cout << " 2- Charger partie" << endl;
	cout << " 3- Quitter" << endl;

	cin >> choixUtilisateur;
	switchMenu(choixUtilisateur);

}

int main()
{
	menu();
	return 0;
}
