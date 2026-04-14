#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>


using namespace std;

class RoundRobin {
  vector<int> burst_time;
  int time_quantum;

public:
  RoundRobin(const vector<int> &bursts, int quantum)
      : burst_time(bursts), time_quantum(quantum) {}

  void run() {
    int process_count = static_cast<int>(burst_time.size());
    vector<int> remaining_time = burst_time;
    vector<int> waiting_time(process_count, 0);
    vector<int> turnaround_time(process_count, 0);
    queue<int> ready_queue;
    int current_time = 0;

    for (int i = 0; i < process_count; i++) {
      ready_queue.push(i);
    }

    while (!ready_queue.empty()) {
      int process_id = ready_queue.front();
      ready_queue.pop();

      if (remaining_time[process_id] > time_quantum) {
        current_time += time_quantum;
        remaining_time[process_id] -= time_quantum;
        ready_queue.push(process_id);
      } else {
        current_time += remaining_time[process_id];
        waiting_time[process_id] = current_time - burst_time[process_id];
        turnaround_time[process_id] = current_time;
        remaining_time[process_id] = 0;
      }
    }

    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    cout << left << setw(12) << "Process" << setw(12) << "Burst Time"
         << setw(14) << "Waiting Time" << setw(16) << "Turnaround Time" << '\n';
    cout << "----------------------------------------------------------\n";

    for (int i = 0; i < process_count; i++) {
      total_waiting_time += waiting_time[i];
      total_turnaround_time += turnaround_time[i];

      cout << left << setw(12) << ("P" + to_string(i + 1)) << setw(12)
           << burst_time[i] << setw(14) << waiting_time[i] << setw(16)
           << turnaround_time[i] << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage waiting time: " << (total_waiting_time / process_count)
         << '\n';
    cout << "Average turnaround time: "
         << (total_turnaround_time / process_count) << '\n';
  }
};
