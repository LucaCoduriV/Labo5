/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.h
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date création   : 05.01.2021

Description     : Ce module contient la déclaration de la classe Date. Cette
                  classe possède trois données membres qui représentent l'année,
                  le mois et le jour à l'aide d'unsigned int. Elle est munie d'un
                  constructeur et d'opérateurs de comparaison, arithmétiques et
                  d'affichage. Les méthodes et surcharges sont implémentées dans le
                  fichier date.cpp.

Remarque(s)     : Il est possible de changer le format d'affichage d'un objet Date.
                  Par défaut "jj.mm.aaaa", mais il est possible de choisir entre
                  trois autres formats : "jj-mm-aaaa", "aaaa.mm.jj", "aaaa-mm-jj".
                  Attention : la classe Date n'est valide que pour le calendrier
                  Grégorien.

Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO5_DATE_H
#define LABO5_DATE_H

#include <iostream>
#include <string>

class Date {

   friend bool operator==(const Date& lDate, const Date& rDate);
   friend bool operator!=(const Date& lDate, const Date& rDate);
   friend bool operator<(const Date& lDate, const Date& rDate);
   friend bool operator<=(const Date& lDate, const Date& rDate);
   friend bool operator>(const Date& lDate, const Date& rDate);
   friend bool operator>=(const Date& lDate, const Date& rDate);
   friend std::ostream& operator<<(std::ostream& lhs,const Date& date);

public:

   explicit Date(unsigned jour = 0, unsigned mois = 0, unsigned annee = 0);
   unsigned getJour() const;
   unsigned getMois() const;
   unsigned getAnnee() const;
   void setJour(unsigned nouveauJour);
   void setMois(unsigned nouveauMois);
   void setAnnee(unsigned nouvelleAnnee);

   Date operator+(unsigned jours) const;
   Date& operator+=(unsigned jours);
   Date& operator++();
   Date operator++(int);
   Date operator-(int jours) const;
   Date& operator-=(unsigned jours);
   long long operator-(const Date& dateInf) const;
   Date& operator--();
   Date operator--(int);
   std::string operator()(const std::string& format) const;

   static bool estBissextile(unsigned anne);
   static unsigned joursDansMois(unsigned mois, unsigned anne);

private:

   unsigned jour;
   unsigned mois;
   unsigned annee;
   static Date incrementer(const Date& date, unsigned jours);
   static Date decrementer(const Date& date, unsigned jours);
};

#endif
