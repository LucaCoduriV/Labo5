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
   explicit Date(unsigned jour = 0, unsigned mois = 0, unsigned annee = 0);

   //<
   //>
   //==
   //<=
   //>=
   //!=
   friend bool operator==(const Date& date1, const Date& date2);
   friend bool operator!=(const Date& date1, const Date& date2);
   friend bool operator<(const Date& date1, const Date& date2);
   friend bool operator>(const Date& date1, const Date& date2);
   friend bool operator<=(const Date& date1, const Date& date2);
   friend bool operator>=(const Date& date1, const Date& date2);
   /*
   bool operator==(const Date& date);
   bool operator!=(const Date& date);
   bool operator<(const Date& date); //chaipa pourquoi, mais les deux operateurs
   bool operator>(const Date& date); // fonctionnent à l'envers...
   bool operator<=(const Date& date);
   bool operator>=(const Date& date);
   */
   Date operator+(unsigned jours) const;
   Date& operator+=(unsigned jours);
   Date& operator++();
   Date operator++(int);
   Date operator-(int jours) const;
   Date& operator-=(unsigned jours);
   unsigned operator-(const Date& date) const;
   Date& operator--();
   Date operator--(int);

   //<<
   //<<()
   //bool estBissextile() const;
   //static estBissextile(unsigned int annee)
   //unsigned jourDansMois() const;
   static unsigned jourDansMois(unsigned int mois, unsigned int annee);
public:
   unsigned jour;
   unsigned mois;
   unsigned annee;
   Date incrementer(unsigned jours) const;
   Date decrementer(unsigned jours) const;
};


#endif
