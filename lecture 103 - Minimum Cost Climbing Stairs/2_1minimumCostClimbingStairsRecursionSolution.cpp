// The problem being Solved -> https://leetcode.com/problems/min-cost-climbing-stairs/
// Here the solution is a Recursive Solution to this problem.
// It also gives TLE when ran because of overlapping Sub-problems present in it.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int lvl){
    // Base cases
    if(lvl == 0){
        return cost[0];
    }

    if(lvl == 1){
        return cost[1];
    }

    return cost[lvl] + min(solve(cost,lvl-1) , solve(cost,lvl-2));
}

int minCostClimbingStairs(vector<int> &cost){
    // This nth lvl cost is not present in the Array because this point has to be reached , so it's cost won't be added to give our final answer.
    int n = cost.size();

    // We would have reached the nth level either through the (n-1)th level or (n-2)th level.
    // The cost of the nth level doesn't have to be added her as it does not exits & it is the level to be reached - not passed through.
    // TH input cost vector contains costs for the 0th to n-1th Steps.
    return min( solve(cost, n-1) , solve(cost , n-2) );
}

int main(){
    vector<int> v = {10,15,20};

    cout<<"\nThe Minimum Cost of Climbing Stairs to reach to the nth level here is-> "<<minCostClimbingStairs(v)<<endl;
}
