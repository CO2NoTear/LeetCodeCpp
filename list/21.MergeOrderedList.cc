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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *it1 = list1, *it2 = list2;
    ListNode *prevNode = new ListNode;
    ListNode *head = prevNode;
    while (it1 != nullptr && it2 != nullptr) {
      if (it1->val < it2->val) {
        ListNode *newListNode = new ListNode(it1->val);
        it1 = it1->next;
        prevNode->next = newListNode;
        prevNode = newListNode;
      } else {
        ListNode *newListNode = new ListNode(it2->val);
        it2 = it2->next;
        prevNode->next = newListNode;
        prevNode = newListNode;
      }
    }
    while (it1 != nullptr) {
      ListNode *newListNode = new ListNode(it1->val);
      it1 = it1->next;
      prevNode->next = newListNode;
      prevNode = newListNode;
    }
    while (it2 != nullptr) {
      ListNode *newListNode = new ListNode(it2->val);
      it2 = it2->next;
      prevNode->next = newListNode;
      prevNode = newListNode;
    }
    return head->next;
  }
};

int main(int argc, char *argv[]) { return 0; }
