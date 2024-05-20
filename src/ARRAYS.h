#pragma once
#include <vector>

class ARRAYS
{
public:
	ARRAYS(int processes);

	~ARRAYS();

	void fill_bt();
	void fill_priority();
	void fill_PID();
	void fill_at();


	void print_avgs();

	int get_bt(int indice);
	int get_tat(int indice);
	int get_wt(int indice);
	int get_index(int indice);
	int get_priority(int indice);
	int get_PID(int indice);
	int get_bt_accumulate();
	int get_at(int indice);
	int get_ccP(int indice);
	int get_ccT(int indice);
	int get_ccP_size();

	std::vector <int> bt;
	std::vector <int> tat;
	std::vector <int> wt;
	std::vector <int> index;
	std::vector <int> priority;
	std::vector <int> PID;
	std::vector <int> at;
	std::vector <int> ccT;
	std::vector <int> ccP;
	std::vector <int> rt;

	void pair_sort(std::vector<int>& first_array, std::vector<int>& second_array);
	void triple_sort(std::vector<int>& first_array, std::vector<int>& second_array, std::vector<int>& tiebreaker_array);

	int processes;

private:

};
