class Solution {
public:
    int searchInsert(vector<int>& arr, int m) {
        
        int s = 0;
        int e = arr.size()-1;
        int ans = 0 ;
	
	    // edge case
        if(arr.size() == 0)
            return 0;
        if(m < arr[0])
            return s;
        if(m > arr[e])
            return e+1;

  
	while( s <=  e)
	{
		int mid = s + (e-s)/2;
		
		if(arr[mid] == m)
        {
           return mid;
        }
			
		else if(arr[mid] > m)
			e = mid-1;
		else
			s = mid+1;
	}
    return s;

}
};