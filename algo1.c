#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*typedef struct {
	char nom;
}sommet; //on a crée le type sommet*/
typedef struct {
	 char *s1;
	 char *s2;
	int *poids;
} arete; //on a crée le type arête



void  boruvka(int a,int b,arete aretes[]) {
	char *somcom[a][a]; //tableau à 2dim qui contient tout les groupes de sommets adjacents
	//int y=sizeof(*somcom);
	int y=sizeof(*somcom)/8; 
	arete tabfin[b]; //tableau des arêtes qui constituerons l'arbre de recouvrement minimal final
	arete aretenulle;
	char e='0';
	aretenulle.s1=&e;
	aretenulle.s2=&e;
	int f;
	aretenulle.poids=&f;
	int r=0;
	for(r=0;r<b;r++) 
			tabfin[r]=aretenulle; //initialisation des éléments du tableau tabfin
	int s=0;
	while (y!=1)
		{
			int i=0;
			for (i=0;i<y;i++) //on parcourt tous les elements du tableau, cad tous les groupes de sommets adjacents
			{
	    		arete tabAr[b]; //tableau des aretes dont une extrimité est en somcom[i] et l'autre extrimité non
	    		int k=0;
				int j=0;
	    		for ( j=0;j<b;j++) //on parcourt toutes les aretes du graphes
		    		{
		        	int A=1;
					int m=0;
		    		for (m=0;m<a;m++){
					int t=0;
		    			for(t=0;t<m;t++) {
		    				if (t==i) continue;
							int l;
		    				for (l=0;l<a;l++){
		    		      			if (((strcmp(aretes[j].s1,somcom[i][m])==0)&&(strcmp(aretes[j].s2,somcom[t][l])==0))||((strcmp(aretes[j].s2,somcom[i][m])==0)&&(strcmp(aretes[j].s1,somcom[t][l])==0)))//si un sommet est dans somcom[i] et l'autre sommet non
		                 				 A=0;
		    				}
		    			}
		    		}
		        	if (A==0)
		              	{
				      tabAr[k]=aretes[j];
				      k++;
		                }
		          }
		    int *w;
        	arete areteChoisie; //on choisit pour chaque groupe de sommets l'arete qui a le poids le plus bas.
        	w=tabAr[0].poids;
        	for (j=0;j<b;j++)
           	{
     	   		 if (tabAr[j].poids<w)
     	 	     		areteChoisie=tabAr[j];
           	}
        	int u=0;
        	int t=0;
        	
        	
        	
        	printf("s1: %c s2: %c",&areteChoisie.s1,&areteChoisie.s2);
        	for (u=0;u<b;u++)
          	{   if (((strcmp(tabfin[u].s1,areteChoisie.s1)==0)&&(strcmp(tabfin[u].s2,areteChoisie.s2)==0))||((strcmp(tabfin[u].s1,areteChoisie.s2)==0)&&(strcmp(tabfin[u].s2,areteChoisie.s1)==0)))
				      break; //si l'arête est déjà dans le tableau on arrête
				else if(((strcmp(tabfin[u].s1,aretenulle.s1))!=0)&&((strcmp(tabfin[u].s2,aretenulle.s2))!=0)&&(tabfin[u].poids!=aretenulle.poids)) 
					{ t=u;
				      tabfin[t]= areteChoisie;
				      break;} //on ajoute l'arête choisie au tableau tabfin
		    }
        	s++;
        int som1,som2; //indices des sous tableaux contenant le premier et le deuxiéme sommet
        int o=0;
        for (o=0;o<a;o++){ //boucle pour determiner som1 et som2
        	int p=0;
        	for (p=0;p<a;p++){
        		if(somcom[o][p]==areteChoisie.s1) 
        			som1=o;
				else if (somcom[o][p]==areteChoisie.s2)
					som2=o;
			}
		}
		char z='0'; 
        int x=0,v=0; //v est le premier element nul du tableau somcom[som1]
        for (x=0;x<a;u++){ //boucle pour determiner v
        	
        	if(somcom[som1][x]==&z) {
        		v=x;
        		break;
			}
		}
        
        int h=0;
        for(h=0;h<a;h++){
        	if (somcom[som2][h]!=&z){
        		somcom[som1][v]=somcom[som2][h];
        		v++;
			}
		} //cette boucle ajoute les elements de somcom[som2] aux élements de somcom[som1]
		//cela permet de fusionner les sommets aretechoisie.s1 et aretechoisie.s2 et leurs sommets adjacents
		int ab=0;
		for (ab=0;ab<a;ab++)
		 somcom[som2][ab]=somcom[y][ab];
		y--;
		
		}
	}

	        int j=0;
	        printf("L'arbre de recouvrement minimal final est constitue des aretes suivantes:\n");
	        for (j=0;j<b;j++) {
	                if(((strcmp(tabfin[j].s1,aretenulle.s1))!=0)&&((strcmp(tabfin[j].s2,aretenulle.s2))!=0)&&(tabfin[j].poids!=aretenulle.poids)) {
					        arete t=tabfin[j];
					        char *s1=(tabfin[j].s1);
					        char *s2=(tabfin[j].s2);
	                        printf("%c-%c\n",*s1,*s2);
	                }
}
}
int main(void) {
        int a;
        int b;
        printf("Combien de sommets contient votre arbre ?\n");
        scanf("%d",&a);
        printf("Combien d'aretes contient votre arbre ?\n");
        scanf("%d",&b);
        arete aretes[b]; //tableau contenant toutes les arêtes du graphe
        int i=0;
        for (i=1;i<b+1;i++) {
        		char x,y;
        		int p;
                printf("Quel est le nom du premier sommet de votre arete numero %d\n",i);
                fflush(stdin);
				scanf("%c",&x);
				aretes[i].s1=&x;
                printf("Quel est le nom du second sommet de votre arete numero %d\n",i);
                fflush(stdin);
				scanf("%c",&y);
				aretes[i].s2=&y;
				printf("Quel est le poids de votre arete numero %d\n",i);
                fflush(stdin);
				scanf("%d",&p);
				aretes[i].poids=&p;
                

        }
        boruvka(a,b,aretes);
        
}

