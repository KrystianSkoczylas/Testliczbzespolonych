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
  Wynik.re = Gora.re/(z2*z2);
  Wynik.im = Gora.im/(z2*z2);  
  return Wynik;
}

double porownaj (LZespolona  Skl1,  LZespolona  Skl2)
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    {std::cout<<"Rowne"<<std::endl; return 1;}
  std::cout<<"Nierowne"<<std::endl; return 0;
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
LZespolona utworz (double re, double im)
{
 LZespolona  Wynik;
 Wynik.re = re;
 Wynik.im = im;
 return Wynik;
}
void wczytaj(LZespolona & L1)
{
  char znak;
  std::cin>>znak>>L1.re>>L1.im>>znak>>znak;
  
}
