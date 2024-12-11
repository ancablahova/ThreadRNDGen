#include <windows.h>
#include "clsRandomGen.h"
#include <iostream>


int main()
{
	int lintCislo;
	DWORD ldwThreadID;
	HANDLE lhThread;
	clsRandomGen* lobjRandomGen;

	//vytvoření objektu
	lobjRandomGen = new clsRandomGen();

	//start generování čísel

	lhThread = CreateThread(NULL, 0, MyThreadStarter, lobjRandomGen, 0, &ldwThreadID);

	// generovat
	lintCislo = lobjRandomGen->GetRND();
	printf("%i", lintCislo);

	// pozastavit na 10s
	Sleep(10000);

	delete(lobjRandomGen);
}

