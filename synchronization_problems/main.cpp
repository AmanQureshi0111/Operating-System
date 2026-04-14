#include "ProducerConsumer.cpp"
#include <iostream>
#include <thread>

using namespace std;

int main() {
  int buffer_size, item_count;
  cout << "Enter buffer size and item count: ";
  cin >> buffer_size >> item_count;

  if (buffer_size <= 0 || item_count < 0) {
    cout << "Invalid input. Buffer size must be > 0 and item count must be >= "
            "0.\n";
    return 1;
  }

  ProducerConsumer pc(buffer_size);

  std::thread producer_thread(&ProducerConsumer::producer, &pc, item_count);
  std::thread consumer_thread(&ProducerConsumer::consumer, &pc, item_count);

  producer_thread.join();
  consumer_thread.join();

  cout << "Producer-Consumer execution completed.\n";
  return 0;
}
