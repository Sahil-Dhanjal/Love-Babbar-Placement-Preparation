// Here, we're going to implement the code for Binary Search Algorithm
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Code to traverse a Linked list?
int binarySearch(int input[] , int size, int key){
    // Initializing the Start and the End Pointers
    int start = 0;
    int end = size-1;

    // Traversing the array part-wise [left sub-part or right sub-part] as how binary search works!
    while(start <= end){

        // find mid element first
        // int mid = (start + end)/2;
        // The formula has been changed to prevent the Integer Range Overflow State that would've occured when both start & end pointers had very large values (e.g. - 2^31 - 1) and we were summing them up.
        // The subtraction operation prevents it as end - start would always be giving us a number that's in the possible Integer Range.    
        int mid = (start) + (end-start)/2;

        // Check the conditions now!
        // Element found as the mid element of the current Sub-array being processed.
        if(input[mid] == key){
            return mid;
        }else if(input[mid] < key){
            // Key came out to be greater than the mid element, therefore the key would be found in the right sub-part.
            start = mid + 1;
        }else{
            // Key came out to be smaller than the mid element, therefore the key would be found in the left sub-part. 
            end = mid -1;
        }
    }

    // If here, means that return statement was never encountered & thus the key is not present in the Array
    return -1;
}

int main(){
    // The Arrays taken below are monotonic - either strictly increasing or strictly decreasing throughout their range.
    int evenSizeArray[6] = {2,4,6,8,12,18};
    int oddSizeArray[5] = {3,8,11,14,16};

    // The key to be searched in the array
    int evenIndex = binarySearch(evenSizeArray , 6 , 12);
    cout << "\nThe index of the key is: " << evenIndex << endl;

    int oddIndex = binarySearch(oddSizeArray , 5 , 3);
    cout << "\nThe index of the key is: " << oddIndex << endl;

}