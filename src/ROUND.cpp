#include<iostream>
#include "ROUND.h"
#include <algorithm>



ROUND::ROUND(int processes) : ARRAYS(processes) {

}

void ROUND::find_wt(int quantum) {
    int completed = 0;
    int t = 0;
    int meter, _meter = -1;

    std::vector<int> remaining(processes, 0);

    for (int i = 0; i < processes; i++) {
        remaining[i] = bt[i];
    }

    while (completed < processes) {
        for (int i = 0; i < processes; i++) {
            
            int current_process = i;

            meter = current_process;

            if (meter != _meter) {
                ccP.push_back(current_process);
                ccT.push_back(t);
            }


            if (at[current_process] <= t && remaining[current_process] > 0) {
                int slice = std::min(quantum, remaining[current_process]);
                remaining[current_process] -= slice;
                t += slice;
                _meter = current_process;

                if (remaining[current_process] == 0) {
                    wt[current_process] = t - bt[current_process] - at[current_process];

                    if (wt[current_process] < 0) {
                        wt[current_process] = 0;
                    }

                    completed++;
                }
            }
        }
    }
}


void ROUND::find_tat() {
    for (int i = 0; i < processes; i++)
        tat[i] = bt[i] + wt[i];
}
