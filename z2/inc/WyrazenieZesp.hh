#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include "LZespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

bool wczytajwyrazenie(WyrazenieZesp & Arg);
LZespolona obliczwyrazenie(WyrazenieZesp & Arg);
void wyswietlwyrazenie(WyrazenieZesp & Arg);
void wyswietl (Operator Skl);
std::istream & operator >>(std::istream & strm, WyrazenieZesp & Arg);
std::istream & operator >>(std::istream & strm, Operator & oper);

std::ostream & operator <<(std::ostream & strm, WyrazenieZesp Arg);
std::ostream & operator <<(std::ostream & strm,Operator oper);
void Wyswietl(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);

#endif
