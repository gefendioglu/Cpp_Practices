#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the stack
#define SIZE 10

// Class for stack
class stack{
public:
    stack(int size = SIZE) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor to free memory allocated to the stack
    ~stack() {
        delete[] arr;
    }

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();

private:
    int* arr;
    int top;
    int capacity;
};

// Utility function to add an element x in the stack
void stack::push(int x)
{
    if (isFull())
    {
        std::cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Inserting " << x << "\n";
    arr[++top] = x;
}

// Utility function to pop top element from the stack
int stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Removing " << peek() << "\n";

    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// Utility function to return top element in a stack
int stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int stack::size()
{
    return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
    return top == -1;    // or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}

int main(){

    stack pt(3);

    pt.push(1);
    pt.push(2);

    pt.pop();
    pt.pop();

    pt.push(3);

    cout << "Top element is: " << pt.peek() << endl;
    cout << "Stack size is " << pt.size() << endl;

    pt.pop();

    if (pt.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

    return 0;
}
