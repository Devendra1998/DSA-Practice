template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T key)
    {
        this->data = key;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            return 0;
        }

        return head->data;
    }

    T dequeue()
    {
        if (size != 0)
        {
            T value = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return value;
        }
        cout << "Queue Empty!" << endl;
        return 0;
    }
};