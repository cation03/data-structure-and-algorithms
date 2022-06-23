#include <stdio.h>
#include <stdlib.h>
typedef struct item {
    int data;
    struct item * right, *left;
} item;

item* createNewNode(int key){
    item * temp = (item *)malloc(sizeof(item));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(item* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

item* insert(item* node, int key){
    if (node == NULL){
        return createNewNode(key);
    }

    if (key < node->data){
        node->left = insert(node->left, key);
    }
    else if (key > node->data){
        node->right = insert(node->right, key);
    }
    return node;
    
}

int main()
{
    item * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    inorder(root);


    return 0;
}