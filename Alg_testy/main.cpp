#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include "funkcje.hh"
#include "algorytmy.hh"

using namespace std;

int main(){
    cout << "Będzie robiona tablica." << endl;
    tablica<int> tab;
    int wybur=0;
    tabzrup:
    Tab_zrup(tab);
    cout<<"Twoja tablica:\n"<<tab;
    cout<<endl<<endl;
    while(wybur!=308){
        cout<<"Jakiego algorytmu chcesz użyć?\n1-Heapsort\n2-Insertion sort\n3-Mergesort\n4-Quicksort\n5-Introsort\n\n10-Nowa tablica\n\n308-Anuluj\n";
        cin>>wybur;
        while(cin.fail()){                                  //Gdy przeciążenie >> zwróci błąd
                cout<<"Błędna wartość!:\n";
                cin.clear();                                //Wyczyszczenie flag
                cin.ignore(10000,'\n');                     //Zignorowanie wpisanych danych
                cin>>wybur;                                 //Ponowne podanie współrzędnych
        }
        cin.clear();
        cin.ignore(10000,'\n');
        switch(wybur){
            case 1:
                cout<<"Sortowanie przez kopcowanie.\n";
                Sort_kopc(tab, tab.rozm);
                cout<<"Po przesortowaniu:\n"<<tab;
                cout<<endl;
            break;
            case 2:
                cout<<"Sortowanie przez wstawianie.\n";
                Sort_wst(tab, tab.rozm);
                cout<<"Po przesortowaniu:\n"<<tab;
                cout<<endl;
            break;
            case 3:
                cout<<"Sortowanie przez scalanie:\n";
                Sort_scal(tab, 0, tab.rozm-1);
                cout<<"Po przesortowaniu:\n"<<tab;
                cout<<endl;
            break;
            case 4:
                cout<<"Quicksort\n";
                quicksort(tab, 0, tab.rozm-1);
                cout<<"Po przesortowaniu:\n"<<tab;
                cout<<endl;
            break;
            case 5:
                cout<<"Sortowanie introspektywne.\n";
                Sort_intro(tab, 0, tab.rozm-1, 2*log(tab.rozm));
                cout<<"Po przesortowaniu:\n"<<tab;
                cout<<endl;
                delete []tab.tab;
            break;
            case 10:
                goto tabzrup;
            break;
            case 308:
                cout<<"Anulowano.\n";
            break;
            default:
                cout<<"\nNie ma takiej opcji. Spróbuj ponownie.\n\n";
            break;
        }
    }

    return 0;
}
