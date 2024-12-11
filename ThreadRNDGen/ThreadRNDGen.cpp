#include <windows.h>
#include "clsRandomGen.h"
#include <iostream>


int main()
{
	int lintCislo;
	DWORD ldwThreadID;
	HANDLE lhThread;
	clsRandomGen* lobjRandomGen;
    char volba;

	//vytvoření objektu
	lobjRandomGen = new clsRandomGen();

	//start generování čísel

	lhThread = CreateThread(NULL, 0, MyThreadStarter, lobjRandomGen, 0, &ldwThreadID);

    // hlavní smyčka programu
    while (true) {
        volba = getchar();

         // čtení klávesy bez nutnosti stisknout Enter
        if (volba == 'n' || volba == 'N')
        {
            // generovat a vypsat číslo
            printf("%i\n", lobjRandomGen->GetRND());
        }
        else if (volba == 'q' || volba == 'Q')
        {
            break;  // ukončení programu
        }
    }

	delete(lobjRandomGen);
    return 0;
}

