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
	// init critick� sekce
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

	// samaz�n� critick� sekce
	DeleteCriticalSection(&mcsGenerator);
}

//--------------------------------------
//thread generov�n� ��sel
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
//vrac� aktu�ln� ��slo
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



//�kol: v mainu
//		aby kdy� zm��knu N, tak se vygeneruje ��slo a kdy� zm��knu Q, tak program ukon�im