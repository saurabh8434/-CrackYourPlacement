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

    int len(ListNode *head){
        ListNode *temp = head;
        int length = 0;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(len(head) < k)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward;
        int curr_len = 0;

        while(curr_len < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            curr_len++;
        }

        head->next = reverseKGroup(forward, k);

        return prev;
    }
};