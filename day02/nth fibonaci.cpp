#include<bits/stdc++.h>
using namespace std;

int helper(int n){
    if(n==1) return 1;
    if(n==2) return 1;
    return helper(n-1) + helper(n-2);
}


int main()
{
      int n;
      cin >> n;
      cout << helper(n);
}