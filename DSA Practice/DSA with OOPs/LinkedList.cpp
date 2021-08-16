#include <iostream>
using namespace std;
#include "Node.cpp"

class Pair
{
public:
    Node *head;
    Node *tail;
};

#define int long long int
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); //fast I/O
int mod = 1e9 + 7;
int inf = 1e18;

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *takeinput_better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node *InsertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *Delete(Node *head, int i)
{
    Node *temp = head;
    int count = 0;
    if (i == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *p = temp->next;
        temp->next = temp->next->next;
        delete p;
    }
    return head;
}

void FindMid(Node *head)
{
    Node *slow = head;
    Node *Fast = head->next;
    while (Fast != NULL && Fast->next != NULL)
    {
        slow = slow->next;
        Fast = Fast->next->next;
    }
    cout << slow->data;
}

Node *Merge(Node *h1, Node *h2)
{
    Node *Final_head = NULL;
    Node *Final_Tail = NULL;
    if (h1->data <= h2->data)
    {
        Final_head = h1;
        Final_Tail = h1;
        h1 = h1->next;
    }
    else
    {
        Final_head = h2;
        Final_Tail = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            Final_Tail->next = h1;
            h1 = h1->next;
            Final_Tail = Final_Tail->next;
        }
        else
        {
            Final_Tail->next = h2;
            h2 = h2->next;
            Final_Tail = Final_Tail->next;
        }
    }
    if (h1 != NULL)
    {
        Final_Tail->next = h1;
    }
    else
    {
        Final_Tail->next = h2;
    }
    return Final_head;
}

Node *ReverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallanswer = ReverseLL(head->next);

    Node *temp = smallanswer;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return smallanswer;
}

Pair ReverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallanswer = ReverseLL_2(head->next);
    smallanswer.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = smallanswer.head;
    ans.tail = head;
    return ans;
}

Node *ReverseLL_Better(Node *head)
{
    return ReverseLL_2(head).head;
}

Node *ReverseLL_3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallanswer = ReverseLL_3(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return smallanswer;
}

int32_t main()
{
    // fast
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = takeinput_better();
    print(head);
    cout << "\n";
    head = ReverseLL_3(head);
    print(head);

    return 0;
    // head = InsertNode(head, 0, 99);
    // head = Delete(head, 7);
    // print(head);
    /*
    // Statically

    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);

    // Dynamically
    
    Node *n3 = new Node(10);

    Node *head = n3;

    Node *n4 = new Node(10);

    n3->next = n4;

    cout << head->data;
*/
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int first = INT32_MIN, second = INT32_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if(arr[i]>first)
    //     {
    //         second=first;
    //         first=arr[i];
    //     }
    //     if (arr[i]>second  && arr[i]<first)
    //     {
    //         second=arr[i];
    //     }

    // }

    // cout<<second<<"\n";

    // int a=1,b=1;
    // cout<<a++ + ++b;
}