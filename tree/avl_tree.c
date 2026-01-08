#include <stdio.h>
#include <stdlib.h>

/*
    =========================
        AVL TREE YAPISI
    =========================

    AVL Tree farkları:
    - Her düğümde "height" (yükseklik) bilgisi tutulur
    - Her ekleme/silmeden sonra dengeleme yapılır
    - Denge için rotasyon fonksiyonları eklenmiştir
*/

struct b {
    int data;
    struct b *left;
    struct b *right;
    int height;              // AVL'e özel: düğüm yüksekliği
};

typedef struct b bts;

// ---------------- AVL YARDIMCI FONKSİYONLAR ----------------

// Maksimum değer
int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

// Düğüm yüksekliği
int height(bts *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Denge faktörü (Balance Factor)
int getBalance(bts *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// ---------------- ROTASYON FONKSİYONLARI ----------------

// Sağ rotasyon (LL durumu)
bts *rightRotate(bts *y) {
    bts *x = y->left;
    bts *T2 = x->right;

    // Rotasyon
    x->right = y;
    y->left = T2;

    // Yükseklik güncelle
    y->height = maxValue(height(y->left), height(y->right)) + 1;
    x->height = maxValue(height(x->left), height(x->right)) + 1;

    return x; // Yeni kök
}

// Sol rotasyon (RR durumu)
bts *leftRotate(bts *x) {
    bts *y = x->right;
    bts *T2 = y->left;

    // Rotasyon
    y->left = x;
    x->right = T2;

    // Yükseklik güncelle
    x->height = maxValue(height(x->left), height(x->right)) + 1;
    y->height = maxValue(height(y->left), height(y->right)) + 1;

    return y; // Yeni kök
}

// ---------------- DÜĞÜM OLUŞTURMA ----------------

// Yeni AVL düğümü oluşturur
bts *btsIdentifer(int data) {
    bts *leaf = (bts *)malloc(sizeof(bts));
    leaf->data = data;
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->height = 1; // AVL'de yeni düğüm yüksekliği 1
    return leaf;
}

// ---------------- AVL'YE ELEMAN EKLEME ----------------

bts *addLeafInBts(bts *tree, int data) {
    // 1) Normal BST ekleme
    if (tree == NULL)
        return btsIdentifer(data);

    if (data < tree->data)
        tree->left = addLeafInBts(tree->left, data);
    else if (data > tree->data)
        tree->right = addLeafInBts(tree->right, data);
    else
        return tree; // Aynı değer eklenmez

    // 2) Yüksekliği güncelle
    tree->height = 1 + maxValue(height(tree->left), height(tree->right));

    // 3) Denge faktörünü al
    int balance = getBalance(tree);

    // 4) AVL dengeleme durumları

    // LL
    if (balance > 1 && data < tree->left->data)
        return rightRotate(tree);

    // RR
    if (balance < -1 && data > tree->right->data)
        return leftRotate(tree);

    // LR
    if (balance > 1 && data > tree->left->data) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    // RL
    if (balance < -1 && data < tree->right->data) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

// ---------------- INORDER TRAVERSAL ----------------

void traversal(bts *tree) {
    if (tree == NULL)
        return;
    traversal(tree->left);
    printf("%d ", tree->data);
    traversal(tree->right);
}

// ---------------- ARAMA ----------------

int find(bts *tree, int key) {
    if (tree == NULL)
        return -1;
    if (tree->data == key)
        return 1;
    if (key < tree->data)
        return find(tree->left, key);
    return find(tree->right, key);
}

// ---------------- MIN / MAX ----------------

int min(bts *tree) {
    while (tree->left != NULL)
        tree = tree->left;
    return tree->data;
}

int max(bts *tree) {
    while (tree->right != NULL)
        tree = tree->right;
    return tree->data;
}

// ---------------- AVL'DEN ELEMAN SİLME ----------------

bts *deleteLeafInBts(bts *tree, int key) {
    if (tree == NULL)
        return tree;

    // BST silme
    if (key < tree->data)
        tree->left = deleteLeafInBts(tree->left, key);
    else if (key > tree->data)
        tree->right = deleteLeafInBts(tree->right, key);
    else {
        if (tree->left == NULL || tree->right == NULL) {
            bts *temp = tree->left ? tree->left : tree->right;

            if (temp == NULL) {
                temp = tree;
                tree = NULL;
            } else {
                *tree = *temp;
            }
            free(temp);
        } else {
            int tempVal = min(tree->right);
            tree->data = tempVal;
            tree->right = deleteLeafInBts(tree->right, tempVal);
        }
    }

    if (tree == NULL)
        return tree;

    // Yükseklik güncelle
    tree->height = 1 + maxValue(height(tree->left), height(tree->right));

    // Denge kontrolü
    int balance = getBalance(tree);

    // LL
    if (balance > 1 && getBalance(tree->left) >= 0)
        return rightRotate(tree);

    // LR
    if (balance > 1 && getBalance(tree->left) < 0) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    // RR
    if (balance < -1 && getBalance(tree->right) <= 0)
        return leftRotate(tree);

    // RL
    if (balance < -1 && getBalance(tree->right) > 0) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }

    return tree;
}

// ---------------- GRAFİKSEL YAZDIRMA ----------------

void printBTS(bts *tree, int level) {
    if (tree == NULL)
        return;

    printBTS(tree->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d(h=%d)\n", tree->data, tree->height);
    printBTS(tree->left, level + 1);
}

void printTree(bts *tree) {
    printf("\n===== AVL TREE (GRAFIKSEL) =====\n\n");
    printBTS(tree, 0);
    printf("\n===============================\n\n");
}

// ---------------- MAIN ----------------

int main() {
    bts *tree = NULL;

    int values[] = {56, 26, 200, 18, 28, 190, 213, 12, 24, 27, 215};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        tree = addLeafInBts(tree, values[i]);

    printf("In-order traversal: ");
    traversal(tree);
    printf("\n");

    printTree(tree);

    printf("Find 27: %s\n", find(tree, 27) == 1 ? "Bulundu" : "Bulunamadi");
    printf("Find 500: %s\n", find(tree, 500) == 1 ? "Bulundu" : "Bulunamadi");

    printf("Max: %d\n", max(tree));
    printf("Min: %d\n", min(tree));

    printf("\n215 siliniyor...\n");
    tree = deleteLeafInBts(tree, 215);

    printTree(tree);

    printf("In-order traversal (güncel): ");
    traversal(tree);
    printf("\n");

    return 0;
}
