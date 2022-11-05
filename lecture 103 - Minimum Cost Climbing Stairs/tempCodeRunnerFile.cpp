// The problem being Solved -> https://leetcode.com/problems/min-cost-climbing-stairs/
// Here the solution is a SPACE OPTIMIZED to the previously solved Recursive problem.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost){
    // This nth lvl cost is not present in the Array because this point has to be reached , so it's cost won't be added to give our final answer.
    int n = cost.size();

    // Make a dp Vector of size 'n+1' and initialize with -1
    vector<int> dp(n+1, -1);

    // Analyse the Base cases & Store them
    int prev1 = cost[0];
    int prev2 = cost[1];
    int current;

    // Decide how to operate on the for loop for the remaining cases
    for(int i = 2; i<=n-1; i++){
        current = cost[i] + min(prev1,prev2);

        // Updated the prev pointers for the next iteration.
        prev1 = prev2;
        prev2 = current;
    }

    // Athe end of the above for loop, prev1 and prev2 would be pointing to n-1's and n-2's minimum Cost Respectively.
    return min(prev1, prev2);
}

int main(){
    vector<int> v = {10,15,20};

    cout<<"\nThe Minimum Cost of Climbing Stairs to reach to the nth level here is-> "<<minCostClimbingStairs(v)<<endl;
}

