//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    bool isPrime(int n){
        
        if(n ==0 || n == 1){
            return false;
        }
        
        int count = 1;
        for(int i=2;i<=n/2;i++){
            if(n%i ==0){
                return false;
            }
        }
        
        return true;
    }
    
    
    public:
    int minNumber(int arr[],int N)
    {
        
        int sum  = 0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
            
        }
        
        // taking the least prime
        int tempSum = sum;
        if(isPrime(sum)){
            return 0;
        }
        else{
            
            
            while(true){
                
                sum += 1;
                if( isPrime(sum) ){
                    break;
                }
            }
            return sum-tempSum;
           
             }
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends