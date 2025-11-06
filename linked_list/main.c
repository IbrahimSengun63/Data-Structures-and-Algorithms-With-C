//"https://github.com/IbrahimSengun63/Data-Structures-and-Algorithms-With-C"


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
    root->next = NULL;

    // İlk düğümün adresini döndür
    return root;
}

// ----------------------------------------------------------------------
// addElementInLinkedList: Bağlı listenin sonuna yeni bir eleman ekler
// ----------------------------------------------------------------------
void addElementInLinkedList(node *root, int element) {
    // Listenin sonuna kadar ilerle
    while (root->next != NULL) {
        root = root->next;
    }

    // Yeni düğüm oluştur
    root->next = (node *) malloc(sizeof(node));
    root->next->data = element;
    root->next->next = NULL; // Yeni düğümün son olduğunu belirt
}

// ----------------------------------------------------------------------
// addBoxInLinkedList: Belirli bir pozisyona (count) yeni düğüm ekler
// ----------------------------------------------------------------------
void addBoxInLinkedList(node *root, int count, int data) {
    int i = 0;

    // Listedeki düğümler arasında ilerle
    while (root != NULL) {
        root = root->next;
        i += 1;

        // İstenilen konuma gelindiğinde yeni düğüm ekle
        if (i == count) {
            node *temp = (node *) malloc(sizeof(node));   // Geçici düğüm
            node *newBox = (node *) malloc(sizeof(node)); // Yeni eklenecek düğüm

            // Yeni düğümün araya eklenmesi
            temp = root->next;     // temp -> ekleme yapılacak konumun sonrası
            root->next = newBox;   // yeni düğüm araya ekleniyor
            newBox->data = data;   // yeni düğüme veri atanıyor
            newBox->next = temp;   // yeni düğümün devamı, eski bağlantıya yöneliyor
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

    // Eğer eklenecek eleman baştaki düğümden küçükse, başa eklenir
    if (root->data > element) {
        node *temp = (node *) malloc(sizeof(node));
        temp->data = element;
        temp->next = root;
        root = temp;
        return root;
    }

    // Listeyi taramak için geçici pointer
    node *iterater;
    iterater = root;

    // Sıralı pozisyonu bul: bir sonraki eleman eklenenden büyük olana kadar ilerle
    while (iterater->next != NULL && iterater->next->data < element) {
        iterater = iterater->next;
    }

    // Yeni düğüm oluştur ve araya ekle
    node *temp = (node *) malloc(sizeof(node));
    temp->next = iterater->next;
    temp->data = element;
    iterater->next = temp;

    return root;
}



// ------------------------------------------------------------
// reverseLinkedList: Bağlı listeyi ters çevirir
// ------------------------------------------------------------
node *reverseLinkedList(node *root) {
    node *prev = NULL;      // Bir önceki düğüm (başta NULL)
    node *current = root;   // Şu anki düğüm
    node *nextNode = NULL;  // Bir sonraki düğüm (geçici olarak tutulur)

    // Liste boyunca ilerle
    while (current != NULL) {
        nextNode = current->next;   //  Sonrakini kaydet
        current->next = prev;       //  Bağlantıyı ters çevir
        prev = current;             //  prev bir adım ilerler
        current = nextNode;         //  current bir adım ilerler
    }

    // prev artık yeni root'u gösteriyor
    return prev;
}


// ----------------------------------------------------------------------
// deleteElementInLinkedList: Verilen değere sahip düğümü listeden siler
// ----------------------------------------------------------------------
node *deleteElementInLinkedList(node *root, int element) {
    node *iterater;
    iterater = root;
    node *temp = (node *) malloc(sizeof(node));

    // Eğer silinecek eleman baştaysa (root düğümü)
    if (root->data == element) {
        temp = root;
        root = root->next; // ikinci düğüm yeni root olur
        free(temp);        // eski root belleği serbest bırakılır
        return root;
    }

    // Silinecek düğümü bulmak için listeyi tara
    while (iterater->next != NULL && iterater->next->data != element) {
        iterater = iterater->next;
    }

    // Eleman bulunamadıysa kullanıcıya bildir
    if (iterater->next == NULL) {
        printf("Silmek istediginiz eleman linked list'te bulunamadi!\n");
        return root;
    }

    // Silinecek düğümü aradan çıkar
    temp = iterater->next;
    iterater->next = iterater->next->next;
    free(temp); // belleği temizle

    return root;
}


// ------------------------------------------------------------
// printLinkedList: Bağlı listedeki tüm elemanları yazdırır
// ------------------------------------------------------------
void printLinkedList(node *root) {
    printf("Linked List: ");
    while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next;
    }
    printf("NULL\n");
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