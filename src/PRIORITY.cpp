#include<iostream>
#include "PRIORITY.h"

PRIORITY::PRIORITY(int procesos) : ARRAYS(procesos) {}

void PRIORITY::find_wt(int tiebreaker) {
    wt[0] = 0;

    if (tiebreaker == 1) {
        triple_sort(priority, index, bt);

        for (int i = 1; i < processes; i++) {
            wt[index[i]] = 0;
            for (int j = 0; j < i; j++) {
                wt[index[i]] += bt[j];
            }
        }

        for (int i = 0; i < processes; i++) {
            ccP.push_back(index[i]);
            ccT.push_back(wt[index[i]]);
        }

        pair_sort(ccT, ccP);

        triple_sort(index, priority, bt);

    }
    else {
        pair_sort(priority, index);
        for (int i = 1; i < processes; i++) {
            wt[index[i]] = 0;
            for (int j = 0; j < i; j++) {
                wt[index[i]] += bt[index[j]];
            }
        }

        for (int i = 0; i < processes; i++) {
            ccP.push_back(index[i]);
            ccT.push_back(wt[index[i]]);
        }

        pair_sort(ccT, ccP);

        pair_sort(index, priority);
    }


    
}

void PRIORITY::find_tat() {
    for (int i = 0; i < processes; i++) {
        tat[i] = bt[i] + wt[i];
    }
}


