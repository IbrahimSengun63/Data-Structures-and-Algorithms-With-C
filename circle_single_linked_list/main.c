#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
    Fonksiyon	                            Görevi
rootIdentifer()	                Bağlı listenin ilk düğümünü oluşturur.
addElementInLinkedList()	    Listenin sonuna yeni düğüm ekler.
addBoxInLinkedList()	        Belirtilen pozisyona yeni düğüm ekler.
addOrderElementInLinkedList()	Elemanı sıralı şekilde uygun yere ekler.
deleteElementInLinkedList()	    Belirli değere sahip düğümü listeden siler.
*/


// Tek yönlü bağlı liste (singly linked list) düğüm yapısı
struct n {
    int data;           // Düğümde tutulacak veri
    struct n *next;     // Bir sonraki düğümün adresi
};

typedef struct n node;  // struct n yerine sadece 'node' yazmak için typedef

// ----------------------------------------------------------------------
// rootIdentifer: Yeni bir bağlı liste başlatır ve ilk düğümü oluşturur
// ----------------------------------------------------------------------
node *rootIdentifer(int data) {
    // Bellekte yeni bir düğüm için yer ayır
    node *root = (node *) malloc(sizeof(node));

    // Düğümün veri ve bağlantı bilgilerini ayarla
    root->data = data;
    root->next = root; // Circular linked list'te kendine bağlanır

    // İlk düğümün adresini döndür
    return root;
}

// ----------------------------------------------------------------------
// addElementInLinkedList: Bağlı listenin sonuna yeni bir eleman ekler
// ----------------------------------------------------------------------
void addElementInLinkedList(node *root, int element) {
    node *iter = root;

    // Listenin sonuna kadar ilerle (dairesel yapıda root’a dönene kadar)
    while (iter->next != root) {
        iter = iter->next;
    }

    // Yeni düğüm oluştur
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = element;
    newNode->next = root;   // Yeni düğüm tekrar root’a bağlanır
    iter->next = newNode;   // Eski son düğüm yeni düğüme bağlanır
}

// ----------------------------------------------------------------------
// addBoxInLinkedList: Belirli bir pozisyona (count) yeni düğüm ekler
// ----------------------------------------------------------------------
void addBoxInLinkedList(node *root, int count, int data) {
    int i = 0;
    node *iter = root;

    // Listedeki düğümler arasında ilerle
    while (iter->next != root) {
        iter = iter->next;
        i += 1;

        // İstenilen konuma gelindiğinde yeni düğüm ekle
        if (i == count) {
            node *temp = (node *) malloc(sizeof(node));   // Geçici düğüm
            node *newBox = (node *) malloc(sizeof(node)); // Yeni eklenecek düğüm

            // Yeni düğümün araya eklenmesi
            temp = iter->next;     // temp -> ekleme yapılacak konumun sonrası
            iter->next = newBox;   // yeni düğüm araya ekleniyor
            newBox->data = data;   // yeni düğüme veri atanıyor
            newBox->next = temp;   // yeni düğümün devamı, eski bağlantıya yöneliyor
            break;
        }
    }
}

// ----------------------------------------------------------------------
// addOrderElementInLinkedList: Verilen elemanı sıralı şekilde listeye ekler
// (Küçükten büyüğe sıralı ekleme)
// ----------------------------------------------------------------------
node *addOrderElementInLinkedList(node *root, int element) {
    // Liste boşsa, ilk düğüm oluşturulur
    if (root == NULL) {
        root = rootIdentifer(element);
        return root;
    }

    node *iterater = root;
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = element;

    // Eğer eklenecek eleman baştaki düğümden küçükse, başa eklenir
    if (root->data > element) {
        // Son düğümü bul
        while (iterater->next != root)
            iterater = iterater->next;

        iterater->next = newNode;
        newNode->next = root;
        root = newNode;
        return root;
    }

    iterater = root;
    // Sıralı pozisyonu bul: bir sonraki eleman eklenenden büyük olana kadar ilerle
    while (iterater->next != root && iterater->next->data < element) {
        iterater = iterater->next;
    }

    // Yeni düğüm oluştur ve araya ekle
    newNode->next = iterater->next;
    iterater->next = newNode;

    return root;
}


