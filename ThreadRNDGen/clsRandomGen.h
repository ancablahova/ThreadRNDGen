#pragma once
#include <windows.h>

DWORD WINAPI MyThreadStarter(LPVOID lpParam);

class clsRandomGen
{
private:
	int mintActNumber;
	bool mblThreadStop;
	CRITICAL_SECTION mcsGenerator;

public:
	clsRandomGen();
	~clsRandomGen();
	void ThreadGen();			//thread generování èísel-instruktor
	int GetRND();				//vrací aktuální èíslo-destruktor
};

