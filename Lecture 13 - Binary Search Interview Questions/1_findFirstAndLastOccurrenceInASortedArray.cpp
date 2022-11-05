// Finding the first and the Last Occurence of an Element in the given sorted Array
#include<iostream>
using namespace std;

// Function to find the leftMost Occurrence of the key element
// T.C -> O(log n)
int findLeftMostOccurrence(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    // An important variable whose work is to just store the latest occurrence of the key element whenever encountered.
    int ans = -1;

    while(start<=end){
        // The first goal is to find the key in the given sorted Array
        // Once found, we'll keep on looking further in the left sub-part of the mid that would've been at that moment. This is because we're in search of the left-most occurrence of the key in the given SORTED ARRAY.
        // Therefore, in order to continue the search in the left sub-part, we'll be updating the end pointer to 'mid-1' of that moment when 'key' was found.
        // This enforces the search to go to the Left sub-part in the next iteration.

        int mid = start + ( (end - start) / 2 );

        if(arr[mid] == key){
            // 1. Store this occurrence index
            ans = mid;

            // 2. Enforce the movement to the left sub-part of this mid for the next Iteration as we need the left most occurrence of the element.
            end = mid - 1;
        }else if(arr[mid] < key){
            // search in the right sub-part
            start = mid + 1;
        }else{
            // search in the left sub-part
            end = mid - 1;
        }

    }

    // Here, our 'ans' variable would be storing the latest encountered occurrence of our key element in the leftward direction.
    // Return it!
    return ans;
}

// Function to find the rightmost Occurrence of the key element
// T.C -> O(log n)
int findRightMostOccurrence(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    // An important variable whose work is to just store the latest occurrence of the key element whenever encountered.
    int ans = -1;

    while(start<=end){
        // The first goal is to find the key in the given sorted Array
        // Once found, we'll keep on looking further in the right sub-part of the mid that would've been at that moment. This is because we're in search of the right-most occurrence of the key in the given SORTED ARRAY.
        // Therefore, in order to continue the search in the right sub-part, we'll be updating the start pointer to 'mid+1' of that moment when 'key' was found.
        // This enforces the search to go to the right sub-part in the next iteration.

        int mid = start + ( (end - start) / 2 );

        if(arr[mid] == key){
            // 1. Store this occurrence index
            ans = mid;

            // 2. Enforce the movement to the right sub-part of this mid for the next Iteration as we need the right most occurrence of the key element.
            start = mid + 1;
        }else if(arr[mid] < key){
            // search in the right sub-part
            start = mid + 1;
        }else{
            // search in the left sub-part
            end = mid - 1;
        }
    }

    // Here, our 'ans' variable would be storing the latest encountered occurence of our key element in the rightward direction.
    // Return it!
    return ans;
}

int main(){
    int arr[6] = {0,5,5,6,6,6};
    cout<<"The first occurrence of the key 3 is at index -> "<<findLeftMostOccurrence(arr,6,3)<<endl;
    cout<<"\nThe last occurrence of the key 3 is at index -> "<<findRightMostOccurrence(arr,6,3)<<endl;
    cout<<"\nThe first occurrence of the key 6 is at index -> "<<findLeftMostOccurrence(arr,6,6)<<endl;
    cout<<"\nThe last occurrence of the key 6 is at index -> "<<findRightMostOccurrence(arr,6,6)<<endl;
    cout<<"\nThe first occurrence of the key 5 is at index -> "<<findLeftMostOccurrence(arr,6,5)<<endl;
    cout<<"\nThe last occurrence of the key 5 is at index -> "<<findRightMostOccurrence(arr,6,5)<<endl;

    cout<<"--------------------------------------------"<<endl;

    int arr2[8] = {0,0,1,1,2,2,2,2};
    cout<<"The first occurrence of the key 0 is at index -> "<<findLeftMostOccurrence(arr2,8,0)<<endl;
    cout<<"\nThe last occurrence of the key 0 is at index -> "<<findRightMostOccurrence(arr2,8,0)<<endl;
    cout<<"\nThe first occurrence of the key 1 is at index -> "<<findLeftMostOccurrence(arr2,8,1)<<endl;
    cout<<"\nThe last occurrence of the key 1 is at index -> "<<findRightMostOccurrence(arr2,8,1)<<endl;
    cout<<"\nThe first occurrence of the key 2 is at index -> "<<findLeftMostOccurrence(arr2,8,2)<<endl;
    cout<<"\nThe last occurrence of the key 2 is at index -> "<<findRightMostOccurrence(arr2,8,2)<<endl;
    cout<<"\nThe first occurrence of the key 3 is at index -> "<<findLeftMostOccurrence(arr2,8,3)<<endl;
    cout<<"\nThe last occurrence of the key 3 is at index -> "<<findRightMostOccurrence(arr2,8,3)<<endl;

}