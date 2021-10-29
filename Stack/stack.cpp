/*

Stack is a linear data structure that follows a particular order in which the
operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed.
If the stack is empty, then it is said to be an Underflow condition.
Peek or Top: Returns the top element of the stack.
isEmpty: Returns true if the stack is empty, else false.

Implementation:
There are two ways to implement a stack:
Using array
Using linked list

PS: It can also be implemented with the help of some other data structures as well, as we see on coding platforms like LeetCode.

*/

// Implementing Stack using Arrays

#include<iostream>
using namespace std;

#define SIZE 1000


class Stack{
    int *arr;
    int top;
    int capacity;
public:

    Stack(int size = SIZE);     //constructor
    ~Stack();                   //destructor

    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};

//initializing the stack
Stack::Stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
}   

// deteing the Stack
Stack::~Stack(){
    delete[] arr;
}

int Stack::size(){
    return top+1;
}

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity-1;
}

int Stack::peek(){
    if(!isEmpty()){
        return arr[top];
    }
    else exit(EXIT_FAILURE);
}

int Stack::pop(){
    if(isEmpty()){
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

void Stack::push(int ele){
    if(isFull()){
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Inserted: "<< ele<< endl;
    arr[++top]=ele;
}

void Stack::display(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
    }
    cout<<endl;
}

int main(){
    class Stack stack;
    int choice;

    while(1){
        cout << "\nEnter the numbers for the operations: ";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Top";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            int ele;
            cout << "\nEnter the element: ";
            cin >> ele;
            stack.push(ele);
            break;

        case 2:
            cout << "\n"<< stack.pop() << " is successfully popped from the stack" << endl;
            break;
        case 3:
            cout << "\nTop element of stack is: " << stack.peek() << endl;
            break;
        case 4:
            stack.display();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nWrong Choice" << endl;
            break;
        }
    }
    return(0);
}
