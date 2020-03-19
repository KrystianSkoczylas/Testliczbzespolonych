#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator /(LZespolona Skl, double rz);
void wyswietl (LZespolona Skl);
void wyswietl (double Skl);
void wyswietl (char Skl);
void wyswietlwyrazenie(LZespolona & L1,LZespolona & L2,char & oper);
LZespolona utworz (double re, double im);
bool wczytaj(LZespolona & L1);
bool wczytaj(char & oper);
LZespolona sprzezenie (LZespolona  Skl);
double modul (LZespolona Skl);
bool porownaj (LZespolona  Skl1,  LZespolona  Skl2);
/*bool wczytajwyrazenie(WyrazenieZesp & Arg);
  LZespolona obliczwyrazenie(LZespolona & L1,LZespolona & L2,Operator & oper); */
std::istream & operator >>(std::istream & str,LZespolona &Skl);
std::ostream & operator <<(std::ostream & str, LZespolona SKl);
#endif
