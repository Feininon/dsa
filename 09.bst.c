#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return create(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* findMin(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

struct Node* findMax(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

struct Node* search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }

    return search(root->right, value);
}

struct Node* delete(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = delete(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        // Case 3: Only left child
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 4: Two children
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}
int main()
{
    struct Node *root = NULL;
    struct Node *result;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    result = findMin(root);
    printf("\nMinimum: %d", result->data);

    result = findMax(root);
    printf("\nMaximum: %d", result->data);

    result = search(root, 40);

    if (result != NULL)
        printf("\nfound");
    else
        printf("\n  not found");

    root = delete(root, 30);

    printf("\n\nAfter deleting 30:");
    printf("\nInorder: ");
    inorder(root);

    return 0;
}