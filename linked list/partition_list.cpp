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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        ListNode *left_head = left;
        ListNode *right_head = right;

        while(head){
            if(head->val < x){
                left_head->next = head;
                left_head = left_head->next;
                head = head->next;
                left_head->next = NULL;
            }
            else{
                right_head->next = head;
                right_head = right_head->next;
                head = head->next;
                right_head->next = NULL;
            }
        }

        right = right->next;

        if(left->next){
            left_head->next = right;
            return left->next;
        }

        return right;
    }
};