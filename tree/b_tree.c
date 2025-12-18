#include <stdio.h>
#include <stdlib.h>


struct node {
    // Her düğüm bir data ve iki çocuk içerir
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node* createNode(int data) {

    // Yeni düğüm için bellekte yer aç
    Node *newNode = (Node*) malloc(sizeof(Node));

    // Veri yükle
    newNode->data = data;

    // Henüz çocuk yok
    newNode->left = NULL;
    newNode->right = NULL;

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
    // Sağ boşsa sağa ekle
    else if (root->right == NULL) {
        root->right = createNode(data);
    }
    // Eğer ikisi de doluysa sol alt ağaca eklemeye devam et
    else {
        root->left = add(root->left, data);
    }

    return root;
}



Node* findRightmost(Node* root) {
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
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // 2) TEK ÇOCUK
        if (root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        if (root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // 3) İKİ ÇOCUK — DOĞRU ÇÖZÜM
        Node *rightmost = findRightmost(root->left); // sol alt ağaçtan en sağ
        root->data = rightmost->data;                // değeri kopyala
        root->left = delete(root->left, rightmost->data); // o düğümü sil

        return root;
    }

    // RECURSIVE ARAMA
    root->left = delete(root->left, key);
    root->right = delete(root->right, key);

    return root;
}



Node* findParent(Node *root, int childValue) {

    if (root == NULL)
        return NULL;

    // Root’un sol veya sağ çocuğu aranan düğümse parent root’tur
    if ((root->left != NULL && root->left->data == childValue) ||
        (root->right != NULL && root->right->data == childValue)) {
        return root;
    }

    // Sol alt ağaçta ara
    Node *leftResult = findParent(root->left, childValue);
    if (leftResult != NULL)
        return leftResult;

    // Sağ alt ağaçta ara
    return findParent(root->right, childValue);
}

// Height: kökten en alt yaprağa olan en uzun yolun uzunluğudur

int height(Node *root) {

    if (root == NULL)
        return -1; // boş ağacın yüksekliği -1 kabul edilir

    int leftH  = height(root->left);
    int rightH = height(root->right);

    // Sol ve sağın büyük olanına +1 ekle
    return (leftH > rightH ? leftH : rightH) + 1;
}

// Depth: düğümün köke olan uzaklığı  

int depth(Node *root, int key, int level) {

    if (root == NULL)
        return -1;

    if (root->data == key)
        return level;

    // Sol tarafta ara
    int left = depth(root->left, key, level + 1);
    if (left != -1)
        return left;

    // Sağ tarafta ara
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

   

    // Parent bulma örneği
    Node *p = findParent(root, 40);
    if (p != NULL)
        printf("40'in parent'i: %d\n", p->data);
    else
        printf("Parent bulunamadi.\n");

    // Height bulma
    printf("Agacin yüksekliği: %d\n", height(root));

    // Depth bulma
    printf("40'in depth'i: %d\n", depth(root, 40, 0));

    // Bir eleman silme
    printf("\n30 siliniyor...\n");
    root = delete(root, 30);



    return 0;
}
