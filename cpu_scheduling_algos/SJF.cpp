#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class SJF_NonPreemptive {
public:
  struct Process {
    int id;
    int arrival;
    int burst;
  };

  static void run(const vector<Process> &processes) {
    int n = static_cast<int>(processes.size());
    vector<int> waiting_time(n, 0), turnaround_time(n, 0), completion_time(n, 0);
    vector<bool> completed(n, false);
    int done = 0;
    int current_time = 0;

    while (done < n) {
      int selected = -1;
      int min_burst = INT_MAX;

      for (int i = 0; i < n; i++) {
        if (!completed[i] && processes[i].arrival <= current_time &&
            processes[i].burst < min_burst) {
          min_burst = processes[i].burst;
          selected = i;
        }
      }

      if (selected == -1) {
        current_time++;
        continue;
      }

      current_time += processes[selected].burst;
      completion_time[selected] = current_time;
      turnaround_time[selected] =
          completion_time[selected] - processes[selected].arrival;
      waiting_time[selected] = turnaround_time[selected] - processes[selected].burst;
      completed[selected] = true;
      done++;
    }

    double total_waiting = 0;
    double total_turnaround = 0;

    cout << left << setw(10) << "PID" << setw(10) << "AT" << setw(10) << "BT"
         << setw(10) << "WT" << setw(10) << "TAT" << '\n';
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
      total_waiting += waiting_time[i];
      total_turnaround += turnaround_time[i];
      cout << left << setw(10) << ("P" + to_string(processes[i].id)) << setw(10)
           << processes[i].arrival << setw(10) << processes[i].burst
           << setw(10) << waiting_time[i] << setw(10) << turnaround_time[i]
           << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage waiting time: " << total_waiting / n << '\n';
    cout << "Average turnaround time: " << total_turnaround / n << '\n';
  }
};
