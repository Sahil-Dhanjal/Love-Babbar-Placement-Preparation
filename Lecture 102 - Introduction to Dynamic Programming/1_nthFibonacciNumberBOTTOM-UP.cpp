// Here, we're going to convert the recursive Solution of finding the nth Fibonacci Number into its DP Solution .
// BOTTOM - UP SOLUTION [TABULATION]
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    // Our taken Fibonacci Number start from 0 and this 0 is assumed to be the oth term of the series
    cout<<"Enter which term of Fibonacci Series you wish to find -> ";
    cin>>n;

    //  STEP 1: Create a DP Array of size n+1. No specific need to initialize all its values with -1 as in tabulation solution, we compute a value from the previously stored values which we're doing in the next step itself. No Checking is done before computation as it is all done for each term in an increasing manner.
    vector<int> dp(n+1);

    // STEP 2: Check for the Base Cases & store them in the DP Array 
    dp[0] = 0;
    dp[1] = 1;

    // STEP 3: Execute a FOR LOOP which solves for the following cases by using the base cases we stored Previously.
    for(int i = 2; i<=n; i++){
        // Recurrence Relation of our Function converted to a Tabular Form
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    // STEP 4: Return the value which the user Required.
    cout<<"The "<<n<<" term is -> "<<dp[n];
    return 0;
}