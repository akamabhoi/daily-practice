void helper(vector<int>& arr, int start, int end){
    if(start >= end) return ;
    swap(arr[start], arr[end]);
    helper(arr, start+1, end-1);
}


void reverseArray(vector<int> &arr , int m)
{
	
    helper(arr, m+1, arr.size()-1);
}
