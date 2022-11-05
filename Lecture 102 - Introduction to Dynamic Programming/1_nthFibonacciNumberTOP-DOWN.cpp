// Here, we're going to convert the recursive Solution of finding the nth Fibonacci Number into its DP Solution .
// TOP-DOWN SOLUTION [RECURSIVE SOLUTION + MEMOIZATION]
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findFibonacciTerm(int n , vector<int> &dp){

    // Base cases
    if(n == 0 || n <= 1){
        return n;
    }
    
    // The following statements here supports our Memoization.

    // 1. If the dp[n]!=-1 (Means that for that particular nth term, we've had already computed the return value & therefore, we don't need to do any further computation to save our time. Simply return that stored value.)
    if(dp[n]!=-1){
        return dp[n];
    }else{
        // 2. If not in the dp array currently, then compute it, store it & then return it.
        dp[n] = findFibonacciTerm(n-1 , dp) + findFibonacciTerm(n-2 , dp);
        return dp[n];
    }

}
int main(){
    int n;
    // Our taken Fibonacci Number start from 0 and this 0 is assumed to be the oth term of the series
    cout<<"Enter which term of Fibonacci Series you wish to find -> ";
    cin>>n;

    // Making the DP Vector that facilitates Memoization
    // The size of the vector would be 'n+1' as we're going to save solution till this nth term & our Fibonacci series starts from 0 which the 0th term.
    vector<int> dp(n+1);

    // Also, alll the values are going to be -1 initially, which represents that computation for that nth term has not been yet done.
    for(int i = 0; i<=n; i++){
        dp[i] = -1;
    }

    cout<<"\nThe "<<n<<" term is -> "<<findFibonacciTerm(n , dp);
    
    return 0;
}