#include <iostream>
#include <vector>

using namespace std;

class BankersAlgorithm {
public:
  static void run(const vector<vector<int>> &allocation,
                  const vector<vector<int>> &maximum,
                  const vector<int> &available) {
    int processes = static_cast<int>(allocation.size());
    int resources = static_cast<int>(available.size());

    vector<vector<int>> need(processes, vector<int>(resources, 0));
    for (int i = 0; i < processes; i++) {
      for (int j = 0; j < resources; j++) {
        need[i][j] = maximum[i][j] - allocation[i][j];
      }
    }

    vector<int> work = available;
    vector<bool> finish(processes, false);
    vector<int> safe_sequence;

    for (int count = 0; count < processes; count++) {
      bool allocated = false;

      for (int i = 0; i < processes; i++) {
        if (finish[i]) {
          continue;
        }

        bool can_run = true;
        for (int j = 0; j < resources; j++) {
          if (need[i][j] > work[j]) {
            can_run = false;
            break;
          }
        }

        if (can_run) {
          for (int j = 0; j < resources; j++) {
            work[j] += allocation[i][j];
          }
          finish[i] = true;
          safe_sequence.push_back(i);
          allocated = true;
        }
      }

      if (!allocated) {
        break;
      }
    }

    if (static_cast<int>(safe_sequence.size()) == processes) {
      cout << "System is in SAFE state.\nSafe sequence: ";
      for (int i = 0; i < processes; i++) {
        cout << "P" << safe_sequence[i];
        if (i + 1 != processes) {
          cout << " -> ";
        }
      }
      cout << '\n';
    } else {
      cout << "System is NOT in a safe state.\n";
    }
  }
};
