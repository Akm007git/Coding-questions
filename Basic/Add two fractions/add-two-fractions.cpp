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
void findLoweset(int &n, int &d)
{
    int gcd2 = __gcd(n,d);
    n = n/gcd2;
    d = d/gcd2;
    cout<<n<<"/"<<d<<endl;
}
void addFraction(int num1, int den1, int num2,int den2)
{
//Your code here
    int gcd = __gcd(den1,den2); // but we need lcm
    //cout<<gcd<<endl;
    int  lcm  = (den1*den2)/gcd;
    //cout<<lcm<<endl;
    
    
    int numeretor = (lcm/den1)*num1 + (lcm/den2)*num2;
    int denometor = lcm;
    
    return findLoweset(numeretor,denometor);
 }