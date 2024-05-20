#pragma once
#include "ARRAYS.h"

class FCFS:public ARRAYS{
public:
	FCFS(int procesos);

	void find_wt();

	void find_tat();
};
