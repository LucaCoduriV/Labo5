/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.h
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO5_DATE_H
#define LABO5_DATE_H

#include <iostream>
#include <string>

class Date {
public:
   explicit Date(unsigned jour = 0, unsigned mois = 0, unsigned annee = 0);

   //<
   //>
   //==
   //<=
   //>=
   //!=
   //++ gauche et droite
   //-- gauche et droite


   Date operator+(unsigned jours) const;
   Date& operator+=(unsigned jours);
   Date operator-(int jours) const;
   Date& operator-=(unsigned jours);
   unsigned operator-(const Date& dateInf) const;

   friend std::ostream& operator<<(std::ostream& lhs, Date date);
   std::string operator()(const std::string& format) const;
   bool estBissextile() const;
   static bool estBissextile(unsigned anne);
   unsigned jourDansMois() const;
   static unsigned jourDansMois(unsigned mois, unsigned anne);
   std::string jourLitteral() const;
   std::string moisLitteral() const;
   std::string anneeLitteral() const;

private:
   unsigned jour;
   unsigned mois;
   unsigned annee;
   Date incrementer(unsigned jours) const;
   Date decrementer(unsigned jours) const;
};


#endif
