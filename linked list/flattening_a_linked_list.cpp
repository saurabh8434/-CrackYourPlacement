#include<bits/stdc++.h>
using namespace std;

Node *merge(Node *root1, Node *root2){
    if(!root1)
        return root2;
        
    if(!root2)
        return root1;
        
    if(root1->data < root2->data){
        root1->bottom = merge(root1->bottom, root2);
        return root1;
    }
    else{
        root2->bottom = merge(root1, root2->bottom);
        return root2;
    }
}   

Node *flatten(Node *root)
{
   
    if(!root || !root->next)
        return root;
    
    Node *flattenHead = flatten(root->next);
    Node *mergeHead = merge(root->bottom, flattenHead);
    
    root->bottom = mergeHead;
    root->next = NULL;
    
    return root;
    
}