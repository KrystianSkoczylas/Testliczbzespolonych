#include <iostream>
#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"
using namespace std;

int main(int argc, char **argv) /*funkcja main oczekuje argumetu latwy lub trudny */
{ 
  LZespolona L1,L2; /*liczby zespolone */
  double i=0; /*zmienna pomocnicza */
  Statystyka stat; /*zmienna przechowujaca dane o statystyce */
  
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
  zeruj(stat);
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << "Podaj wynik operacji: ";
    std::cout << WyrZ_PytanieTestowe << endl;
    L1=obliczwyrazenie(WyrZ_PytanieTestowe);
    std::cout << "Twoja odpowiedz: ";
    std::cin>>L2;
    while(std::cin.fail() &&(i<2) )  /*gdy nie uda sie porawnie wczyatc liczby zespolonej */
      {
	std::cout<<"Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl;
	std::cin.clear( ); /*wyczyszczenie strumienia */
	std::cin.ignore(10000,'\n');
	std::cout << "Twoja odpowiedz: ";
	std::cin>>L2;
	i++;
      }
    i=0;
    std::cin.clear( );
    std::cin.ignore(10000,'\n');
     
    if(L1==L2) /*gdy wynik poprawny */
      {std::cout << "Odpowiedz poprawna"<<endl;
	dodaj_dobra(stat);
      };
    
    if(L1!=L2)/*gdy wynik nie poprawny */
      {std::cout << "Blad.Prawidlowym wynikiem jest: "<<L1<<endl;
	dodaj_zla(stat);
      };
       
  }
  std::cout << endl;
  std::cout << " Koniec testu" << endl;
  std::cout<<stat; /*wyswietlenie statystyki */
  std::cout << endl;
}
/*Krystian Skoczylas Test arytmetyki liczb zespolonych */
