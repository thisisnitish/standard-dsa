/*
Queue can be implemented in so many ways such as array, linked list.
But below is the Array implementation of Queue in CPP.
*/

#include <iostream>
using namespace std;

#define SIZE 1000

//A class to store the Queue information
class Queue{
    int *arr;
    int capacity;
    int front;
    int rear;
    int currentSize;
public:

    Queue(int size = SIZE);
    ~Queue();

    void enqueue(int item);     //insert an element into the queue
    void dequeue();     //delete an element from the queue
    int peek();         //to get the front element from the queue
    int size();         //to get the size of the queue
    bool isEmpty();     //to check if the queue is empty
    bool isFull();      //to check if the queue is full
    void display();     //display the queue elements
};

//Initializing our Queue
Queue::Queue(int size){
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    currentSize = 0;
}

Queue::~Queue(){
    delete[] arr;
}

//function returns the size of the Queue
int Queue::size(){
    return currentSize;
}

//function is to check if the queue is full or not
bool Queue::isFull(){
    return (size() == capacity);
}

//function is to check if the queue is empty or not
bool Queue::isEmpty(){
    return (size() == 0);
}

//function to get the front element of the queue
int Queue::peek(){
    if(isEmpty()){
        cout<<"Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

void Queue::enqueue(int item){
    if(isFull()){
        cout<<"Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Inserting "<<item<<endl;
    rear = (rear + 1) % capacity; //increase the rear and then insert an item into queue
    arr[rear] = item;
    currentSize++;
}

void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout<<"Deleting "<<arr[front]<<"!!!";
    front = (front + 1) % capacity; //increase the front value by 1
    currentSize--;
}

void Queue::display(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"\nQueue elements are: ";
    int i=0;
    while(i<currentSize){   
        cout<<arr[i]<<" ";
        i++;
    }   
}

int main(){
    int size;
    cout<<"Enter the size of the queue: "<<endl;
    cin>>size;

    Queue queue(size);

    int choice;
    while(1){
        cout << "\nEnter the numbers for the operations: ";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front";
        cout << "\n4. Size";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            int ele;
            cout<<"\nEnter the element in the queue: ";
            cin>>ele;
            queue.enqueue(ele);
            break;
        case 2:
            queue.dequeue();
            cout<<"\nElement is successfully deleted from Queue"<<endl;
            break;
        case 3:
            cout<<"\nFront element of the queue is: "<<queue.peek()<<endl;
            break;
        case 4:
            cout<<"\nCurrent Size of the queue is: "<<queue.size()<<endl;
            break;
        case 5:
            queue.display();
            cout<<endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nWrong Choice!!!"<<endl;
            break;
        }
    }
    return(0);
}
