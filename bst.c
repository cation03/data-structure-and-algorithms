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

item * search(item* root, int key){
    if (root == NULL || root->data == key){
        return root;
    }
    if (root->data > key){
        return search(root->left, key);
    }
    return search(root->left, key);
}

item* minValue(item* node){
    item* current = node;

    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

item* deleteNode(item* node, int key){
    if (node == NULL){
        return node;
    }
    else if (key < node->data){
        return deleteNode(node->left, key);
    }
    else if (key > node->data){
        return deleteNode(node->right, key);
    }
    else {
        if (node->left == NULL && node->right == NULL){
            return NULL;
        }
        else if (node->left == NULL){
            item * temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL){
            item * temp = node->left;
            free(node);
            return temp;
        }
        item* temp = minValue(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;

}

int main()
{
    item * root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: \n");
    
    inorder(root);

    printf("On deleting 20: \n");
    root = deleteNode(root, 20);
    printf("Inorder traversal now: \n");
    inorder(root);

    printf("On deleting 30: \n");
    root = deleteNode(root, 30);
    printf("Inorder traversal now: \n");
    inorder(root);

    printf("On deleting 50: \n");
    root = deleteNode(root, 50);
    printf("Inorder traversal now: \n");
    inorder(root);

    return 0;
}