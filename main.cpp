/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date création   : 05.01.2021

Description     : Ce module met en oeuvre le test des fonctionnalités de la
                  classe Date. Trois objets de cette classe sont instanciés afin
                  de tester les différents opérateurs et méthodes de Date.

Remarque(s)     : -

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "date.h"

using namespace std;

int main() {

    Date date1(1, 1, 2021);
    Date date2(11, 9, 2057);
    Date date3(1, 1, 2021);

    // Test des accesseurs
    cout << "Jour de " << date1 << " : " << date1.getJour() << endl;
    date1.setJour(3);
    cout << "Nouveau jour de " << date1 << " : " << date1.getJour() << endl << endl;

    cout << "Mois de " << date2 << " : " << date2.getMois() << endl;
    date2.setMois(3);
    cout << "Nouveau mois de " << date2 << " : " << date2.getMois() << endl << endl;

    cout << "Annee de " << date3 << " : " << date3.getAnnee() << endl;
    date3.setAnnee(2022);
    cout << "Nouvelle annee de " << date3 << " : " << date3.getAnnee() << endl <<
         endl;

    // Test des opérateurs de comparaison
    cout << date1 << " == " << date2 << " : " << boolalpha << (date1 == date2) <<
         endl;
    cout << date1 << "!=" << date3 << " : " << boolalpha << (date1 != date2) << endl;
    cout << date1 << " < " << date2 << " : " << boolalpha << (date1 < date2) << endl;
    cout << date1 << " <= " << date3 << " : " << boolalpha << (date1 <= date3) <<
         endl;
    cout << date1 << " > " << date2 << " : " << boolalpha << (date1 > date2) << endl;
    cout << date1 << " >= " << date2 << " : " << boolalpha << (date1 >= date2) <<
         endl << endl;

    // Test des opérateurs arithmétiques
    cout << date1 << "++ : " << date1++ << endl;
    cout << "++" << date1 << " : " << ++date1 << endl;
    cout << date2 << "-- : " << date2-- << endl;
    cout << "--" << date2 << " : " << --date2 << endl;
    cout << date2 << " + 1000000 : " << date2 + 1000000 << endl;
    cout << date1 << " += 63 : " << (date1 += 63) << endl;
    cout << date2 << " - 100000 : " << date2 - 100000 << endl;
    cout << date1 << " -= 63 : " << (date1 -= 63) << endl;
    cout << date2 << " - " << date1 << " : " << date2 - date1 << endl;
    cout << date1 << " - " << date2 << " : " << date1 - date2 << endl << endl;

    // Test des opérateurs d'affichage
    cout << "Affichage avec le format aaaa-mm-jj : " << date1("aaaa-mm-jj")
         << endl;

    return EXIT_SUCCESS;
}