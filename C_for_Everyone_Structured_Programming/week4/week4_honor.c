//=============================================================================
//! \brief      Open and read a file of integer pairs into an array that is created
//!             with the first integer telling you how many to read.
//!             So  4 9  11  4  5    would mean create an integer array size 4 and read into data[].
//!             Write a routine that places these values into a binary tree structure.
//!             Then walk the tree “inorder” and print these values to the screen.
//!             Submit your work in a text file.
//!
//! \date       Nov 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTreeNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *createTreeNodeFromArray(int *arr, int i, int size)
{
    TreeNode *root = NULL;
    if (i < size)
    {
        root = createTreeNode(arr[i]);
        // insert left child
        root->left = createTreeNodeFromArray(arr, 2 * i + 1, size);
        // insert right child
        root->right = createTreeNodeFromArray(arr, 2 * i + 2, size);
    }
    return root;
}

// Inorder traversal
void printInorder(TreeNode *root)
{
    if (root != NULL)
    {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}
// level order traversal
void printLevelOrder(TreeNode *root)
{
    int h = 3;// 7 nodes in total, 3 levels
    int i;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
    }
}
void printGivenLevel(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int main(void)
{
    FILE *fp = fopen("week4_honor.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file week4_option.txt");
        exit(1);
    }
    int size;
    fscanf(fp, "%d", &size);
    int *data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
    TreeNode *root = createTreeNodeFromArray(data, 0, size);
    printf("print the tree in level order:\n");
    printLevelOrder(root);
    printf("\n");
    printf("print the tree in inorder order:\n");
    printInorder(root);
    free(data);
    return 0;
}

