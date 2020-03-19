#include "LZespolona.hh"
#include <iostream>
#include <cmath>



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im+Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik,Z2,Gora;
  double z2;
  z2=modul(Skl2);
  if(z2==0)
    {std::cerr<<"Modul 0"<<std::endl; exit(1);}
  Z2=sprzezenie(Skl2);
  Gora=Skl1*Z2;
 /*Wynik.re = Gora.re/(z2*z2); */
 /*Wynik.im = Gora.im/(z2*z2); */
  Wynik=Gora/(z2*z2);
  return Wynik;
}
LZespolona operator /(LZespolona Skl, double rz)
{
  LZespolona Wynik;
  Wynik.re = Skl.re/(rz); /* */
  Wynik.im = Skl.im/(rz); /* */
  return Wynik;
}

bool porownaj (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    {std::cout<<"Rowne"<<std::endl; return true;}
  std::cout<<"Nierowne"<<std::endl; return false;
}

LZespolona sprzezenie (LZespolona  Skl)
{
  LZespolona  Wynik;
  Wynik.re = Skl.re;
  Wynik.im = -Skl.im;
  return Wynik;
}

double modul (LZespolona Skl)
{
  double Wynik;
  Wynik=sqrt(Skl.re*Skl.re+Skl.im*Skl.im);
  return Wynik;
}

void wyswietl (LZespolona Skl)
{
  std::cout<<"("<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<"i)";
}

void wyswietl (double Skl)
{
  std::cout<<Skl;
}
void wyswietl (char Skl)
{
  std::cout<<Skl;
}

LZespolona utworz (double re, double im)
{
 LZespolona  Wynik;
 Wynik.re = re;
 Wynik.im = im;
 return Wynik;
}
/*void wczytaj(LZespolona & L1)*/
bool wczytaj(LZespolona & L1)  
{
  char znak;
  /* std::cin>>znak>>L1.re>>L1.im>>znak>>znak;*/
  /* std::cin>>znak;*/
  std::cin>>znak;
  if(znak!='(')return false;
  std::cin>>L1.re>>L1.im;
  std::cin>>znak;
  if(znak!='i')return false;
  std::cin>>znak;
  if(znak!=')')return false;
  return true;
}

bool wczytaj(char & oper)
{
  std::cin>>oper;
  return true;
}

/*bool wczytajwyrazenie(WyrazenieZesp & Arg)
{
  wczytaj(Arg.Arg1);
  wczytaj(Arg.Op);
  wczytaj(Arg.Arg2);
  return true;
  }*/
/*
bool wczytajwyrazenie(LZespolona & L1,LZespolona & L2,char & oper)
{
  wczytaj(L1);
  wczytaj(oper);
  wczytaj(L2);
  return true;
}
*/
void wyswietlwyrazenie(LZespolona & L1,LZespolona & L2,char & oper)
{
  wyswietl(L1);
  wyswietl(oper);
  wyswietl(L2);
}
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
  }*/
/*
LZespolona obliczwyrazenie(LZespolona & L1,LZespolona & L2,char & oper)
{LZespolona Wynik;
  switch(oper)
    {
    case '+':
      {Wynik=L1+L2; break;}      
    case '-':
      {Wynik=L1-L2; break;}
    case '*':
      {Wynik=L1*L2; break;}
    case '/':
      {Wynik=L1/L2; break;}
    default:
      {std::cout<<"zly operator"<<std::endl; break;}
    }
  return Wynik;
}
*/
std::istream & operator >>(std::istream & str,LZespolona &Skl)
{
  char znak;
  str>>znak;
  if(znak!='(') {str.setstate(std::ios::failbit);};
  str>>Skl.re;
  str>>Skl.im;
  str>>znak;
  if(znak!='i') {str.setstate(std::ios::failbit);};
  str>>znak;
  if(znak!=')') {str.setstate(std::ios::failbit);};
  return str; 
}

std::ostream & operator <<(std::ostream & str, LZespolona Skl)
{
  str<<'('<<Skl.re<<std::showpos<<Skl.im<<std::noshowpos<<'i'<<')';
  return str;
}
