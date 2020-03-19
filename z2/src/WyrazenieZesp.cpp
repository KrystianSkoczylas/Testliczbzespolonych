#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona obliczwyrazenie(LZespolona & L1,LZespolona & L2,Operator & oper)
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
bool wczytajwyrazenie(WyrazenieZesp & Arg)
{
  char znak;
  wczytaj(Arg.Arg1);
  std::cin >> znak;
  if (znak == '+')
    Arg.Op=Op_Dodaj;
  wczytaj(Arg.Arg2);
  return true;
}
