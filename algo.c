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

void unionAr(sommet a,sommet b,arete aret[]) {
	sommet T[];
	if strcmp(a.nom,b.nom)>0{
		T[0] = a.nom;
		T[1] = b.nom;
	}
	else {
		T[0] = b.nom;
                T[1] = a.nom;
        }
	for (int i=0,i<size_of(aret),i++){
		if (aret[i] == T)
			k = 0;
	    if (k == 1)
		    aret += T;

}
}


int main(void) {
	int a;
	int b;
	arete aretes[b]; //tableau contenant toutes les arêtes du graphe
	printf("Combien de sommets contient votre arbre ?");
	scanf("%d",&a);
	printf("Combien d'arêtes contient votre arbre ?");
	scanf("%d",&b);
	int i=0;
	for (i=0;i<b;b++) {
		printf("Quel est le nom du premier sommet de votre arete numero %d",i);
		scanf("%s",&aretes[i].s1.nom);
		printf("Quel est le nom du second sommet de votre arete numero %d",i);
		scanf("%s",&aretes[i].s2.nom);
		printf("Quel est le poids de votre arete numero %d",i);
		scanf("%d",&aretes[i].poids);
	}


}


void function boruvka(int a,int b,arete aretes[b]) {
sommet somcom[a][a]; //tableau à 2dim qui contient tout les groupes de sommets adjacents
arete tabfin[b]; //tableau des arêtes qui constituerons l'arbre de recouvrement minimal final
s=0;
while (//somcom est vide sauf le premier element)
{
for (i=0;i<a;i++) //on parcourt tous les elements du tableau, cad tous les groupes de sommets adjacents
	{
	    arete tabAr[b]; //tableau des aretes dont une extrimité est en somcom.som[i] et l'autre extrimité non
	    for (j=0;j<b;j++) //on parcourt toutes les aretes du graphes
		    {   k=0;
		        A=1;
		    	for (m=0;m<a;m++){
		    		for(t=0;t<a;t++) {
		    			for (l=0;l<a;l++){
		    		      if (((aretes[j].s1==somcom[i][m])&&(aretes[j].s2==somcom[t][l]))||(((aretes[j].s2==somcom[i][m]))&&(aretes[j].s1==somcom[t][l]))//si un sommet est dans somcom[i] et l'autre sommet non
		                  A=0;
		    		}
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
        unionAr(areteChoisie.s1, areteChoisie.s2 ,tabfin); //on ajoute l'arête choisie au tableau tabfin
        s++;
    }

}
}
