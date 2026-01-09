#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct heap {
    // Heap dizisi ve mevcut eleman sayısı
    int arr[MAX];
    int size;
};

typedef struct heap MaxHeap;



MaxHeap* createHeap() {

    // Heap için bellekte yer aç
    MaxHeap *h = (MaxHeap*) malloc(sizeof(MaxHeap));

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
void heapifyUp(MaxHeap *h, int index) {

    // Kök düğüme gelene kadar devam et
    while (index > 0) {

        int parent = (index - 1) / 2;

        // Max Heap kuralı bozulmuşsa yer değiştir
        if (h->arr[parent] < h->arr[index]) {
            swap(&h->arr[parent], &h->arr[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}



// Heap'e eleman ekleme
void add(MaxHeap *h, int data) {

    // Heap doluysa ekleme yapma
    if (h->size == MAX) {
        printf("Heap dolu!\n");
        return;
    }

    // Elemanı sona ekle
    h->arr[h->size] = data;
    h->size++;

    // Max Heap özelliğini sağla
    heapifyUp(h, h->size - 1);
}



// Aşağı doğru düzeltme (heapify down)
void heapifyDown(MaxHeap *h, int index) {

    while (1) {

        int left  = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        // Sol çocuk daha büyükse
        if (left < h->size && h->arr[left] > h->arr[largest])
            largest = left;

        // Sağ çocuk daha büyükse
        if (right < h->size && h->arr[right] > h->arr[largest])
            largest = right;

        // Değişiklik yoksa dur
        if (largest == index)
            break;

        swap(&h->arr[index], &h->arr[largest]);
        index = largest;
    }
}



// Max (kök) silme
int deleteMax(MaxHeap *h) {

    if (h->size == 0) {
        printf("Heap bos!\n");
        return -1;
    }

    int maxValue = h->arr[0];

    // Son elemanı köke al
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    // Heap düzenini yeniden kur
    heapifyDown(h, 0);

    return maxValue;
}



// Heap yazdırma
void printHeap(MaxHeap *h) {

    printf("Heap: ");
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}



int main() {

    MaxHeap *heap = createHeap();

    // Heap'e eleman ekleme
    add(heap, 10);
    add(heap, 20);
    add(heap, 5);
    add(heap, 30);
    add(heap, 2);
    add(heap, 8);

    printHeap(heap);

    // Max silme
    printf("Max silindi: %d\n", deleteMax(heap));
    printHeap(heap);

    printf("Max silindi: %d\n", deleteMax(heap));
    printHeap(heap);

    return 0;
}
