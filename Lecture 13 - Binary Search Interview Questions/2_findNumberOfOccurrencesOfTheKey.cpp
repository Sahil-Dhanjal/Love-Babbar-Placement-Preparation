// Finding the Number of Occurrences of the 'key' Element in the Given Sorted Array.
// This question is Just an application of the Previous Question we solved.
// The number of occurrences of the 'key', provided the key exists in the given Sorted Array is given by:
//  Total number of occurrences of key = (rightMostIndex - leftMostIndex) + 1;
// BUT NOTE!!!! -> This formula can't be applied on the key that is not present in the given sorted array. This case would've to be handled Separately. [DONE ON LINE 87]
// T.C -> O(log n)
#include<iostream>
using namespace std;

// Function to find the leftMost Occurrence of the key element
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

int totalOccurrencesOfKey(int arr[], int size, int key){
    int leftMostOccurrence = findLeftMostOccurrence(arr,size,key);
    int rightMostOccurrence = findRightMostOccurrence(arr,size,key);

    // Handling the case where the key is not present in the given sorted Array at all as the formula can't be applied for that case.
    if( (leftMostOccurrence == -1) && (rightMostOccurrence == -1) ){
        return 0;
    }else{
        // The key was present in the given sorted Array
        return ( rightMostOccurrence - leftMostOccurrence ) + 1;
    }
}

int main(){
    int arr[8] = {0,0,1,1,2,2,2,2};
    int size = 8;
    int key = 2;

    cout<<"\nThe total Number of occurrences of the key "<<key<<" is -> "<<totalOccurrencesOfKey(arr , size , key)<<endl;

    // Doing the same for an element not present at all in the given Sorted Array
    key = 5;
    cout<<"\nThe total Number of occurrences of the key "<<key<<" is -> "<<totalOccurrencesOfKey(arr , size , key)<<endl;
}