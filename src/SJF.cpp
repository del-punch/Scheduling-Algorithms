#include<iostream>
#include "SJF.h"

SJF::SJF(int procesos) : ARRAYS(procesos) {}

void SJF::find_wt() {
    wt[0] = 0;

    pair_sort(bt, index);

    for (int i = 1; i < processes; i++) {
        wt[index[i]] = 0;
        for (int j = 0; j < i; j++) {
            wt[index[i]] += bt[j];
        }
    }

    pair_sort(index, bt); 



    for (int i = 0; i < processes; i++) {
        ccP.push_back(index[i]);
        ccT.push_back(wt[index[i]]);
    }

    pair_sort(ccT, ccP);

}

void SJF::find_tat() {
    for (int i = 0; i < processes; i++) {
        tat[i] = bt[i] + wt[i];
    }
}


