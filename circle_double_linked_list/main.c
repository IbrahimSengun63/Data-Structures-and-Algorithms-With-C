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


// Çift yönlü dairesel bağlı liste (circular doubly linked list) düğüm yapısı
struct n {
    int data;              // Düğümde tutulacak veri
    struct n *next;        // Bir sonraki düğümün adresi
    struct n *prev;        // Bir önceki düğümün adresi
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
    root->next = root; // Circular: kendini gösterir
    root->prev = root; // Circular: kendini gösterir

    // İlk düğümün adresini döndür
    return root;
}

// ----------------------------------------------------------------------
// addElementInLinkedList: Bağlı listenin sonuna yeni bir eleman ekler
// ----------------------------------------------------------------------
void addElementInLinkedList(node *root, int element) {
    node *last = root->prev; // root'un prev'i son düğümdür

    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = element;

    // Yeni düğümün bağlantıları
    newNode->next = root;   // root’a bağlanır
    newNode->prev = last;   // eski son düğüme bağlanır
    last->next = newNode;   // eski son düğüm yeni düğüme bağlanır
    root->prev = newNode;   // root’un prev’i yeni düğüm olur
}

// ----------------------------------------------------------------------
// addBoxInLinkedList: Belirli bir pozisyona (count) yeni düğüm ekler
// ----------------------------------------------------------------------
void addBoxInLinkedList(node *root, int count, int data) {
    int i = 0;
    node *iter = root;

    // Listedeki düğümler arasında ilerle
    while (i < count && iter->next != root) {
        iter = iter->next;
        i += 1;
    }

    // Yeni düğüm oluştur
    node *newBox = (node *) malloc(sizeof(node));
    newBox->data = data;

    // Yeni düğümün araya eklenmesi
    node *temp = iter->next;   // Ekleme yapılacak yerin sonrası
    iter->next = newBox;       // Yeni düğüm araya ekleniyor
    newBox->prev = iter;       // Geri bağlantı
    newBox->next = temp;       // Yeni düğümün devamı
    temp->prev = newBox;       // Sonraki düğümün prev’i yeni düğüm olur
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
        node *last = root->prev;

        newNode->next = root;
        newNode->prev = last;
        last->next = newNode;
        root->prev = newNode;
        root = newNode;
        return root;
    }

    // Sıralı pozisyonu bul: bir sonraki eleman eklenenden büyük olana kadar ilerle
    while (iterater->next != root && iterater->next->data < element) {
        iterater = iterater->next;
    }

    // Yeni düğüm oluştur ve araya ekle
    newNode->next = iterater->next;
    newNode->prev = iterater;
    iterater->next->prev = newNode;
    iterater->next = newNode;

    return root;
}


// ------------------------------------------------------------
// reverseLinkedList: Bağlı listeyi ters çevirir
// ------------------------------------------------------------
node *reverseLinkedList(node *root) {
    if (root == NULL || root->next == root) return root;

    node *current = root;
    node *temp = NULL;

    // Tüm bağlantıları tersine çevir
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // tersine gittiğimiz için prev kullanıyoruz
    } while (current != root);

    // Yeni root, eski root'un bir önceki düğümü olur
    root = root->next;
    return root;
}


// ----------------------------------------------------------------------
// deleteElementInLinkedList: Verilen değere sahip düğümü listeden siler
// ----------------------------------------------------------------------
node *deleteElementInLinkedList(node *root, int element) {
    if (root == NULL) return NULL;

    node *iterater = root;

    // Eğer silinecek eleman baştaysa (root düğümü)
    if (root->data == element) {
        // Tek eleman varsa
        if (root->next == root) {
            free(root);
            return NULL;
        }

        node *last = root->prev;
        node *newRoot = root->next;

        last->next = newRoot;
        newRoot->prev = last;
        free(root);
        return newRoot;
    }

    // Silinecek düğümü bul
    do {
        if (iterater->data == element) break;
        iterater = iterater->next;
    } while (iterater != root);

    // Eleman bulunamadıysa
    if (iterater == root) {
        printf("Silmek istediginiz eleman linked list'te bulunamadi!\n");
        return root;
    }

    iterater->prev->next = iterater->next;
    iterater->next->prev = iterater->prev;
    free(iterater);

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
        printf("%d <-> ", iter->data);
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
