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
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool Date::estBissextile() const {
    return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned Date::jourDansMois() const {

    switch (mois) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2 :
            return estBissextile() ? 29 : 28;
        default:
            return 31;
    }
}

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee) : jour(jour),
                                                                       mois(mois),
                                                                       annee(
                                                                          annee) {}

Date Date::operator+(unsigned jours) const {
   return incrementer(jours);
}

Date &Date::operator+=(unsigned int jours) {
   Date date = incrementer(jours);
   jour = date.jour;
   mois = date.mois;
   annee = date.annee;
   return *this;
}

Date Date::operator-(int jours) const {
   return decrementer((unsigned) jours);
}

Date &Date::operator-=(unsigned int jours) {
   Date date = decrementer(jours);
   jour = date.jour;
   mois = date.mois;
   annee = date.annee;
   return *this;
}

unsigned Date::operator-(const Date &dateInf) const {
   // TODO vérifier que la dateInf est plus petite avant;
   unsigned jours = 0;
   if (dateInf.annee == annee && dateInf.mois == mois) {
      return jour - dateInf.jour;
   } else if (dateInf.annee == annee) {
      //ajouter le nombre de jours dans les mois
      for (unsigned i = dateInf.mois + 1; i < mois; i++) {
         jours += jourDansMois();
      }
      //ajouter les jours qui restent
      jours += jour;
      jours += jourDansMois() - dateInf.jour;
   } else {
      //ajouter les jours des années
      for (unsigned i = dateInf.annee + 1; i < annee; i++) {
         if (estBissextile()) jours += 366;
         else jours += 365;
      }
      //ajouter les jours des mois
      for (unsigned i = dateInf.mois + 1; i <= 12; i++) {
         jours += jourDansMois();
      }
      for (unsigned i = 1; i < mois; i++) {
         jours += jourDansMois();
      }
      //ajouter les jours qui restent
      jours += jour;
      jours += jourDansMois() - dateInf.jour;

   }
   return jours;

}

Date Date::incrementer(unsigned jours) const {
   cout << "jour: " << jour << " mois: " << mois << " annee: " << annee << endl;
   unsigned jourTemp = jour;
   unsigned moisTemp = mois;
   unsigned anneeTemp = annee;

   jourTemp += jours;
   while(jourTemp > jourDansMois()){
      jourTemp -= jourDansMois();
      moisTemp++;
      if (moisTemp > 12) {
         moisTemp = 1;
         anneeTemp++;
      }
   }

   cout << "jour: " << jourTemp << " mois: " << moisTemp << " annee: " << anneeTemp
        << endl;

   return Date(jourTemp, moisTemp, anneeTemp);
}

Date Date::decrementer(unsigned jours) const {
   cout << "jour: " << jour << " mois: " << mois << " annee: " << annee << endl;
   int jourTemp = (int) jour;
   int moisTemp = (int) mois;
   int anneeTemp = (int) annee;

   jourTemp -= (int) jours;
   while (jourTemp < 1) {
      moisTemp--;
      if (moisTemp < 1) {
         moisTemp = 12;
         anneeTemp--;
      }
      jourTemp += (int) jourDansMois();
   }

   cout << "jour: " << jourTemp << " mois: " << moisTemp << " annee: " << anneeTemp
        << endl;

   return Date((unsigned) jourTemp, (unsigned) moisTemp, (unsigned) anneeTemp);
}

ostream& operator<<(ostream& lhs, Date date) {
    lhs << date("jj.mm.aaaa");
    return lhs;
}

ostream& operator<<(ostream& lhs, const string& date) {
    lhs << date;
    return lhs;
}

string Date::operator()(const string& format) const {
    const string SEP = format == "jj.mm.aaaa" || format == "aaaa.mm.jj" ? "." : "-";
    string dateFormat;
    if (format == "jj.mm.aaaa" || format == "jj-mm-aaaa") {
        dateFormat = jourLitteral() +  SEP + moisLitteral() + SEP + anneeLitteral();
    } else {
        dateFormat = anneeLitteral() + SEP + moisLitteral() + SEP + jourLitteral();
    }
    return dateFormat;
}

string Date::jourLitteral() const {
    string jourLit;
    if ((int)log10(jour) == 0) {
        jourLit += "0";
    }
    jourLit += to_string(jour);
    return jourLit;
}

string Date::moisLitteral() const {
    string moisLit;
    if ((int)log10(mois) == 0) {
        moisLit += "0";
    }
    moisLit += to_string(mois);
    return moisLit;
}

string Date::anneeLitteral() const {
    string anneeLit;
    const unsigned NB_ANNEES = 4;
    if (annee && ceil(log10(annee)) < NB_ANNEES) {
        for (unsigned i = (unsigned)log10(annee); i < NB_ANNEES - 1; ++i) {
            anneeLit += "0";
        }
    }
    anneeLit += to_string(annee);
    return anneeLit;
}

