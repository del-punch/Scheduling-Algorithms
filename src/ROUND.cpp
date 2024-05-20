#include <iostream>
#include "ROUND.h"
#include <algorithm>
#include <vector>


ROUND::ROUND(int processes) : ARRAYS(processes) {}


void ROUND::find_wt(int quantum) {
    int completed = 0;
    int t = 0;

    std::vector<int> remaining(processes, 0);
    std::vector<std::pair<int, int>> context_changes; 

    for (int i = 0; i < processes; i++) {
        remaining[i] = bt[i];
    }

    int prev_process = -1;
    while (completed < processes) {
        bool process_executed = false; 

        for (int i = 0; i < processes; i++) {
            int current_process = i;

            if (at[current_process] <= t && remaining[current_process] > 0) {

                if (current_process != prev_process) {
                    ccP.push_back(current_process);
                    ccT.push_back(t);
                    prev_process = current_process; 
                }

                int slice = std::min(quantum, remaining[current_process]);
                remaining[current_process] -= slice;
                t += slice;
                process_executed = true;

                if (remaining[current_process] == 0) {
                    wt[current_process] = t - bt[current_process] - at[current_process];
                    if (wt[current_process] < 0) {
                        wt[current_process] = 0;
                    }
                    completed++;
                }
            }
        }

        if (!process_executed) {
            t++;
        }
    }


}

void ROUND::find_tat() {
    for (int i = 0; i < processes; i++)
        tat[i] = bt[i] + wt[i];
}
