#include <iostream>
#include <unordered_map>

using namespace std;
class node {
public:
  node *prev, *next;
  int val;
  node() { prev = next = nullptr; }
  node(int val) {
    this->val = val;
    prev = next = nullptr;
  }
  node(int val, node *prev, node *next) {
    this->val = val;
    this->prev = prev;
    this->next = next;
  }
};
class LRU_DLL {
  int frames;
  int faults;
  unordered_map<int, node *> mp;
  node *head, *tail;

public:
  LRU_DLL(int f) {
    faults = 0;
    frames = f;
    tail = new node(-1);
    head = new node(-1);
    tail->prev = head;
    head->next = tail;
  }
  void addPage(int p) {
    if (mp.find(p) != mp.end()) {
      removePage(p);
      cout << "page hit = " << p << endl;
    } else {
      cout << "page fault =" << p << endl;
      faults++;
    }
    if (mp.size() == frames) {
      removePage(head->next->val);
    }
    node *temp = new node(p, tail->prev, tail);
    tail->prev = temp;
    temp->prev->next = temp;
    mp[p] = temp;
  }
  void removePage(int p) {
    node *temp = mp[p];
    mp.erase(p);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
  }
  int page_fault() { return faults; }
};