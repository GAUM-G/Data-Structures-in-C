#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *insert(Node *root, int x);
Node *create();
void display(Node *root);
Node *delete(Node *root, int x);
Node *minValueNode(Node *node);

int main() {
    int choice;
    Node *root = NULL;

    printf("1) INSERT\n2) DISPLAY\n3) DELETE\n4) EXIT\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = create(); 
                break;
            case 2:
                printf("Display:\n");
                display(root); 
                printf("\n");
                break;
            case 3: {
                int value;
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Value deleted if it existed.\n");
                break;
            }
            case 4:
                printf("Exiting...\n");
                return 0; // Use return instead of exit
            default:
                printf("INVALID CHOICE\n");
        }
    } while (choice != 4);

    return 0;
}

Node *create() {
    int x, n, i;
    Node *root = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    return root;
}

Node *insert(Node *root, int x) {
    Node *p, *q, *r;
    r = (Node *)malloc(sizeof(Node));
    r->data = x;
    r->left = r->right = NULL;

    if (root == NULL) {
        return r;
    }
    p = root;
    while (p != NULL) {
        q = p;
        if (x > p->data) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (x > q->data) {
        q->right = r;
    } else {
        q->left = r;
    }
    return root;
}

void display(Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
Node *delete(Node *root, int x) {
    if (root == NULL) {
        printf("Value not found in the tree.\n");
        return root;
    }
    if (x < root->data) {
        root->left = delete(root->left, x);
    } else if (x > root->data) {
        root->right = delete(root->right, x);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = minValueNode(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = delete(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}
