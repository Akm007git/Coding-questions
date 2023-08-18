//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	// Your code here
    	int totalSum=0;
    	int currentSum =0;
    	
    	for(int i=0;i<str.size();i++)
    	{
    	    if(isdigit(str[i]))
    	    {
    	        currentSum = currentSum*10 + (str[i]-'0');
    	        
    	    }
    	    else
    	    {
    	        totalSum +=currentSum;
    	        currentSum = 0;
    	    }
    	}
    	return totalSum + currentSum;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends