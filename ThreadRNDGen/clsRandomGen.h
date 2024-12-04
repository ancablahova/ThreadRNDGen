#pragma once
#include <windows.h>

DWORD WINAPI MyThreadStarter(LPVOID lpParam);

class clsRandomGen
{
private:
	int mintActNumber;

public:
	clsRandomGen();
	~clsRandomGen();
	void ThreadGen();			//thread generování èísel-instruktor
	int GetRND();				//vrací aktuální èíslo-destruktor
};

