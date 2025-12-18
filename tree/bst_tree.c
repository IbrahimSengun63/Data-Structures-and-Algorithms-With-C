#include <stdio.h>
#include <stdlib.h>

struct b {
    // Binary Search Tree (BST) düğüm yapısı:
    // Her düğüm bir veri (data) ve sol/sağ çocuk düğümlerine işaretçiler içerir.
    int data;
    struct b *left;
    struct b *right;
};

typedef struct b bts;

// Yeni bir BST düğümü oluşturur (leaf node)
bts *btsIdentifer(int data) {

    // Yeni bir düğüm için heap bellekte yer ayırıyoruz
    bts *leaf = (bts *) malloc(sizeof(bts));

    // Düğümün veri kısmı atanıyor
    leaf -> data = data;

    // Yeni düğümün henüz çocukları yoktur, bu nedenle NULL atanır
    leaf -> left = NULL;
    leaf -> right = NULL;

    return leaf;
}

// BST'ye eleman ekleme (recursive şekilde)
bts *addLeafInBts(bts *tree, int data) {

    // Eğer ağaç boşsa, eklenen değer kök olur
    if(tree == NULL) {
        return btsIdentifer(data);
    }

    // Eğer eklenecek değer düğümden büyükse sağ tarafa ekleme yapılır
    if (tree -> data < data) {

        /* Açıklama:
           Recursive şekilde sağ alt ağaçlara gidilir.
           Sağ çocuk NULL olduğunda yeni düğüm oluşturulup oraya yerleştirilir.
        */
        tree -> right = addLeafInBts(tree -> right, data);
        return tree;
    }

    // Eğer eklenecek değer düğümden küçükse sol tarafa ekleme yapılır
    tree -> left = addLeafInBts(tree -> left, data);
    return tree;
}

// In-order traversal (Sıralı dolaşım): SOL - KÖK - SAĞ
void traversal(bts *tree) {

    // Boş düğüm varsa durdur
    if (tree == NULL) {
        return;
    }

    /*
        In-order traversal:
        1) Sol alt ağacı dolaşır
        2) Mevcut düğümün verisini yazar
        3) Sağ alt ağacı dolaşır

        Bu yöntem BST için her zaman sıralı çıktı sağlar.
    */

    traversal(tree -> left);            // Sol taraf
    printf("%d ", tree -> data);        // Kök
    traversal(tree -> right);           // Sağ taraf
}

// Ağaçta bir değer arama
int find (bts * tree , int key) {

    // Boş düğüme gelindiyse bulunamadı
    if (tree == NULL) {
        return -1;
    }

    // Aranan değer bulundu
    if (tree -> data == key) {
        return 1;
    }

    // Sol alt ağaçta aramaya devam
    if(find(tree -> left, key) == 1) {
        return 1;
    }

    // Sağ alt ağaçta aramaya devam
    if(find(tree -> right, key) == 1) {
        return 1;
    }

    return -1; // Bulunamadı
}

// BST'de en büyük elemanı bulur (en sağdaki düğüm)
int max(bts *tree) {

    // Sağ çocuk NULL olana kadar ilerle
    while (tree -> right != NULL) {
        tree = tree -> right;
    }

    return tree -> data;
}

// BST'de en küçük elemanı bulur (en soldaki düğüm)
int min(bts *tree) {

    // Sol çocuk NULL olana kadar ilerle
    while (tree -> left != NULL) {
        tree = tree -> left;
    }

    return tree -> data;
}

// BST'den eleman silme
bts *deleteLeafInBts(bts *tree, int key) {

    // Ağaç boşsa geri dön
    if (tree == NULL) {
        return NULL;
    }

    // Aranan düğüm bulundu
    if (tree -> data == key) {

        // Eğer düğüm yaprak ise (child yoksa) direkt silinir
        if (tree -> left == NULL && tree -> right == NULL) {
            return NULL;
        }

        // Sağ çocuk varsa: sağ alt ağacın en küçük elemanı ile yer değiştirilir
        if (tree -> right != NULL) {
            tree -> data = min(tree -> right);
            tree -> right = deleteLeafInBts(tree -> right, min(tree -> right));
            return tree;
        }

        // Sağ çocuk yoksa: sol alt ağacın en büyük elemanı ile yer değiştirilir
        tree -> data = max(tree -> left);
        tree -> left = deleteLeafInBts(tree -> left, max(tree -> left));
        return tree;
    }

    // Silinecek değer düğümden büyükse sağ alt ağaca git
    if (tree -> data < key) {
        tree -> right = deleteLeafInBts(tree -> right, key);
        return tree;
    }

    // Silinecek değer düğümden küçükse sol alt ağaca git
    tree -> left = deleteLeafInBts(tree -> left, key);
    return tree;
}
// Sağ -> Kök -> Sol şeklinde yazdırır
void printBTS(bts *tree, int level) {
    if (tree == NULL)
        return;

    // Önce sağ alt ağacı yazdır
    printBTS(tree->right, level + 1);

    // Level kadar boşluk koyarak görüntüyü ağaç gibi yap
    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", tree->data);

    // Ardından sol alt ağacı yazdır
    printBTS(tree->left, level + 1);
}

void printTree(bts *tree) {
    printf("\n===== BST YAPISI (GRAFIKSEL) =====\n\n");
    printBTS(tree, 0);
    printf("\n==================================\n\n");
}

//////////////////////
//     MAIN         //
//////////////////////
int main() {

    bts *tree = NULL;

    // Örnek BST oluşturma
    tree = addLeafInBts(tree, 56);
    tree = addLeafInBts(tree, 26);
    tree = addLeafInBts(tree, 200);
    tree = addLeafInBts(tree, 18);
    tree = addLeafInBts(tree, 28);
    tree = addLeafInBts(tree, 190);
    tree = addLeafInBts(tree, 213);
    tree = addLeafInBts(tree, 12);
    tree = addLeafInBts(tree, 24);
    tree = addLeafInBts(tree, 27);
    tree = addLeafInBts(tree, 215);

    // In-order traversal
    printf("In-order traversal: ");
    traversal(tree);
    printf("\n");

    // Grafiksel yazdırma
    printTree(tree);

    // Arama örnekleri
    printf("Find 27: %s\n", find(tree, 27) == 1 ? "Bulundu" : "Bulunamadi");
    printf("Find 500: %s\n", find(tree, 500) == 1 ? "Bulundu" : "Bulunamadi");

    // Max ve Min
    printf("Max: %d\n", max(tree));
    printf("Min: %d\n", min(tree));

    // Silme işlemi
    printf("\n215 siliniyor...\n");
    tree = deleteLeafInBts(tree, 215);

    printTree(tree);

    printf("In-order traversal (güncel): ");
    traversal(tree);
    printf("\n");

    return 0;
}
