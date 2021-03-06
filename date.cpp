/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.cpp
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021

Description     : Ce module contient l'implémentation des méthodes et opérateurs de
                  la classe Date déclarée dans le fichier date.h.

Remarque(s)     : Les opérateurs + et - ne modifient pas les objets, mais en
                  renvoient un nouveau.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iomanip>
#include <sstream>
#include "date.h"

using namespace std;

bool estBissextile(unsigned annee) {
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned joursDansMois(unsigned mois, unsigned annee) {
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

Date incrementer(const Date &date, unsigned jours) {
   unsigned jourTemp = date.getJour();
   unsigned moisTemp = date.getMois();
   unsigned anneeTemp = date.getAnnee();

   jourTemp += jours;
   while (jourTemp > joursDansMois(moisTemp, anneeTemp)) {
      jourTemp -= joursDansMois(moisTemp, anneeTemp);
      moisTemp++;
      if (moisTemp > 12) {
         moisTemp = 1;
         anneeTemp++;
      }
   }
   return Date((unsigned) jourTemp, (unsigned) moisTemp, (unsigned) anneeTemp);
}

Date decrementer(const Date &date, unsigned jours) {
   long long jourTemp = date.getJour();
   long long moisTemp = date.getMois();
   long long anneeTemp = date.getAnnee();

   jourTemp -= jours;
   while (jourTemp < 1) {
      moisTemp--;
      if (moisTemp < 1) {
         moisTemp = 12;
         anneeTemp--;
      }
      jourTemp += joursDansMois((unsigned) moisTemp, (unsigned) anneeTemp);
   }

   return Date((unsigned) jourTemp, (unsigned) moisTemp, (unsigned) anneeTemp);
}

bool operator==(const Date &lDate, const Date &rDate) {
    return lDate.annee == rDate.annee && lDate.mois == rDate.mois && lDate.jour ==
                                                                     rDate.jour;
}

bool operator!=(const Date &lDate, const Date &rDate) {
    return !(lDate == rDate);
}

bool operator<(const Date &lDate, const Date &rDate) {
    return lDate.annee < rDate.annee || (lDate.annee == rDate.annee &&
                                         (lDate.mois < rDate.mois ||
                                          (lDate.mois == rDate.mois &&
                                           lDate.jour < rDate.jour)));
}

bool operator<=(const Date &lDate, const Date &rDate) {
    return !(lDate > rDate);
}

bool operator>(const Date &lDate, const Date &rDate) {
    return rDate < lDate;
}

bool operator>=(const Date &lDate, const Date &rDate) {
    return !(lDate < rDate);
}

ostream &operator<<(ostream &lhs, const Date& date) {
    lhs << date("jj.mm.aaaa");
    return lhs;
}

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee) : jour(jour),
           mois(mois), annee(annee) {}

unsigned Date::getJour() const {
    return jour;
}

unsigned Date::getMois() const {
    return mois;
}

unsigned Date::getAnnee() const {
    return annee;
}

void Date::setJour(unsigned nouveauJour) {
    jour = nouveauJour;
}

void Date::setMois(unsigned nouveauMois) {
    mois = nouveauMois;
}

void Date::setAnnee(unsigned nouvelleAnnee) {
    annee = nouvelleAnnee;
}

Date Date::operator+(unsigned jours) const {
    return incrementer(*this, jours);
}

Date &Date::operator+=(unsigned jours) {
    const Date DATE = incrementer(*this, jours);
    jour = DATE.jour;
    mois = DATE.mois;
    annee = DATE.annee;
    return *this;
}

Date &Date::operator++() {
    *this = incrementer(*this, 1);
    return *this;
}

Date Date::operator++(int) {
    const Date TEMP = *this;
    *this = incrementer(*this, 1);
    return TEMP;
}

Date Date::operator-(int jours) const {
    return decrementer(*this, (unsigned) jours);
}

Date &Date::operator-=(unsigned jours) {
    const Date DATE = decrementer(*this, jours);
    jour = DATE.jour;
    mois = DATE.mois;
    annee = DATE.annee;
    return *this;
}

long long Date::operator-(const Date &dateInf) const {
    Date dateTempSup(0, 0, 0);
    Date dateTempInf(0, 0, 0);
    int signe = 1;

    if (*this > dateInf) {
        dateTempSup = *this;
        dateTempInf = dateInf;
    } else {
        signe = -1;
        dateTempSup = dateInf;
        dateTempInf = *this;
    }

    long long nbJour = 0;
    for (unsigned i = dateTempInf.annee; i < dateTempSup.annee; i++) {
        if (estBissextile(i)) nbJour++;
    }

    for (unsigned i = 1; i < dateTempSup.mois; i++) {
        nbJour += joursDansMois(i, dateTempSup.annee);
    }

    for (unsigned i = 1; i < dateTempInf.mois; i++) {
        nbJour += joursDansMois(i, dateTempSup.annee);
    }

    nbJour += (dateTempSup.annee - dateTempInf.annee) * 365;
    nbJour += dateTempSup.jour;
    nbJour -= dateTempInf.jour;
    return nbJour * signe;
}

Date &Date::operator--() {
    *this = decrementer(*this, 1);
    return *this;
}

Date Date::operator--(int) {
    const Date TEMP = *this;
    *this = decrementer(*this, 1);
    return TEMP;
}

string Date::operator()(const string &format) const {
    const string SEP = format == "jj.mm.aaaa" || format == "aaaa.mm.jj" ? "." : "-";
    ostringstream dateFormat;
    if (format == "jj.mm.aaaa" || format == "jj-mm-aaaa") {
        dateFormat << setfill('0') << setw(2) << jour << SEP << setw(2)
                   << mois << SEP << setw(4) << annee;
    } else if (format == "aaaa.mm.jj" || format == "aaaa-mm-jj") {
        dateFormat << setfill('0') << setw(4) << annee << SEP << setw(2)
                   << mois << SEP << setw(2) << jour;
    } else {
        dateFormat << "Format incompatible.";
    }
    return dateFormat.str();
}



