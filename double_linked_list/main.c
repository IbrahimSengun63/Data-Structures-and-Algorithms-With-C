#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>



/*
    ============================================================
           ÇİFT YÖNLÜ BAĞLI LİSTE (DOUBLY LINKED LIST)
    ============================================================
    Bu program, çift yönlü (doubly) bağlı liste üzerinde temel işlemleri gösterir.

     Kullanılan Fonksiyonlar:

    1️ dnode *rootDoublyIdentifer(int data)
        → Yeni bir düğüm (node) oluşturur ve verilen veriyi (data) içine yazar.
        → next ve prew işaretçilerini NULL olarak başlatır.

    2️ void printDoublyLinkedList(dnode *root)
        → Bağlı listedeki tüm elemanları sırayla ekrana yazdırır.
        → root’tan başlayarak son düğüme kadar ilerler.

    3️ dnode *addOrderElementInDoublyLinkedList(dnode *root, int element)
        → Verilen elemanı (element) listeye sıralı bir şekilde ekler.
        → Küçükten büyüğe sıralı bir yapı oluşturur.
        → Eğer liste boşsa yeni root oluşturur.

    4️ dnode *deleteElementInDoublyLinkedList(dnode *root, int element)
        → Verilen değeri (element) listeden siler.
        → Silinecek eleman başta, ortada veya sonda olabilir.
        → Eleman bulunamazsa kullanıcıya mesaj verir.

*/








// Çift yönlü bağlı liste düğüm yapısı (her düğüm bir önceki ve sonraki düğümü gösterir)
struct dn {
    struct dn *prew;  // Bir önceki düğümü gösteren gösterici
    struct dn *next;  // Bir sonraki düğümü gösteren gösterici
    int data;         // Düğümün tuttuğu veri
};

typedef struct dn dnode;

// Yeni bir düğüm (node) oluşturur ve başlatır
dnode *rootDoublyIdentifer(int data) {
    // Yeni düğüm için bellekte yer ayır
    dnode *root = (dnode *) malloc(sizeof(dnode));

    // Düğüm verilerini ayarla
    root->data = data;
    root->next = NULL;
    root->prew = NULL;

    // Baş düğümü döndür
    return root;
}

// Bağlı listedeki tüm elemanları yazdırır
void printDoublyLinkedList(dnode *root) {
    printf("Double Linked List: ");
    while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next; // Bir sonraki düğüme geç
    }
    printf("NULL\n"); // Listenin sonunu belirt
}

// Verilen değeri (element) sıralı şekilde çift yönlü bağlı listeye ekler
dnode *addOrderElementInDoublyLinkedList(dnode *root, int element) {
    // Eğer liste boşsa, doğrudan yeni düğümü kök (root) yap
    if (root == NULL) {
        root = rootDoublyIdentifer(element);
        return root;
    }

    // Yeni eklenecek eleman, listedeki ilk elemandan küçükse başa ekle
    if (root->data > element) {
        dnode *temp = (dnode *) malloc(sizeof(dnode));
        temp->data = element;
        temp->next = root;  // Yeni düğüm mevcut root’tan önce gelir
        root->prew = temp;  // Eski root’un prew’u yeni düğüm olur

        return temp; // Yeni kök düğümü döndür
    }

    // Listeyi sıralı ekleme için uygun konumu bul
    dnode *iterater = root;
    while (iterater->next != NULL && iterater->next->data < element) {
        iterater = iterater->next;
    }

    // Yeni düğüm oluştur
    dnode *temp = (dnode *) malloc(sizeof(dnode));

    // Yeni düğümün bağlantılarını ayarla
    temp->next = iterater->next; // Yeni düğüm, iterater’in sonrasına bağlanır
    iterater->next = temp;
    temp->prew = iterater;       // Yeni düğümün prew’u iterater olur

    // Eğer yeni düğümün arkasında başka bir düğüm varsa, onun prew bağlantısını düzelt
    if (temp->next != NULL) {
        temp->next->prew = temp;
    }

    temp->data = element; // Veriyi ata

    return root; // Liste başını döndür (değişmediyse aynı kalır)
}

// Verilen değere sahip düğümü listeden siler
dnode *deleteElementInDoublyLinkedList(dnode *root, int element) {
    dnode *iterater = root;
    dnode *temp = (dnode *) malloc(sizeof(dnode));

    // Eğer silinecek düğüm ilk düğümse
    if (root->data == element) {
        temp = root;
        root = root->next;  // İkinci düğüm yeni kök olur
        free(temp);         // Eski kökü bellekte serbest bırak
        return root;
    }

    // Silinecek elemanı bulmak için listeyi tara
    while (iterater->next != NULL && iterater->next->data != element) {
        iterater = iterater->next;
    }

    // Eğer aranan eleman bulunamadıysa
    if (iterater->next == NULL) {
        printf("Silmek istediginiz eleman linked list'te bulunamadi!\n");
        return root;
    }

    // Silinecek düğüm bulunursa bağlantıları güncelle
    temp = iterater->next;                // Silinecek düğüm
    iterater->next = iterater->next->next; // Aradaki düğümü atla

    free(temp); // Düğümü serbest bırak

    // Eğer silinen düğüm ortadaysa, sonrasındaki düğümün prew işaretçisini düzelt
    if (iterater->next != NULL) {
        iterater->next->prew = iterater;
    }

    return root; // Güncellenmiş kökü döndür
}

// =================== ÖRNEK KULLANIM (main) ===================
int main() {
    dnode *root = NULL; // Başlangıçta boş liste

    printf("=== CIFT YONLU BAGLI LISTE ORNEGI ===\n");

    // Elemanları sıralı şekilde ekle
    root = addOrderElementInDoublyLinkedList(root, 30);
    root = addOrderElementInDoublyLinkedList(root, 10);
    root = addOrderElementInDoublyLinkedList(root, 50);
    root = addOrderElementInDoublyLinkedList(root, 20);
    root = addOrderElementInDoublyLinkedList(root, 40);

    // Listeyi ekrana yazdır
    printf("\nIlk liste:\n");
    printDoublyLinkedList(root);

    // Eleman silme işlemleri
    printf("\n20 elemani siliniyor...\n");
    root = deleteElementInDoublyLinkedList(root, 20);
    printDoublyLinkedList(root);

    printf("\n10 elemani siliniyor...\n");
    root = deleteElementInDoublyLinkedList(root, 10);
    printDoublyLinkedList(root);

    printf("\n100 (olmayan eleman) siliniyor...\n");
    root = deleteElementInDoublyLinkedList(root, 100);
    printDoublyLinkedList(root);

    // Bellek temizliği
    printf("\nTum liste siliniyor...\n");
    while (root != NULL) {
        root = deleteElementInDoublyLinkedList(root, root->data);
    }

    printf("Liste temizlendi.\n");

    
    return 0;
}