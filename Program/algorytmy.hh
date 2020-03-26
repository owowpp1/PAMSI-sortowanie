#ifndef ALGORYTMY_HH_INCLUDED
#define ALGORYTMY_HH_INCLUDED

#include "tablica.hh"

void Podmien(tablica<int> tab, int ind1, int ind2);
void Sort_scal(tablica<int> tab, int lewa, int prawa);
void Scal(tablica<int> tab, int lewa, int prawa);
void quicksort(tablica<int> tab, int lewa, int prawa);
void Utworz_Kopiec(tablica<int> tab, int rozm, int korzen);
void Sort_kopc(tablica<int> tab, int rozm);
void Sort_wst(tablica<int> tab, int rozm);
int Podziel(tablica<int> tab, int lewa, int prawa);
void Sort_intro(tablica<int> tab, int lewa, int prawa, int glebokosc);

#endif // ALGORYTMY_HH_INCLUDED
