#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }

public:
    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }

private:
    BinaryTreeNode<int> *insertData(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data > data)
        {
            node->left = insertData(data, node->left);
        }
        else
        {
            node->right = insertData(data, node->right);
        }

        return node;
    }

public:
    void insertData(int data)
    {
        this->root = insertData(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasData(data, root->left);
        }
        else
        {
            return hasData(data, root->right);
        }
    }

    void printTree(BinaryTreeNode<int> *root)
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

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void printTree()
    {
        printTree(root);
    }
};