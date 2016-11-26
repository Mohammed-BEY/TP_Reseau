#ifndef COUCHE_PHYSIQUE_H_INCLUDED
#define COUCHE_PHYSIQUE_H_INCLUDED

/*Reception d'une trame arrivee*/
void de_canal(void *trame,int taille);
/*Emission d'une trame */
void vers_canal(void *trame,int taille);
/*Attendre un evenement*/
int attendre();
/*Demarre le timer numero n(0<n<100
qui s'arrete apres ms millisecondes(ms doit etre multiple de 100)
*/
void depart_compteur(int n,int ms);
/*Arrete le timer numero n*/
void arreter_compteur(int n);

#endif // COUCHE_PHYSIQUE_H_INCLUDED
