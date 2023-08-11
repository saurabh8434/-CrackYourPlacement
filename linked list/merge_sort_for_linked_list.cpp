#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    
    Node *merge(Node *left, Node *right){
        if(left == NULL)
            return right;
            
        if(right == NULL)
            return left;
            
        if(left->data < right->data){
            left->next = merge(left->next, right);
            return left;
        }
        else{
            right->next = merge(left, right->next);
            return right;
        }
    }
    
    Node *middle(Node *head){
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
        
    }
    
    Node* mergeSort(Node* head) {

        if(head == NULL || head->next == NULL)
            return head;
            
        Node *midNode = middle(head);
        Node *rightNode = midNode->next;
        midNode->next = NULL;
        
        Node *left = mergeSort(head);
        Node *right = mergeSort(rightNode);
        
        Node *result = merge(left, right);
        
        return result;
    }
};