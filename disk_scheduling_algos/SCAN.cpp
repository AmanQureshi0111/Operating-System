#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SCAN {
public:
  static void run(vector<int> requests, int head, int disk_size,
                  const string &direction) {
    vector<int> left, right;
    int total_seek = 0;
    int current = head;

    for (int req : requests) {
      if (req < head) {
        left.push_back(req);
      } else {
        right.push_back(req);
      }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "Seek sequence: " << current;

    if (direction == "left") {
      for (int i = static_cast<int>(left.size()) - 1; i >= 0; i--) {
        total_seek += abs(left[i] - current);
        current = left[i];
        cout << " -> " << current;
      }

      total_seek += abs(current - 0);
      current = 0;
      cout << " -> " << current;

      for (int req : right) {
        total_seek += abs(req - current);
        current = req;
        cout << " -> " << current;
      }
    } else {
      for (int req : right) {
        total_seek += abs(req - current);
        current = req;
        cout << " -> " << current;
      }

      total_seek += abs((disk_size - 1) - current);
      current = disk_size - 1;
      cout << " -> " << current;

      for (int i = static_cast<int>(left.size()) - 1; i >= 0; i--) {
        total_seek += abs(left[i] - current);
        current = left[i];
        cout << " -> " << current;
      }
    }

    cout << '\n';
    cout << "Total seek operations: " << total_seek << '\n';
  }
};
