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
//thread generov�n� ��sel
//--------------------------------------
void clsRandomGen::ThreadGen()
{

}
//--------------------------------------
//vrac� aktu�ln� ��slo
//--------------------------------------
int clsRandomGen::GetRND()
{

}