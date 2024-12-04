#include <windows.h>
#include "clsRandomGen.h"

int main()
{
	DWORD ldwThreadID;
	HANDLE lhThread;
	clsRandomGen* lobjRandomGen;

	//vytvoření objektu
	lobjRandomGen = new clsRandomGen();

	//start generování čísel

	lhThread = CreateThread(NULL, 0, MyThreadStarter, lobjRandomGen, 0, &ldwThreadID);

	delete(lobjRandomGen);
}

