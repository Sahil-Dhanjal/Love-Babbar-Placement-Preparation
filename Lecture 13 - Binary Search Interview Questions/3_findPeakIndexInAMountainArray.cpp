// Finding the Peak Index in a Mountain Array
// Leetcode Question -> https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPeakIndex(int arr[] , int size){
    // We find the Peak by searching inside the given Mountain Array in a Binary Search Format
    int start = 0;
    int end = size - 1;

    // Why haven't we included the equal condition as we do in binary Search?
    // This is to prevent ourselves from being Stuck in an Infinite loop.
    while( start < end ){
        
        // Find the Mid Element First
        int mid = start + (end - start)/2;

        if(arr[mid] < arr[mid+1]){
            // This means that the mid pointer is currently on the Ascending side of the Mountain Array
            // Increment Start by 'mid+1' for our next iteration [We keep on reducing the Search space]
            // Done because peak obviously would now be present on mid+1 & not mid as (mid<mid+1)
            start = mid + 1;
        }else{
            // This means that the element is currently either going to be the Peak Element or it'll be there on the Descending Size of the Mountain Array
            // Update end to the current mid for our next iteration.
            // We don't know about whether this Mid was a Peak or not as when both the pointers coincide, WE'LL HAVE OUR PEAK AT THAT POINT.
            end = mid;
        }
    }

    // Here, our Start pointer would surely have been pointing to the peak as the loop terminate when both the start & end Pointers Coincided! [ They won't cross each other as we are not updating both the pointers at the same time!]
    // Therefore, the end pointer could've been returned too!
    return start;
}

int main(){
    // int size = 10;
    // int arr[10] = {24,69,100,99,79,78,67,36,26,19};

    int size = 4;
    int arr[4] = {0,10,5,2};


    int peak = findPeakIndex( arr , size );
    cout<<"The Peak Index of the Array is "<<peak<<" and the corresponding Peak element is -> "<<arr[peak];
}
