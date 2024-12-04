#include "clsRandomGen.h"

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
clsRandomGen::~clsRandomGen()
{

}

//--------------------------------------
//thread generování èísel
//--------------------------------------
void clsRandomGen::ThreadGen()
{

}
//--------------------------------------
//vrací aktuální èíslo
//--------------------------------------
int clsRandomGen::GetRND()
{

}