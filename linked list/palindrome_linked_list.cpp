#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    ListNode *middle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *forward = NULL;
        ListNode *curr = head;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *mid = middle(head);
        ListNode *revHead = reverse(mid);

        ListNode *temp1 = head;
        ListNode *temp2 = revHead;

        while(temp1 != revHead && temp2 != NULL){
            if(temp1->val != temp2->val)
                return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};