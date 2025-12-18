#include <stdio.h>
#include <stdlib.h>


struct node {
    // Her düğüm bir data ve üç çocuk içerir
    int data;
    struct node *left;
    struct node *middle;
    struct node *right;
};

typedef struct node Node;


Node* createNode(int data) {

    // Yeni düğüm için bellekte yer aç
    Node *newNode = (Node*) malloc(sizeof(Node));

    // Veri yükle
    newNode->data = data;

    // Henüz çocuk yok
    newNode->left   = NULL;
    newNode->middle = NULL;
    newNode->right  = NULL;

    return newNode;
}



Node* add(Node *root, int data) {

    // Ağaç boşsa yeni düğüm kök olur
    if (root == NULL) {
        return createNode(data);
    }

    // Sol boşsa sola ekle
    if (root->left == NULL) {
        root->left = createNode(data);
    }
    // Orta boşsa ortaya ekle
    else if (root->middle == NULL) {
        root->middle = createNode(data);
    }
    // Sağ boşsa sağa ekle
    else if (root->right == NULL) {
        root->right = createNode(data);
    }
    // Üçü de doluysa sol alt ağaçtan devam et
    else {
        root->left = add(root->left, data);
    }

    return root;
}



/*
    Sol → Orta → Sağ sırasına göre
    en sağdaki düğümü bulur
*/
Node* findRightmost(Node* root) {

    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}



Node* delete(Node* root, int key) {

    if (root == NULL)
        return NULL;

    // DÜĞÜM BULUNDU
    if (root->data == key) {

        // 1) YAPRAK (ÇOCUKSUZ)
        if (root->left == NULL &&
            root->middle == NULL &&
            root->right == NULL) {

            free(root);
            return NULL;
        }

        // 2) TEK ÇOCUK
        if (root->left != NULL &&
            root->middle == NULL &&
            root->right == NULL) {

            Node *temp = root->left;
            free(root);
            return temp;
        }

        if (root->left == NULL &&
            root->middle != NULL &&
            root->right == NULL) {

            Node *temp = root->middle;
            free(root);
            return temp;
        }

        if (root->left == NULL &&
            root->middle == NULL &&
            root->right != NULL) {

            Node *temp = root->right;
            free(root);
            return temp;
        }

        // 3) BİRDEN FAZLA ÇOCUK
        // Sol alt ağaçtan en sağdaki düğüm bulunur
        Node *rightmost = findRightmost(root->left);

        // Değer kopyalanır
        root->data = rightmost->data;

        // Kopyalanan düğüm silinir
        root->left = delete(root->left, rightmost->data);

        return root;
    }

    // RECURSIVE ARAMA
    root->left   = delete(root->left, key);
    root->middle = delete(root->middle, key);
    root->right  = delete(root->right, key);

    return root;
}



Node* findParent(Node *root, int childValue) {

    if (root == NULL)
        return NULL;

    // Root’un herhangi bir çocuğu aranan düğümse parent root’tur
    if ((root->left   != NULL && root->left->data   == childValue) ||
        (root->middle != NULL && root->middle->data == childValue) ||
        (root->right  != NULL && root->right->data  == childValue)) {

        return root;
    }

    // Sol alt ağaçta ara
    Node *res = findParent(root->left, childValue);
    if (res != NULL)
        return res;

    // Orta alt ağaçta ara
    res = findParent(root->middle, childValue);
    if (res != NULL)
        return res;

    // Sağ alt ağaçta ara
    return findParent(root->right, childValue);
}



// Height: kökten en alt yaprağa olan en uzun yol
int height(Node *root) {

    if (root == NULL)
        return -1;

    int h1 = height(root->left);
    int h2 = height(root->middle);
    int h3 = height(root->right);

    // En büyük yüksekliği seç
    int max = h1;
    if (h2 > max) max = h2;
    if (h3 > max) max = h3;

    return max + 1;
}



// Depth: düğümün köke olan uzaklığı
int depth(Node *root, int key, int level) {

    if (root == NULL)
        return -1;

    if (root->data == key)
        return level;

    int d;

    d = depth(root->left, key, level + 1);
    if (d != -1) return d;

    d = depth(root->middle, key, level + 1);
    if (d != -1) return d;

    return depth(root->right, key, level + 1);
}



int main() {

    Node *root = NULL;

    // Ağaç oluşturma
    root = add(root, 10);
    root = add(root, 20);
    root = add(root, 30);
    root = add(root, 40);
    root = add(root, 50);
    root = add(root, 60);
    root = add(root, 70);

    // Parent bulma
    Node *p = findParent(root, 40);
    if (p != NULL)
        printf("40'in parent'i: %d\n", p->data);
    else
        printf("Parent bulunamadi.\n");

    // Height
    printf("Agacin yüksekliği: %d\n", height(root));

    // Depth
    printf("40'in depth'i: %d\n", depth(root, 40, 0));

    // Silme
    printf("\n30 siliniyor...\n");
    root = delete(root, 30);

    return 0;
}
