#include <stdio.h>
#include <stdlib.h>


typedef struct sommet {
	char nom;
} //on a cr�e le type sommet
typedef struct arete {
	sommet s1;
	sommet s2;
	int poids;
} arete; //on a cr�e le type ar�te
typedef struct component {
    sommet som[a];
}



int main(void) {

}


void function boruvka(int a,int b) {
component somcom.som[a]; //tableau � 2dim qui contient tout les groupes de sommets adjacents
sommet sommets[a]; //tableau contenant tous les sommets du graphe
arete aretes[b]; //tableau contenant toutes les ar�tes du graphe
arete tabfin[b]; //tableau des ar�tes qui constituerons l'arbre de recouvrement minimal final
s=0;
while (length(somcom)!=[1][a])
{
for (i=0;i<a;i++) //on parcourt tous les elements du tableau, cad tous les groupes de sommets adjacents
	{
	    arete tabAr[b]; //tableau des aretes dont tabsommets[i] est une extrimit�
	    for (j=0;j<b;j++) //on parcourt toutes les aretes du graphes
		    {   k=0;
		        A=0;
		    	for (m=0;m<length(somcom[i]);m++){
		    		for(t=0;t<length(somcom[i]);t++) {
		    		  if (((aretes[j].s1==somcom[i][m])&&(aretes[j].s2==somcom[i][t]))||((aretes[j].s2==somcom[i][m]))&&(aretes[j].s1==somcom[i][t]) )//si il existe dans ce groupe un sommet de cette arete et que l'autre sommet est dans un autre groupe
		               A=1;
		    		}
		    	}
		        if (A=0)
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
        tabfin[s]=areteChoisie; //on ajoute l'ar�te choisie au tableau tabfin
        s++;
    }

}
}
