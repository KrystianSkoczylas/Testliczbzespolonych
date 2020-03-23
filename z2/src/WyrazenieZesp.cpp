#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
/*LZespolona obliczwyrazenie(LZespolona & L1,LZespolona & L2,Operator & oper)
{LZespolona Wynik;
  switch(oper)
    {
    case Op_Dodaj:
      {Wynik=L1+L2; break;}      
    case Op_Odejmij:
      {Wynik=L1-L2; break;}
    case Op_Mnoz:
      {Wynik=L1*L2; break;}
    case Op_Dziel:
      {Wynik=L1/L2; break;}
    }
  return Wynik;
}
*/
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


bool wczytajwyrazenie(WyrazenieZesp & Arg)
{
  char znak;
  wczytaj(Arg.Arg1);
  std::cin >> znak;
  if (znak == '+')
    Arg.Op=Op_Dodaj;
  if(znak=='-')
    Arg.Op=Op_Odejmij;
  if (znak=='*')
    Arg.Op=Op_Mnoz;
  if (znak=='/')
     Arg.Op=Op_Dziel;
  wczytaj(Arg.Arg2);
  return true;
}
std::istream & operator >>(std::istream & strm, WyrazenieZesp & Arg)/*wczytaj*/
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

/*std::istream & operator >>(std::istream & strm, Operator & oper)
{
  strm>>oper;
  return strm;
  }*/

void wyswietlwyrazenie(WyrazenieZesp & Arg)
{
  wyswietl(Arg.Arg1);
  wyswietl(Arg.Op);
  wyswietl(Arg.Arg2);
}
void wyswietl (Operator Skl)
{
  if(Skl==Op_Dodaj)
    std::cout<<'+';
  if(Skl==Op_Odejmij)
    std::cout<<'-';
  if(Skl==Op_Mnoz)
    std::cout<<'*';
  if(Skl==Op_Dziel)
    std::cout<<'/';
}

std::ostream & operator <<(std::ostream & strm, WyrazenieZesp Arg) /*wyswietl*/
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
}

std::ostream & operator <<(std::ostream & strm,Operator oper)
{
  strm<<oper;
  return strm;
}
