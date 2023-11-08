#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define swap(x,y){\
    int t = x;    \
        x = y;    \
        y = t;    \
}

typedef struct _MinHeap{
    int* arr;
    int tail;
    int size;
    int def;
} MinHeap;

void perUp(int* arr, int p){
    if(p<=1) return;
    if(arr[p] >= arr[p/2]) return;
    swap(arr[p], arr[p/2]);
    perUp(arr, p/2);
}

void perDown(MinHeap* h, int p){
    if(2*p>=h->size) return;
    int off = h->arr[2*p]>h->arr[2*p+1];
    if(h->arr[p] <= h->arr[2*p+off]) return;
    swap(h->arr[p], h->arr[2*p+off]);
    perDown(h, 2*p+off);
}

MinHeap* insert(MinHeap* h, int n){
    if(h == NULL){
        h = (MinHeap*)malloc(sizeof(MinHeap));
        h->tail = h->size = 1; h->def = INT_MAX;
        h->arr = (int*)malloc(sizeof(int)*h->size);
    }
    if(h->tail>=h->size){
        h->size = h->size*2+1;
        h->arr = (int*)realloc(h->arr, sizeof(int)*h->size);
        for(int i=h->tail; i<=h->size; i++) h->arr[i] = h->def;
    }
    h->arr[h->tail] = n;
    perUp(h->arr, h->tail++);
    return h;
}

int pop(MinHeap* h){
    if(h->tail == 1) return h->def;

    int res = h->arr[1];
    h->arr[1] = h->arr[--h->tail];
    h->arr[h->tail] = h->def;

    perDown(h, 1);

    if(h->tail*2+1 < h->size/2){
        h->size = h->size/2;
        h->arr = (int*)realloc(h->arr, sizeof(int)*h->size);
    }
    return res;
}

int main(){
    int n, t; scanf("%d", &n);
    MinHeap* h = NULL;
    for(int i=0; i<n; i++){
        scanf("%d", &t);
        h = insert(h, t);
    }
    for(int i=1; i<h->tail; i++) printf("%d ", h->arr[i]); puts("");
    for(int i=0; i<n; i++) printf("%d ", pop(h)); puts("");
    free(h->arr);
    free(h);
    return 0;
}
