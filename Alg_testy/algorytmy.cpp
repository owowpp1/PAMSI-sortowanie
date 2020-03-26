#include "algorytmy.hh"
#include <iostream>
using namespace std;

//Funkcja podmieniająca wartości w tablicy o indeksach ind1 oraz ind2
void Podmien(tablica<int> tab, int ind1, int ind2){
  int temp;                     //zmienna pomocnicza
  temp=tab.tab[ind1];
  tab.tab[ind1]=tab.tab[ind2];
  tab.tab[ind2]=temp;
}

/*****SORTOWANIE PRZEZ SCALANIE*****/
void Scal(tablica<int> tab, int lewa, int prawa);
//Sortowanie przez scalanie tablicy tab
//lewa- poczatek tablicy (lewa strona)
//prawa- koniec tablicy (prawa strona)
void Sort_scal(tablica<int> tab, int lewa, int prawa){

    if(lewa>=prawa)return;

    int srodek=(lewa+prawa)/2;

    Sort_scal(tab, lewa, srodek);
    Sort_scal(tab, srodek+1, prawa);

    Scal(tab, lewa, prawa);
}

void Scal(tablica<int> tab, int lewa, int prawa){

    int srodek=(lewa+prawa)/2;
    int a=lewa, b=srodek+1, c=lewa;

    int *pomoc=new int[tab.rozm];

    while(a<=srodek && b<=prawa){
        if(tab.tab[a]<tab.tab[b]){
            pomoc[c++]=tab.tab[a++];
        }
        else{
            pomoc[c++]=tab.tab[b++];
        }
    }
    while(a<=srodek){
        pomoc[c++]=tab.tab[a++];
    }
    while(b<=prawa){
        pomoc[c++]=tab.tab[b++];
    }
    for(int i=lewa; i<=prawa; i++){
        tab.tab[i]=pomoc[i];
    }
    delete [] pomoc;
}


/*************QUICKSORT*************/
//szybkie sortowanie tablicy tab
//lewa- poczatek tablicy (lewa strona)
//prawa- koniec tablicy (prawa strona)
void quicksort(tablica<int> tab, int lewa, int prawa){

	int i=lewa, j=prawa;

    if(lewa>=prawa)return;

	int pkt_od=tab.tab[(lewa+prawa)/2];
    i--; j++;
//    cout<<"Zaczynam while\n";
    while(1)
	{
		while(pkt_od>tab.tab[++i]);
		while(pkt_od<tab.tab[--j]);
		if(i<=j)Podmien(tab, i, j);
		else    break;
	}
//	cout<<"Po pętli while\n";

	if(j>lewa)
	quicksort(tab, lewa, j);
	if(i<prawa)
	quicksort(tab, i, prawa);
}

/****SORTOWANIE PRZEZ KOPCOWANIE****/
//Sortowanie przez kopcowanie tablicy tab
//rozm- rozmiar tablicy
//korzen- poczatek tablicy (root)
void Utworz_Kopiec(tablica<int> tab, int rozm, int korzen){
    int Max=korzen;
    int lewysyn =2*korzen+1;
    int prawysyn=2*korzen+2;

    if (lewysyn<rozm  && tab.tab[lewysyn] >tab.tab[Max]) Max=lewysyn;
    if (prawysyn<rozm && tab.tab[prawysyn]>tab.tab[Max]) Max=prawysyn;

    if (Max!=korzen){
        Podmien(tab, Max, korzen);

        Utworz_Kopiec(tab, rozm, Max);
    }
}

void Sort_kopc(tablica<int> tab, int rozm){
    for (int i=rozm/2-1; i>=0; i--)
        Utworz_Kopiec(tab, rozm, i);

    for (int i=rozm-1; i>=0; i--){
        Podmien(tab, 0, i);

        Utworz_Kopiec(tab, i, 0);
    }
}

/****SORTOWANIE PRZEZ WSTAWIANIE****/
//Sortowanie przez wstawianie tablicy tab
//rozm- rozmiar tablicy
void Sort_wst(tablica<int> tab, int rozm){
   int pomoc, j;
   for(int i=1; i<rozm; i++){
      pomoc=tab.tab[i];
      j=i;
      while(j>0 && tab.tab[j-1]>pomoc){
         tab.tab[j]=tab.tab[j-1];
         j--;
      }
      tab.tab[j]=pomoc;
   }
}

/***********INTROSPEKTYWNE**********/
//Sortowanie introspektywne tablicy tab
//lewa- poczatek tablicy (lewa strona)
//prawa- koniec tablicy (prawa strona)
//glebokosc- maksymalna glebokosc rekursji
int Podziel(tablica<int> tab, int lewa, int prawa){

    int i=lewa, j=prawa;

	int pkt_od=tab.tab[(lewa+prawa)/2];
    i--; j++;
//    cout<<"Zaczynam while\n";
    while(1)
	{
		while(pkt_od>tab.tab[++i]);
		while(pkt_od<tab.tab[--j]);
		if(i<=j)Podmien(tab, i, j);
		else    return j;
	}
}

void Sort_intro(tablica<int> tab, int lewa, int prawa, int glebokosc){
  if((prawa-lewa)<16)   Sort_wst(tab, prawa-lewa+1);
  else if(glebokosc==0) Sort_kopc(tab, prawa-lewa+1);
  else{
//  cout<<"poelse\n";
    int pkt_od=Podziel(tab, lewa, prawa);
//    cout<<"glebokosc="<<glebokosc<<endl;
    Sort_intro(tab, lewa,     pkt_od-1, glebokosc-1);
//    cout<<"Przeskoczylem\n";
    Sort_intro(tab, pkt_od+1, prawa,    glebokosc-1);
  }
}
