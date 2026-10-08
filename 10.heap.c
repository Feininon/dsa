#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct heapStruct
{
    int capacity;
    int size;
    elementtype *elements;
};
typedef struct heapStruct *Heap;
Heap initialize(int capacity)
{
    Heap H;

    H = (Heap)malloc(sizeof(struct heapStruct));

    if (H == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    H->elements = (elementtype *)malloc((capacity + 1) * sizeof(elementtype));

    if (H->elements == NULL)
    {
        free(H);
        return NULL;
    }

    H->capacity = capacity;
    H->size = 0;

    return H;
}

int isFull(Heap H)
{
    return H->size == H->capacity;
}

int isEmpty(Heap H)
{
    return H->size == 0;
}

void insert(elementtype x, Heap H)
{
    int i;

    if (isFull(H))
    {
        printf("Heap is full\n");
        return;
    }

    for (i = ++H->size; i > 1 && x < H->elements[i / 2]; i = i / 2)
    {
        H->elements[i] = H->elements[i / 2];
    }

    H->elements[i] = x;
}

elementtype findMin(Heap H)
{
    if (isEmpty(H))
    {
        printf("Heap is empty\n");
        return -1;
    }

    return H->elements[1];
}

elementtype deleteMin(Heap H)
{
    int i, child;
    elementtype min, last;

    if (isEmpty(H))
    {
        printf("Heap is empty\n");
        return -1;
    }

    min = H->elements[1];
    last = H->elements[H->size--];

    for (i = 1; i * 2 <= H->size; i = child)
    {
        child = i * 2;

        if (child != H->size &&
            H->elements[child + 1] < H->elements[child])
        {
            child++;
        }

        if (H->elements[child] < last)
        {
            H->elements[i] = H->elements[child];
        }
        else
        {
            break;
        }
    }

    H->elements[i] = last;

    return min;
}

void makeEmpty(Heap H)
{
    H->size = 0;
}

void dispose(Heap H)
{
    if (H != NULL)
    {
        free(H->elements);
        free(H);
    }
}

void display(Heap H)
{
    int i;

    if (isEmpty(H))
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap: ");

    for (i = 1; i <= H->size; i++)
    {
        printf("%d ", H->elements[i]);
    }

    printf("\n");
}

void heapSort(elementtype arr[], int n)
{
    Heap H;
    int i;

    H = initialize(n);

    for (i = 0; i < n; i++)
    {
        insert(arr[i], H);
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = deleteMin(H);
    }

    dispose(H);
}

int main()
{
    Heap H;
    int arr[] = {40, 10, 30, 20, 50};
    int n = 5;
    int i;

    H = initialize(10);

    insert(30, H);
    insert(10, H);
    insert(20, H);
    insert(5, H);
    insert(15, H);

    printf("Heap:\n");
    display(H);

    printf("Minimum: %d\n", findMin(H));

    printf("Deleted Minimum: %d\n", deleteMin(H));

    printf("After deleteMin:\n");
    display(H);

    printf("\nHeap Sort:\n");

    heapSort(arr, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    makeEmpty(H);

    printf("\nAfter makeEmpty:\n");
    display(H);

    dispose(H);

    return 0;
}