#include "funkcje.hh"

using namespace std;
//Funkcja wypelniajaca tablicę tab losowymi wartościami
int Tab_wyp(tablica<int> &tab){
    int dolna, gorna;
    char podkreslnik;
    cout<<"Podaj zakres w postaci min_max"<<endl;
    cin>>dolna;
    if (cin.fail()){ cout<<"Błąd pobrania wartości minimalnej\n";return 1;}
    cin>>podkreslnik;
    if (cin.fail()) return 1;
    if (podkreslnik != '_')  {
    std::cout<<"Bląd! Oczekiwano samego podkreślnika (_) między wartościami!\n";
    cin.setstate(std::ios::failbit); return 1;}
    cin>>gorna;
    if (cin.fail()){ cout<<"Błąd pobrania wartości maksymalnej\n";return 1;}
    if(dolna>=gorna){cout<<"Wartość maksymalna jest mniejsza lub równa minimalnej!\n"; return 1;}
    gorna++;
    for(int i=0; i<tab.rozm; i++){
        tab.tab[i]=rand() % (gorna-dolna) + dolna;
    }
    return 308;
}
//Funkcja tworząca tablicę i zapełniająca ją zgodnie z preferencją użytkownika
void Tab_zrup(tablica<int> &tab){

    int wybur=0;
    cout<<"Podaj rozmiar tablicy"<<endl;
    cin>>tab.rozm;
    while(cin.fail()){                              //Gdy >> zwróci błąd
            cout<<"Wpisz ponownie!:\n";
            cin.clear();                                //Wyczyszczenie flag
            cin.ignore(10000,'\n');                     //Zignorowanie wpisanych danych
            cin>>tab.rozm;                              //Ponowne podanie rozmiaru
        }
        cin.clear();                                //Wyczyszczenie flag
        cin.ignore(10000,'\n');

    tab.tab=new int[tab.rozm];

    cout<<"Czym zapychamy?\n1- zera\n2- losowe wartości\n";
    while(wybur!=1&&wybur!=2){
        cin>>wybur;
        switch(wybur){
            case 1:
                for(int i=0; i<tab.rozm; i++){
                    tab.tab[i]=0;
                }
            break;
            case 2:
            int a;
            while(a!=308){
                a=Tab_wyp(tab);
                cin.clear();                                //Wyczyszczenie flag
                cin.ignore(10000,'\n');                     //Zignorowanie wpisanych danych
            }
            break;
            default:
            cout<<"Nie ma takiej opcji. Spróbuj ponownie.\n";
            break;
        }
    }
}
