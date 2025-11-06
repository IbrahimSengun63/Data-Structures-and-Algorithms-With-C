#include "algoritma.h"

/*
    Fonksiyon	                            Görevi
rootIdentifer()	                Bağlı listenin ilk düğümünü oluşturur.
addElementInLinkedList()	    Listenin sonuna yeni düğüm ekler.
addBoxInLinkedList()	        Belirtilen pozisyona yeni düğüm ekler.
addOrderElementInLinkedList()	Elemanı sıralı şekilde uygun yere ekler.
deleteElementInLinkedList()	    Belirli değere sahip düğümü listeden siler.
*/



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

    // Sıralı ekleme (örnek: 2 ekleniyor)
    root = addOrderElementInLinkedList(root, 2);
    printf("\n2 sirali sekilde eklendi:\n");
    printLinkedList(root);

    // Başa küçük bir eleman ekle (örnek: 1)
    root = addOrderElementInLinkedList(root, 1);
    printf("\n1 sirali sekilde eklendi (basa):\n");
    printLinkedList(root);

    // Ortaya manuel ekleme (örnek: 9 üçüncü düğümden sonra)
    addBoxInLinkedList(root, 2, 9);
    printf("\n2. dugumden sonra 9 eklendi:\n");
    printLinkedList(root);

    // Bir eleman silme (örnek: 5 siliniyor)
    root = deleteElementInLinkedList(root, 5);
    printf("\n5 silindi:\n");
    printLinkedList(root);

    // Olmayan eleman silme denemesi
    root = deleteElementInLinkedList(root, 99);

    
    return 0;
}