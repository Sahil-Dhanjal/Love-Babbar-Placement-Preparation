// Stack Implementation using classes
// Internal Data Structure used is [Arrays]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
	// PROPERTIES
	public:
		// Stores the size of our Stack
		int size;
		
		// Top is used to store the "index" of the top-most element in our stack
		int top;
		
		// The data structure which is actually used to store the elements of our stack
		int *arr;
	
	// OPERATIONS / BEHAVIOURS
		// CONSTRUCTOR
		Stack(int size){
			this->size = size;
			
			// Dynamic Memory Allocation
			arr = new int[size];
			
			// Top initialised with -1 indicating that our stack is currently Empty!
			top = -1;
		}
		
		// Inserting Element
		void push(int element){
			// Before Inserting, we first check whether the array is already full or not 
            // [Is Space Available]?
			if(top == (size-1)){
				// When top is actually equal to -1, it just indicated that we're currently on the very top of our stack
				// .. and if we try to increment top further to insert the element, we'll end up inserting it outside the range of our array
				// Therefore, in order to prevent doing that, we just stop here itself & return the Error!
				cout<<"\nERROR: Stack Overflow";
			}else{
				top++;
				arr[top] = element;
			}
		}
		
		// Removing Element
		int pop(){
			// We first check whether the Stack is empty or not
			if(top == -1){
				cout<<"\nERROR: Stack Underflow";
				return INT_MIN;
			}else{
				int element = arr[top];
				top--;
				return element;
			}
		}
		
		// Checking whether the Stack is Empty or not
		bool isEmpty(){
			if(top == -1) return 1;
			else return 0;
		}
		
		// Peeking over the topmost element in our stack
		int peek(){
			// We first check whether the Stack is empty or not
			if(top == -1){
				cout<<"\nStack Empty!";
				return INT_MIN;
			}else{
				return arr[top];
			}
		}	
		
		~Stack(){
			cout<<"\nStack Deleted. The Memory has been erased!";
			delete arr;
		}		
};

int main(){
	Stack s(5);
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	
	cout<<endl<<s.isEmpty();
	
	s.push(6) ;
	
	cout<<endl<<s.peek();
	
	cout<<endl<<s.isEmpty();
}