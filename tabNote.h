
#ifndef __TABNOTE__
#define __TABNOTE__

#include <stdlib.h>
#include <stdio.h>

typedef struct note_eleve{
	float noteEl; // note
	int nombreEl; // nombre d'élève
	struct note_eleve* suivant;
}t_frequence;


typedef struct{
	t_frequence* debut;
	t_frequence* fin;
}t_liste;


float* lecture(FILE *fiche,int taille);

float* tabNoteEleve(float note[], int taille);

t_frequence *liste_create(float f, int nb);

t_frequence *append(t_frequence *debut, float f, int nb);

t_frequence *listeDeFrequence(float note[], int taille);

void afficherListe(t_frequence *debutDeListe);

void affichagehisto(t_frequence *debutDeListe);

/*t_liste* liste(float note[], int taille);




t_frequence *liste_create(float f, int nb);
t_frequence *ajout(float note[], int taille);
*/

#endif
