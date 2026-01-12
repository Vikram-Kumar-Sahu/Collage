#include <stdio.h>
#include <stdlib.h>

typedef struct SYMBOL 
{
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct Node 
{
    char alphabet;
    int frequency;
    struct Node *left, *right;
} Node;

Node* createNode5990(char alphabet, int frequency) 
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->alphabet = alphabet;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

typedef struct MinHeap 
{
    int size;
    int capacity;
    Node** array;
} MinHeap;

MinHeap* createMinHeap5990(int capacity) 
{
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}

void swapNodes5990(Node** a, Node** b) 
{
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify5990(MinHeap* minHeap, int idx) 
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) 
    {
        swapNodes5990(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify5990(minHeap, smallest);
    }
}

void insertMinHeap5990(MinHeap* minHeap, Node* node) 
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) 
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

Node* extractMin5990(MinHeap* minHeap) 
{
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify5990(minHeap, 0);
    return temp;
}

Node* buildHuffmanTree5990(SYMBOL symbols[], int n) 
{
    Node *left, *right, *top;
    MinHeap* minHeap = createMinHeap5990(n);

    for (int i = 0; i < n; ++i)
        insertMinHeap5990(minHeap, createNode5990(symbols[i].alphabet, symbols[i].frequency));

    while (minHeap->size != 1) 
    {
        left = extractMin5990(minHeap);
        right = extractMin5990(minHeap);

        top = createNode5990('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap5990(minHeap, top);
    }

    return extractMin5990(minHeap);
}

void inorder5990(Node* root) 
{
    if (root) 
    {
        inorder5990(root->left);
        if (root->alphabet != '$')
            printf("%c ", root->alphabet);
        inorder5990(root->right);
    }
}

int main() 
{
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    SYMBOL* symbols = (SYMBOL*)malloc(n * sizeof(SYMBOL));

    printf("Enter the alphabets: ");
    getchar();
    for (int i = 0; i < n; i++) 
        scanf(" %c", &symbols[i].alphabet);

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &symbols[i].frequency);

    Node* root = buildHuffmanTree5990(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorder5990(root);
    printf("\n");

    free(symbols);
    return 0;
}
