#include "FCFS.cpp"
#include "Priority.cpp"
#include "RoundRobin.cpp"
#include "SJF.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "===== CPU Scheduling Interview Pack =====\n";
  cout << "1. FCFS\n2. SJF (Non-Pre1emptive)\n3. Priority (Non-Preemptive)\n4. "
          "Round Robin\n";
  cout << "Select algorithm: ";

  int choice;
  cin >> choice;

  if (choice == 4) {
    int process_count;
    cout << "Enter number of processes: ";
    cin >> process_count;

    vector<int> burst_time(process_count);
    cout << "Enter burst times: ";
    for (int i = 0; i < process_count; i++) {
      cin >> burst_time[i];
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    RoundRobin rr(burst_time, quantum);
    cout << "\n--- Round Robin Result ---\n";
    rr.run();
    return 0;
  }

  int process_count;
  cout << "Enter number of processes: ";
  cin >> process_count;

  if (choice == 1) {
    vector<FCFS::Process> processes(process_count);
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < process_count; i++) {
      processes[i].id = i + 1;
      cin >> processes[i].arrival >> processes[i].burst;
    }
    cout << "\n--- FCFS Result ---\n";
    FCFS::run(processes);
  } else if (choice == 2) {
    vector<SJF_NonPreemptive::Process> processes(process_count);
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < process_count; i++) {
      processes[i].id = i + 1;
      cin >> processes[i].arrival >> processes[i].burst;
    }
    cout << "\n--- SJF Result ---\n";
    SJF_NonPreemptive::run(processes);
  } else if (choice == 3) {
    vector<Priority_NonPreemptive::Process> processes(process_count);
    cout << "Enter arrival time, burst time, and priority for each process:\n";
    for (int i = 0; i < process_count; i++) {
      processes[i].id = i + 1;
      cin >> processes[i].arrival >> processes[i].burst >>
          processes[i].priority;
    }
    cout << "\n--- Priority Result ---\n";
    Priority_NonPreemptive::run(processes);
  } else {
    cout << "Invalid choice\n";
  }

  return 0;
}
