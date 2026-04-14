#include "Bankers.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int processes, resources;
  cout << "Enter number of processes and resources: ";
  cin >> processes >> resources;

  vector<vector<int>> allocation(processes, vector<int>(resources));
  vector<vector<int>> maximum(processes, vector<int>(resources));
  vector<int> available(resources);

  cout << "Enter allocation matrix:\n";
  for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
      cin >> allocation[i][j];
    }
  }

  cout << "Enter maximum matrix:\n";
  for (int i = 0; i < processes; i++) {
    for (int j = 0; j < resources; j++) {
      cin >> maximum[i][j];
    }
  }

  cout << "Enter available resources vector:\n";
  for (int i = 0; i < resources; i++) {
    cin >> available[i];
  }

  cout << "\n===== Banker's Algorithm Result =====\n";
  BankersAlgorithm::run(allocation, maximum, available);
  return 0;
}
