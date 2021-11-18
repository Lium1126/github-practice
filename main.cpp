#include <iostream>
#include <vector>
#include "sort.hpp"
#include "search.hpp"

using namespace std;

#define FIRST_TARGET 38
#define SECOND_TARGET 75

void printData(vector<int> data);

int main(const int argc, const char *argv[])
{
	vector<int> data{29, 48, 70, 34, 92, 64, 26, 100, 15, 20, 82, 24, 79, 99, 87, 38, 14, 45, 94, 8};

	cout << endl
		 << "Before sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	data = githubPractice::sort(data);
	cout << "After sort" << endl;
	cout << "---------------------------------------------------------------" << endl;
	printData(data);
	cout << endl;

	cout << "Search for " << FIRST_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	if (githubPractice::search(data, FIRST_TARGET))
		cout << FIRST_TARGET << " is found!" << endl;
	else
		cout << FIRST_TARGET << " is not found!" << endl;
	cout << endl;

	cout << "Search for " << SECOND_TARGET << endl;
	cout << "---------------------------------------------------------------" << endl;
	if (githubPractice::search(data, SECOND_TARGET))
		cout << SECOND_TARGET << " is found!" << endl;
	else
		cout << SECOND_TARGET << " is not found!" << endl;
	cout << endl;

	return 0;
}

void printData(vector<int> data)
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		cout << data[i];
		if (i == size - 1)
			cout << endl;
		else
			cout << ' ';
	}
}