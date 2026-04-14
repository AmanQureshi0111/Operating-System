#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class LRU_Counter {
  int counter;
  int frame_count;
  map<int, int> counter_to_page;
  unordered_map<int, int> page_to_counter;
  int page_faults_count;

public:
  LRU_Counter(int frames) : counter(0), frame_count(frames), page_faults_count(0) {}

  void allotPage(int page) {
    if (page_to_counter.find(page) == page_to_counter.end()) {
      page_faults_count++;
      cout << "Page " << page << " -> FAULT" << endl;
    }

    if (counter_to_page.size() == frame_count) {
      int least_recent_page = counter_to_page.begin()->second;
      counter_to_page.erase(counter_to_page.begin());
      page_to_counter.erase(least_recent_page);
      cout << "Evicted page: " << least_recent_page << endl;
    }

    counter_to_page[counter] = page;
    page_to_counter[page] = counter;
    counter++;
  }

  int page_fault() { return page_faults_count; }
};
