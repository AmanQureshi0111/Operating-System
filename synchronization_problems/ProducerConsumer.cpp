#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <semaphore>
#include <thread>

using namespace std;

class ProducerConsumer {
  queue<int> buffer;
  const int buffer_size;
  counting_semaphore<> empty_slots;
  counting_semaphore<> filled_slots;
  mutex buffer_mutex;

public:
  ProducerConsumer(int size)
      : buffer_size(size), empty_slots(size), filled_slots(0) {}

  void producer(int items_to_produce) {
    for (int item = 1; item <= items_to_produce; item++) {
      empty_slots.acquire();
      {
        lock_guard<mutex> lock(buffer_mutex);
        buffer.push(item);
        cout << "Produced: " << item << '\n';
      }
      filled_slots.release();
      this_thread::sleep_for(chrono::milliseconds(50));
    }
  }

  void consumer(int items_to_consume) {
    for (int i = 0; i < items_to_consume; i++) {
      filled_slots.acquire();
      int item;
      {
        lock_guard<mutex> lock(buffer_mutex);
        item = buffer.front();
        buffer.pop();
        cout << "Consumed: " << item << '\n';
      }
      empty_slots.release();
      this_thread::sleep_for(chrono::milliseconds(80));
    }
  }
};
