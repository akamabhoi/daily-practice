long long Pow(int X, int N)
{
    // Write your code here. 
    if(N==0) return 1;
    if(N==1) return X;
    return X*Pow(X,N-1);
}