#include <iostream>
#include <cmath>
#include "Statystyka.hh"
void dodaj_dobra(Statystyka & stat)
{
  stat.dobre++; 
}

void dodaj_zla(Statystyka & stat)
{
  stat.zle++;
}

void zeruj(Statystyka & stat)
{
  stat.dobre=0;
  stat.zle=0;
}

int ile_dobrych(Statystyka & stat)
{
  return stat.dobre;
}

int ile_zlych(Statystyka & stat)
{
  return stat.zle;
}

int ile_w_sumie(Statystyka & stat)
{
  return (stat.dobre+stat.zle);
}

double procent_dobrych(Statystyka & stat)
{ double Wynik,a;
  a=stat.dobre+stat.zle;
  Wynik=(( (stat.dobre)/(a))*100);
  return Wynik;
}

std::ostream & operator <<(std::ostream & str, Statystyka stat)
{
 str<<"Ilosc dobrych  odpowiedzi: "<< ile_dobrych(stat)  <<std::endl;
 str<<"Ilosc blednych  odpowiedzi: "<< ile_zlych(stat)  <<std::endl;
 str<<"Wynik procentowy poprawnych odpowiedzi: "<< procent_dobrych(stat)<<'%'<<std::endl;
 return str;
}
