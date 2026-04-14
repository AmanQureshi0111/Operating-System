#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class FIFO {
  int page_faults_count;
  queue<int> page_order;
  unordered_set<int> pages_in_memory;
  int frame_count;

public:
  FIFO(int frames) : page_faults_count(0), frame_count(frames) {}

  void allotPage(int page) {
    if (pages_in_memory.find(page) == pages_in_memory.end()) {
      cout << "Page " << page << " -> FAULT" << endl;
      page_faults_count++;

      if (page_order.size() >= frame_count) {
        int evicted_page = page_order.front();
        page_order.pop();
        pages_in_memory.erase(evicted_page);
        cout << "Evicted page: " << evicted_page << endl;
      }

      pages_in_memory.insert(page);
      page_order.push(page);
    } else {
      cout << "Page " << page << " -> HIT" << endl;
    }
  }

  int page_faults() { return page_faults_count; }
};
