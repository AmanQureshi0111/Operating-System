#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class FCFS_Disk {
public:
  static void run(const vector<int> &requests, int head) {
    int total_seek = 0;
    int current = head;

    cout << "Seek sequence: " << current;
    for (int request : requests) {
      total_seek += abs(request - current);
      current = request;
      cout << " -> " << current;
    }
    cout << '\n';
    cout << "Total seek operations: " << total_seek << '\n';
  }
};
