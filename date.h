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


class Date {
public:
   Date(unsigned jour = 0, unsigned mois = 0, unsigned annee = 0);

   //<
   //>
   //==
   //<=
   //>=
   //!=
   //++ gauche et droite
   //-- gauche et droite

   //+
   Date operator+(unsigned jours) const;
   //+=
   Date& operator+=(unsigned jours);
   //-
   Date operator-(unsigned jours);
   //-=
   Date& operator-=(unsigned jours);
   //– (différence)
   unsigned operator-(const Date& date);

   //<<
   //<<()
   bool estBissextile() const;
   //static estBissextile(unsigned int annee)
   unsigned jourDansMois() const;
   static unsigned jourDansMois(unsigned int mois, unsigned int annee);
public:
   unsigned jour;
   unsigned mois;
   unsigned annee;
   Date incrementer(unsigned jours) const;
   Date decrementer(unsigned jours) const;
};


#endif
