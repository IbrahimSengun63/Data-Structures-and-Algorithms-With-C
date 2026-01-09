#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct heap {
    // Heap dizisi ve mevcut eleman sayısı
    int arr[MAX];
    int size;
};

typedef struct heap MinHeap;



MinHeap* createHeap() {

    // Heap için bellekte yer aç
    MinHeap *h = (MinHeap*) malloc(sizeof(MinHeap));

    // Başlangıçta heap boş
    h->size = 0;

    return h;
}



// Swap işlemi
void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}



// Yukarı doğru düzeltme (heapify up)
void heapifyUp(MinHeap *h, int index) {

    // Kök düğüme gelene kadar devam et
    while (index > 0) {

        int parent = (index - 1) / 2;

        // Min Heap kuralı bozulmuşsa yer değiştir
        if (h->arr[parent] > h->arr[index]) {
            swap(&h->arr[parent], &h->arr[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}



// Heap'e eleman ekleme
void add(MinHeap *h, int data) {

    // Heap doluysa ekleme yapma
    if (h->size == MAX) {
        printf("Heap dolu!\n");
        return;
    }

    // Elemanı sona ekle
    h->arr[h->size] = data;
    h->size++;

    // Min Heap özelliğini sağla
    heapifyUp(h, h->size - 1);
}



// Aşağı doğru düzeltme (heapify down)
void heapifyDown(MinHeap *h, int index) {

    while (1) {

        int left  = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // Sol çocuk daha küçükse
        if (left < h->size && h->arr[left] < h->arr[smallest])
            smallest = left;

        // Sağ çocuk daha küçükse
        if (right < h->size && h->arr[right] < h->arr[smallest])
            smallest = right;

        // Değişiklik yoksa dur
        if (smallest == index)
            break;

        swap(&h->arr[index], &h->arr[smallest]);
        index = smallest;
    }
}



// Min (kök) silme
int deleteMin(MinHeap *h) {

    if (h->size == 0) {
        printf("Heap bos!\n");
        return -1;
    }

    int minValue = h->arr[0];

    // Son elemanı köke al
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    // Heap düzenini yeniden kur
    heapifyDown(h, 0);

    return minValue;
}



// Heap yazdırma
void printHeap(MinHeap *h) {

    printf("Heap: ");
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}



int main() {

    MinHeap *heap = createHeap();

    // Heap'e eleman ekleme
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);
    add(heap, 30);
    add(heap, 2);
    add(heap, 8);

    printHeap(heap);

    // Min silme
    printf("Min silindi: %d\n", deleteMin(heap));
    printHeap(heap);

    printf("Min silindi: %d\n", deleteMin(heap));
    printHeap(heap);

    return 0;
}
