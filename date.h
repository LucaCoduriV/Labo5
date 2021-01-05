/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.h
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO5_DATE_H
#define LABO5_DATE_H


class Date {
public:
   Date(unsigned int jour, unsigned int mois, unsigned int annee);
private:
   unsigned int jour;
   unsigned int mois;
   unsigned int annee;
};


#endif
