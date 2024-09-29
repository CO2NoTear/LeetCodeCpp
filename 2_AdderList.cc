struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = new ListNode;
    ListNode *res_tail = result;

    ListNode *it1 = l1, *it2 = l2;
    int carry = 0;
    while (it1 && it2) {
      res_tail->next = new ListNode((carry + it1->val + it2->val) % 10);
      res_tail = res_tail->next;
      carry = (carry + it1->val + it2->val) / 10;
      it1 = it1->next;
      it2 = it2->next;
    }
    while (it1) {
      res_tail->next = new ListNode((carry + it1->val) % 10);
      res_tail = res_tail->next;
      carry = (carry + it1->val) / 10;
      it1 = it1->next;
    }
    while (it2) {
      res_tail->next = new ListNode((carry + it2->val) % 10);
      res_tail = res_tail->next;
      carry = (carry + it2->val) / 10;
      it2 = it2->next;
    }
    if (carry > 0) {
      res_tail->next = new ListNode(carry % 10);
      res_tail = res_tail->next;
    }

    return result->next;
  }
};
