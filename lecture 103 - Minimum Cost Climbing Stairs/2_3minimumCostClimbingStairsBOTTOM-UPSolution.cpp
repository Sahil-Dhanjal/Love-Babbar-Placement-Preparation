// The problem being Solved -> https://leetcode.com/problems/min-cost-climbing-stairs/
// Here the solution is a TABULATION SOLUTION to the previously solved Recursive problem.
// T.C ~ O(n)
// S.C ~ O(n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost){
    // This nth lvl cost is not present in the Array because this point has to be reached , so it's cost won't be added to give our final answer.
    int n = cost.size();

    // Make a dp Vector of size 'n+1' and initialize with -1
    vector<int> dp(n+1, -1);

    // Analyse the Base cases & Store them
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Decide how to operate on the for loop for the remaining cases
    for(int i = 2; i<=n; i++){
        dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
    }

    return min(dp[n-1] , dp[n-2]);
}

int main(){
    vector<int> v = {10,15,20};

    cout<<"\nThe Minimum Cost of Climbing Stairs to reach to the nth level here is-> "<<minCostClimbingStairs(v)<<endl;
}
