#include <iostream>
#include <algorithm>
#include "SRTF.h"
#include <vector>

SRTF::SRTF(int procesos) : ARRAYS(procesos) {}

void SRTF::find_wt() {

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, _shortest = -1, finish_time;
    bool check = false;

    std::vector <int> remaining(processes);


    for (int i = 0; i < processes; i++) {
        remaining[i] = bt[i];
    }

    while (complete != processes) {
        for (int j = 0; j < processes; j++) {
            if ((at[j] <= t) &&
                (remaining[j] < minm) && remaining[j] > 0) {
                minm = remaining[j];
                shortest = j;
                check = true;
            }
        }

        if (shortest != _shortest) {
            _shortest = shortest;
            ccP.push_back(shortest);
            ccT.push_back(t);
        }

        if (check == false) {
            t++;
            continue;
        }

        remaining[shortest]--;

        minm = remaining[shortest];

        if (minm == 0)
            minm = INT_MAX;

        if (remaining[shortest] == 0) {
            complete++;
            check = false;

            finish_time = t + 1;

            wt[shortest] = finish_time -
                bt[shortest] -
               at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void SRTF::find_tat() {
    for (int i = 0; i < processes; i++) {
        tat[i] = bt[i] + wt[i];
    }
}