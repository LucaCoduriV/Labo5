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
   Date date2(3,2,2021);
   Date date(1,1,2021);

   unsigned test = -31;
   cout << test << endl;
   cout << "NEW: " << date - date2 << endl;

   return EXIT_SUCCESS;
}