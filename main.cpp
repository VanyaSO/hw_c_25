#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
    const int EMPTY = -1;
    int FULL = 10;

    char* stack = new char[FULL-1];
    int top;

public:
    Stack();
    void push(char);
    char pop();
    char getCount();
    bool isEmpty();
    bool isFull();
    void clear();
    char getTop();
    void output();
};

Stack::Stack()
{
    top = EMPTY;
}

void Stack::push(char c)
{
    if (!isFull())
    {
        stack[++top] = c;
    }
    else
    {
        char* updateStack = new char[FULL+1];
        FULL+=1;

        for (int i = 0; i < FULL; ++i) {
            updateStack[i] = stack[i];
        }
        updateStack[++top] = c;
        delete[] stack;
        stack = updateStack;
    }

}

char Stack::pop()
{
    if (!isEmpty())
        return stack[top--];
    else
        return 0;
}

char Stack::getCount()
{
    return top+1;
}

bool Stack::isEmpty()
{
    return top == EMPTY;
}

bool Stack::isFull()
{
    return top == FULL;
}

void Stack::clear()
{
    top = EMPTY;
}

char Stack::getTop()
{
    return stack[top+1];
}

void Stack::output()
{
    for (int i = 0; i < top + 1; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}


int main()
{
    srand(time(0));
    Stack ST;
    char c;
    int a = 0;

    // Пока стек не полон
    while (!ST.isFull())
    {
        c = 45 + a;
        ST.push(c);
        a+=1;
    }
    ST.output();
    ST.push('A');
    ST.push('A');
    ST.output();
    return 0;
}
