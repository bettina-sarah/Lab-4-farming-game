#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Objets_s
{
	string NomObjet;
	int CreditCost;
	string Capacite;
};

struct Inventaire_s
{
	Objets_s Objet;
	int QuantiteObjet;
};

struct Player_s
{
	string NomComplet;
	int Credits;
	vector <Inventaire_s> InventaireJoueur;
};

void AjouterActionsetCredits(Player_s &Player);
void AchatObjet(vector <Inventaire_s>& marchand, int& indexvectormarchand, int& QuantitePourAcheter, Player_s& Player);

void UtiliserObjet(Player_s& Player, int& indexvectorplayer, int& QuantitePourUtiliser);

void main(void)
{
	vector <Inventaire_s> InventaireObjetsJoueur;

	Player_s Joueur = { "Noob", 50000, InventaireObjetsJoueur};

	vector <Inventaire_s> Marchand = { {{"Pelle", 10000, "Semer légumes"},100}, {{"Arrosoir (1L)", 5000, "Arroser cultures"},100},{{"Grain (1KG)", 6000, "Nourrir animaux"},100} };

	cout << "MARCHAND: INVENTAIRE D'OBJETS\n";
	for (int i = 0; i < 3; i++)
	{
		cout << Marchand[i].Objet.NomObjet << "\t" << Marchand[i].Objet.CreditCost << "\t" << Marchand[i].Objet.Capacite << "\tQuantite disponible: " << Marchand[i].QuantiteObjet << "\n";
	}

	int QuantiteDesireAchat;
	int IndexDesireAchat;
	int QuantiteDesireUtiliser;
	int IndexDesireUtiliser;


	cout << "\nQuel objet a acheter (0,1,2)";
	cin >> IndexDesireAchat;
	cout << "\nCombien d'objets a acheter";
	cin >> QuantiteDesireAchat;
	AchatObjet(Marchand, IndexDesireAchat, QuantiteDesireAchat, Joueur);
	cout << "\n\nCredits joueur: " << Joueur.Credits << "\nName + quantity: ";
	cout << Joueur.InventaireJoueur[0].Objet.NomObjet << Joueur.InventaireJoueur[0].QuantiteObjet;
	cout << "\n\nQuel objet a utiliser? (0,1)";
	cin >> IndexDesireUtiliser;
	cout << "\nCombien a utiliser";
	cin >> QuantiteDesireUtiliser;
	UtiliserObjet(Joueur, IndexDesireUtiliser, QuantiteDesireUtiliser);
	cout << "\n\nCredits joueur: " << Joueur.Credits << "\nName + quantity: ";
	cout << Joueur.InventaireJoueur[0].Objet.NomObjet << Joueur.InventaireJoueur[0].QuantiteObjet;







}

void AjouterActionsetCredits(Player_s &Player) // a chaque action // OK
{
	static int ActionsJoueur = 0;
	ActionsJoueur++;
	if (ActionsJoueur % 3 == 0)
	{
		Player.Credits += 500;
	}
}

void AchatObjet(vector <Inventaire_s> &marchand, int &indexvectormarchand, int &QuantitePourAcheter, Player_s &Player)
{
	if (Player.Credits > marchand[indexvectormarchand].Objet.CreditCost) // joueur a assez credits pour acheter
	{
		Player.InventaireJoueur.push_back({ marchand[indexvectormarchand].Objet, QuantitePourAcheter });
		Player.Credits -= marchand[indexvectormarchand].Objet.CreditCost*QuantitePourAcheter;
	}
	AjouterActionsetCredits(Player);
}

void UtiliserObjet(Player_s& Player, int& indexvectorplayer, int& QuantitePourUtiliser)
{
	if (Player.InventaireJoueur[indexvectorplayer].QuantiteObjet >= QuantitePourUtiliser)
	{
		Player.InventaireJoueur[indexvectorplayer].QuantiteObjet -= QuantitePourUtiliser;

		if (Player.InventaireJoueur[indexvectorplayer].QuantiteObjet == 0)
		{
			Player.InventaireJoueur.erase(Player.InventaireJoueur.begin() + indexvectorplayer);
		}
		AjouterActionsetCredits(Player);
	}
}





