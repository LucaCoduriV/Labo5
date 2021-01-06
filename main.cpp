/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : Ce module permet de tester les fonctionnalités de la classe Date
                  Deux objets de cette classe sont instanciés afin de tester les
                  différents opérateurs et méthodes de Date.
Remarque(s)     : -
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main() {
   Date date(1,1,2001);
   Date date2(11,9,2057);

   cout << "NEW: " << date - date2 << endl;

   return EXIT_SUCCESS;
}