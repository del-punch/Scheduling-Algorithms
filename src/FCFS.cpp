#include<iostream>
#include "FCFS.h"


FCFS::FCFS(int procesos) : ARRAYS(procesos) {

}

void FCFS::find_wt() {
    this->wt[0] = 0;
    for (int i = 1; i < processes; i++) {
        this->wt[i] = 0;
        for (int j = 0; j < i; j++)
            this->wt[i] += this->bt[j];
    }

    for (int i = 0; i < processes; i++) {
        ccP.push_back(index[i]);
        ccT.push_back(wt[i]);
    }

}



void FCFS::find_tat() {
    for (int i = 0; i < processes; i++){
        this->tat[i] = this->bt[i] + this->wt[i];
    }
}




