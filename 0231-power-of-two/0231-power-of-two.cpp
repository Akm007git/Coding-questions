class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0)
        {
            return false;
        }
        else
        {
             return n&(n-1) ? false : true;
        }
       
        
    }
};

/*
    if(n&n-1)
        {
            return false;
        }
        else
        {
            return true;
        }
 */