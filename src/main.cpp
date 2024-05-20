#include <iostream>
#include "ARRAYS.h"
#include "FCFS.h"
#include "SJF.h"
#include "PRIORITY.h"
#include "SRTF.h"
#include <algorithm>
#include <numeric>
#include "_PRIORITY.h"
#include "ROUND.h"
#include "../include/color.hpp"

int main(){
	int mode;
	int processes;

	std::cout << dye::green("ALGORITHMS\n");
	printf("\n1)FIRST COME FIRTS SERVED\t\t\t2)SHORTEST JOB FIRTS\n");
	printf("\n3)PRIORITY SCHEDULING\t\t\t\t4)SHORTEST REMAINING JOB FIRTS\n");
	printf("\n5)PREEMPTIVE PRIORITY SCHEDULING\t\t6)ROUND-ROBIN SCHEDULING\n");

	std::cout<<dye::black_on_red("\nS: ");
	(void)scanf_s("%d", &mode);

	switch (mode) {
	case 1:
		{
		printf("\nNumber of processes: ");
		(void)scanf_s("%d", &processes);

		FCFS* driver = new FCFS(processes);

		printf("\nPID\n");
		driver->fill_PID();

		printf("\nBurst time\n");
		driver->fill_bt();

		driver->find_wt();

		driver->find_tat();

		printf("\nPROCESS\t\tBURST TIME\tEXECUTION TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
		for (int i = 0; i <processes; i++){
			printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n\n", i+1, driver->get_PID(i), driver->get_bt(i), driver->get_bt(i), driver->get_wt(i), driver->get_tat(i));
		}

		for (int i = 0; i < processes; i++) {
			if (i == 0) {
				printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i)+1, driver->get_PID(i), driver->get_ccT(i+1));
			}
			else if (i == processes - 1) {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i)+1, driver->get_PID(i), driver->get_bt_accumulate());
			}
			else {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i)+1, driver->get_PID(i), driver->get_ccT(i + 1));
			}

		}
		
		driver->print_avgs();

		delete driver;
		}
		break;

	case 2:
		{
		printf("\nNumber of processes: ");
		(void)scanf_s("%d", &processes);

		SJF* driver = new SJF(processes);

		printf("\nPID\n");
		driver->fill_PID();

		printf("\nBurst time\n");
		driver->fill_bt();

		driver->find_wt();

		driver->find_tat();

		printf("\nPROCESS\t\tBURST TIME\tEXECUTION TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
		for (int i = 0; i < processes; i++) {
			printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n\n", i + 1, driver->get_PID(i), driver->get_bt(i), driver->get_bt(i), driver->get_wt(i), driver->get_tat(i));
		}

		for (int i = 0; i < processes; i++) {
			if (i == 0) {
				printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i) + 1, driver->get_PID(i), driver->get_ccT(i+1));
			}
			else if (i == processes - 1) {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(i), driver->get_bt_accumulate());
			}
			else {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(i), driver->get_ccT(i+1));
			}

		}

		driver->print_avgs();

		delete driver;
		}
		break;
	case 3:
			{
		int tiebreaker;

			printf("\nNumber of processes: ");
			(void)scanf_s("%d", &processes);

			PRIORITY* driver = new PRIORITY(processes);

			printf("\nPID\n");
			driver->fill_PID();

			printf("\nBurst time\n");
			driver->fill_bt();

			printf("\nPriority\n");
			driver->fill_priority();

			printf("\nTiebreaker [0) FCFS	1)SJF]: ");
			(void)scanf_s("%d", &tiebreaker);

			driver->find_wt(tiebreaker);

			driver->find_tat();

			printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tEXECUTION TIME\t\tWAITING TIME\tTURNAROUND TIME\n\n");
			for (int i = 0; i < processes; i++) {
				printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n\n", i + 1, driver->get_PID(i), driver->get_bt(i), driver->get_priority(i), driver->get_bt(i), driver->get_wt(i), driver->get_tat(i));
			}


			for (int i = 0; i < processes; i++) {
				if (i == 0) {
					printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
				}
				else if (i == processes - 1) {
					printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_bt_accumulate());
				}
				else {
					printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
				}

			}

			driver->print_avgs();

			delete driver;
			}
		break;
	case 4:
	{
		printf("\nNumber of processes: ");
		(void)scanf_s("%d", &processes);

		SRTF* driver = new SRTF(processes);

		printf("\nPID\n");
		driver->fill_PID();

		printf("\nBurst time\n");
		driver->fill_bt();

		printf("\nArrive time\n");
		driver->fill_at();

		driver->find_wt();

		driver->find_tat();

		printf("\nPROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
		for (int i = 0; i < processes; i++) {
			printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n\n", i + 1, driver->get_PID(i), driver->get_bt(i), driver->get_at(i), driver->get_wt(i), driver->get_tat(i));
		}


		for (int i = 0; i < driver->get_ccP_size(); i++) {
			if (i == 0) {
				printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
			}
			else if (i == driver->get_ccP_size() - 1) {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_bt_accumulate());
			}
			else {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
			}

		}


		driver->print_avgs();

		delete driver;
		}
		break;
	case 5:
		{
			printf("\nNumber of processes: ");
			(void)scanf_s("%d", &processes);

			_PRIORITY* driver = new _PRIORITY(processes);

			printf("\nPID\n");
			driver->fill_PID();

			printf("\nBurst time\n");
			driver->fill_bt();

			printf("\nPRIORITY\n");
			driver->fill_priority();

			printf("\nArrive time\n");
			driver->fill_at();

			driver->find_wt();

			driver->find_tat();

			printf("\nPROCESS\t\tBURST TIME\tARRIVAL TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n\n");
			for (int i = 0; i < processes; i++) {
				printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n", i + 1, driver->get_PID(i), driver->get_bt(i), driver->get_at(i), driver->get_priority(i), driver->get_wt(i), driver->get_tat(i));
			}

			for (int i = 0; i < driver->get_ccP_size(); i++) {
				if (i == 0) {
					printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
				}
				else if (i == driver->get_ccP_size() - 1) {
					printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_bt_accumulate());
				}
				else {
					printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
				}

			}


			driver->print_avgs();

			delete driver;
		}
		break;
	case 6:
	{
		int quantum;

		printf("\nNumber of processes: ");
		(void)scanf_s("%d", &processes);

		ROUND* driver = new ROUND(processes);

		printf("\nQuantum: ");
		(void)scanf_s("%d", &quantum);

		printf("\nPID\n");
		driver->fill_PID();

		printf("\nBurst time\n");
		driver->fill_bt();

		printf("\nArrive time\n");

		driver->fill_at();

		driver->find_wt(quantum);

		driver->find_tat();

		printf("\nPROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME\n\n");
		for (int i = 0; i < processes; i++) {
			printf("\nP%d[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n\n", i + 1, driver->get_PID(i), driver->get_bt(i),driver->get_at(i), driver->get_wt(i), driver->get_tat(i));
		}

		for (int i = 0; i < driver->get_ccP_size(); i++) {
			if (i == 0) {
				printf("[%d (P%d[%d]) %d]\t", 0, driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
			}
			else if (i == driver->get_ccP_size() - 1) {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_bt_accumulate());
			}
			else {
				printf("[%d (P%d[%d]) %d]\t", driver->get_ccT(i), driver->get_ccP(i) + 1, driver->get_PID(driver->get_ccP(i)), driver->get_ccT(i + 1));
			}

		}

		driver->print_avgs();





		delete driver;
	}
		break;
	default:
		break;
	}
}

