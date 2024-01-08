#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a>b?a:b)
#define height(n) (n==NULL?0:n->height)
#define setHeight(n) (n->height = 1+max(height(n->left), height(n->right)))
#define balance(n) (n==NULL?0:height(n->left)-height(n->right))

typedef struct Node {
    int data, height;
    struct Node* left, * right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

Node* leftRot(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    setHeight(x);
    setHeight(y);

    return y;
}

Node* rightRot(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;

    setHeight(x);
    setHeight(y);

    return y;
}

Node* insert(Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    setHeight(node);
    int b = balance(node);

    if (b > 1) {
        if (data > node->left->data) node->left = leftRot(node->left);
        return rightRot(node);
    }
    if (b < -1) {
        if (data < node->right->data) node->right = rightRot(node->right);
        return leftRot(node);
    }
    return node;
}

int cmp(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}

Node* minElement(Node* node) {
    if (node == NULL || node->left == NULL) return node;
    return minElement(node->left);
}

Node* del(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data) root->left = del(root->left, data);
    else if (data > root->data) root->right = del(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else {
            Node* temp = minElement(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }

    if (root == NULL) return root;

    setHeight(root);
    int bf = balance(root);
    if (bf > 1) {
        if (balance(root->left) >= 0) return rightRot(root);
        else {
            root->left = leftRot(root->left);
            return rightRot(root);
        }
    }

    if (bf < -1) {
        if (balance(root->right) <= 0) return leftRot(root);
        else {
            root->right = rightRot(root->right);
            return leftRot(root);
        }
    }
    return root;
}


void levelOrder(Node* root) {
    if (root == NULL) return;
    Node* queue[100]; int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    printf("\n");
}


int main() {
    int n; scanf("%d", &n); int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr + i);

    Node* root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);
    levelOrder(root);
    root = del(root, 7);
    levelOrder(root);

    return 0;
}