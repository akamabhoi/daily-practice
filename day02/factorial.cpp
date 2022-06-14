#include <iostream>
using namespace std;

int helper(int n){
    if(n==1) return 1;
    if(n==0) return 1; 
    return n*helper(n-1);
    
}


int main() {
    //Write your code here
    int n;
    cin >> n;
    int ans;
    if(n<0){
        cout << "Error";
    }
    else{
        ans = helper(n);
        cout << ans;
    }
    
    
    return 0;
}