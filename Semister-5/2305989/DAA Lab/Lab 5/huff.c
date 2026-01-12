#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} NODE;

// Create new node
NODE* newNode(char c, int f) {
    NODE* n = (NODE*)malloc(sizeof(NODE));
    n->ch = c; n->freq = f;
    n->left = n->right = NULL;
    return n;
}

// Min-Heap helpers
void swap(NODE** a, NODE** b) { NODE* t = *a; *a = *b; *b = t; }

void heapify(NODE* heap[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l]->freq < heap[smallest]->freq) smallest = l;
    if (r < n && heap[r]->freq < heap[smallest]->freq) smallest = r;
    if (smallest != i) { swap(&heap[i], &heap[smallest]); heapify(heap, n, smallest); }
}

NODE* extractMin(NODE* heap[], int *n) {
    NODE* root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}

void insertMinHeap(NODE* heap[], NODE* node, int *n) {
    int i = (*n)++;
    heap[i] = node;
    while (i && heap[(i-1)/2]->freq > heap[i]->freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// In-order traversal
void inorder(NODE* root) {
    if (!root) return;
    inorder(root->left);
    if (root->ch != '#') printf("%c  ", root->ch);
    inorder(root->right);
}

int main() {
    int n;
    char ch[50];
    int f[50];
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) scanf(" %c", &ch[i]);

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) scanf("%d", &f[i]);

    NODE* heap[100];
    for (int i = 0; i < n; i++) heap[i] = newNode(ch[i], f[i]);

    // Build initial min heap
    for (int i = n/2 - 1; i >= 0; i--) heapify(heap, n, i);

    // Build Huffman Tree
    while (n > 1) {
        NODE* x = extractMin(heap, &n);
        NODE* y = extractMin(heap, &n);
        NODE* z = newNode('#', x->freq + y->freq);
        z->left = x; z->right = y;
        insertMinHeap(heap, z, &n);
    }

    printf("\nIn-order traversal of the tree (Huffman): ");
    inorder(heap[0]);
    printf("\n");
    return 0;
}
