#include "ARRAYS.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>

ARRAYS::ARRAYS(int processes) {
	this->processes = processes;
	bt.resize(processes);
	tat.resize(processes);
	wt.resize(processes);
	index.resize(processes);
	priority.resize(processes);
	PID.resize(processes);
	at.resize(processes);
	rt.resize(processes);

}


ARRAYS::~ARRAYS() {

}


void ARRAYS::fill_bt() {
	for (int i = 0; i < processes; i++){
		printf("P[%d]: ", PID[i]);
		(void)scanf_s("%d", &bt[i]);
	}
}

void ARRAYS::fill_priority() {
	for (int i = 0; i < processes; i++){
		printf("P[%d]: ", PID[i]);
		(void)scanf_s("%d", &priority[i]);
	}
}

void ARRAYS::fill_PID() {
	for (int i = 0; i < processes; i++){
		printf("P%d: ", i+1);
		(void)scanf_s("%d", &PID[i]);
		this->index[i] = i;
	}
}

void ARRAYS::fill_at() {
	for (int i = 0; i < processes; i++){
		printf("P[%d]: ", PID[i]);
		(void)scanf_s("%d", &at[i]);
	}
}

void ARRAYS::pair_sort(std::vector<int>& first_array, std::vector<int>& second_array) {

	int elements = first_array.size();

	std::vector<std::pair<int, int>> pair_sorted(elements);

	for (int i = 0; i < elements; ++i) {
		pair_sorted[i].first = first_array[i];
		pair_sorted[i].second = second_array[i];
	}

	std::sort(pair_sorted.begin(), pair_sorted.end());

	for (int i = 0; i < elements; ++i) {
		first_array[i] = pair_sorted[i].first;
		second_array[i] = pair_sorted[i].second;
	}
}

void ARRAYS::triple_sort(std::vector<int>& first_array, std::vector<int>& second_array, std::vector<int>& third_array) {

	int elements = first_array.size();

	std::vector<std::tuple<int, int, int>> triple_sorted(elements);

	for (int i = 0; i < elements; ++i) {
		triple_sorted[i] = std::make_tuple(first_array[i], second_array[i], third_array[i]);
	}

	std::sort(triple_sorted.begin(), triple_sorted.end(), [](const auto& left, const auto& right) {
		if (std::get<0>(left) != std::get<0>(right)) {
			return std::get<0>(left) < std::get<0>(right);
		}
		else {
			return std::get<2>(left) < std::get<2>(right);
		}
		});

	for (int i = 0; i < elements; ++i) {
		first_array[i] = std::get<0>(triple_sorted[i]);
		second_array[i] = std::get<1>(triple_sorted[i]);
		third_array[i] = std::get<2>(triple_sorted[i]);
	}
}

void ARRAYS::print_avgs() {
	
	printf("\n\nAverage Waiting Time: %.2f", (std::accumulate(wt.begin(), wt.end(), 0)) / (float)(processes));

	printf("\nAverage Turn Arround Time: %.2f ", (std::accumulate(tat.begin(), tat.end(), 0)) / (float)(processes));
}

int ARRAYS::get_bt(int indice){
	return bt[indice];
}
int ARRAYS::get_tat(int indice){
	return tat[indice];
}
int ARRAYS::get_wt(int indice) {
	return wt[indice];
}

int ARRAYS::get_index(int indice) {
	return index[indice];
}

int ARRAYS::get_priority(int indice) {
	return priority[indice];
}

int ARRAYS::get_PID(int indice) {
	return PID[indice];
}

int ARRAYS::get_bt_accumulate() {
	return std::accumulate(bt.begin(), bt.end(),0);
}

int ARRAYS::get_at(int indice) {
	return at[indice];
}

int ARRAYS::get_ccP(int indice) {
	return ccP[indice];
}
int ARRAYS::get_ccT(int indice) {
	return ccT[indice];
}

int ARRAYS::get_ccP_size() {
	return ccP.size();
}