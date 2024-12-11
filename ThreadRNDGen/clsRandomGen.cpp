#include "clsRandomGen.h"
#include <time.h>

//--------------------------------------
//start threadu
//--------------------------------------
DWORD WINAPI MyThreadStarter(LPVOID lpParam)
{
	clsRandomGen* lobjGen;

	lobjGen = (clsRandomGen*)lpParam;

	lobjGen->ThreadGen();

	return 0;
}
//--------------------------------------
//konstruktor
//--------------------------------------
clsRandomGen::clsRandomGen()
{
	// init critické sekce
	InitializeCriticalSection(&mcsGenerator);

	// seed generatoru
	srand(time(NULL));

	// generovat cislo
	mintActNumber = rand();

	// thread bude bezet
	mblThreadStop = false;
}

//--------------------------------------
//destruktor
//--------------------------------------
clsRandomGen ::~clsRandomGen()
{
	mblThreadStop = true;

	// samazání critické sekce
	DeleteCriticalSection(&mcsGenerator);
}

//--------------------------------------
//thread generování èísel
//--------------------------------------
void clsRandomGen::ThreadGen()
{
	try
	{

		do
		{
		
			// vstoupit
			EnterCriticalSection(&mcsGenerator);

			//generovat cislo
			mintActNumber = rand();

			// vystoupit
			LeaveCriticalSection(&mcsGenerator);

		}
		while (mblThreadStop == false);

	}
	catch (...)

	{
		// vystoupit
		LeaveCriticalSection(&mcsGenerator);
	}
}

//--------------------------------------
//vrací aktuální èíslo
//--------------------------------------
int clsRandomGen::GetRND()
{
	int lintNumber;
	// vstoupit
	EnterCriticalSection(&mcsGenerator);

	lintNumber = mintActNumber;

	// vystoupit
	LeaveCriticalSection(&mcsGenerator);

	return lintNumber;
}



//úkol: v mainu
//		aby když zmáèknu N, tak se vygeneruje èíslo a když zmáèknu Q, tak program ukonèim