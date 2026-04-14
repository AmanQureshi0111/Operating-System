#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class FCFS {
public:
  struct Process {
    int id;
    int arrival;
    int burst;
  };

  static void run(const vector<Process> &input_processes) {
    vector<Process> processes = input_processes;
    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b) {
           if (a.arrival == b.arrival) {
             return a.id < b.id;
           }
           return a.arrival < b.arrival;
         });

    vector<int> waiting_time(processes.size(), 0);
    vector<int> turnaround_time(processes.size(), 0);
    int current_time = 0;

    for (int i = 0; i < static_cast<int>(processes.size()); i++) {
      current_time = max(current_time, processes[i].arrival);
      waiting_time[i] = current_time - processes[i].arrival;
      current_time += processes[i].burst;
      turnaround_time[i] = waiting_time[i] + processes[i].burst;
    }

    double total_waiting = 0;
    double total_turnaround = 0;

    cout << left << setw(10) << "PID" << setw(10) << "AT" << setw(10) << "BT"
         << setw(10) << "WT" << setw(10) << "TAT" << '\n';
    cout << "---------------------------------------------\n";

    for (int i = 0; i < static_cast<int>(processes.size()); i++) {
      total_waiting += waiting_time[i];
      total_turnaround += turnaround_time[i];
      cout << left << setw(10) << ("P" + to_string(processes[i].id)) << setw(10)
           << processes[i].arrival << setw(10) << processes[i].burst << setw(10)
           << waiting_time[i] << setw(10) << turnaround_time[i] << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage waiting time: " << total_waiting / processes.size()
         << '\n';
    cout << "Average turnaround time: " << total_turnaround / processes.size()
         << '\n';
  }
};
