/*
Problem Statement : Maximum Shop Visited by K person.
Approach : Greedy.

*/
#include <iostream>
#include <vector>
using namespace std;

int FindMinimum(vector<int>& Diff, vector<bool>& NonVisited) {
	int minIndex = -1;
	for (int i = 0; i < Diff.size(); i++) {
		if (NonVisited[i]) {
			if (minIndex == -1 || Diff[i] < Diff[minIndex]) {
				minIndex = i;
			}
		}
	}
	return minIndex;
}

int main() {
	int N, K;
	cout << "Enter the number of Shops [N]: ";
	cin >> N;

	vector<int> Starting(N);
	vector<int> Ending(N);
	vector<int> Diff(N);
	vector<bool> NonVisited(N, true);

	cout << "Enter the Number of Persons [K]: ";
	cin >> K;

	for (int Shop = 0; Shop < N; Shop++) {
		cout << "Enter the Starting and Ending Time for Shop " << Shop << ": ";
		cin >> Starting[Shop] >> Ending[Shop];
		Diff[Shop] = Ending[Shop] - Starting[Shop];
	}

	int total_Visits = 0;
	for (int person = 0; person < K; person++) {
		int minpos = FindMinimum(Diff, NonVisited);
		if (minpos == -1) break;
		NonVisited[minpos] = false;
		total_Visits++;

		for (int shop = 0; shop < N; shop++) {
			if ((Starting[minpos] > Starting[shop]) &&
			        (Ending[minpos] > Ending[shop]) &&
			        (Starting[minpos] > Ending[shop]) &&
			        (NonVisited[shop]))
			{
				total_Visits++;
				NonVisited[shop] = false;
			}
		}
	}

	cout << "Total Visits: " << total_Visits << endl;
	return 0;
}
