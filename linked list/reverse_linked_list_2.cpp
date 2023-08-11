#include<bits/stdc++.h>
using namespace std;

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
class Solution {
public:

    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i=0; i<left-1; i++){
            prev = prev->next;
        }

        ListNode *tail = prev->next;
        ListNode *curr = prev->next;
        for(int i=0; i<right-left; i++){
            curr = curr->next;
        }

        ListNode *forward = curr->next;
        curr->next = NULL;

        ListNode *revHead = reverse(prev->next);

        prev->next = revHead;
        tail->next = forward;

        return dummy->next;
    }
};