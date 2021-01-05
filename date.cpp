/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.cpp
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "date.h"

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee):jour(jour),
mois(mois),annee(annee) {}

Date Date::operator+(unsigned int jours) {
   return Date(0, 0, 0);
}

Date &Date::operator+=(unsigned int jours) {
   return *this;
}

Date Date::operator-(unsigned int jours) {
   return Date(0, 0, 0);
}

Date &Date::operator-=(unsigned int jours) {
   return *this;
}

unsigned Date::operator-(const Date &date) {
   return 0;
}
