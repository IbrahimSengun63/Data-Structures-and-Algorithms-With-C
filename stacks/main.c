#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
    ============================================================
                          STACK (YIĞIT) YAPISI
    ============================================================

    Bu program, dinamik olarak büyüyüp küçülen bir STACK veri 
    yapısını gösterir. STACK yapısı LIFO (Last In First Out) 
    prensibiyle çalışır: "Son giren ilk çıkar".

    Kullanılan Fonksiyonlar:

    1️ stack *stackIdentifer()
        → Yeni stack oluşturur.
        → size = 2, peak = 0 olarak başlatır.
        → Dinamik dizi bellekte oluşturulur.

    2️ void push(int element, stack *s)
        → Stack’e eleman ekler.
        → Stack dolu ise kapasiteyi 2 katına çıkarır.

    3️ int pop(stack *s)
        → Stack’in en üstündeki elemanı çıkarır.
        → Stack boşsa -1 döndürür.
        → Stack gereğinden büyükse kapasiteyi yarıya indirir.

    4️ int stackInTop(stack *s)
        → Stack’in en üstteki elemanını silmeden gösterir.

    5️ void printStack(stack *s)
        → Stack içeriğini ekrana yazdırır.
*/



// ======================= STACK YAPI TANIMI =======================

typedef struct s {
    int size;       // Ayrılmış alan kapasitesi
    int peak;       // Eleman sayısı (aynı zamanda top)
    int *array;     // Dinamik dizi
} stack;


// ===================== STACK OLUŞTURMA ==========================
stack *stackIdentifer() {
    stack *s = (stack *) malloc(sizeof(stack));

    s->size = 2;                     // başlangıç kapasitesi
    s->peak = 0;                     // stack boş
    s->array = (int *) malloc(sizeof(int) * s->size);

    return s;
}


// ==================== STACK YAZDIRMA ============================
void printStack(stack *s) {

    if (s->peak == 0) {
        printf("Stack: EMPTY\n");
        return;
    }

    printf("Stack: ");

    for (int i = 0; i < s->peak; i++) {
        printf("%d -> ", s->array[i]);
    }

    printf("TOP\n");
}



// ====================== PUSH (ELEMAN EKLEME) ====================
void push(int element, stack *s) {

    // Kapasite dolu ise kapasiteyi 2 kat artır
    if (s->peak >= s->size) {
        int newSize = s->size * 2;
        int *newArray = (int *) malloc(sizeof(int) * newSize);

        // Elemanları yeni diziye kopyala
        for (int i = 0; i < s->peak; i++) {
            newArray[i] = s->array[i];
        }

        free(s->array);
        s->array = newArray;
        s->size = newSize;
    }

    // Elemanı stack'e ekle
    s->array[s->peak++] = element;
}



// ====================== POP (ELEMAN ÇIKARMA) ====================
int pop(stack *s) {

    // Stack boşsa hata
    if (s->peak == 0) {
        printf("Stack is empty!\n");
        return -1;
    }

    int popped = s->array[--s->peak];

    // Stack kapasitesi gerekenden büyükse yarıya indir
    if (s->peak <= s->size / 4 && s->size > 2) {

        int newSize = s->size / 2;
        int *newArray = (int *) malloc(sizeof(int) * newSize);

        for (int i = 0; i < s->peak; i++) {
            newArray[i] = s->array[i];
        }

        free(s->array);
        s->array = newArray;
        s->size = newSize;
    }

    return popped;
}



// ====================== TOP (ELEMAN GÖSTERME) ====================
int stackInTop(stack *s) {

    if (s->peak == 0) {
        printf("Stack is empty!\n");
        return -1;
    }

    return s->array[s->peak - 1];
}



// ======================= ÖRNEK KULLANIM (main) =======================
int main() {

    printf("=== DINAMIK STACK ORNEGI ===\n\n");

    // Yeni stack oluştur
    stack *s = stackIdentifer();


    // Eleman ekleme
    printf("Elemanlar push ediliyor...\n");
    push(10, s);
    push(20, s);
    push(30, s);
    push(40, s);
    push(50, s);

    printf("\nMevcut Stack:\n");
    printStack(s);


    // En üstteki elemanı göster
    printf("\nStack'in en ust elemani (Top): %d\n", stackInTop(s));


    // Eleman çıkarma
    printf("\nElemanlar pop ediliyor...\n");
    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));
    printf("Pop: %d\n", pop(s));

    printf("\nYeni Stack:\n");
    printStack(s);


    // Tekrar en üst elemanı göster
    printf("\nYeni Top: %d\n", stackInTop(s));


    // Stack tamamen boşalt
    printf("\nStack tamamen bosaltiliyor...\n");
    while (s->peak > 0) {
        printf("Pop: %d\n", pop(s));
    }

    printf("\nStack bosaltildi.\n");

    // Boş stack'ten pop denemesi
    printf("\nBos stack'ten pop denemesi:\n");
    pop(s);


    printf("\nProgram tamamlandi.\n");
    return 0;
}
