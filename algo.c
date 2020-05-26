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
	int a;
	int b;
	arete aretes[b]; //tableau contenant toutes les arêtes du graphe
	printf("Combien de sommets contient votre arbre ?\n");
	scanf("%d",&a);
	printf("Combien d'arêtes contient votre arbre ?\n");
	scanf("%d",&b);
	int i=0;
	for (i=0;i<b;b++) {
		printf("Quel est le nom du premier sommet de votre arete numero %d\n",i);
		scanf("%s",&aretes[i].s1.nom);
		printf("Quel est le nom du second sommet de votre arete numero %d\n",i);
		scanf("%s",&aretes[i].s2.nom);
		printf("Quel est le poids de votre arete numero %d\n",i);
		scanf("%d",&aretes[i].poids);

	}
	boruvka(a,b,aretes);
	int j=0;
	printf("L'arbre de recouvrement minimal final est constitué des arêtes suivantes:\n");
	for (j=0;j<b;j++) {
		if(tabfin[j]!=aretenulle)
			printf("%d-%d\n",tabfin[j].s1,tabfin[j].s2);
		else break;
		}
	}



}


void function boruvka(int a,int b,arete aretes[b]) {
sommet somcom[a][a]; //tableau à 2dim qui contient tout les groupes de sommets adjacents
arete tabfin[b]; //tableau des arêtes qui constituerons l'arbre de recouvrement minimal final
arete aretenulle;
int i=0;
for(i=0;i<b;i++) tabfin[i]=aretenulle; //initialisation des éléments du tableau tabfin
s=0;
while (length(somcom)!=[1][a])
{
for (i=0;i<a;i++) //on parcourt tous les elements du tableau, cad tous les groupes de sommets adjacents
	{
	    arete tabAr[b]; //tableau des aretes dont une extrimité est en somcom.som[i] et l'autre extrimité non
	    k=0;
	    for (j=0;j<b;j++) //on parcourt toutes les aretes du graphes
		    {
		        A=1;
		    	for (m=0;m<a;m++){
		    		for(t=0;t<m;t++) {
		    			if (t=i) continue;
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

        arete areteChoisie; //on choisit pour chaque sommet ou groupes de sommets l'arete qui a le poids le plus bas.
        w=tabAr[0].poids;
        for (j=0;j<b;j++)
           {
     	     if (tabAr[j].poids<w)
     	 	     areteChoisie=tabAr[j];
           }
        int u=0;
        int t=0;
        for (u=0;u=b;u++)
          {
        	if (((tabfin[u].s1==areteChoisie.s1)&&(tabfin[u].s2==areteChoisie.s2))||((tabfin[u].s1==areteChoisie.s2)&&(tabfin[u].s2==areteChoisie.s1))) break; //si l'arête est déjà dans le tableau on arrête
        	else if (tabfin[u]=aretenulle) {tabfin[u]= areteChoisie; break;} //on ajoute l'arête choisie au tableau tabfin
          }


        s++;
    }

}
}
