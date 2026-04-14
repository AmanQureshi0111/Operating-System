# Operating System Interview Codes (C++)

This repository contains important Operating System algorithms organized by topic for interview preparation.

## Topics Covered

### 1) CPU Scheduling (`cpu_scheduling_algos`)
- FCFS
- SJF (Non-Preemptive)
- Priority Scheduling (Non-Preemptive)
- Round Robin
- `interview_main.cpp` menu driver

### 2) Page Replacement / Memory Management (`page_scheduling_algos`)
- FIFO
- LRU (Counter)
- LRU (Doubly Linked List)
- Optimal Page Replacement
- `main.cpp` driver

### 3) Deadlock (`deadlock_algos`)
- Banker's Algorithm (safe state / safe sequence)
- `main.cpp` driver

### 4) Synchronization (`synchronization_problems`)
- Producer-Consumer Problem (threads, mutex, semaphores)
- `main.cpp` driver

### 5) Disk Scheduling (`disk_scheduling_algos`)
- FCFS
- SSTF
- SCAN
- `main.cpp` driver

## Build and Run (example)

Compile a module driver with any C++17+ compiler:

```bash
g++ cpu_scheduling_algos/interview_main.cpp -std=c++17 -o cpu_sched
./cpu_sched
```

Use the corresponding `main.cpp` inside each topic folder to run that topic.
