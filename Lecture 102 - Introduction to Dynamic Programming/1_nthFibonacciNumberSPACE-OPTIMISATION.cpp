// Here, we'll be Space Optimising for our Previously created Tabulation Solution for Fibonacci Sequence.
#include<iostream>
using namespace std;

int main(){
        int n;
        cout<<"Enter which term of Fibonacci Series you wish to find -> ";
        cin>>n;

        // Update the Prev pointers first - these are used to calculate current value
        int prev1 = 0;
        int prev2 = 1;

        int current;

        // This handles the case where the user would've required the values of our base cases.
        // For such cases, as there needs no computation & simply the values of our prev pointers, therefore we update 'current' accordingly.

        if(n == 0 || n == 1){
            current = n;
        }

        for(int i = 2; i <= n; i++){
            current = prev1 + prev2;

            // Update the prev pointers for the next iteration
            prev1 = prev2;
            prev2 = current; 
        }

        // Here, our 'current' variable would've been storing the answer.
        cout<<"The "<<n<<" term is -> "<<current;

}