#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int forward_ptr(ListNode** ptr) {
        int val = (*ptr)->val;
        *ptr = (*ptr)->next;
        return val;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        ListNode* cur;
        if(!l1) {
            cur = new ListNode(forward_ptr(&l2));
        }
        else if(!l2) {
            cur = new ListNode(forward_ptr(&l1));
        }
        else {
            if(l1->val <= l2->val) {
                cur = new ListNode(forward_ptr(&l1));
            }
            cur = new ListNode(forward_ptr(&l2));
        }
        cur->next = mergeTwoLists(l1, l2);
        return cur;
    }
};