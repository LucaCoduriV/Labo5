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
   unsigned getJour() const;
   unsigned getMois() const;
   unsigned getAnnee() const;
   void setJour(unsigned nouveauJour);
   void setMois(unsigned nouveauMois);
   void setAnnee(unsigned nouvelleAnnee);

   bool operator==(const Date& date) const;
   bool operator!=(const Date& date) const;
   bool operator<(const Date& date) const;
   bool operator>(const Date& date) const;
   bool operator<=(const Date& date) const;
   bool operator>=(const Date& date) const;
   Date operator+(unsigned jours) const;
   Date& operator+=(unsigned jours);
   Date& operator++();
   Date operator++(int);
   Date operator-(int jours) const;
   Date& operator-=(unsigned jours);
   long long operator-(const Date& dateInf) const;
   Date& operator--();
   Date operator--(int);

   friend std::ostream& operator<<(std::ostream& lhs, Date date);
   std::string operator()(const std::string& format) const;
   static bool estBissextile(unsigned anne);
   unsigned joursDansMois() const;
   static unsigned joursDansMois(unsigned mois, unsigned anne);
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
