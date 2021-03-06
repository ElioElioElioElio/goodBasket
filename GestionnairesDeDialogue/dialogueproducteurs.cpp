#include <QtDebug>
#include "dialogueproducteurs.h"

#include "../producteur.h"
#include "../Gestionnaire/gestionnaire.h"

#include <iostream>
using namespace std;

int DialogueProducteurs::nbProducteur(){
    return this->producteurs.size();
}

DialogueProducteurs::DialogueProducteurs()
{
    qDebug() << "Creation Gestionnaire dialogue Producteur" <<endl;
}

void DialogueProducteurs::retirerProduit(int idProduit, int idProducteur)
{
    if(produitExiste(idProduit, idProducteur))
    {
        Producteur* pr = retrouverProducteur(idProducteur);
        pr->retirerProduit(idProduit);
    }
    else
    {
        qDebug() <<"PRODUIT INEXISTANT"<<endl;
    }
}

void DialogueProducteurs::ajouterProduit(double prix, int quantite, std::string nom, std::string imagePath,int producteurId)
{
    qDebug() << "AjoutProduit" << endl;

    if(formulaireOk(prix, quantite, nom,imagePath,producteurId))
    {
        qDebug() << "Formulaire OK" << endl;
        Producteur* pr = retrouverProducteur(producteurId);
        pr->ajouterProduit(quantite, prix, nom, imagePath);
    }
}

void DialogueProducteurs::ajouterProduitBDD(double prix, int quantite, std::string nom,int producteurId)
{
    qDebug() << "AjoutProduit" << endl;

    if(formulaireOkBDD(prix, quantite, nom,producteurId))
    {
        qDebug() << "Formulaire OK" << endl;
        Producteur* pr = retrouverProducteur(producteurId);
        pr->ajouterProduitBDD(quantite, prix, nom);
    }
}

bool DialogueProducteurs::formulaireOk(double prix, int quantite, std::string nom, std::string imagePath, int producteurId)
{
    if(producteurExiste(producteurId) && prix>=0 && quantite >0 && !nom.empty() && !imagePath.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DialogueProducteurs::formulaireOkBDD(double prix, int quantite, std::string nom, int producteurId)
{
    if(producteurExiste(producteurId) && prix>=0 && quantite >0 && !nom.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DialogueProducteurs::producteurExiste(int producteurId)
{
    return producteurs.contains(producteurId);
}

bool DialogueProducteurs::produitExiste(int idProduit, int producteurId)
{
    if(producteurExiste(producteurId))
    {
        Producteur* pr = retrouverProducteur(producteurId);
        return pr->produitExiste(idProduit);
    }
    else
    {
        return false;
    }
}

Producteur* DialogueProducteurs::retrouverProducteur(int producteurId)
{
    return producteurs.value(producteurId);
}

void DialogueProducteurs::ajouterProducteur(Producteur* pr)
{
    producteurs.insert(pr->getId(),pr);
}

void DialogueProducteurs::notifierProducteurPayment(int producteurid,int montant)
{
    std::string s = "vous avez reçu le montant de payment ";
    s = s + to_string(montant);
    producteurs.value(producteurid)->setMessage(s);

}

void DialogueProducteurs::supprimerLivraison(Livraison livraison,int idproducteur)
{
    /*
     * partie de sql
    */
    //this->getProducteurById(idproducteur)->supprimerLivraison(livraison);
    /*
     * notifier le reponsable
    */
}

Producteur* DialogueProducteurs::getProducteurById(int producteurId)
{
    return (producteurExiste(producteurId)) ? retrouverProducteur(producteurId) : nullptr;
}

QHash<int,std::string>& DialogueProducteurs::getDemande(){
    return  this->demande;
}

void DialogueProducteurs::recruteProducteur(int idResponsable,std::string recrutement){
    cout<<recrutement+"(responsable id:"+std::to_string(idResponsable)+")"<<endl;
}

void DialogueProducteurs::recevoirDemande(int idResponsable,int idProducteur,std::string demande){
    this->demande.insert(idProducteur,demande);
}


const std::string DialogueProducteurs::toString()
{
    std::string returned = "Gestionnaire de Dialogue PRODUCTEUR (Nb producteur = ";
    returned.append(to_string(nbProducteur())).append(")\n");
    QHashIterator<int,Producteur*> i(this->producteurs);
    while(i.hasNext())
    {
        i.next();
        returned.append("-(key = "+std::to_string(i.key())+")- ");
        Producteur pr = *i.value();
        returned.append(pr.toString()+"\n");
    }

    return returned;
}

