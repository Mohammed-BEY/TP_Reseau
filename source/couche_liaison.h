#ifndef COUCHE_LIAISON_H_INCLUDED
#define COUCHE_LIAISON_H_INCLUDED

#include "couche_physique.h"
#include <stdio.h>
#include <stdlib.h>
#include <libnet.h>
#include <stdint.h>
//Mode non connecte

/*Transferer une unite de donnees*/
void emettre_sur_liaison(char* adr_src,char* adr_dest,char* msg,int lg_msg);
/*Recuperer une unite de donnees*/
int recevoir_de_liaison(char* adr_src,char* adr_dest,char* msg);

//Mode connecte

/*Etablissement d'une connexion*/
int etablir_connexion_liaison(char* adr_src,char* adr_dest);
/*Pour notifier d'une demande de connexion*/
void recevoir_demande_connexion_liaison(char* adr_src,char* adr_dest);
/*Pour repondre a une notification*/
void repondre_demande_connexion_liaison(int reponse);
/*Pour transferer une unité de donnees*/
void emettre_sur_liaison_connectee(char* msg,int lg_msg);
/*Pour recevoir un unite de donnees*/
int recevoir_de_liaison_connectee(char* msg);
/*Pour mettre fin a une connexion*/
void terminer_connexion_liaison();
/*Pour de notification d'une fermeture de connexion*/
void recevoir_terminaison_connexion_liaison();


//La structure
#define MTU 20

#define CONNECT_REQUEST 0
#define CONNECT_ACCEPT 1
#define CONNECT_DENY 2
#define DISCONNECT_REQUEST 3
#define TANSFERT_PDU 4
#define TANSFERT_PDU_SUCCESS 5
#define TANSFERT_PDU_FAIL 6
#define OTHER 7

typedef struct Trame{
    uint8_t deb_trame;
    char adr_dst[6];
    char adr_src[6];
    uint8_t ctrl;
    uint8_t num_seq;
    uint8_t lg_info;
    char  info[MTU];
    char fcs;
    uint8_t fin_trame;
}











#endif // COUCHE_LIAISON_H_INCLUDED
