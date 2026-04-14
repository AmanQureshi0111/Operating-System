#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class SSTF {
public:
  static void run(const vector<int> &requests, int head) {
    int n = static_cast<int>(requests.size());
    vector<bool> served(n, false);
    int total_seek = 0;
    int current = head;

    cout << "Seek sequence: " << current;

    for (int count = 0; count < n; count++) {
      int idx = -1;
      int min_dist = numeric_limits<int>::max();

      for (int i = 0; i < n; i++) {
        if (!served[i]) {
          int dist = abs(requests[i] - current);
          if (dist < min_dist) {
            min_dist = dist;
            idx = i;
          }
        }
      }

      served[idx] = true;
      total_seek += abs(requests[idx] - current);
      current = requests[idx];
      cout << " -> " << current;
    }

    cout << '\n';
    cout << "Total seek operations: " << total_seek << '\n';
  }
};
