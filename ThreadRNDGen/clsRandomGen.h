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
	void ThreadGen();			//thread generov�n� ��sel-instruktor
	int GetRND();				//vrac� aktu�ln� ��slo-destruktor
};

