/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main() {
   Date *date = new Date(05,02,2021);
   Date *date2 = new Date(05,01,2021);
   if (date < date2) {cout << "coucou" << endl;}
   cout << *date - *date2;

   //cout << test.jour << "." << test.mois << "." << test.annee;
   //cout << date->jour << "." << date->mois << "." << date->annee;

   return EXIT_SUCCESS;
}