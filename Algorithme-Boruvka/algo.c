#include <stdio.h>
#include <stdlib.h>


typedef struct sommet {
	char nom;
} //on a crée le type sommet
typedef struct arete {
	sommet s1;
	sommet s2;
	int poids;
} arete; //on a crée le type arête

int main(void) {

}
void function boruvka {
	sommet tabsommets[]; //tableau contenant tous les sommets du graphe
	arete tabaretes[]; //tableau contenant toutes les arêtes du graphe
	a=sizeof(tabsommets)/sizeof(tabsommets[0]); //a est la taille du tableau tabsommets
	b=sizeof(tabaretes)/sizeof(tabaretes[0]); //b est la taille du tableau tabaretes
	for (i=0;i<a;i++) //on parcourt tous les elements du tableau, cad tous les sommets du graphe
	{
		for (j=0;j<b;j++) //on parcourt toutes les aretes du graphes
		{
			if ((tabaretes[j].s1==tabsommets[i])||(tabaretes[j].s2==tabsommets[i]))
			{
				tabAr[k]=aretes[j];
				k++;
			}
		}
     		arete areteChoisie; //on choisit pour chaque sommet l'arete qui a le poids le plus bas.
     		w=tabAr[0].poids;
     		for (j=0;j<b;j++)
     		{
     	 		if (tabAr[j].poids<w)
     	 	 	areteChoisie=tabAr[j];
     		}
     		tabfin[s]=areteChoisie; //on ajoute l'arête choisie au tableau tabfin
     		s++;
	}
}
   	
