#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int mod = 1e9 + 7;
int inf = 1e18;

struct Node
{
	int data;
	Node *next;
};

Node *GetNewNode(int data)
{
	Node *NewNode = new Node();
	NewNode->data = data;
	NewNode->next = NULL;
}

int GetLength(Node *head)
{
	int length = 0;
	while (head)
	{
		length++;
		head = head->next;
	}
	return length;
}

Node *Insert(Node *head, int data)
{

	Node *temp = NULL;
	if (head == NULL)
	{
		temp = GetNewNode(data);
		head = temp;
	}
	else
	{
		temp = GetNewNode(data);
		temp->next = head;
		head = temp;
	}
	return head;
}

Node *InsertAtPosition(Node *head, int data, int pos)
{
	Node *temp = NULL;
	int length = GetLength(head);
	if (pos > length)
	{
		cout << "Invalid Position";
	}
	else if (pos == 0)
	{
		temp = GetNewNode(data);
		temp->next = head;
		head = temp;
	}
	else
	{
		Node *current = head;
		while (pos - 2)
		{
			current = current->next;
			pos--;
		}
		temp = GetNewNode(data);
		temp->next = current->next;
		current->next = temp;
	}
	return head;
}

void PrintList(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	cout << head->data << " ";
	PrintList(head->next);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Node *head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);

	// head=InsertAtPosition(head,7,2);
	// head=InsertAtPosition(head,8,3);

	PrintList(head);

	return 0;
}
