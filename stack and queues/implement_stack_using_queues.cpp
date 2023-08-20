#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue <int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);

        while(size--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int num = q.front();
        q.pop();

        return num;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};