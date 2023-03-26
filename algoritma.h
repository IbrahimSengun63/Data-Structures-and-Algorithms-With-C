#ifndef algoritma
#define algoritma
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
float twoNumberOrt(float x, float y) {
	return (x + y) / (float)2;
}

int minArrayElement(int array[],int size) {
	
	int i,min;
	min = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

void arrayPrint(int array[], int size) {
	
	int i;
	
	for (i = 0; i < size; i++) {
		
		if (i >= 10) {
			printf("%d.Element of array = %d\n",i,array[i]);
		} else {
			printf("%d. Element of array = %d\n",i,array[i]);
		}
	}
}

int arrayCreate (int array[],int size) {
	
	int i = 0,x=0;
	for ( ; i < size; i++){
		printf("Please write the %d. element of array: ",i);
		scanf("%d",&x);
		array[i] = x;
	}
	// arrayCreate function return outside world a pointer that way if we want to use this funciton, we must declare a pointer variable.
	return *array;
}

void arrayMemberCheck (int array[], int size, int searchValue) {
	
	//if you want the use this function you must include "stdbool.h" in your project.
	int i = 0;
	bool find = false;
	
	for (i = 0; i < size; i++)
	{
		if (searchValue == array[i])
		{
			printf("The value you want to search is in the array\n");
			find = true;
			break;
		}
	}
	
	if (find == false)
	{
		printf("The value you want to search is not in the array \n");
	}
	
}

void arrayNegativeAndPositiveSum (int array[], int size) {
	
	int i = 0, na = 0, pa = 0, nt = 0, pt = 0;
	
	for (i = 0; i < size; i++)
	{
		if (array[i] >= 0)
		{
			pa++;
			pt += array[i];
		}else
		{
			na++;
			nt += array[i];
		}
	}
	
	printf("Negative value and negative sum=%d , %d\n",na,nt);
	printf("Positive value and positive sum=%d , %d\n",pa,pt);
	
}

int arraySort (int array[], int size) {
	
	// arraySort function return outside world a pointer that way if we want to use this funciton, we must declare a pointer variable.
	int i , j, temp, min;
	
	min = array[0];
	
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return *array;
}

int arraySum (int array[],int size) {
	int i = 0;
	int sum = 0;
	
	for (i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

float calculateAvarage() {
	
	int x;
	float counter=0;
	float result=0;
	float ort=0;
	printf("If you want to termanete the function press ('0')\n");
	printf("Please input values\n");
	while (x!=0)
	{
		scanf("%d",&x);
		result+=x;
		counter+=1;
	}
	counter-=1;
	ort=result/counter;
	return ort;
	
}

int sum () {
	int sum = 0;
	int i, x;
	
	printf("If you want to termanete the function press ('0')\n");
	printf("Please input values\n");
	
	while (x != 0) {
		scanf("%d",&x);
		sum += x;
	}
	
	return sum;
	
}

int factoriel(int number)
{
	if (number == 0)
	{
		return 1;
	}
	else
	{
		return number * factoriel(number-1);
	}
	
}

int generateFibonacciArray(int fibonacci[],int length) {
	
	// generateFibonacciArray function return outside world a pointer that way if we want to use this funciton, we must declare a pointer variable.
	int i;
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
	for (i = 2; i < length; i++)
	{
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}
	
	return *fibonacci;
}

int randomArrayGenarater(int array[], int size) {
	
	// randomArrayGenarater function return outside world a pointer that way if we want to use this funciton, we must declare a pointer variable.
	
	int i = 0;
	
	srand(time(NULL));
	
	for (i = 0; i < size; i++) {
		array[i] = rand()%100+1;
	}
	
	return *array;
}

void twoDimensionMatris (int array[][4],int size) {
	
	int i = 0, j = 0, x;
	
	for (i = 0; i < size; i++) {
		
		for (j = 0; j < size; j++){
			printf("Input element array[%d][%d]: ",i,j);
			scanf("%d",&x);
			array[i][j] = x;
		}
	}
	
	for (i = 0; i < size; i++) {
		
		for (j = 0; j < size; j++){
			printf(" %d ", array[i][j]);
			
		}
		printf("\n");
	}
	
	
}

int listDivisorsAndSum (int number) {
	
	int i;
	int result = 0;
	
	for (i = 1; i <= number; i++)
	{ 
		
		if (number % i == 0)
		{
			printf("%d \n",i);
			result += i;	
		}
	}
	printf("--------\n");
	return result;
}

void pozitiveAndNegativeNumberInArray(int array[], int size) {
	
	int i;
	for (i = 0; i < size; i++)
	{
		if (array[i] >= 0)
		{
			printf("%d. element in the array is positive = %d\n",i,array[i]);
		} else 
		{
			printf("%d. element in the array is negative = %d\n",i,array[i]);
		}
	}
}

void reverse(char array[]) {
	
	int i;
	char temp;
	int size = strlen(array);
	
	for (i = 0; i < size / 2; i++) {
		temp = array[i];
		array[i] = array[size - i - 1] ;
		array[size -i -1]  = temp;
	}
}

bool armstrongNumber (int number) {
	
	//if you want the use this function you must include "stdbool.h" in your project.
	int i, sum = 0, digit = 0, temp = 0;
	temp = number;
	
	while (number > 0)
	{
		digit = number % 10;
		sum += (digit * digit * digit);
		number = number / 10;
	} 
	
	if (temp == sum)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int minSumMembers(int array[],int size)
{
	int i ,j;
	int min1, min2, sum, minSum;
	min1 = array[0];
	min2 = array[1];
	minSum = abs(min1) + abs(min2);
	for (i = 0; i < size; i++)
	{
		for (j = i+1; j < size; j++)
		{
			sum = array[i] + array[j];
			if (abs(minSum) > abs(sum))
			{
				minSum = sum;
				min1 = array[i];
				min2 = array[j];
			}
		}
	}
	
	return printf("min sum = %d, min1 = %d, min2 = %d\n",minSum,min1,min2);
}

void pascalPyramid (int numberOfRow) {
	
	int c = 1, blk, i, j;
    
	for(i = 0; i < numberOfRow; i++)
    {
        for(blk = 1; blk <= numberOfRow-i; blk++)
		{
			printf("  ");
	    }
        for(j = 0; j <= i; j++)
        {
            if (j==0 || i==0)
			{
				c = 1;
			}   
            else
			{
				c = c * (i-j+1) /j;
			}  
            printf("% 4d",c);
        }
        printf("\n");
    }
}

int sameFirstDigit (int number1,int number2)
{
	int c, d;
	while (number1 > 0)
	{
		c = number1 % 10;
		number1 = number1 / 10;
	}
	
	while (number2 > 0)
	{
		d = number2 % 10;
		number2 = number2/10;
	}
	
	if (d == c)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void swapElementInArray(int array[], int size, int change, int exchange)
{
	int i, temp;
	
	for (i = 0; i < size; i++)
	{
		if (i == change)
		{
			temp = array[change];
			array[change] = array[exchange];
			array[exchange] = temp;
		}
	}
}

typedef struct s {
	int size;
	int peak;
	int *array;
	//ilk giren eleman son ��kar ilkesi stack ilkesidir.
	//stack yap�s� i�in birden fazla de�i�keni bir arada tutabilmek i�in sturctlar ile ve typedef ile stack veri yap�s� olu�turulur.
} stack;


int pop (stack *s) {
	
	//stackde eger f�rlat�lacak eleman kalmaz ise -1 de�erini d�nd�r�r�z.
	if (s -> peak <= 0 || s -> array == NULL){
		printf("Stack Is NULL\n");
		return -1;
	}
	
	int i = 0;
	if (s -> peak <= s -> size / 4 && s -> size > 2) {
		
		//stack den eleman ��kard���m�z i�in e�er stack�n toplam size'� peakin 4 kat� veya daha y�ksek se size yar�ya indiririz.
		//yeni bir dynamic dizi olu�tururuz ve bu dizinin boyutunu eskisin yar�s� yapar�z.
		int *newArray = (int *) malloc(sizeof(int) * (s->size / 2));
		
		//eski diziyi yeni diziye kopyalamadan �nce elemanlar� for dongusuyle elemanlar� kopyalar�z.
		for (i = 0; i < s -> peak; i++) {
			newArray[i] = s -> array[i];
		}
		//free()->geli�mi� dillerdeki garbage collecter g�revi g�r�r ramda hi� bir i�e yaramayan eski de�erleri siler.
		free(s -> array);
		s -> array = newArray;
		s -> size /=2;
	}
	
	//stackten eleman ��kard���m�zda en �sten eleman ��kard���m�z i�in top de�erini bir azalt�r�z.
	return s -> array[--s -> peak];
}

void push (int element, stack *s) {
	
	//eger stac i�indeki array null ise haf�zada yeni bir array i�in malloc ile yer a�ar�z.
	if (s -> peak <= 0 || s -> array == NULL) {
		s -> array = (int *) malloc(sizeof(int) * 2);
	}
	
	int i = 0;
	if (s -> peak >= (s -> size) - 1) {
		
		// push i�lemi s�ras�nda e�er size de�eri dolursa, size de�i�tirmek i�in eski dizinin iki kat� boyuta sahip yeni bir dizi tan�mlay�p eski diziyi yeni diziye kopyalamam�z gerekir.
		//size � de�i�tirmek i�in ise ilk ba�ta veriler 'size' de�i�kenini 2 kat�na ��karmam�z yeterli olur.
		//bu iki kat�na ��karma i�lemini newArray[size * 2] �eklinde yapamaya�a��m�z i�in yani dizi yap�s� dynamic memory'e sahip olmad��� i�in pointerlar� kullan�r�z.
		int *newArray = (int *) malloc(sizeof(int) * s->size * 2);
		
		//eski diziyi yeni diziye kopyalamadan �nce elemanlar� for dongusuyle elemanlar� kopyalar�z.
		for (i = 0; i < s -> size; i++){
			newArray[i] = s-> array[i];
		}
		//free()->geli�mi� dillerdeki garbage collecter g�revi g�r�r ramda hi� bir i�e yaramayan eski de�erleri siler.
		free(s -> array);
		s -> array = newArray;
		s -> size *=2;
	}
	
	//stack a eleman ekled�g�m�zde en uste eklend�g� �c�n top u bir art�r�r�z.
	s -> array[s -> peak++] = element;
	
}

int stackInTop (stack *s) {
	//stackdeki en tepedeki de�eri bulmak i�in peak i 1 azalt�r�z.
	return s -> array[--s -> peak];
}

stack *stackIdentifer() {
	stack *s = (stack * ) malloc(sizeof(stack));
	s -> array = NULL;
	s -> size = 2;
	s -> peak = 0;
	return s;
}

typedef struct q {
	//queue = t�rk�e kar��l��� s�rad�r. ilk giren ilk ��kar ve son giren son ��kar ilkesine g�re �al���r. iki fonksiyondan olu�ur enque() -> eleman ekler deque()-> eleman ��kart�r.
	//queue i�in gerekli global de�i�kenlerin bir arada tutulabilinmesi i�in global bir struct tan�mlay�p bu struct�n �rne�inide typedef ile olu�turuyoruz.
	int first;
	int last;
	int size;
	int *array;
}queue;

int deque (queue *q) {
	
	int i = 0;
	if (q -> first == q -> last) {
		//queue nin s�raba�� ile s�rasonu birbirine e�it ise queue bo�tur
		printf("Queue Is Null\n");
		return -1;
	}
	// queue deki eleman say�s�n� son s�radan ilk s�ray� ��kartarak bulabiliriz.
	// e�er queue nun eleman say�s� size 1/4 �nden k���kse yeni bir dizi olu�turup bunun boyutunu size / 2 yaparak eski diziyi yeni diziye kopyalar�z.
	// eski diziyi yeni diziye kopyalarken yeni dizinin elemanlar�n�n eski dizinin first + i elemanlar�na e�it olmas�na dikkat ederek ba�taki bo�luklardan kurtulmu� oluruz.
	if ((q->last - q-> first) <= (q->size / 4)) {
		
		int *newArray = (int *) malloc(sizeof(int) * q->size / 2);
		
		for (i = 0; i < (q->last - q->first); i++) {
			newArray[i] = q->array[q->first + i];
		}
		
		// dizi k���lteme i�leminden �nce s�raba��n� 0 s�ra sonunuda s�rasonu - s�raba�� yaparak de�erleri g�ncelliyoruz
		q -> last = q->last - q->first;
		q -> first = 0;
		//eski diziyi haf�zadan freeliyoruz.
		free(q->array);
		q -> size /= 2;
		q->array = newArray;
		
	}
	//ilk �nce first degerini al�r i�leme sonra o de�erdeki eleman� d�nd�r�r sonra ise first de�erini bir art�r�r
	return q->array[q->first++];
}

void enque (int element, queue *q) {
	
	if (q -> array == NULL) {
		//e�er dizi bo� ise yeni bir dizi i�in haf�zada yer a��yoruz
		q -> array = (int *) malloc(sizeof(int) * q->size);
	}
	
	
	if ((q->last - q-> first)  >= q->size) {
		
		int i = 0;
		// e�er dizinin ba�� sonuna e�it veya sonundan b�y�k olursa dizi dolmu� demektir
		// bu durumda eski dizinin iki kat� b�y�kl���nde yeni bir dizi olu�turulur ve eski dizi yeni diziye kopyalan�r.
		
		int *newArray = (int *) malloc(sizeof(int) * q->size * 2);
		// queue deki eleman say�s�n� son s�radan ilk s�ray� ��kartarak bulabiliriz.
		for (i = 0; i < (q->last - q->first); i++) {
			
			newArray[i] = q -> array[i];
		}
		free(q->array);
		q -> size *=2;
		q->array = newArray;
	}	
	
	//�nce last de�erini al i�leme koy s�ra 0 oldu�u icin 0 de�eri konulacak sonrada s�ran�n de�erini 1 art�racak dolay�s�yla s�ra 1 sonraki de�er olucak.
	//yani 0 eleman bo� oldu�u i�in 0 a koyucak koyduktan sonra ise s�ra de�erini bir art�racak.
	q->array[q->last++] = element;
	
}


queue *queueIdentifer() {
	
	//ilk �nce malloc ile haf�zada pointer t�r�nde bir struct olu�turulur sonra bu struct de�erleri atan�p d�nd�r�l�r.
	// queue ye paremetre olarak verilmedi�i halde eri�ebilmemizin sebebi queue nin global bir de�i�ken olmas�.
	queue *q = (queue *) malloc(sizeof(queue));
	q -> first = 0;
	q -> last = 0;
	q -> size = 2;
	q -> array = NULL;
	
	
	return q;
}

void cleanSpaceInQueue (queue *q) {
	
	int i = 0;
	if (q->first == 0) {
		//e�er dizi nin firsti 0 a e�it ise hi� bir �ey yapma void d�nd�r.
		return ;
	}
	
	for (i = 0; i < q->size; i++) {
		
		// deque fonkisyonlar� ile olu�an bo�luklar� kapatmak i�in dizinin �u anki eleman indekslerine dizinin first indeks de�erini ekleyerek bo�luklar� kapat�yoruz.
		// yani k�saca diziyi first kadar ba�a kayd�r�yoruz. 
		q->array[i] = q->array[i + q->first];
	}
	
	q -> last = q->last - q->first;
	q -> first = 0;
}

struct n {
	
	//ba�l� liste i�in bir x datas� ve n pointer� olu�turuyoruz.
	int data;
	struct n *next;
};
//burda diyiyoruzk ki struct i�inde belirledi�imiz veriler bir b�t�n olu�turarak struct� tan�mlad� sonra typedef ile bu struct�n art�k "isminde" bir veri yap�s� olmas�n� istiyoruz int gibi.
// typedef struct n �zelliklerine sahip bir veri yap�s� olu�tur ve buna int gibi global veri yap� isimleri yerine kendi belirledi�imiz node ismini ver ve bundan sonra ne zaman node �a��r�l�rsa struct i�inde veri yap�lar�na uygun yeni nesne tan�mlamalar� olu�tur.
typedef struct n node;

node *rootIdentifer(int data) {
	
	node *root = (node *) malloc(sizeof(node));
	root -> data = data;
	root -> next = NULL;
	
	return root;
}

void printLinkedList(node * root) {
	
	//root un kendisi null olana kadar donguye g�rer�z burda mant�k listen�n null dan yan� bosluktan b�r oncek� elemana kadar g�tmek.
	while (root != NULL) {
		printf("%d\n",root -> data);
		root = root-> next;
	}
}

void addElementInLinkedList(node * root,int element) {
	
	//eleman eklerken hep ayn� yere eklememek i�in root dan ba�lay�p listenin son kutucugunun nexti null g�steridi�i yere kadar gideriz.
	//sonra bu yere elementi yerle�tiririz.
	//sonra bu yer�n nextine haf�zada bir kutuluk yer a�ar�z
	//a�t���m�z kutunun nextini null e�itlerizki program sonsuz d�ng�ye girmesin
	
	while (root -> next != NULL) {
		root = root -> next;
	}
	root -> next = (node *) malloc(sizeof(node));
	root -> next -> data = element;
	root -> next -> next = NULL;
}

void addBoxInLinkedList (node *root , int count, int data) {
	
	int i = 0;
	
	//linked listi while ile geziyoruz son eleman�n nexti null olana kadar
	//bu s�rada araya konulmak istenilen s�ra de�erine geldi�inde bo� bir kutu eleman� olu�turuyoruz
	//o s�radan �nceki eleman�n nexti ge�ici bir de�er ile sakl�yoruz (temp)
	//sonra s�radaki elaman�n nexti bo� kutuya y�nlendiriyoruz
	//sonra bo� kutunun datas�n� dolduruyoruz
	//sonra bo� kutunun nextini saklad���m�z de�erin nextine e�itleyerek listenin sonundaki elamanlar� kaybetmemi� oluyoruz.
	
	while (root != NULL) {
		root = root -> next;
		i+=1;
		if (i == count) {
			node *temp = (node *) malloc(sizeof(node));
			node *newBox = (node *) malloc(sizeof(node));
			temp = root -> next;
			root -> next = newBox;
			newBox -> data = data;
			newBox -> next = temp;
		}
	}
	
}

node *addOrderElementInLinkedList(node * root , int element) {
	
	// bu fonksiyonu kullan�rken l�tfen bir global node (root) de�i�kenine de�er olarak kullan�n�n ��nk� baz� durumlarda root de�i�ebiliyor.
	
	if(root == NULL) {
		//e�er g�nderilen root bo� ise doldur;
		root = rootIdentifer(element);
		return root;
	}
	
	if (root -> data > element) {
		 		
		//e�er linked listte sadece bir eleman var ise ve biz bu elemandan daha k���k bir eleman eklemek istiyorsak listeye root u yani ba�lang�� de�erini de�i�tirmi� olucaz bu y�zden bu i�lemden sonra de�i�mis rootu return ederek d�� d�nyaya haber edicez.
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = element;
		temp -> next = root;
		root = temp;
		return root;
	}
	
	 
	//e�er link listte bir veya birden daha fazla elaman varsa bu elemanlar� gezecek bir iterater olu�tururuz ve bunu root a e�itleriz 
	node * iterater;
	iterater = root;
	//iteratr�n nexti null ve iterat�rn nextinin datas� listeye konulmak istenilen elementden k�c�k olana kadar ilerle.
	while (iterater -> next != NULL && iterater -> next -> data < element) {
		
		iterater = iterater -> next;
	}
	
	/*temp = iterater -> next;
	node *newBox = (node *) malloc(sizeof(node));
	iterater -> next = newBox;
	newBox -> data = element;
	newBox -> next = temp;
	*/ 
	// ge�ici bir temp de�eri olu�turuyoruz bu de�erin nextini iterat�r�n nexti yaparak listenin sonunun kaybolmas�n� engelliyoruz.
	// daha sonra bu ge�ici degere bir data at�yoruz
	// daha sonra ise iterater�n next�n� temp e e�itleyerek listenin ba��n� g�vence alt�na al�yoruz
	node *temp = (node *) malloc(sizeof(node));
	temp -> next = iterater -> next;
	temp -> data = element;
	iterater -> next = temp;
	return root;
}

node *deleteElementInLinkedList (node *root , int element) {
	
	//bu fonkisyonu kullan�rken e�er ba�taki eleman� silme gibi bir durum var ise l�tfen global bir node(root) objes�ne de�er atarak kullan�n
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullan�m ile
	
	node * iterater;
	iterater = root;
	node *temp = (node *) malloc(sizeof(node));
	if (root -> data == element) {
		temp = root;
		root = root -> next;
		free(temp);
		return root;
	}
	
	//iterater�m�z� nexti nulldan farkl� oldugu surece (yan� l�ste b�tmed�g� surece) ve iterater�m�z�n nextinin datas� arad���m�z elemandan farkl� oldugu surece don.
	//arad���m�z elemandan farkl� olmas�n�n sebeb� eger arad�g�m�z elemana es�t olsayd� d�ye kosul koysayd�k iterater eleman� buldugunda kosuldan c�kmay�p sonsuz donguye g�recekt�.
	//linked listte eleman s�lmek �c�n s�lmek �sted�g�m�z elemandan b�r oncek� elemana gelmem�z laz�m bu yuzde �terater datas� deg�lde �terater�n next�n�n datas�na gore kosul koyuyoruz
	while (iterater -> next != NULL && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == NULL) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	//temp ile listenin silecegimiz eleman� tutuyoruzki i�lemlerden sonra ramdan free edelim
	//silecegimiz elemandan �nceki eleman�n nextini silece�imiz elemandan sonraki elemana e�itliyoruz
	temp = iterater -> next;
	iterater -> next = iterater -> next -> next;
	free(temp);
	return root;
}

//burdan sonras� dairesel link list

node *rootCircleIdentifer(int element) {
	node *root = (node *) malloc(sizeof(node));
	root -> data = element;
	root -> next = root;
	return root;
}


void printCircleLinkedList(node * root) {
	
	//Dairesel ba�l� listte gezici eleman�m�z iter tekrardan roota e�it oluncaya kadar listeye koyar�z.
	node * iterater = root -> next;
	printf("%d\n",root -> data);
	while (iterater != root) {
		printf("%d\n",iterater -> data);
		iterater = iterater -> next;
	}
}

void addElementInCircleLinkedList(node * root,int element) {
	
	//eleman eklerken hep ayn� yere eklememek i�in rootun nextinden ba�lay�p listenin son kutucugunun bir daha root u i�aret etti�i yere kadar gideriz.
	//sonra bu yere elementi yerle�tiririz.
	//sonra bu yer�n nextine haf�zada bir kutuluk yer a�ar�z
	//a�t���m�z kutunun nextini roota e�itleriz ki daire k�r�lmas�n
	
	if(root == NULL) {
		//e�er g�nderilen root bo� ise doldur
		//e�er sadece bir eleman var ise bu eleman�n nextini yine kendisene e�itliyoruz.
		root = rootCircleIdentifer(element);
		
	}
	
	node *iterater = root;
	node *temp;
	node *newBox;
	while (iterater -> next != root) {
		iterater = iterater -> next;
	}
	newBox = (node *) malloc(sizeof(node));
	temp = (node *) malloc(sizeof(node));
	temp = iterater -> next; //root
	iterater -> next = newBox;
	newBox -> next = temp;
	newBox -> data = element;
	
}

node *addOrderElementInCircleLinkedList(node * root , int element) {
	
	// bu fonksiyonu kullan�rken l�tfen bir global node (root) de�i�kenine de�er olarak kullan�n�n ��nk� baz� durumlarda root de�i�ebiliyor.
	
	if(root == NULL) {
		//e�er g�nderilen root bo� ise doldur
		//e�er sadece bir eleman var ise bu eleman�n nextini yine kendisene e�itliyoruz.
		root = rootCircleIdentifer(element);
		return root;
	}
	
	if (root -> data > element) {
		 		
		//e�er circle linked listte sadece bir eleman var ise ve biz bu elemandan daha k���k bir eleman eklemek istiyorsak listeye root u yani ba�lang�� de�erini de�i�tirmi� olucaz bu y�zden bu i�lemden sonra de�i�mis rootu return ederek d�� d�nyaya haber edicez.
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = element;
		temp -> next = root;
		node * iterater = root;
		//iterater�m�z�n nexti roota e�it olana kadar dola��yoruz ve e�it oldu�unda iterater�n nexti koyaca��m�z eleman yaparak rootu de�i�tiriyoruz.
		while (iterater -> next != root) {
			iterater = iterater -> next;
		}
		iterater -> next = temp;
		return temp;
	}
	
	 
	//e�er link listte bir veya birden daha fazla elaman varsa bu elemanlar� gezecek bir iterater olu�tururuz ve bunu root a e�itleriz 
	node * iterater;
	iterater = root;
	//iteratr�n nextini root a kadar g�t�r�yoruz ve iterat�rn nextinin datas� listeye konulmak istenilen elementden k�c�k olana kadar ilerliyoruz.
	while (iterater -> next != root && iterater -> next -> data < element) {
		
		iterater = iterater -> next;
	}

	// ge�ici bir temp de�eri olu�turuyoruz bu de�erin nextini iterat�r�n nexti yaparak listenin sonunun kaybolmas�n� engelliyoruz.
	// daha sonra bu ge�ici degere bir data at�yoruz
	// daha sonra ise iterater�n next�n� temp e e�itleyerek listenin ba��n� g�vence alt�na al�yoruz
	node *temp = (node *) malloc(sizeof(node));
	temp -> next = iterater -> next;
	temp -> data = element;
	iterater -> next = temp;
	return root;
}

node *deleteElementInCircleLinkedList (node *root , int element) {
	
	//bu fonkisyonu kullan�rken e�er ba�taki eleman� silme gibi bir durum var ise l�tfen global bir node(root) objes�ne de�er atarak kullan�n
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullan�m ile
	
	node * iterater;
	iterater = root;
	node *temp = (node *) malloc(sizeof(node));
	if (root -> data == element) {
		//ilk eleman� silme durumu
		while (iterater -> next != root){
			iterater = iterater -> next;
		}
		//Iterater�n nexti root olana kadar ilerledik.
		//sonra iterater�n nextini rootun nexti yapt�k
		//sonra haf�zadan rootu free ettik.
		//sonra ise yeni root olan iterater�n nextini d�nderdik ��nk� iterater hala daha root dan bir �nceki eleman� g�steriyor.
		iterater -> next = root -> next;
		free(root);
		return iterater -> next;
	}
	
	//iterater�m�z� nexti roottan farkl� oldugu surece (yan� l�ste b�tmed�g� surece) ve iterater�m�z�n nextinin datas� arad���m�z elemandan farkl� oldugu surece d�n.
	//arad���m�z elemandan farkl� olmas�n�n sebeb� eger arad�g�m�z elemana es�t olsayd� d�ye kosul koysayd�k iterater eleman� buldugunda kosuldan c�kmay�p sonsuz donguye g�recekt�.
	//linked listte eleman s�lmek �c�n s�lmek �sted�g�m�z elemandan b�r oncek� elemana gelmem�z laz�m bu yuzde �terater datas� deg�lde �terater�n next�n�n datas�na gore kosul koyuyoruz
	while (iterater -> next != root && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == root) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	//temp ile listenin silecegimiz eleman� tutuyoruzki i�lemlerden sonra ramdan free edelim
	//silecegimiz elemandan �nceki eleman�n nextini silece�imiz elemandan sonraki elemana e�itliyoruz
	temp = iterater -> next;
	iterater -> next = iterater -> next -> next;
	free(temp);
	return root;
}


struct dn {
	struct dn *prew;
	struct dn *next;
	int data;
}; 

typedef struct dn dnode;

dnode *rootDoublyIdentifer(int data) {
	
	// doubly link list rootu tan�mland�
	dnode *root = (dnode *) malloc(sizeof(dnode));
	root -> data = data;
	root -> next = NULL;
	root -> prew = NULL;
	
	return root;
}

void printDoublyLinkedList(dnode * root) {
	
	//root un kendisi null olana kadar donguye g�rer�z burda mant�k listen�n null dan yan� bosluktan b�r oncek� elemana kadar g�tmek.
	while (root != NULL) {
		printf("%d\n",root -> data);
		root = root-> next;
	}
}

dnode *addOrderElementInDoublyLinkedList(dnode * root , int element) {
	
	//bo� ise yeni bir kutu tan�ml�yoruz
	if(root == NULL) {
		
		root = rootDoublyIdentifer(element);
		return root;
	}
	
	//ba�a ekle
	if (root -> data > element) {
		 		
		dnode *temp = (dnode *) malloc(sizeof(dnode));
		temp -> data = element;
		temp -> next = root;
		root -> prew = temp;
		
		return temp;
	}
	
	//sona ve ortaya ekle
	dnode * iterater;
	iterater = root;
	while (iterater -> next != NULL && iterater -> next -> data < element) {
		
		iterater = iterater -> next;
	}
	
	dnode *temp = (dnode *) malloc(sizeof(dnode));
	temp -> next = iterater -> next;
	iterater -> next = temp;
	temp -> prew = iterater;
	//NULL IN PREWI OLMADIGI ICIN KONTROL SAGLIYORUZ
	if (temp -> next != NULL) {
		temp -> next -> prew = temp;
	}
	temp -> data = element;
	
	return root;
}


dnode *deleteElementInDoublyLinkedList (dnode *root , int element) {
	
	//bu fonkisyonu kullan�rken e�er ba�taki eleman� silme gibi bir durum var ise l�tfen global bir node(root) objes�ne de�er atarak kullan�n
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullan�m ile
	
	dnode * iterater;
	iterater = root;
	dnode *temp = (dnode *) malloc(sizeof(dnode));
	if (root -> data == element) {
		temp = root;
		root = root -> next;
		free(temp);
		return root;
	}
	
	//iterater�m�z� nexti nulldan farkl� oldugu surece (yan� l�ste b�tmed�g� surece) ve iterater�m�z�n nextinin datas� arad���m�z elemandan farkl� oldugu surece don.
	//arad���m�z elemandan farkl� olmas�n�n sebeb� eger arad�g�m�z elemana es�t olsayd� d�ye kosul koysayd�k iterater eleman� buldugunda kosuldan c�kmay�p sonsuz donguye g�recekt�.
	//linked listte eleman s�lmek �c�n s�lmek �sted�g�m�z elemandan b�r oncek� elemana gelmem�z laz�m bu yuzde �terater datas� deg�lde �terater�n next�n�n datas�na gore kosul koyuyoruz
	while (iterater -> next != NULL && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == NULL) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	
	//temp ile listenin silecegimiz eleman� tutuyoruzki i�lemlerden sonra ramdan free edelim
	//silecegimiz elemandan �nceki eleman�n nextini silece�imiz elemandan sonraki elemana e�itliyoruz
	temp = iterater -> next;
	iterater -> next = iterater -> next -> next;
	free(temp);
	//NULL IN PREW I OLMAZ
	if(iterater -> next != NULL) {
		iterater -> next -> prew = iterater;
	}
	
	return root;
}


struct b {
	//binary tree struct yap�s�n�n hang� ozell�kler� olucak o belirleniyor.
	int data;
	struct b *left;
	struct b *right;
};

typedef struct b bts;

bts *btsIdentifer(int data) {
	
	//ba�lang�c olarak bts y� tan�ml�yoruz.
	bts *leaf = (bts *) malloc(sizeof(bts));
	leaf -> data = data;
	leaf -> left = NULL;
	leaf -> right = NULL;
	
	return leaf;
}

bts *addLeafInBts(bts *tree, int data) {
	
	if(tree == NULL) {
		//burada e�er aga� bo� ise kok degeri eklen�yor "56" diyelim.
		tree = btsIdentifer(data);
		return tree;
	}
	
	//bts * iter;
	//iter = tree;
	if (tree -> data < data) {
		
		/*				 56
					   /   \
					 26	   200
					/  \   /  \ 
				  18   28 190  213
				 / \   / 
				12 24 27
		*/
		//a�aca eklemek istedi�imiz de�er 215 ise 
		// ilk �nce de�er 56 dan b�y�k m� diye bak�yor
		//b�y�k oldu�u i�in fonkisyonu rekers�f bir �ekilde d�nderiyorlar ve d�nderirken 56 n�n sa��n� g�nderiyor
		//bundan sonra tree de�erimiz yani k�k de�erimiz 200
		//sonra kontrol ediyor eklemek isted�imiz 215 200 den b�y�km� diye ve b�y�k oldu�u i�in
		// 200 �n sa��n� fonksiyona rekers�f bir bi�imde d�nderiyor ve art�k tree de�erimiz 213
		// daha sonra bir daha bak�yor 215 de�eri 213 den b�y�k m� diye b�y�k oldu�u i�in
		// 213 �n sa��n� ve eklemek istedi�imiz data de�erini birlikte d�nderiyor
		//213 sa�� null oldu�u i�in bundan �nceki if e tak�l�p orda yeni bir leaf olu�turuluyor ve bu leaf in i�ine 215 de�eri ekleniyor
		tree -> right = addLeafInBts(tree ->right, data);
		return tree;
		/*if (iter -> right != NULL) {
			return addLeafInBts(tree -> right , data);
		}
		if (iter -> left != NULL) {
			return addLeafInBts(tree -> left, data);
		}*/
	}
	//burda ise yukardaki i�lemlerin ayn�s�n� yap�yor sadece eklemek istedi�imiz deger k���k ise bu kod parcas� cal�s�yor	
	tree -> left = addLeafInBts(tree -> left, data);
	return tree;
}


void traversal(bts *tree) {
	
	if (tree == NULL) {
		return;
	}
	
			/*			 56
					   /   \
					 26	   200
					/  \   /  \ 
				  18   28 190  213
				 / \   / 
				12 24 27
		   */
	
	//e�er a�ac bo� de�il ise a�ac�n yan� k�k�n soluna gidiyoruz ve 26 y� g�r�p d�nderiyoruz fonksiyona
	//daha sonra 26 n�n soluna bak�yoruz ve 18 i g�r�p 18 i fonksiyona geri d�nderiyoruz
	//daha sonra 18 in soluna bak�yoruz 12 yi g�r�p 12 yi fonksiyona geri d�nderiyoruz
	//daha sonra 12 nin solu bo� oldu�u datas�n� yazd�r�r (anlamad�m buray� sallad�m :)))) 
	traversal(tree -> left);
	printf(" %d \n",tree -> data);
	traversal(tree -> right);
}

int find (bts * tree , int key) {
	
	if (tree == NULL) {
		return -1;
	}
	if (tree -> data == key) {
		return 1;
	}
	if(find(tree -> left,key) == 1) {
		return 1;
	}
	if(find(tree -> right,key) == 1) {
		return 1;
	}
	return -1;
}

int max(bts *tree) {
	//bts de en sagdak� eleman en buyuk eleman oldugu �c�n o elemana kadar bts y� dolas�yoruz
	while (tree -> right != NULL) {
		tree = tree -> right;
	}
	return tree -> data;
	
}

int min(bts *tree) {
	//bts de en soldaki eleman en k���k eleman oldugu �c�n o elemana kadar bts y� dolas�yoruz
	while (tree -> left != NULL) {
		tree = tree -> left;
	}
	return tree -> data;
	
}

//soldakilerin en b�y��� sa�dakilerin en k�����

bts *deleteLeafInBts(bts *tree, int key) {
	if (tree == NULL) {
		return NULL;
	}
	if (tree -> data == key) {
		if (tree -> left == NULL && tree -> right == NULL) {
			//e�er hem solu hem sag� bo� ise bu bir yaprakt�r ve silindi�i yere ba�ka bir eleman atamak zorunda olmad���m�z icin direk null a e�itleriz.
			return NULL;
		}
		if (tree -> right != NULL) {
			//silmek istedi�imiz eleman�n sa�� null de�il ise o eleman�n de�erini o a�actaki en k���k de�er yap�yoruz
			// ve daha sonra tre nin sa��ndaki elemanlardan en k���g�n� silece�imiz tree nin yerine koyuyoruz
			//ve koydugumuz eleman�n alt�ndak�ler� treen�n r�ght�na bagl�yoruz
			tree -> data = min(tree -> right);
			tree -> right = deleteLeafInBts(tree -> right,min(tree -> right));
			return tree;
		} else {
			tree -> data = max(tree -> left);
			tree -> left = deleteLeafInBts(tree -> left,max(tree -> left));
			return tree;
		}
		
	}
	if (tree -> data < key) {
		//silmek istedi�imiz de�er treenin de�erinden b�y�kse fonksiyona treenin sa��n� yolluyoruz.
		tree -> right = deleteLeafInBts(tree -> right,key);
		return tree;
	}
	//silmek istedi�imiz de�er treenin de�erinden k���kse fonksiyona treenin solunu yolluyoruz.
	tree -> left = deleteLeafInBts(tree -> left,key);
	return tree;
}

void selectionSort(int array[], int size) {
	
	//Diziyi ba�tan sona dola�arak en k���k say�y� bulur buldu�u say� ile en ku�uk say�n�n yerini de�i�tirir.
	//ornek olarak 5,4,2,1,3 olan bir dizi ilk etapta 1,4,2,5,3 olur.
	
	
	// ilk �nce 3 � tutar ve dizinin geri kalan�nda 3 �n k�����n� arar bulursa yerlerini de�i�tirir.
	// daha sonra 44 � tutar ba�tan ba�lamak yerine 44 den sonraki elemanlar� tarar ve en k���k eleman� bulunca yer de�i�tirir.
	
	int i,temp,j;
	for (i = 0; i < size; i++) {
		//0.118 big(o) = n^2
		for (j = i+1; j < size; j++) {
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void insertionSort(int array[], int size) {
	
	//tuttu�u say�ya kadar olan say�lar�n s�ral� oldu�unu kabul ederiz.
	// 33|44 21 83 56 73 22
	//taramaya devam ed�nce s�ras�n� bozmayan bir eleman ile kar��la�t���nda duvar� bir birim ileri al�r.
	// 33 44 | 21 83 56 73 22
	//s�ras�n� bozan b�r say� ile kar��la�t���nda onu ondan �nceki elemanlar ile kar��la�t�rarak hareket ettirir.
	// 33 21 44 | 83 56 73 22
	// 21 33 44 | 83 56 73 22
	// 21 22 33 44 56 73 83 | s�ralanm�� halidir.
	
	int i,j,temp;
		
	// {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48}
	for (i = 0; i < size -1; i++) {
		//0.0843 big(0) = n^2
		//s�ray� bozan b�r say� ile kar��la��ld���nda o elemandan s�ran�n ba��na kadar hareket ederek gerekli d�zenlemeler yap�l�r.
		if (array[i] > array[i +1]) {
			for (j = i + 1; j >= 0;  j--) {
				if (array[j] < array[j-1]) {
					temp = array[j];
					array[j] = array[j-1];
					array[j-1] = temp;
				}
			}
		}
		
	}
}

void bubbleSort(int array[], int size) {
	
	//dizinin iki�erli elemanlar�n� de�erlendirip s�raya koyar.
	// 3 44 38 5 47 15  olan diziyi a�a��daki gibi s�ralar
	// 3 38 5 44 15 47 dizinin birinci ada�m� boyle
	// 3 5 38 15 44 47 
	// 3 5 15 38 44 47 bu ad�mlardan sonra diziyi s�ralam�� oluyor.
	
	int i,j,temp;
	bool order;
	
	do{ //0.1217
		order = true;
		for (i = 0; i < size -1; i++){
			if (array[i] > array[i+1]) {
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				order = false;
			}
		}			
	}while (order != true);
	
	/*for (i = 1; i < size; i++) {
		order = true;
		for (j = size -1; j > 0; j--) {
			if (array[j-1] > array[j]) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				order = false;
			} 
		}
		if (order == true) {
			break;
		}
	}*/
	
	/*bool swap = false;
	
	for (i = 0; i < size -1; i++) {
		
		if (array[i] > array[i+1]) {
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			swap = true;
		}else {
			swap = false;
		} 
		
		if (swap == true) {
			i = -1;
		}
		
	}*/	
}

#endif