// ------------------------------------------------------------
// reverseLinkedList: Bağlı listeyi ters çevirir
// ------------------------------------------------------------
node *reverseLinkedList(node *root) {
    if (root == NULL || root->next == root) return root;

    node *prev = root;
    node *current = root->next;
    node *nextNode;

    while (current != root) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    root->next = prev; // Son düğümün bağlantısı eski root’a yapılır
    root = prev;       // Yeni root son düğüm olur
    return root;
}


// ----------------------------------------------------------------------
// deleteElementInLinkedList: Verilen değere sahip düğümü listeden siler
// ----------------------------------------------------------------------
node *deleteElementInLinkedList(node *root, int element) {
    if (root == NULL) return NULL;

    node *iterater = root;
    node *temp;

    // Eğer silinecek eleman baştaysa (root düğümü)
    if (root->data == element) {
        // Tek eleman varsa
        if (root->next == root) {
            free(root);
            return NULL;
        }

        // Son düğümü bul
        while (iterater->next != root)
            iterater = iterater->next;

        temp = root;
        iterater->next = root->next;
        root = root->next;
        free(temp);
        return root;
    }

    // Silinecek düğümü bulmak için listeyi tara
    while (iterater->next != root && iterater->next->data != element) {
        iterater = iterater->next;
    }

    // Eleman bulunamadıysa kullanıcıya bildir
    if (iterater->next == root) {
        printf("Silmek istediginiz eleman linked list'te bulunamadi!\n");
        return root;
    }

    // Silinecek düğümü aradan çıkar
    temp = iterater->next;
    iterater->next = temp->next;
    free(temp); // belleği temizle

    return root;
}


// ------------------------------------------------------------
// printLinkedList: Bağlı listedeki tüm elemanları yazdırır
// ------------------------------------------------------------
void printLinkedList(node *root) {
    if (root == NULL) {
        printf("Liste bos.\n");
        return;
    }

    printf("Linked List: ");
    node *iter = root;
    do {
        printf("%d -> ", iter->data);
        iter = iter->next;
    } while (iter != root);
    printf("(root'a dondu)\n");
}


// ------------------------------------------------------------
// main fonksiyonu
// ------------------------------------------------------------
int main() {
    // Başlangıçta ilk düğümü oluştur
    node *root = rootIdentifer(5);
    printf("Ilk dugum olusturuldu (5)\n");
    printLinkedList(root);

    // Listenin sonuna eleman ekleme
    addElementInLinkedList(root, 4);
    addElementInLinkedList(root, 3);
    printf("\nSonuna 4 ve 3 eklendi:\n");
    printLinkedList(root);

    // Sıralı ekleme (örnek: 25 ekleniyor)
    root = addOrderElementInLinkedList(root, 2);
    printf("\n2 sirali sekilde eklendi:\n");
    printLinkedList(root);

    // Başa küçük bir eleman ekle (örnek: 5)
    root = addOrderElementInLinkedList(root, 6);
    printf("\n6 sirali sekilde eklendi (basa):\n");
    printLinkedList(root);

    // Ortaya manuel ekleme (örnek: 15 üçüncü düğümden sonra)
    addBoxInLinkedList(root, 2, 9);
    printf("\n2. dugumden sonra 9 eklendi:\n");
    printLinkedList(root);

    // Bir eleman silme (örnek: 20 siliniyor)
    root = deleteElementInLinkedList(root, 5);
    printf("\n5 silindi:\n");
    printLinkedList(root);

    // Listeyi ters çevir
    root = reverseLinkedList(root);
    printf("\nTers Cevrilmis Liste:\n");
    printLinkedList(root);

    // Olmayan eleman silme denemesi
    root = deleteElementInLinkedList(root, 99);

    return 0;
}
