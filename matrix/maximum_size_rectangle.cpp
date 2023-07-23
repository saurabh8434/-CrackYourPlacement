#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

void calcLeft(int row[], vector <int> &left){
    stack <int> s;

    for(int i=0; i<C; i++){
        while(!s.empty() && row[s.top()]>=row[i])
            s.pop();

        if(!s.empty() && row[s.top()]<row[i])
            left[i] = s.top();

        s.push(i);
    }

}

void calcRight(int row[], vector <int> &right){
    stack <int> s;

    for(int i=C-1; i>=0; i--){
        while(!s.empty() && row[s.top()]>=row[i])
            s.pop();

        if(!s.empty() && row[s.top()]<row[i])
            right[i] = s.top();

        s.push(i);
    }

}

int maxHist(int row[]){
    vector <int> left(C,-1);
    vector <int> right(C,-1);

    calcLeft(row, left);
    calcRight(row, right);

    int ans = 0;

    for(int i=0; i<C; i++){
        if(right[i]==-1)
            right[i] = C;

        ans = max(ans, (right[i]-left[i]-1)*row[i]);
    }

    return ans;
}

int maxRectangle(int a[][C]){

    int result = maxHist(a[0]);

    for(int i=1; i<R; i++){
        for(int j=0; j<C; j++){

            if(a[i][j]){
                a[i][j] += a[i-1][j];
            }

        }
        result = max(result, maxHist(a[i]));
    }

    return result;
}

int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "
         << maxRectangle(A);
 
    return 0;
}