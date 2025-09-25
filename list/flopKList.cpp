#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *pivotHead = head, *pivotTail = nullptr, *newListHead = nullptr,
             *lastGroupTail = nullptr, *pivot = pivotHead;
    int cnt = 0;

    while (pivot != nullptr) {
      pivotTail = pivot;
      pivot = pivot->next;
      ++cnt;

      if (cnt % k == 0) {
        auto [groupHead, groupTail] = this->reverse(pivotHead, pivotTail->next);
        pivotHead = pivot;
        if (lastGroupTail != nullptr) {
          lastGroupTail->next = groupHead;
        }
        if (newListHead == nullptr) {
          newListHead = groupHead;
        }

        lastGroupTail = groupTail;
      }
    }
    if (cnt != 0 && lastGroupTail != nullptr && pivotHead != nullptr) {
      lastGroupTail->next = pivotHead;
    }
    return newListHead;
  }
  std::pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
    ListNode *pivot = head, *newListTail = nullptr, *needToFlop;
    while (pivot != tail) {
      needToFlop = pivot;
      pivot = needToFlop->next;
      needToFlop->next = newListTail;
      newListTail = needToFlop;
    }
    return {needToFlop, head};
  }
};

ListNode *buildList(std::vector<int> array) {
  ListNode *head, *tail;
  for (int i = 0; i < array.size(); i++) {
    ListNode *node = new ListNode(array[i]);
    if (i == 0) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}
void printList(ListNode *listHead) {
  ListNode *p = listHead;
  while (p != nullptr) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;
}

int main() {
  ListNode *list = buildList({1, 2, 3, 4, 5});
  // ListNode *list = buildList({1});
  printList(list);
  Solution sol;
  // printList(sol.reverse(list, nullptr).first);
  printList(sol.reverseKGroup(list, 3));
  return 0;
}
