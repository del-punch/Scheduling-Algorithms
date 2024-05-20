#include <iostream>
#include <algorithm>
#include "_PRIORITY.h"
#include <vector>

_PRIORITY::_PRIORITY(int procesos) : ARRAYS(procesos) {}

void _PRIORITY::find_wt() {
    int completed = 0;
    int current_process = -1;
    int meter, _meter =-1;
    int finish_time;
    int t = 0;

    std::vector <int> remaining(processes);

    for (int i = 0; i < processes; i++) {
        remaining[i] = bt[i];
    }

    while (completed < processes) {
        pair_sort(priority, index);

        current_process = -1;

        for (int i = 0; i < processes; i++) {
            if (at[index[i]] <= t && remaining[index[i]] > 0) {
                
                current_process = i;
                meter = current_process;

                if (meter != _meter) {
                    ccP.push_back(index[current_process]);
                    ccT.push_back(t);
                }
                break;
            }
        }

        if (current_process != -1) {
            remaining[index[current_process]]--;
            t++;
            _meter = current_process;
            if (remaining[index[current_process]] == 0) {
                finish_time = t;
                wt[index[current_process]] = finish_time - bt[index[current_process]] - at[index[current_process]];

                if (wt[index[current_process]] < 0)
                    wt[index[current_process]] = 0;

                completed++;
                current_process = -1;
            }
        }
        else {
            t++;
        }
    }
}

void _PRIORITY::find_tat() {
    for (int i = 0; i < processes; i++) {
        tat[i] = bt[i] + wt[i];
    }
}