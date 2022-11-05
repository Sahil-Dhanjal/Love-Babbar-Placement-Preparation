// This is the simple recursive solution for the Problem.
// This code would work fine for some test cases but for some other it'll be giving out a TLE Error because this Problem contains Overlapping Sub-Problems.
#include<iostream>
using namespace std;
#define MOD 1000000007

// The 1st Argument denoted the nth stair we've to reach to.
// And the second Argument denotes the step that we're standing at currently.
int solve(long long nStairs, int i){
    // BASE CASE
    if(i == nStairs){
        // if the current Stair is the nth stair
        // Then the only way to reach the nth Stair is through a Single way.
        return 1;
    }

    // ANOTHER INVALID CASE
    // LET'S say, we took 2 steps & we missed the nth Step. THis becomes and invalid case & we return o.
    if(i > nStairs){
        return 0;
    }
    
    // WE'LL LOOK AT ALL THE CASES, WHEN WE STARTED WITH ONE STEP OR TWO STEPS FROM OUR CURRENT stair.
    // Here, the first operand tells us about the number of ways to reach the nth stair when we took 1 step from our current location & started off.
    // And, the second operand tells us about the number of ways to reach the nth stair when we took 2 steps from our current location & started off.
    return (solve(nStairs , i+1) + solve(nStairs , i+2))%MOD;
}

int countDistinctWayToClimbStair(long long nStairs)
{
    // We need to return the Number of unique Ways to reach the nth Step when we started from the 0th Step.
    // The solve function actually does the Calculation.
    return solve(nStairs , 0);
}

int main(){

    int n;

    cout<<"Enter n: ";
    cin>>n;

    cout<<"The Total ways to reach "<< n <<" are: "<<countDistinctWayToClimbStair(n);
}