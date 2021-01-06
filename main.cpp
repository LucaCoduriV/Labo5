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
#include <cmath>
#include "date.h"

using namespace std;

int main() {
   Date *date = new Date(1,1,2021);
   Date *date2 = new Date(1,1,2021);

   Date test = *date - 5;

   cout << date;

   return EXIT_SUCCESS;
}