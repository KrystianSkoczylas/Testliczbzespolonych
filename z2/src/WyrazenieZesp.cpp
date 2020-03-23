#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>

LZespolona obliczwyrazenie(WyrazenieZesp & Arg)
{LZespolona Wynik;
  switch(Arg.Op)
    {
    case Op_Dodaj:
      {Wynik=Arg.Arg1+Arg.Arg2; break;}      
    case Op_Odejmij:
      {Wynik=Arg.Arg1-Arg.Arg2; break;}
    case Op_Mnoz:
      {Wynik=Arg.Arg1*Arg.Arg2; break;}
    case Op_Dziel:
      {Wynik=Arg.Arg1/Arg.Arg2; break;}
    }
  return Wynik;
}

std::istream & operator >>(std::istream & strm, WyrazenieZesp & Arg)
{
  char znak;
  strm>>Arg.Arg1>>znak>>Arg.Arg2;
  if (znak == '+')
    Arg.Op=Op_Dodaj;
  if(znak=='-')
    Arg.Op=Op_Odejmij;
  if (znak=='*')
    Arg.Op=Op_Mnoz;
  if (znak=='/')
     Arg.Op=Op_Dziel;
  return strm;
}

std::ostream & operator <<(std::ostream & strm, WyrazenieZesp Arg)
{  
  strm<<Arg.Arg1;
  if(Arg.Op==Op_Dodaj)
  strm<<'+';
  if(Arg.Op==Op_Odejmij)
  strm<<'-';
  if(Arg.Op==Op_Mnoz)
  strm<<'*';
  if(Arg.Op==Op_Dziel)
  strm<<'/';
  strm<<Arg.Arg2;
  return strm;
}

std::ostream & operator <<(std::ostream & strm,Operator oper)
{
  strm<<oper;
  return strm;
}
