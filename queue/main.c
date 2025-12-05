#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    ============================================================
                          QUEUE (SIRA) YAPISI
    ============================================================

    Queue → FIFO (First In First Out) mantığı ile çalışır.
    Yani “ilk giren ilk çıkar”.

    Kullanılan Fonksiyonlar:

    1️ queue *queueIdentifer()
         → Yeni bir queue oluşturur ve başlangıç değerlerini atar.
         → first = 0, last = 0, size = 2, array = NULL

    2️ void enque(int element, queue *q)
         → Queue'nun sonuna eleman ekler.
         → Eğer doluysa kapasiteyi 2 katına çıkarır.

    3️ int deque(queue *q)
         → Queue'nun ilk elemanını çıkarır.
         → Eğer eleman sayısı kapasitenin 1/4'ünden küçükse
           kapasiteyi yarıya indirir.

    4️ void cleanSpaceInQueue(queue *q)
         → Dequeue işlemleriyle oluşan boşlukları sola kaydırarak temizler.
*/



// ======================= QUEUE YAPI TANIMI =======================

typedef struct q {
    int first;   // İlk elemanın index'i
    int last;    // Sonraki boş index
    int size;    // Ayrılmış kapasite
    int *array;  // Dinamik dizi
} queue;



// ===================== QUEUE OLUŞTURMA ==========================
queue *queueIdentifer() {
    queue *q = (queue *) malloc(sizeof(queue));

    q->first = 0;
    q->last  = 0;
    q->size  = 2;
    q->array = NULL;

    return q;
}



// ====================== ELEMAN EKLEME (ENQUE) ====================
void enque(int element, queue *q) {

    // Eğer dizi henüz oluşturulmadıysa  oluştur
    if (q->array == NULL) {
        q->array = (int *) malloc(sizeof(int) * q->size);
    }

    // Eğer queue doluysa  kapasiteyi 2 kat artır
    if ((q->last - q->first) >= q->size) {

        int *newArray = (int *) malloc(sizeof(int) * q->size * 2);

        // Elemanları sıkıştırarak yeni diziye kopyala
        int count = q->last - q->first;
        for (int i = 0; i < count; i++) {
            newArray[i] = q->array[q->first + i];
        }

        free(q->array);

        q->array = newArray;
        q->size *= 2;
        q->last = count;
        q->first = 0;
    }

    // Elemanı sona ekle
    q->array[q->last++] = element;
}



// ==================== ELEMAN ÇIKARMA (DEQUE) =====================
int deque(queue *q) {

    // Queue boşsa
    if (q->first == q->last) {
        printf("Queue is empty!\n");
        return -1;
    }

    int removed = q->array[q->first++];

    int count = q->last - q->first;

    // Gereksiz büyük kapasiteyi küçült
    if (count <= q->size / 4 && q->size > 2) {

        int newSize = q->size / 2;
        int *newArray = (int *) malloc(sizeof(int) * newSize);

        for (int i = 0; i < count; i++) {
            newArray[i] = q->array[q->first + i];
        }

        free(q->array);

        q->array = newArray;
        q->size = newSize;
        q->last = count;
        q->first = 0;
    }

    return removed;
}



// ==================== BOŞLUK TEMİZLEME FONKSİYONU =====================
void cleanSpaceInQueue(queue *q) {

    // Eğer first zaten 0 ise işlem yapmaya gerek yok
    if (q->first == 0)
        return;

    int count = q->last - q->first;

    for (int i = 0; i < count; i++) {
        q->array[i] = q->array[i + q->first];
    }

    q->last  = count;
    q->first = 0;
}

// ========================= ÖRNEK KULLANIM (main) =========================

int main() {

    printf("=== DINAMIK QUEUE (FIFO) ORNEGI ===\n\n");

    // Yeni queue oluştur
    queue *q = queueIdentifer();

    // Eleman ekleme
    printf("Elemanlar enque ediliyor...\n");
    enque(10, q);
    enque(20, q);
    enque(30, q);
    enque(40, q);
    enque(50, q);

    // Queue durumunu yazdır
    printf("\nMevcut Queue:\n");
    for (int i = q->first; i < q->last; i++) {
        printf("%d -> ", q->array[i]);
    }
    printf("END\n");

    // Eleman çıkarma
    printf("\nElemanlar deque ediliyor...\n");
    printf("Deque: %d\n", deque(q));
    printf("Deque: %d\n", deque(q));
    printf("Deque: %d\n", deque(q));

    // Queue durumunu tekrar yazdır
    printf("\nGuncel Queue:\n");
    for (int i = q->first; i < q->last; i++) {
        printf("%d -> ", q->array[i]);
    }
    printf("END\n");

    // Eleman eklemeye devam
    printf("\nYeni elemanlar enque ediliyor...\n");
    enque(60, q);
    enque(70, q);

    printf("\nSon Queue Durumu:\n");
    for (int i = q->first; i < q->last; i++) {
        printf("%d -> ", q->array[i]);
    }
    printf("END\n");

    // Queue tamamen boşalt
    printf("\nQueue tamamen bosaltiliyor...\n");
    while (q->first < q->last) {
        printf("Deque: %d\n", deque(q));
    }

    // Boş queue’dan deque denemesi
    printf("\nBos queue'dan deque denemesi:\n");
    deque(q);

    printf("\nProgram tamamlandi.\n");
    return 0;
}
