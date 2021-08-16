#include <bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left)
    {
        cout << "L" << root->left->data;
    }

    if (root->right)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> printNode;
    printNode.push(root);
    while (printNode.size() != 0)
    {
        BinaryTreeNode<int> *front = printNode.front();
        printNode.pop();
        cout << front->data << " :";
        if (front->left)
        {
            cout << "L " << front->left->data << " ";
            printNode.push(front->left);
        }
        if (front->right)
        {
            cout << "R " << front->right->data << " ";
            printNode.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data :" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();

    root->left = leftchild;
    root->right = rightchild;

    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingsNodes;
    pendingsNodes.push(root);
    while (pendingsNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingsNodes.front();
        pendingsNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftchildData;
        cin >> leftchildData;
        if (leftchildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchildData);
            front->left = child;
            pendingsNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightchildData;
        cin >> rightchildData;
        if (rightchildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchildData);
            front->right = child;
            pendingsNodes.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int> *mirror(BinaryTreeNode<int> *root)
{
    if (root)
    {
        mirror(root->left);
        mirror(root->right);

        BinaryTreeNode<int> *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

BinaryTreeNode<int> *BuildTreeHelper(int *In, int *Pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = Pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (In[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = BuildTreeHelper(In, Pre, linS, linE, lpreS, lpreE);
    root->right = BuildTreeHelper(In, Pre, rinS, rinE, rpreS, rpreE);

    return root;
}

BinaryTreeNode<int> *BuildTree(int *In, int *Pre, int size)
{
    return BuildTreeHelper(In, Pre, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root)
{
    if (root = NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftans = heightDiameter(root->left);
    pair<int, int> rightans = heightDiameter(root->right);

    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

BinaryTreeNode<int> *BinarySearchTree(BinaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return BinarySearchTree(root->left, key);
    }
    else
    {
        return BinarySearchTree(root->right, key);
    }
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST1(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data <= rightmin) && (isBST1(root->left)) && (isBST1(root->right));
    return output;
}

class IsBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;

        return output;
    }

    IsBSTReturn leftoutput = isBST2(root->left);
    IsBSTReturn rightoutput = isBST2(root->right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isBSTFinal = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && (leftoutput.isBST) && (rightoutput.isBST);
    IsBSTReturn output;
    output.isBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum;

    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftok = isBST3(root->left, min, root->data - 1);
    bool isrightok = isBST3(root->right, root->data, max);

    return isLeftok && isrightok;
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftoutput = getRootToNodePath(root->left, data);
    if (leftoutput != NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }

    vector<int> *rightoutput = getRootToNodePath(root->right, data);
    if (rightoutput != NULL)
    {
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
    {
        return NULL;
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 7 3 9 2 5 8 10 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
      BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left =node1;
    root->right = node2;
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    BinaryTreeNode<int> *root = BuildTree(in, pre, 9);
    // cout << "Mirror View" << endl;
    // root = mirror(root);
    // printLevelWise(root);
    cout << "Number of Nodes :" << numNodes(root) << endl;
    cout << "Inorder Traversal:";
    inorder(root);
    cout << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height :" << p.first << endl;
    cout << "Diameter :" << p.second << endl;
    
    BinaryTreeNode<int> *node = BinarySearchTree(root, 2);
    if (node)
    {
        cout << "Key Found with value: " << node->data << endl;
    }
    else
    {
        cout << "Key Not Found " << endl;
    }
    

    IsBSTReturn output;
    output = isBST2(root);
    cout << output.isBST << endl
         << output.minimum << endl
         << output.maximum << endl;

    printLevelWise(root);
    cout << isBST3(root) << endl;

    
    BinaryTreeNode<int> *root = takeInputLevelWise();
    vector<int> *output = getRootToNodePath(root, 8);
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i) << endl;
    }

    delete root;

    */
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);
    b.printTree();
    b.deleteData(10);
    b.deleteData(100);
    cout<<endl;
    b.printTree();

    return 0;
}