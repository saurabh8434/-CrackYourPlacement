#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;

        Node *next1 = flatten(head->child);
        Node *next2 = flatten(head->next);

        Node *tail = head;

        if(next1){
            head->next = next1;
            next1->prev = head;
            head->child = NULL;
            
            tail = next1;
            while(tail->next){
                tail = tail->next;
            }
        }

        if(next2){
            tail->next = next2;
            next2->prev = tail;
        }

        return head;
    }
};