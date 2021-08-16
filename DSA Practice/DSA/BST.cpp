#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
int arr[10000008]; //for maximum range of int
char a[26];        //for character array

struct Node
{
    int data;
    Node *left;
    Node *right;
};

unordered_map<Node *, Node *> map;
Node *GetNewNode(int x)
{
    Node *NewNode = new Node();
    NewNode->data = x;
    NewNode->left = NewNode->right = NULL;
    return NewNode;
}

Node *BST_Insert(struct Node *root, int x)
{
    if (root == NULL)
    {
        root = GetNewNode(x);
    }
    else if (x <= root->data)
    {
        root->left = BST_Insert(root->left, x);
    }
    else
    {
        root->right = BST_Insert(root->right, x);
    }

    return root;
}

int Search(Node *root, int x)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == x)
    {
        return x;
    }
    else if (x <= root->data)
    {
        return Search(root->left, x);
    }
    else
    {
        return Search(root->right, x);
    }
}

Node *Find_Min(Node *root)
{
    Node *temp = root;
    if (root == NULL)
    {
        return root;
    }
    else if (temp->left == NULL)
    {
        return temp;
    }
    Find_Min(temp->left);
}
void Find_Max(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->right == NULL)
    {
        cout << root->data;
    }
    Find_Max(root->right);
}

int Find_Height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(Find_Height(root->left), Find_Height(root->right)) + 1;
}

void PreOrder(struct Node *root)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        return;
    }
    cout << temp->data << " ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

Node *StoreParent(Node *root, int target)
{
    Node *t = NULL;
    if (root == NULL)
    {
        return t;
    }

    // map[root] = NULL;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *curr = Q.front();
        if (curr->data == target)
        {
            t = curr;
        }
        if (curr->left)
        {
            // map[curr->left] = curr;
            Q.push(curr->left);
        }
        if (curr->right)
        {
            // map[curr->right] = curr;
            Q.push(curr->right);
        }

        Q.pop();
    }
    return t;
}

int sum_at_distance(Node *root, int target, int k)
{
    Node *t = StoreParent(root, target);
    if (t == NULL)
    {
        return 0;
    }

    int sum = 0;
    queue<Node *> q;
    set<Node *> s;

    q.push(t);
    s.insert(t);

    int level = 0;
    while (!q.empty() && level <= k)
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *f = q.front();
            sum += f->data;

            if (f->left && s.find(f->left) == s.end())
            {
                q.push(f->left);
                s.insert(f->left);
            }
            if (f->data && s.find(f->right) == s.end())
            {
                q.push(f->right);
                s.insert(f->right);
            }
            // if (map[f] && s.find(map[f]) == s.end())
            {
                q.push(f);
                s.insert(f);
            }
            q.pop();
        }
        level++;
    }
    return sum;
}

bool IsSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsSubtreeGreater(Node *root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsBSTUtil(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > minValue && root->data < maxValue && IsBSTUtil(root->left, minValue, root->data) && IsBSTUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBST2(Node *root)
{
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}

Node *Delete(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    else if (value < root->data)
    {
        root->left = Delete(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Delete(root->right, value);
    }
    else //I found the node that to be deleted
    {    //Case:1 NO child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case:2 a.Left child is Null
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        //Case:2 b.Right child is Null
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = Find_Min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

        return root;
    }
}

void Shortest_range(Node *root)
{
    pair<int, int> range;
    range = make_pair(root->data, root->data);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        // cout << current->data << " ";
        range.first = min(current->data, range.first);
        range.second = max(current->data, range.second);
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
        q.pop();
    }
    cout << range.first << " " << range.second;
}

void PrintGivenLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 0)
    {
        cout << root->data << " ";
    }
    else if (level > 0)
    {
        PrintGivenLevel(root->left, level - 1);
        PrintGivenLevel(root->right, level - 1);
    }
}

void PrintLevelOrder(Node *root)
{
    int h = Find_Height(root);
    for (int i = 0; i <= h; i++)
    {
        PrintGivenLevel(root, i);
        cout<<"\n";
    }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Node *root = NULL;
    root = BST_Insert(root, 15);
    root = BST_Insert(root, 10);
    root = BST_Insert(root, 20);
    root = BST_Insert(root, 25);
    root = BST_Insert(root, 8);
    root = BST_Insert(root, 12);
    // cout << Search(root, 8);
    // Find_MIN(root);
    // Find_Max(root);
    // LevelOrder(root);
    // PreOrder(root);
    // InOrder(root);
    // PostOrder(root);
    // cout << IsBST(root);
    // cout << IsBST2(root);
    // Shortest_range(root);
    // PrintGivenLevel(root, 2);
    PrintLevelOrder(root);

    return 0;
}