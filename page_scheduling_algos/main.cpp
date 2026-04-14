#include "FIFO.cpp"
#include "LRU_DLL.cpp"
#include "LRU_counter.cpp"
#include "Optimal.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int frames;
  cout << "Enter number of frames: ";
  cin >> frames;

  int pages_count;
  cout << "Enter number of pages in reference string: ";
  cin >> pages_count;

  vector<int> pages(pages_count);
  cout << "Enter page reference sequence: ";
  for (int i = 0; i < pages_count; i++) {
    cin >> pages[i];
  }

  cout << "\n========== FIFO Page Replacement ==========\n";
  FIFO fifo(frames);
  for (const auto &page : pages) {
    fifo.allotPage(page);
  }
  cout << "Total page faults (FIFO): " << fifo.page_faults() << endl;

  cout << "\n========== LRU Counter Page Replacement ==========\n";
  LRU_Counter lru_counter(frames);
  for (const auto &page : pages) {
    lru_counter.allotPage(page);
  }
  cout << "Total page faults (LRU Counter): " << lru_counter.page_fault()
       << endl;
  cout << "\n===========LRU Linked List===========\n";
  LRU_DLL lru_ll(frames);
  for (auto &page : pages) {
    lru_ll.addPage(page);
  }
  cout << "Total page faults (LRU Linked List): " << lru_ll.page_fault()
       << endl;

  cout << "\n========== Optimal Page Replacement ==========\n";
  Optimal optimal(frames);
  optimal.run(pages);
  cout << "Total page faults (Optimal): " << optimal.page_faults() << endl;
  return 0;
}
