#include <stdlib.h>
#include <stdio.h>
#include "tabNote.h"





float* lecture(FILE *fiche, int taille){

	//ouverture de fiche et mettre les notes dans un tableau
	float *note;
	note = malloc (sizeof(float)*taille);
	for (int i=0; i< taille; i++){
		fscanf(fiche, "%f", &note[i]);
	}
	fclose(fiche);
	return note;

}




/* classer le tableau de note des élèves en l'ordre croissant
*
*
*
*
*
*/
float* tabNoteEleve(float note[], int taille){

	float min; // la note
	//int cpt=0; // le compteur pour le nombre de l'élève a obtenu la même note

	// on met les notes obetenues des élèves en l'ordre croissant
	for (int i = 0; i < taille-1; i++){
		min = note[i];
		for (int j = i+1; j < taille; j++){
			if ( min > note[j]){
				min = note[j];
				note[j] = note[i];
				note[i] = min;
			}
		}
	}
	return note;
}

t_frequence *liste_create(float f, int nb){
	t_frequence* liste = malloc(sizeof(t_frequence));
	if (liste)
	{
		liste -> noteEl = f;
		liste -> nombreEl = nb;
		liste -> suivant = NULL;
	}
	return liste;
}

/* Ajouter un élément à la fin de la liste chainée
*
*
*
*
*
*/
t_frequence *append(t_frequence *debut, float f, int nb){

	t_frequence *nouveau = malloc(sizeof(t_frequence));

	if (nouveau != NULL){
		nouveau = liste_create(f, nb);

		if ( debut == NULL){
			debut = nouveau;
		}
		else{
			t_frequence *inter = debut;
			while (inter -> suivant != NULL){
				inter = inter -> suivant;
			}
			inter -> suivant = nouveau;
		}
	}
	return debut;
}


/* Construit une liste de la fréquence des notes de 150 élèves
*
*
*
*
*
*
*
*/
t_frequence *listeDeFrequence(float note[], int taille)
{
	float n = note[0];
	int cpt = 1;
	int change = 0;
	t_frequence *debutDeListe = NULL;

	for (int i = 1; i < taille; i++){

		if (note[i] == n){
			cpt ++;
		}else {
			change ++ ;
		}

		if ((change == 1) && (debutDeListe == NULL)){
			printf(" *******\n");
			debutDeListe = append (debutDeListe, n, cpt);
			n = note[i];
		}
		else if(( change != 1) && (debutDeListe != NULL) && (note[i] != n))
		{
			debutDeListe = append(debutDeListe, n, cpt);
			n = note[i];
			cpt = 1;
		}
	}
	debutDeListe = append(debutDeListe, n, cpt);

	return debutDeListe;

}



/*l'affichage de la liste de la fréquence de 150 élèves
*
*
*
*
*
*
*/
void afficherListe(t_frequence *debutDeListe){

    if (debutDeListe == NULL){
        exit(EXIT_FAILURE);
    }

    t_frequence *actuel = debutDeListe;

    while (actuel != NULL)
    {
        printf("\nPour %.2f , il y a %d élèves.", actuel -> noteEl, actuel -> nombreEl);
        actuel = actuel -> suivant;
    }
		printf("\n");
}

void affichagehisto(t_frequence *debutDeListe){
	if(debutDeListe == NULL){
		EXIT_FAILURE;
	}
	t_frequence *actuel= debutDeListe;

	while (actuel != NULL){
		printf ("%.2f || ",actuel->noteEl );
		for (int i=0; i< actuel->nombreEl; i++){
			printf ("%c ", '*');
		}
		printf ("\n");
		actuel = actuel->suivant;
	}
}
