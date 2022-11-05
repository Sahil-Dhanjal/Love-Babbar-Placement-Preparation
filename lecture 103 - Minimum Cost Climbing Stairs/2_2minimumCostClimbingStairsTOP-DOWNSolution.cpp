// The problem being Solved -> https://leetcode.com/problems/min-cost-climbing-stairs/
// Here the solution is a Memoization Solution to the previously solved Recursive problem.
// T.C ~ O(n)
// S.C ~ O(n) + O(n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, vector<int> &dp, int lvl){
    // Base cases
    if(lvl == 0){
        dp[0] = cost[0];
        return dp[0];
    }

    if(lvl == 1){
        dp[1] = cost[1];
        return dp[1];
    }

    // Checking if the Computation was done earlier & stored -> if yes, we use the same w/o wasting time on doing it again. Otherwise, if not present only then we computer and consequently store in the dp Array
    if(dp[lvl]!=-1){
        return dp[lvl];
    }else{
        dp[lvl] = cost[lvl] + min(solve(cost,dp,lvl-1) , solve(cost,dp,lvl-2));
        return dp[lvl];
    } 
}

int minCostClimbingStairs(vector<int> &cost){
    // This nth lvl cost is not present in the Array because this point has to be reached , so it's cost won't be added to give our final answer.
    int n = cost.size();

    // Making a 1D DP Array [Stores the Minimum Cost corresponding to every level]
    vector<int> dp(n+1);

    // Initiaze all its values to -1 denoting that Computation has not been yet done & stored.
    for(int i = 0; i<=n; i++){
        dp[i] = -1;
    }

    // Call the Solve Function
    int ans = solve(cost, dp, n);

    // Return the minimum cost to reach the nth step - minimum cost incurred to reach the Previous two steps
    return (dp[n-1] , dp[n-2]);
}

int main(){
    vector<int> v = {10,15,20};

    cout<<"\nThe Minimum Cost of Climbing Stairs to reach to the nth level here is-> "<<minCostClimbingStairs(v)<<endl;
}
