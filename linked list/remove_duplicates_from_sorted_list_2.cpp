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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode();
        ListNode *temp = newHead;

        while(head != NULL){
            if(head->next && head->val == head->next->val){
                while(head->next && head->next->val == head->val)
                    head = head->next;

                head = head->next;
            }
            else{
                temp->next = head;
                head = head->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }

        return newHead->next;
    }
};