#include "ProducerConsumer.cpp"
#include <iostream>
#include <thread>

using namespace std;

int main() {
  int buffer_size, item_count;
  cout << "Enter buffer size and item count: ";
  cin >> buffer_size >> item_count;

  ProducerConsumer pc(buffer_size);

  thread producer_thread(&ProducerConsumer::producer, &pc, item_count);
  thread consumer_thread(&ProducerConsumer::consumer, &pc, item_count);

  producer_thread.join();
  consumer_thread.join();

  cout << "Producer-Consumer execution completed.\n";
  return 0;
}
