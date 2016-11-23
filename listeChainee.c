#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LL 255

typedef struct cellule{
	char ligne[LL];
	struct cellule * suiv;
}cellule_t;

void lire_clavier(cellule_t** ptDebut, FILE * flux);
void inserV(cellule_t* ptFin, char * v);
void libererListe(cellule_t* ptDebut);
void afficherListe(cellule_t* ptDebut);

int main(){
	cellule_t *liste;
	lire_clavier(&liste,stdin);
	afficherListe(liste);
	libererListe(liste);
	return 1;
}

void lire_clavier(cellule_t** ptDebut, FILE * flux){
	char phrase[LL];
	cellule_t * ptFin;

	fgets(phrase, LL, flux);
	while(!feof(flux)){
		inserV(ptFin,phrase);
		fgets(phrase, LL, flux);
		
	}
}

void afficherListe(cellule_t* ptDebut){
	cellule_t* ptCour = ptDebut;
	while(ptCour != NULL){
		printf("%s\n",&(ptCour->ligne));
		ptCour = ptCour->suiv;
	}
}

void inserV(cellule_t* ptFin, char * v){
	cellule_t * nouv;
	nouv = (cellule_t * ) malloc (sizeof(cellule_t));
	nouv->ligne = (char *) malloc (LL+1);
	strcpy(nouv->ligne, v);
	if(ptFin == NULL) ptFin = nouv;
	else ptFin->suiv = nouv;
	*ptFin = *nouv;
	
}

void libererListe(cellule_t* ptDebut){
	cellule_t * ptTemp;
	while(ptDebut != NULL){
		ptTemp = (*ptDebut)->suiv;
		free(ptDebut);
		ptDebut = ptTemp;
	}
}
