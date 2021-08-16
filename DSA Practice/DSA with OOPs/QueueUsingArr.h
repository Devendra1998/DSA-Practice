template <typename T>

class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    // Insert element
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newdata = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            for (int i = 0; i < firstIndex; i++)
            {
                newdata[j] = data[i];
                j++;
            }
            delete [] data;
            data=newdata;
            firstIndex=0;
            nextIndex=capacity;
            capacity*=2; 
            // cout << "Queue Full !" << endl;
            // return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeu()
    {
        if (isEmpty())
        {
            cout << "Queue Empty" << endl;
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
};
