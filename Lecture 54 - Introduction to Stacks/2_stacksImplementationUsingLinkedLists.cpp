// Implementing Stacks using Linked Lists
// There are the main operations that can be performed on any Stack:
//	1. Push()
//	2. Pop()
//	3. isFull()
//	4. isEmpty()
//	5. top()

// All the Above operations have to be implemented in a Way that they take o(1) time complexity!
// The entire implementation has been done with the right to left direction like this below:
// ... <- 5thIntertion <- 4thInsertion <- 3rdInsertion <- 2ndInsertion <- 1stInsertion
// Any new insertion would be there on the head of the Linked list & not in the end.
// That's the way how i've implemented the code.
// The Reason for this is that the top() operation would be o(1) in this case. It would be O(1) in left to right implementation as well, but in that case to pop an element, we would have to traverse the entire list to reach the last element, which would be o(n) time complexity. But in this case, we can directly pop the head element, which would be o(1) time complexity.

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;

		// CONSTRUCTOR FUNCTION
		Node(int data){
			this->data =  data;
			next = NULL;
		}
};

class stackUsingLinkedList{
	
	// Stack Properties
	Node* t; // Tells us about what element is present
	Node* head; // Tell us about the head of our Linked List 
	
	// Stack Operations
	public:

		int size; // Store the current Size of our Dynamic Stack / Linked List [one and the same thing]

		// CONSTRUCTOR FUNCTION
		stackUsingLinkedList(){
			t = NULL;
			head = NULL;
			size = 0;
		}
		
		// Checking if the Stack is empty or not.
		// If the top pointer of our stack would still have been pointing to the Null Value, it means that there are no elements in our Stack Currently.
		bool isEmpty(){
			if(t == NULL)	{
				return true;
			}else{
				return false;
			}
		}
		
		// Checking if the stack is full or not [Can it take any more Elements?]
		// Since the Stack is Dynamic, we're going to check for whether any more memory exists in the heap memory or not!
		// It's not that we can just infinitely keep on inserting elements into our stack.
		// There's a restiction to the physical memory of our system. 
		// One can place a restriction on the number of elements that can be taken at max in a stack by putting some if conditions as well.
		// But, i've implemented this code thinking that we can take infinite elements in our stack.
		// It's all going to be decided by the value of the Address that's returned by the 'new' keyword. If the Address returned is NULL, Means that there isn't anymore memory left in the Heap Memory.
		bool isFull(){
			Node* newNode = new Node(1);
			if(newNode == NULL){
				return true;
			}else{
				return false;
			}
		}
		
		// Pushing an element into the stack
		// First we'll check if the Stack is full or not
		// If full, then it is an -> "Stack Overflow Condition" & we can't insert any element into the stack.
		void push(int x){
			
			if(isFull()){
				
				cout<<"\nStack Overflow Condition!"<<endl;
				return;
				
			}else{
				
				Node* newNode = new Node(x);
				
				if(t == NULL){
					
					// If stack is currently empty!
					// Initialiaze the head and top pointer with this newNode
					head = newNode;
					t = newNode;
					
				}else{
					
					// Update the top pointer now as well as the head of the Linked List
					// Head is being updated as we're inserting any new Element at the head of the Linked List & not in the rear end, because of the reason that we want to make the pop() operation o(1) time complexity & the simultaneous updation of top.

					newNode->next = head;
					t = newNode;
					head = newNode;
					
				}

				// Increase the current Stack's size by 1
				size++;
			}
		}
		
		// Popping an Element off the Stack
		// We first check if the Stack is Empty or not.
		// If empty, it is a 'Stack Underflow Condition'
		int pop(){
			// is Stack empty()?
			if(isEmpty()){
				
				cout<<"\nStack Underflow Condition!"<<endl;
				// We return -1 indicating that there's no element in the stack currently.
				return -1;
				
			}else{
				
				// Store the value of the top pointer in a temporary variable
				int temp = t->data;

				// Update the head and the top pointers
				head = t->next;
				t = head;

				// Decrease the current Size value by 1
				size--;

				// Return the value of the popped element
				return temp;
			}
		}

		// Getting the top element of the stack
		int top(){
			// is Stack empty()?
			if(isEmpty()){
				
				cout<<"\nStack Underflow Condition!"<<endl;
				// We return -1 indicating that there's no element in the stack currently.
				return -1;
				
			}else{
				
				// Return the value of the top element
				return t->data;
			}
		}	
};

int main(){

	stackUsingLinkedList s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout<<"\nCurrent Size of the Stack"<<s.size<<endl;
	cout<<"\nTop Element of the Stack"<<s.top()<<endl;
	cout<<"\nIs the Stack Empty?"<<s.isEmpty()<<endl;
	cout<<"\nIs the Stack Full?"<<s.isFull()<<endl;

	while(!s.isEmpty()){
		cout<<s.pop();
		cout<<"\nCurrent Size of the Stack"<<s.size<<endl;
	}

	s.pop();
	s.top();
	s.isEmpty();
}
