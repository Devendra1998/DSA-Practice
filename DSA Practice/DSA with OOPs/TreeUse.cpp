#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

#define int long long int
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); //fast I/O
int mod = 1e9 + 7;
int inf = 1e18;

TreeNode<int> *takeInputLevelWise()
{
    int rootdata;
    cout << "Enter root Data: " << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of" << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "Enter Data: " << endl;
    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata);

    int n;
    cout << "Enter number of children of" << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << endl;
    cout << "Level Order Traversal" << endl;
    queue<TreeNode<int> *> printchild;
    printchild.push(root);
    while (printchild.size() != 0)
    {
        TreeNode<int> *front = printchild.front();
        printchild.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            printchild.push(front->children[i]);
        }
        cout << endl;
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int FindHeight(TreeNode<int> *root)
{
    int height = 0;
    if (root == NULL)
    {
        return height;
    }

    if (root->children.size() == 0)
    {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        height = max(height, FindHeight(root->children[i]));
    }
    return height + 1;
}

void printatLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printatLevelK(root->children[i], k - 1);
    }
}

int countleafNodes(TreeNode<int> *root)
{
    int ans = 0;

    if (root == NULL)
    {
        return ans;
    }

    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countleafNodes(root->children[i]);
    }
    return ans;
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL) //This is not a Base Case else it is a edge case
    {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

void deletetree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int32_t main()
{
    /* fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    // printTreeLevelWise(root);
    // cout << "Number of Nodes " << numNodes(root) << endl;
    // cout << "Height of Tree " << FindHeight(root) << endl;
    // int k = 2;
    // cout << "Nodes At Level " << k << " :";
    // printatLevelK(root, k);
    // cout << "The number of Leaf Node: " << countleafNodes(root) << endl;
    // postorder(root);
    // delete root;

    return 0;
}