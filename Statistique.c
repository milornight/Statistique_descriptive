#include <stdlib.h>
#include <stdio.h>
#include "tabNote.h"

int main(){
  	FILE* fichier;
    fichier = fopen("notes.txt","r");
    if (fichier == NULL){
      printf("fichier est vide");
      return EXIT_FAILURE;
    }
    int taille = 150;
    float *n1 = lecture(fichier,taille);
    float *n2 = tabNoteEleve(n1,taille);

    for (int i =0; i < taille; i++){
      printf("%.2f ", n2[i]);
    }
    //t_liste* liste1= liste(n2, taille);
    //t_frequence* liste1 = ajout(n2,taille)
    t_frequence *liste1 = listeDeFrequence(n2,taille);
    afficherListe(liste1);
    affichagehisto(liste1);
    return 1;
  }
