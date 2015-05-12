#include<stdlib.h>
#include<stdio.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node* search(struct node* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);
	return search(root->left, key);
}

struct node *newnode(int item)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node *node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newnode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key> node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

int main()
{
	/* Let us create following BST
	50
	/     \
	30      70
	/  \    /  \
	20   40  60   80 */
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	//insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// print inoder traversal of the BST
	inorder(root);

	getchar();
	return 0;
}