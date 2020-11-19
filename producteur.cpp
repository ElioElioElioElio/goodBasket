#include "producteur.h"
#include <QDebug>
#include <iostream>
using namespace std;

Producteur::Producteur(DialogueProducteurs &dp):gestionnaireDialogue(dp)
{
    IdGenerator& gen = IdGenerator::Instance();
    int newId = gen.getNewIdProducteur();
    this->id = newId;
    gestionnaireDialogue = dp;
    gestionnaireDialogue.ajouterProducteur(this);
};

void Producteur::demanderAjoutProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    qDebug() << "DemanderAjoutProduit" << endl;
    gestionnaireDialogue.ajouterProduit(prix, quantite, nom, imagePath, this->id);
}

void Producteur::ajouterProduit(int quantite, double prix, std::string nom, std::string imagePath)
{
    IdGenerator& gen = IdGenerator::Instance();
    int idProduit = gen.getNewIdProduit();
    Produit produitAjoute = Produit(idProduit, quantite, prix, nom, imagePath);

    boutique.insert(idProduit,produitAjoute);
}

bool Producteur::produitExiste(int idProduit)
{
    return this->boutique.contains(idProduit);
}

void Producteur::demanderRetirerProduit(int idProduit)
{
    this->gestionnaireDialogue.retirerProduit(idProduit, this->id);
}

const int& Producteur::getId()
{
    return this->id;
}

void Producteur::retirerProduit(int idProduit)
{
    this->boutique.remove(idProduit);
}

void Producteur::setGestionnaireDialogue(DialogueProducteurs dp)
{
    this->gestionnaireDialogue = dp;
}

const std::string  Producteur::toString()
{
    std::string returned = "Producteur [ID-"+std::to_string(this->getId())+"]\n";
    QHashIterator<int,Produit> i(this->boutique);
    while(i.hasNext())
    {
        i.next();
        returned.append("      -(key = "+std::to_string(i.key())+")- ");
        Produit pr = i.value();
        returned.append(pr.toString()+"\n");
    }

    return returned;
}