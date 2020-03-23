#include <iostream>
#include <cmath>

 struct Statystyka {
  int dobre;
  int zle;
 };
   
void dodaj_dobra(Statystyka & stat);
void dodaj_zla(Statystyka & stat);
void zeruj(Statystyka & stat);
int ile_dobrych(Statystyka & stat);
int ile_w_sumie(Statystyka & stat);
double procent_dobrych(Statystyka & stat);
std::ostream & operator <<(std::ostream & str, Statystyka stat);
