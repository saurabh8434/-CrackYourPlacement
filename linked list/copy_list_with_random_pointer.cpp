#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
        Node *newHead = new Node(-1);
        Node *temp1 = head;
        Node *temp2 = newHead;

        while(temp1 != NULL){
            temp2->next = new Node(temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        Node *delNode = newHead;
        newHead = newHead->next;
        delete(delNode);

        temp1 = head;
        temp2 = newHead;
        Node *next;
        Node *clonedNext;

        while(temp1 != NULL){
            next = temp1->next;
            temp1->next = temp2;
            clonedNext = temp2->next;
            temp2->next = next;
            temp2 = clonedNext;
            temp1 = next;
        }

        temp1 = head;

        while(temp1 != NULL){
            if(temp1->random != NULL)
                temp1->next->random = temp1->random->next;
            temp1 = temp1->next->next;
        }

        temp1 = head;

        while(temp1 != NULL){
            next = temp1->next;
            temp1->next = next->next;
            
            if(next->next != NULL)
                next->next = next->next->next;
            temp1 = temp1->next;
        }

        return newHead;
    }
};