/*
-----------------------------------------------------------------------------------
Nom du fichier  : date.h
Auteur(s)       : Chloé Fontaine & Tania Nunez & Luca Coduri
Date creation   : 05.01.2021
Description     : Ce module contient la déclaration de la classe Date. Cette
                  classe possède trois données membres qui représentent l'année,
                  le mois et le jour à l'aide d'unsigned int. Elle est munie d'un
                  constructeur et d'opérateurs de comparaison, arithmétiques et
                  d'affichage. Les corps de méthodes et surcharge sont implémentés
                  dans le fichier date.cpp.
Remarque(s)     : Il est possible de changer le format d'affichage d'un objet Date.
                  Par défaut "jj.mm.aaaa", mais il est possible de choisir entre
                  trois autres formats.
                  La classe Date a été n'est valide que pour le calendrier Grégorien.
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

   bool operator==(const Date& date) const;
   bool operator!=(const Date& date) const;
   bool operator<(const Date& date) const; //Une date est plus petite qu'une autre
   bool operator>(const Date& date) const; // si elle est antérieure.
   bool operator<=(const Date& date) const;
   bool operator>=(const Date& date) const;
   Date operator+(unsigned jours) const;
   Date& operator+=(unsigned jours);
   Date& operator++();
   Date operator++(int);
   Date operator-(int jours) const;
   Date& operator-=(unsigned jours);
   unsigned operator-(const Date& dateInf) const; //Calcule le nombre de jours
   Date& operator--();                            // entre les deux dates.
   Date operator--(int);

   friend std::ostream& operator<<(std::ostream& lhs, Date date);
   std::string operator()(const std::string& format) const; // Choix des formats
   bool estBissextile() const;                              // jj-mm-aaaa, aaaa.mm.jj
   static bool estBissextile(unsigned anne);                // ou aaaa-mm-jj.
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
