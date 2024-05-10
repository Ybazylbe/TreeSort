#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла дерева
typedef struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Функция для создания нового узла дерева
TreeNode* createNode(int data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для вставки элемента в дерево
TreeNode* insert(TreeNode* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    } else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Функция для обхода дерева в порядке возрастания и вывода элементов
void inorderTraversal(TreeNode* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Освобождение памяти, занимаемой деревом
void freeTree(TreeNode* root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Сортировка массива чисел с использованием дерева
void sortWithTree(int arr[], int n)
{
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    inorderTraversal(root);
    freeTree(root);
}

int main() 
{
    int n;
    printf("Введите элементы массива через пробел: ");

    // Считываем элементы массива до конца ввода (EOF)
    int arr[500];
    n = 0;
    while (scanf("%d", &arr[n]) != EOF)
    {
        n++;
    }

    printf("Отсортированный массив:\n");
    sortWithTree(arr, n);

    return 0;
}
