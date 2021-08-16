// A C program to demonstrate serialization and deserialiation of
// Binary Tree
#include <stdio.h>
#define MARKER '-'

/* A binary tree Node has key, pointer to left and right children */
struct Node
{
	char key;
	struct Node* left, *right;
};

/* Helper function that allocates a new Node with the
given key and NULL left and right pointers. */
Node* newNode(char key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// This function stores a tree in a file pointed by fp
void serialize(Node *root, FILE *fp)
{
	// If current node is NULL, store marker
	if (root == NULL)
	{
		fprintf(fp, "%c ", MARKER);
		return;
	}

	// Else, store current node and recur for its children
	fprintf(fp, "%c ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

// This function constructs a tree from a file pointed by 'fp'
void deSerialize(Node *&root, FILE *fp)
{
	// Read next item from file. If theere are no more items or next
	// item is marker, then return
	char val;
	if ( !fscanf(fp, "%c ", &val) || val == MARKER)
	return;

	// Else create node with this item and recur for children
	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}

// A simple inorder traversal used for testing the constructed tree
void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%c ", root->key);
		inorder(root->right);
	}
}

/* Driver program to test above functions*/
int main()
{
	// Let us construct a tree shown in the above figure
	struct Node *root	 = newNode('a');
	root->left			 = newNode('b');
	root->right			 = newNode('c');
	root->left->left		 = newNode('d');
	root->left->right	 = newNode('e');
	root->left->right->left = newNode('f');
	root->left->right->right = newNode('g');

	// Let us open a file and serialize the tree into the file
	FILE *fp = fopen("tree.txt", "w");
	if (fp == NULL)
	{
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);

	// Let us deserialize the storeed tree into root1
	Node *root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from file:\n");
	inorder(root1);

	return 0;
}
