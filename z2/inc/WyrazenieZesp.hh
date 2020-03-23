#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include "LZespolona.hh"

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

struct WyrazenieZesp {
  LZespolona   Arg1;   
  Operator     Op;    
  LZespolona   Arg2;  
};

LZespolona obliczwyrazenie(WyrazenieZesp & Arg);
std::istream & operator >>(std::istream & strm, WyrazenieZesp & Arg);
std::istream & operator >>(std::istream & strm, Operator & oper);
std::ostream & operator <<(std::ostream & strm, WyrazenieZesp Arg);
std::ostream & operator <<(std::ostream & strm,Operator oper);

#endif
