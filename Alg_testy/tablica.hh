#ifndef TABLICA_HH_INCLUDED
#define TABLICA_HH_INCLUDED

#include <chrono>
#include <iostream>

//Tablica dynamiczna typu Typ o rozmiarze rozm
template<typename Typ>
struct tablica{
    Typ* tab;
    int rozm;
};

//Przeciążenie przesunięcia bitowego w lewo dla łatwego
//wypisywania zawartości tablicy.
template<typename Typ>
void operator << (std::ostream& Wyjscie, tablica<Typ> tab){
    for(int i=0; i<tab.rozm; i++){
        std::cout<<tab.tab[i]<<' ';
    }
}

#endif // TABLICA_HH_INCLUDED
