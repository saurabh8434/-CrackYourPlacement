class Solution 
{
    public:
    
    bool isPossible(int *a, int n, int m, int max){
        int curr_count = 0;
        
        for(int i=0; i<n; i++){
            if(curr_count + a[i] > max){
                curr_count = a[i];
                m--;
                
                if(m==0 || a[i]>max)
                    return false;
                    
                continue;
            }
            
            curr_count += a[i];
        }

        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(M>N)
            return -1;
        
        int sum = 0;
        
        for(int i=0; i<N; i++)
            sum += A[i];
            
        int start = 0;
        int end = sum;
        int ans = sum;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isPossible(A, N, M, mid)){
                ans = min(ans, mid);
                end = mid-1;
            }
            else
                start = mid+1;
        }
        
        return ans;
    }
};