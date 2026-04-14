#include "FCFS_Disk.cpp"
#include "SCAN.cpp"
#include "SSTF.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "===== Disk Scheduling Interview Pack =====\n";
  cout << "1. FCFS\n2. SSTF\n3. SCAN\n";
  cout << "Select algorithm: ";

  int choice;
  cin >> choice;

  int request_count;
  cout << "Enter number of requests: ";
  cin >> request_count;

  vector<int> requests(request_count);
  cout << "Enter disk requests: ";
  for (int i = 0; i < request_count; i++) {
    cin >> requests[i];
  }

  int head;
  cout << "Enter initial head position: ";
  cin >> head;

  if (choice == 1) {
    cout << "\n--- FCFS Disk Scheduling Result ---\n";
    FCFS_Disk::run(requests, head);
  } else if (choice == 2) {
    cout << "\n--- SSTF Disk Scheduling Result ---\n";
    SSTF::run(requests, head);
  } else if (choice == 3) {
    int disk_size;
    string direction;
    cout << "Enter disk size: ";
    cin >> disk_size;
    cout << "Enter initial direction (left/right): ";
    cin >> direction;

    cout << "\n--- SCAN Disk Scheduling Result ---\n";
    SCAN::run(requests, head, disk_size, direction);
  } else {
    cout << "Invalid choice\n";
  }

  return 0;
}
