#include "LZespolona.hh"
#include <iostream>
#include <cmath>

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
  Z2=sprzezenie(Skl2);
  Gora=Skl1*Z2;
  Wynik=Gora/(z2*z2);
  return Wynik;
}

LZespolona operator /(LZespolona Skl, double rz)
{
  LZespolona Wynik;
   if(rz==0)
    {std::cerr<<"Dzielenie przez 0"<<std::endl; exit(1);}
  Wynik.re = Skl.re/(rz); 
  Wynik.im = Skl.im/(rz); 
  return Wynik;
}

bool operator == (LZespolona  Skl1,  LZespolona  Skl2) 
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    { return true;}
  return false;
}

bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  return!(Skl1==Skl2);
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

LZespolona utworz (double re, double im)
{
 LZespolona  Wynik;
 Wynik.re = re;
 Wynik.im = im;
 return Wynik;
}

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

