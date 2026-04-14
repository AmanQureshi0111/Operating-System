#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class ProducerConsumer {
  queue<int> buffer;
  const int buffer_size;
  mutex buffer_mutex;
  condition_variable not_full;
  condition_variable not_empty;

public:
  ProducerConsumer(int size) : buffer_size(size) {}

  void producer(int items_to_produce) {
    for (int item = 1; item <= items_to_produce; item++) {
      {
        unique_lock<mutex> lock(buffer_mutex);
        not_full.wait(lock, [this] {
          return static_cast<int>(buffer.size()) < buffer_size;
        });
        buffer.push(item);
        cout << "Produced: " << item << '\n';
      }
      not_empty.notify_one();
      this_thread::sleep_for(chrono::milliseconds(50));
    }
  }

  void consumer(int items_to_consume) {
    for (int i = 0; i < items_to_consume; i++) {
      int item;
      {
        unique_lock<mutex> lock(buffer_mutex);
        not_empty.wait(lock, [this] { return !buffer.empty(); });
        item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << '\n';
      }
      not_full.notify_one();
      this_thread::sleep_for(chrono::milliseconds(80));
    }
  }
};
