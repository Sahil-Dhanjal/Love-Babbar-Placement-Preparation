// Implementing Two Stacks within the same Array
#include<iostream>
using namespace std;

class twoStacks{
    // As discussed by love bhaiya, we need the following properties for sure to implement two stacks in the same array:
    public:
        // top1 pointer will point to the top of the first stack
        // top1 would move from LEFT TO RIGHT.
        int top1;

        // top2 pointer will point to the top of the second stack
        // top2 would move from RIGHT TO LEFT.
        int top2;

        // The size of our initial whole Array that we're going to use for both the stacks.
        // We need this because it further helps us in checking some conditions while we push/pop elements from the stacks.
        int size;

        // The array that store the Elements of both the Stacks.
        int* arr;

        // Constructor Function
        // Initialize the Properties of the class.
        twoStacks(int size){
            this->size = size;
            top1 = -1;
            top2 = size;
            arr = new int[size];
        }

        // PUSH OPERATIONS
        // We atleast need to have one space available to insert the element. If the difference between the values of top1 and top2 is equal to 1, this shows that both the tops' are present just adjacent to each there and both the stacks have been already brought to an end. There's no space left to insert a new element. There the difference between both of them should be greater than one and not greater than or equal to one.
        // PUSH INTO STACK 1
        void push1(int data){
            if(top2 - top1 > 1){
                // Means that there's space available.
                // Therefore, Insert Element in the first Stack.
                // Again Note: The pointer for the first stack works from left to right direction. 
                // Therfore, incrementing happens in this case.
                top1++;
                arr[top1] = data;
            }else{
                // Space isn't available
                cout<<"\nStack Overflow State!"<<endl;
            }
        }

        // PUSH INTO STACK 2
        void push2(int data){
            if(top2 - top1 > 1){
                // Means that there's space available.
                // Therefore, Insert Element in the Second Stack.
                // Again Note: The pointer for the Second stack works from right to left direction. 
                // Therfore, decrementing happens in this case.
                top2--;
                arr[top2] = data;
            }else{
                // Space isn't available
                cout<<"\nStack Overflow State!"<<endl;
            }
        }  

        // POP OPERATIONS
        // Pop from stack1 & return the popped Element.
        int pop1(){
            // First check that is there any element in stack 1
            if(top1>=0){
                // Store the current Top element of Stack 1
                // Check if top1 is still equal to its initial value or not.
                int x = arr[top1];

                // Update the top element of Stack 1
                // Moved to the left direction, i.e. decremented.
                top1--;

                // Return the top1 element we stored previously.
                return x;
            }else{
                // Stack1 has no elements
                cout<<"\nStack Underflow State."<<endl;
                // -1 value returned denotes that there's no element in stack1
                return -1;
            }
        }

        // Popping an element off Stack2 & returning the same.
        int pop2(){
            // Check first if there's any element in stack2
            // Check if top2 is still equal to its inital value or not.
            if(top2 < size){
                // Store the current Top element of Stack 2
                int x = arr[top2];

                // Update the top element of Stack 2
                // Moved to the right direction, i.e. incremented.
                top2++;

                // Return the Element we stored previously.
                return x;
            }else{
                // There's no element in stack2 currently.
                cout<<"\nStack Underflow State."<<endl;
                return -1;
            }
        }
};

int main(){
    twoStacks s(3);

    s.push1(3);
    s.push2(4);
    s.push1(5);

    s.push1(6);
    s.push2(7);

    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;

    cout<<s.pop2()<<endl;
    cout<<s.pop2()<<endl;
}