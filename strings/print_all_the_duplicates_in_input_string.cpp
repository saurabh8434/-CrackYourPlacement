#include <bits/stdc++.h>
using namespace std;
 
void printDuplicates(string str)
{
    int bitVector = 0; 
    int charCounts[26] = { 0 }; 
 
    for (int i = 0; i < str.length(); i++) {
        int bitIndex = str[i] - 'a'; 

        charCounts[bitIndex]++; 
    }
 
    for (int i = 0; i < 26; i++) {
        if (charCounts[i] > 1) {
            char c = i + 'a'; 
            cout << c << ", count = " << charCounts[i] << endl; 
        }
    }
}
 
int main()
{
    string str = "test string";
 
    printDuplicates(str);
 
    return 0;
}