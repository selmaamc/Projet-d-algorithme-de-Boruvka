#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct {
	char nom;
}sommet; //on a crÈe le type sommet*/
typedef struct {
	 char *s1;
	 char *s2;
	int poids;
} arete;

int chercher(char sommet[10], char *a)
{
	for (int i = 0, i<10 ,i++)
	{
		if ( sommet[i] == a)
			return 0;
	}
	return 1;
}


void solution_naive(int a, int s, arete art[10], int sommet[10])
{
	int k = arete[0].poids;
	int p;
	int n;
	char sommet[s];
	char *b = arete[0].s1; //
	arete tabfin[a]
	while (i<s)
	{
		sommet[i] = b;
		for (int j=0, j<a, j++)
		{
			if (((arete[j].s1 == b) && (recherche (sommet, arete[j].s2) == 1)) || ((arete[j].s2 == b)&&(recherche (sommet, arete[j].s2) == 1))&&(arete[j].poids <= k))
			{
				k = arete[j].poids;
				n = j;	
			}
		}
		Tabfin += arete[n];
		p += k;
		if (arete[n].s1 == b)
			b = arete[n].s2;
		else b = arete[n].s1;
		i++;
	}
}


