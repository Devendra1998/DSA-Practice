#include <bits/stdc++.h>
using namespace std;

template <typename T>

class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    // Return the number of elements present in my stack

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    //Insert Element in the stack

    void Push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
            /*cout << "Stack  Full" << endl;
            return;
            */
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //Remove Element from stack

    T Pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};