// TODO: It's now LRU
#include <iostream>
#include <unordered_map>
using namespace std;
// TEST: to test if diff success

struct Node {
  int key_, value_;
  Node *next_, *prev_;
  Node() : key_(0), value_(0), next_(nullptr), prev_(nullptr) {}
  Node(int key, int value)
      : key_(key), value_(value), next_(nullptr), prev_(nullptr) {}
  void insertAtFront(Node *src) {
    src->next_ = this->next_;
    src->prev_ = this;
    this->next_->prev_ = src;
    this->next_ = src;
  }
  void remove() {
    next_->prev_ = prev_;
    prev_->next_ = next_;
  }
};

class LRUCache {
private:
  int capacity_;
  int size_;
  Node *head_;
  Node *tail_;
  unordered_map<int, Node *> data_;

public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    Node *dummy_head = new Node;
    Node *dummy_tail = new Node;
    dummy_head->next_ = dummy_tail;
    dummy_tail->prev_ = dummy_head;
    head_ = dummy_head;
    tail_ = dummy_tail;
  }

  int get(int key) {
    if (data_.count(key) > 0) {
      Node *new_head = data_.at(key);
      new_head->remove();
      head_->insertAtFront(new_head);
      return new_head->value_;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (data_.count(key) > 0) {
      Node *new_head = data_.at(key);
      new_head->value_ = value;
      new_head->remove();
      head_->insertAtFront(new_head);
    } else {
      Node *new_head = new Node(key, value);
      data_[key] = new_head;
      size_++;
      head_->insertAtFront(new_head);
      if (size_ > capacity_) {
        Node *to_erase = tail_->prev_;
        to_erase->remove();
        data_.erase(to_erase->key_);
        delete to_erase;
        --size_;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
