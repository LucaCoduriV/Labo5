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
#include <iostream>
#include <cstdlib>

using namespace std;

bool estBissextile(unsigned annee) {
   return (annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned short nbreJoursMois(unsigned mois, unsigned annee) {

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

bool Date::operator==(const Date& date) {
   return annee == date.annee && mois == date.mois && jour ==
   date.jour;
}

bool Date::operator!=(const Date& date) {
  return !(*this == date);
}

bool Date::operator<(const Date& date){
  return annee < date.annee || (annee == date.annee &&
  (mois < date.mois || (mois == date.mois && jour < date.jour)));
}

bool Date::operator>(Date date) {
   return date < *this;
}

bool Date::operator<=(const Date& date) {
  return !(*this > date);
}

bool Date::operator>=(const Date& date) {
   return !(*this < date);
}

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee):jour(jour),
mois(mois),annee(annee) {}

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
   Date temp = *this;
   *this = incrementer(1);
   return temp;
}

Date Date::operator-(int jours) const {
   return decrementer((unsigned)jours);
}

Date &Date::operator-=(unsigned int jours) {
   Date date = decrementer(jours);
   jour = date.jour;
   mois = date.mois;
   annee = date.annee;
   return *this;
}

unsigned Date::operator-(const Date &date) const {
   cout << "DIFFERENCE" << endl;
   // ATTENTION vérifier que la date est plus grande avant;
   if(date.annee == annee && date.mois == mois){
      return jour - date.jour;
   }else{
      unsigned jours = 0;

      for(unsigned i = date.annee;i < annee; i++){
         if(estBissextile(i)) jours += 366;
         else jours += 365;
      }
      for(unsigned i = date.mois;i <= 12;i++){
         jours += nbreJoursMois(i, date.annee);
      }
      for(unsigned i = 1;i <= mois;i++){
         jours += nbreJoursMois(i, annee);
      }
      jours -= date.jour;
      jours -= nbreJoursMois(mois,annee) - jour;

      return jours;
   }
}

Date& Date::operator--() {
   this->decrementer(1);
   return *this;
}

Date Date::operator--(int) {
   Date temp = *this;
   this->decrementer(1);
   return temp;
}

Date Date::incrementer(unsigned jours) const{
   cout << "jour: " << jour << " mois: " << mois << " annee: " << annee << endl;
   unsigned jourTemp = jour;
   unsigned moisTemp = mois;
   unsigned anneeTemp = annee;

   jourTemp += jours;
   while(jourTemp > jourDansMois(moisTemp, anneeTemp)){
      jourTemp -= jourDansMois(moisTemp, anneeTemp);
      moisTemp++;
      if(moisTemp > 12){
         moisTemp = 1;
         anneeTemp++;
      }
   }

   cout << "jour: " << jourTemp << " mois: " << moisTemp << " annee: " << anneeTemp
   << endl;

   return Date(jourTemp, moisTemp, anneeTemp);
}

Date Date::decrementer(unsigned jours) const{
   cout << "jour: " << jour << " mois: " << mois << " annee: " << annee << endl;
   int jourTemp = (int)jour;
   int moisTemp = (int)mois;
   int anneeTemp = (int)annee;

   jourTemp -= (int)jours;
   while(jourTemp < 1){
      moisTemp--;
      if(moisTemp < 1){
         moisTemp = 12;
         anneeTemp--;
      }
      jourTemp += (int)jourDansMois((unsigned)moisTemp, (unsigned)anneeTemp);
   }

   cout << "jour: " << jourTemp << " mois: " << moisTemp << " annee: " << anneeTemp
        << endl;

   return Date((unsigned)jourTemp, (unsigned)moisTemp, (unsigned)anneeTemp);
}

unsigned Date::jourDansMois(unsigned int mois, unsigned int annee) {
   return nbreJoursMois(mois, annee);
}

//unsigned Date::jourDansMois() const {
//   return Date::jourDansMois(mois, annee);
//}



