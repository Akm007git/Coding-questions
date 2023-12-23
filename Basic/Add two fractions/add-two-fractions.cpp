//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


void addFraction(int num1, int den1, int num2,
                 int den2);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,resultNum,resultDen;
        cin>>a>>b>>c>>d;
        addFraction(a,b,c,d);

    }
}

// } Driver Code Ends

/*You are required to complete this function*/
int findGcd(int a, int b)
{
    //base case
    if(b == 0)
        return a;
    return findGcd(b,a%b);
    
}

void findLowest(int &a,int &b)
{
    int gcdOfAns = findGcd(a,b);
    
    a = a/gcdOfAns;
    b = b/gcdOfAns;
    
   cout<<a<<"/"<<b<<endl;
    
}


void addFraction(int num1, int den1, int num2,int den2)
{
    //Your code here
    int gcd = findGcd(den1,den2);
    int lcm = (den1*den2)/gcd;
    
    int numeretor =  (num1)*(lcm/den1) + (num2)*(lcm/den2);
    int denominator = lcm;
    
    // int lowest = findLowest(numeretor,denominator);
    // cout<<lowest<<endl;
    
   findLowest(numeretor,denominator);

    
    

 }