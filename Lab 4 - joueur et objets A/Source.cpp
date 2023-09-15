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

void AjouterCredits(Player_s &Player);
void AchatObjet(Inventaire_s& marchand, int& indexvectormarchand, int& QuantitePourAcheter, Player_s& Player);

void main(void)
{
	vector <Inventaire_s> InventaireObjetsJoueur;
	Player_s Joueur = { "Noob", 50000, InventaireObjetsJoueur};
	vector <Inventaire_s> Marchand = { {{"Pelle", 10000, "Semer légumes"},100}, {{"Arrosoir (1L)", 5000, "Arroser cultures"},100},{{"Grain (1KG)", 6000, "Nourrir animaux"},100} };

	AjouterCredits(Joueur);
	AjouterCredits(Joueur);
	AjouterCredits(Joueur);
	AjouterCredits(Joueur);
	cout << Joueur.Credits;
}

void AjouterCredits(Player_s &Player) // a chaque action // OK
{
	static int ActionsJoueur = 0;
	ActionsJoueur++;
	if (ActionsJoueur % 3 == 0)
	{
		Player.Credits += 500;
	}
}

void AchatObjet(Inventaire_s &marchand, int &indexvectormarchand, int &QuantitePourAcheter, Player_s &Player)
{
	if (Player.Credits > marchand.Objet.CreditCost)
	{
		
	}

}