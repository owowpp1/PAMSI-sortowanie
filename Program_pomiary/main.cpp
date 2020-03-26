
#include "funkcje.hh"
#include "algorytmy.hh"

/***************************************************/
/***_____________________________________________***/
/***                                             ***/
/***     PROGRAM DO POMIARU CZASÓW SORTOWANIA    ***/
/***_____________________________________________***/
/***                                             ***/
/***************************************************/

using namespace std;

int main()
{

    for(int i=0; i<3; i++){
        WykonajPomiary((Jakisort)i);
    }

    return 0;
}
