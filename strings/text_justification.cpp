#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string line(vector <string> words, int start, int end, int lineLen, int max){
        int p=1, q=0;
        string a;

        if(end != start){
            p = (max-lineLen) / (end-start);
            q = (max-lineLen) % (end-start);
        }

        for(int i=start; i<=end; i++){
            a += words[i];
            
            if(i != end){
                if(end==words.size()-1)
                    a += " ";
                else{
                    for(int j=1; j<=p; j++){
                        a += " ";
                        if(q-- >= 1)
                            a += " ";
                    }
                }
            }
        }

        while(a.size() < max)
            a += " ";

        return a;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int word = 0;
        vector <string> ans;

        while(word < words.size()){
            int j = word-1;
            int characters = 0;

            while(j+1 < words.size() && characters+words[j+1].size()+j+1-word <= maxWidth){
                j++;
                characters += words[j].size();
            }

            ans.push_back(line(words, word, j, characters, maxWidth));
            word = j+1;
        }

        return ans;
    }
};