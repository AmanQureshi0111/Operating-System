#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Optimal {
  int frame_count;
  int faults;
  vector<int> frames;

public:
  Optimal(int frames_limit) : frame_count(frames_limit), faults(0) {}

  int findVictimIndex(const vector<int> &pages, int current_index) {
    int farthest_use = -1;
    int victim_index = -1;

    for (int i = 0; i < static_cast<int>(frames.size()); i++) {
      int next_use = -1;
      for (int j = current_index + 1; j < static_cast<int>(pages.size()); j++) {
        if (pages[j] == frames[i]) {
          next_use = j;
          break;
        }
      }

      if (next_use == -1) {
        return i;
      }
      if (next_use > farthest_use) {
        farthest_use = next_use;
        victim_index = i;
      }
    }

    return victim_index;
  }

  void run(const vector<int> &pages) {
    unordered_set<int> in_memory;

    for (int i = 0; i < static_cast<int>(pages.size()); i++) {
      int page = pages[i];
      if (in_memory.find(page) != in_memory.end()) {
        cout << "Page " << page << " -> HIT\n";
        continue;
      }

      faults++;
      cout << "Page " << page << " -> FAULT\n";

      if (static_cast<int>(frames.size()) < frame_count) {
        frames.push_back(page);
        in_memory.insert(page);
      } else {
        int victim_pos = findVictimIndex(pages, i);
        int victim_page = frames[victim_pos];
        in_memory.erase(victim_page);
        frames[victim_pos] = page;
        in_memory.insert(page);
        cout << "Evicted page: " << victim_page << '\n';
      }
    }
  }

  int page_faults() const { return faults; }
};
