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

    ListNode *merge(ListNode *list1, ListNode *list2){
        ListNode *newHead = new ListNode();
        ListNode *temp = newHead;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
                temp->next = NULL;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }

        while(temp1){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
            temp->next = NULL;
        }

        while(temp2){
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
            temp->next = NULL;
        }

        return newHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;

        if(lists.size()==1)
            return lists[0];

        ListNode *newHead = merge(lists[0], lists[1]);
        int n = lists.size();

        for(int i=2; i<n; i++){
            newHead = merge(newHead, lists[i]);
        }

        return newHead;
    }
};