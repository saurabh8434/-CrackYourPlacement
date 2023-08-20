#include<bits/stdc++.h>
using namespace std;

/*The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int current_fuel = 0;
       int start_index = 0;
       
       for(int i=0; i<n; i++){
           current_fuel += p[i].petrol - p[i].distance;
           
           if(current_fuel < 0){
               start_index = i+1;
               current_fuel = 0;
           }
       }
       
       if(start_index == n)
            return -1;
            
        for(int i=0; i<start_index; i++){
            current_fuel += p[i].petrol - p[i].distance;
            
            if(current_fuel < 0)
                return -1;
        }
            
        return start_index;
    }
};