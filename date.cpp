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
#include <cstdlib>
#include <cmath>
using namespace std;

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee):jour(jour),
    mois(mois),annee(annee) {}

unsigned Date::getJour() const {
    return jour;
}

unsigned Date::getMois() const {
    return mois;
}

unsigned Date::getAnnee() const {
    return annee;
}

void Date::setJour(unsigned int nouveauJour) {
    jour = nouveauJour;
}

void Date::setMois(unsigned int nouveauMois) {
    mois = nouveauMois;
}

void Date::setAnnee(unsigned int nouvelleAnnee) {
    annee = nouvelleAnnee;
}

bool Date::estBissextile(unsigned annee) {
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned Date::joursDansMois() const {
    return joursDansMois(mois, annee);
}
unsigned Date::joursDansMois(unsigned int mois, unsigned int annee) {
   switch (mois) {
      case 4:
      case 6:
      case 9:
      case 11:
         return 30;
      case 2 :
         return estBissextile(annee) ? 29 : 28;
      default:
         return 31;
   }
}

bool Date::operator==(const Date& date) const{
   return annee == date.annee && mois == date.mois && jour ==
   date.jour;
}

bool Date::operator!=(const Date& date) const{
  return !(*this == date);
}

bool Date::operator<(const Date& date) const{
  return annee < date.annee || (annee == date.annee &&
  (mois < date.mois || (mois == date.mois && jour < date.jour)));
}

bool Date::operator>(const Date& date) const{
   return date < *this;
}

bool Date::operator<=(const Date& date) const{
  return !(*this > date);
}

bool Date::operator>=(const Date& date) const{
   return !(*this < date);
}

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

Date& Date::operator++() {
   *this = incrementer(1);
   return *this;
}

Date Date::operator++(int) {
   const Date temp = *this;
   *this = incrementer(1);
   return temp;
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
         jours += joursDansMois(i, annee);
      }
      //ajouter les jours qui restent
      jours += jour;
      jours += dateInf.joursDansMois() - dateInf.jour;
   } else {
      //ajouter les jours des années
      for (unsigned i = dateInf.annee + 1; i < annee; i++) {
         if (estBissextile(i)) jours += 366;
         else jours += 365;
      }
      //ajouter les jours des mois
      for (unsigned i = dateInf.mois + 1; i <= 12; i++) {
         jours += joursDansMois(i, dateInf.annee);
      }
      for (unsigned i = 1; i < mois; i++) {
         jours += joursDansMois(i, annee);
      }
      //ajouter les jours qui restent
      jours += jour;
      jours += joursDansMois(dateInf.mois, dateInf.annee) - dateInf.jour;

   }
   return jours;

}

Date& Date::operator--() {
   *this = this->decrementer(1);
   return *this;
}

Date Date::operator--(int) {
   const Date temp = *this;
   *this = this->decrementer(1);
   return temp;
}

Date Date::incrementer(unsigned jours) const{
   unsigned jourTemp = jour;
   unsigned moisTemp = mois;
   unsigned anneeTemp = annee;

   jourTemp += jours;
   while(jourTemp > joursDansMois()){
      jourTemp -= joursDansMois();
      moisTemp++;
      if (moisTemp > 12) {
         moisTemp = 1;
         anneeTemp++;
      }
   }
   return Date(jourTemp, moisTemp, anneeTemp);
}

Date Date::decrementer(unsigned jours) const {
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
      jourTemp += (int) joursDansMois();
   }

   return Date((unsigned) jourTemp, (unsigned) moisTemp, (unsigned) anneeTemp);
}

ostream& operator<<(ostream& lhs, Date date) {
    lhs << date("jj.mm.aaaa");
    return lhs;
}

string Date::operator()(const string& format) const {
    const string SEP = format == "jj.mm.aaaa" || format == "aaaa.mm.jj" ? "." : "-";
    string dateFormat;
    if (format == "jj.mm.aaaa" || format == "jj-mm-aaaa") {
        dateFormat = jourLitteral() +  SEP + moisLitteral() + SEP + anneeLitteral();
    } else if (format == "aaaa.mm.jj" || format == "aaaa-mm-jj") {
        dateFormat = anneeLitteral() + SEP + moisLitteral() + SEP + jourLitteral();
    } else {
        return "Format incompatible.";
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





