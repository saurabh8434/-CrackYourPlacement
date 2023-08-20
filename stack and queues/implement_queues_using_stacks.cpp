#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:

    stack <int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty()){
            st.push(x);
            return;
        }

        int top_element = st.top();
        st.pop();

        push(x);

        st.push(top_element);
    }
    
    int pop() {
        int num = st.top();
        st.pop();

        return num;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};