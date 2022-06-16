/*
1. Culmination of Combination Sum-I and Combination Sum-II
2. Instead of having a given vector nums or arr, we are asked to consider numbers from 1 to 9(both inclusive)
3. We can also visualise them to be inside an array but actually we don't to create it and use extra space.
4. Now we need to pass in the void helper() the following parameters:
    1) i for the element and n for the target sum
    2) sumTillNow to calculate the sum we have accumulated till now
    3) k for the number of elements we require in our subset
    4) vector subset and vector<vector<int>> ans

5. Now we will have the base conditions:
    a) if(k==0)
        It means we have calculated the number of elements required. Thus check whether sumTillNow==         n. If so include it in the subset else simply return
    b) if(sumTillNow > n)
        We have a sum which is more than target, and as we don't have negative numbers we cannot form         n so we simply return.
    c) if(i==10)
        We can have elements till 9 only. So we return

6. Now we pick the i-th element into our subset , increment sumTillNow by i and ask Recursion to do the calculation for i+1 elements.
7. When we return, we backtrack the changes, decrement sumTillNow by i and pop_back() the inserted element.
8. We now ignore the i-th element, so we simply call for i+1 and ask Recursion to do the remaining task.

Time Complexity: O(2^N) [ In worst case, we need to include all the elements till 9 to have n]
Space Complexity: O(N) [ Height of Recursive Tree]
*/

void helper(int i, int k, int n, int currSum, vector<int> &temp, vector<vector<int>> &ans){
    
    if(currSum > n) return;
    if(k == 0 and currSum == n){ ans.push_back(temp); return;}
    if(i == 10) return;
    
    currSum += i;
    temp.push_back(i);
    helper(i+1, k-1, n, currSum, temp, ans);
    currSum -= i;
    temp.pop_back();
    helper(i+1, k, n, currSum, temp, ans);
}



vector<vector<int>> combinationSum3(int k, int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    int currSum = 0;
    helper(1, k, n, currSum, temp, ans);
    return ans;
}
