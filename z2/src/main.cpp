#include <iostream>
#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"
using namespace std;



int main(int argc, char **argv)
{ WyrazenieZesp D1;
  LZespolona L1,L2,L3,L4,L5,L6,L7;
  double A,B;
  Operator symbol;
  /* L1=utworz(1,-3);
  wyswietl(L1);
  L2=utworz(1,-2);
  wyswietl(L2);
  L3=L1*L2;
  std::cout<<"dodanie";
  wyswietl(L3);
  B=wczytaj(L4);
  std::cout<<"wczytaj"<<B<<std::endl;
  std::cin>>L4;
  if(!cin.good() ){std::cout<<"zle wpisana liczba"<<endl;}
  std::cout << L4.re << std::endl;
  wyswietl(L4);*/
  
  //A=wczytajwyrazenie(D1);
  std::cin>>D1;
  // wyswietlwyrazenie(D1);
  std::cout<<D1;
  // L7=obliczwyrazenie(D1.Arg1,D1.Arg2,D1.Op);
  L7=obliczwyrazenie(D1);
  std::cout<<L7;
  std::cin>>L1;
  std::cout<<L1;
  if(L1==L7){std::cout<<"Rowne"<<std::endl;};
  /* L5=sprzezenie(L1);
  std::cout<<"sprzezenie";
  wyswietl(L5);
  D1=modul(L1);
  std::cout<<"modul";
  wyswietl(D1);
  D2=modul(L5);
  wyswietl(D2);
  L3=L1*L2;
  std::cout<<"mnozenie";
  wyswietl(L3);
  L3=L1/L2;
  std::cout<<"dzielenie";
  wyswietl(L3);
  A=porownaj(L1,L2);
  std::cout<<"porownaj"<<A<<std::endl;*/
  
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
