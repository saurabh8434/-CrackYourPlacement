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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> s1;
        stack <int> s2;

        while(l1 != NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *ans = new ListNode();
        ans = NULL;
        int carry = 0;

        while(!s1.empty() && !s2.empty()){
            int sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            int digit = sum % 10;
            carry = sum / 10;

            ListNode * temp = new ListNode(digit);
            temp->next = ans;
            ans = temp;
        }

        while(!s1.empty()){
            int sum = s1.top() + carry;
            s1.pop();
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *temp = new ListNode(digit);
            temp->next = ans;
            ans = temp;
        }

        while(!s2.empty()){
            int sum = s2.top() + carry;
            s2.pop();
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *temp = new ListNode(digit);
            temp->next = ans;
            ans = temp;
        }

        if(carry != 0){
            ListNode * temp = new ListNode(carry);
            temp->next = ans;
            ans = temp;
        }

        return ans;
    }
};