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
//Zapełnienie tablicy losowymi wartościami- uproszczona
//wersja powyższych funkcji- bez udziału użytkownika
void Tab_zrup_los(tablica<int> &tab, int dolna, int gorna){
    tab.tab=new int[tab.rozm];
    for(int i=0; i<tab.rozm; i++){
        tab.tab[i]=rand() % (gorna-dolna) + dolna;
    }
}
void WykonajPomiary(Jakisort tryp){

    tablica<int> tab;
    string Nazwapliku;
    ofstream Plik;
    double prawa;
    int rozmiary[5]={10000, 50000, 100000, 500000, 1000000};
    double Sortowania[8]={0, 25, 50, 75, 95, 99, 99.7, 100};
    auto poczatek=chrono::steady_clock::now();
    auto koniec=chrono::steady_clock::now();
    int glebokosc=2*log(tab.rozm);

    for(int i=0; i<5; i++){
    Nazwapliku="Pomiary/";
    cout<<"Rozpoczynam pomiary ";
    switch (tryp){
        case Merge:
            cout<<"sortowania przez scalanie:\n";
            Nazwapliku+="Mergesort/mergesort";
        break;
        case Quick:
            cout<<"sortowania szybkiego:\n";
            Nazwapliku+="Quicksort/quicksort";
        break;
        case Intro:
            cout<<"sortowania introspektywnego:\n";
            Nazwapliku+="Introsort/introsort";
        break;
        default:
           cerr<<"Błędna wartość Jakisort\n";
            return;
        break;
    }
        Nazwapliku+=std::to_string(rozmiary[i])+=".dat";
        Plik.open(Nazwapliku, ios::trunc);
        Plik.close();
        Plik.open(Nazwapliku, ios::app);
        if (!Plik.is_open()){
            cerr << "Niepowodzenie otwarcia pliku "<<Nazwapliku<<endl;
            return;}
        tab.rozm=rozmiary[i];
        Plik<<"Rozpoczęto pomiary.\n";
        cout<<"Tablicy o rozmiarze "<<rozmiary[i];

        for(int j=0; j<8; j++){
            if(j!=7){
                cout<<" posortowanej w "<<Sortowania[j]<<"%.\n";
                Plik<<"Tabela posortowana w "<<Sortowania[j]<<"%:\n";
//                Plik<<endl;
                }
            else{
                cout<<" posortowanej i odwróconej.\n";
                Plik<<"Tabela posortowana a następnie odwrócona:\n";
//                Plik<<endl;
                }
            for(int k=0; k<100; k++){
                if(j!=7){
                prawa=(Sortowania[j]*rozmiary[i])/100;
                Tab_zrup_los(tab, 0, 10000);
                quicksort(tab,0,prawa);}
                else{

                    int* pomoc=new int[tab.rozm];
                    Tab_zrup_los(tab, 0, 10000);
                    quicksort(tab,0,tab.rozm-1);
                    for(int s=0; s<tab.rozm; s++){
                        pomoc[s]=tab.tab[tab.rozm-1-s];
                    }
                    for(int s=0; s<tab.rozm; s++){
                        tab.tab[s]=pomoc[s];
                    }
                    delete [] pomoc;
                }

                switch (tryp){
                case Merge:
                    cout<<"Posortowano przez scalanie";
                    poczatek=chrono::steady_clock::now();
                    Sort_scal(tab, 0, tab.rozm-1);
                    koniec=chrono::steady_clock::now();
                break;
                case Quick:
                    cout<<"Posortowano przez quicksort";
                    poczatek=chrono::steady_clock::now();
                    quicksort(tab, 0, tab.rozm-1);
                    koniec=chrono::steady_clock::now();
                break;
                case Intro:
                    cout<<"Posortowano przez introsort";
                    poczatek=chrono::steady_clock::now();
                    Sort_intro(tab, 0, tab.rozm-1, glebokosc);
                    koniec=chrono::steady_clock::now();
                break;
                default:
                    cerr<<"Błędna wartość Jakisort\n";
                    return;
                break;
                }
                cout<<" tabelkę numer "<<k+1<<" o rozmiarze "<<rozmiary[i]<<endl;
                Plik<<chrono::duration_cast<chrono::microseconds>(koniec-poczatek).count()<<endl;
                delete [] tab.tab;
            }
        }
        cout<<"Zakończono pomiary.\n";
        Plik<<"Zakończono pomiary.\n";
        Plik.close();
    }
}
