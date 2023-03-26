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
	//ilk giren eleman son çýkar ilkesi stack ilkesidir.
	//stack yapýsý için birden fazla deðiþkeni bir arada tutabilmek için sturctlar ile ve typedef ile stack veri yapýsý oluþturulur.
} stack;


int pop (stack *s) {
	
	//stackde eger fýrlatýlacak eleman kalmaz ise -1 deðerini döndürürüz.
	if (s -> peak <= 0 || s -> array == NULL){
		printf("Stack Is NULL\n");
		return -1;
	}
	
	int i = 0;
	if (s -> peak <= s -> size / 4 && s -> size > 2) {
		
		//stack den eleman çýkardýðýmýz için eðer stackýn toplam size'ý peakin 4 katý veya daha yüksek se size yarýya indiririz.
		//yeni bir dynamic dizi oluþtururuz ve bu dizinin boyutunu eskisin yarýsý yaparýz.
		int *newArray = (int *) malloc(sizeof(int) * (s->size / 2));
		
		//eski diziyi yeni diziye kopyalamadan önce elemanlarý for dongusuyle elemanlarý kopyalarýz.
		for (i = 0; i < s -> peak; i++) {
			newArray[i] = s -> array[i];
		}
		//free()->geliþmiþ dillerdeki garbage collecter görevi görür ramda hiç bir iþe yaramayan eski deðerleri siler.
		free(s -> array);
		s -> array = newArray;
		s -> size /=2;
	}
	
	//stackten eleman çýkardýðýmýzda en üsten eleman çýkardýðýmýz için top deðerini bir azaltýrýz.
	return s -> array[--s -> peak];
}

void push (int element, stack *s) {
	
	//eger stac içindeki array null ise hafýzada yeni bir array için malloc ile yer açarýz.
	if (s -> peak <= 0 || s -> array == NULL) {
		s -> array = (int *) malloc(sizeof(int) * 2);
	}
	
	int i = 0;
	if (s -> peak >= (s -> size) - 1) {
		
		// push iþlemi sýrasýnda eðer size deðeri dolursa, size deðiþtirmek için eski dizinin iki katý boyuta sahip yeni bir dizi tanýmlayýp eski diziyi yeni diziye kopyalamamýz gerekir.
		//size ý deðiþtirmek için ise ilk baþta veriler 'size' deðiþkenini 2 katýna çýkarmamýz yeterli olur.
		//bu iki katýna çýkarma iþlemini newArray[size * 2] þeklinde yapamayaçaðýmýz için yani dizi yapýsý dynamic memory'e sahip olmadýðý için pointerlarý kullanýrýz.
		int *newArray = (int *) malloc(sizeof(int) * s->size * 2);
		
		//eski diziyi yeni diziye kopyalamadan önce elemanlarý for dongusuyle elemanlarý kopyalarýz.
		for (i = 0; i < s -> size; i++){
			newArray[i] = s-> array[i];
		}
		//free()->geliþmiþ dillerdeki garbage collecter görevi görür ramda hiç bir iþe yaramayan eski deðerleri siler.
		free(s -> array);
		s -> array = newArray;
		s -> size *=2;
	}
	
	//stack a eleman ekledýgýmýzde en uste eklendýgý ýcýn top u bir artýrýrýz.
	s -> array[s -> peak++] = element;
	
}

int stackInTop (stack *s) {
	//stackdeki en tepedeki deðeri bulmak için peak i 1 azaltýrýz.
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
	//queue = türkçe karþýlýðý sýradýr. ilk giren ilk çýkar ve son giren son çýkar ilkesine göre çalýþýr. iki fonksiyondan oluþur enque() -> eleman ekler deque()-> eleman çýkartýr.
	//queue için gerekli global deðiþkenlerin bir arada tutulabilinmesi için global bir struct tanýmlayýp bu structýn örneðinide typedef ile oluþturuyoruz.
	int first;
	int last;
	int size;
	int *array;
}queue;

int deque (queue *q) {
	
	int i = 0;
	if (q -> first == q -> last) {
		//queue nin sýrabaþý ile sýrasonu birbirine eþit ise queue boþtur
		printf("Queue Is Null\n");
		return -1;
	}
	// queue deki eleman sayýsýný son sýradan ilk sýrayý çýkartarak bulabiliriz.
	// eðer queue nun eleman sayýsý size 1/4 ünden küçükse yeni bir dizi oluþturup bunun boyutunu size / 2 yaparak eski diziyi yeni diziye kopyalarýz.
	// eski diziyi yeni diziye kopyalarken yeni dizinin elemanlarýnýn eski dizinin first + i elemanlarýna eþit olmasýna dikkat ederek baþtaki boþluklardan kurtulmuþ oluruz.
	if ((q->last - q-> first) <= (q->size / 4)) {
		
		int *newArray = (int *) malloc(sizeof(int) * q->size / 2);
		
		for (i = 0; i < (q->last - q->first); i++) {
			newArray[i] = q->array[q->first + i];
		}
		
		// dizi küçülteme iþleminden önce sýrabaþýný 0 sýra sonunuda sýrasonu - sýrabaþý yaparak deðerleri güncelliyoruz
		q -> last = q->last - q->first;
		q -> first = 0;
		//eski diziyi hafýzadan freeliyoruz.
		free(q->array);
		q -> size /= 2;
		q->array = newArray;
		
	}
	//ilk önce first degerini alýr iþleme sonra o deðerdeki elemaný döndürür sonra ise first deðerini bir artýrýr
	return q->array[q->first++];
}

void enque (int element, queue *q) {
	
	if (q -> array == NULL) {
		//eðer dizi boþ ise yeni bir dizi için hafýzada yer açýyoruz
		q -> array = (int *) malloc(sizeof(int) * q->size);
	}
	
	
	if ((q->last - q-> first)  >= q->size) {
		
		int i = 0;
		// eðer dizinin baþý sonuna eþit veya sonundan büyük olursa dizi dolmuþ demektir
		// bu durumda eski dizinin iki katý büyüklüðünde yeni bir dizi oluþturulur ve eski dizi yeni diziye kopyalanýr.
		
		int *newArray = (int *) malloc(sizeof(int) * q->size * 2);
		// queue deki eleman sayýsýný son sýradan ilk sýrayý çýkartarak bulabiliriz.
		for (i = 0; i < (q->last - q->first); i++) {
			
			newArray[i] = q -> array[i];
		}
		free(q->array);
		q -> size *=2;
		q->array = newArray;
	}	
	
	//önce last deðerini al iþleme koy sýra 0 olduðu icin 0 deðeri konulacak sonrada sýranýn deðerini 1 artýracak dolayýsýyla sýra 1 sonraki deðer olucak.
	//yani 0 eleman boþ olduðu için 0 a koyucak koyduktan sonra ise sýra deðerini bir artýracak.
	q->array[q->last++] = element;
	
}


queue *queueIdentifer() {
	
	//ilk önce malloc ile hafýzada pointer türünde bir struct oluþturulur sonra bu struct deðerleri atanýp döndürülür.
	// queue ye paremetre olarak verilmediði halde eriþebilmemizin sebebi queue nin global bir deðiþken olmasý.
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
		//eðer dizi nin firsti 0 a eþit ise hiç bir þey yapma void döndür.
		return ;
	}
	
	for (i = 0; i < q->size; i++) {
		
		// deque fonkisyonlarý ile oluþan boþluklarý kapatmak için dizinin þu anki eleman indekslerine dizinin first indeks deðerini ekleyerek boþluklarý kapatýyoruz.
		// yani kýsaca diziyi first kadar baþa kaydýrýyoruz. 
		q->array[i] = q->array[i + q->first];
	}
	
	q -> last = q->last - q->first;
	q -> first = 0;
}

struct n {
	
	//baðlý liste için bir x datasý ve n pointerý oluþturuyoruz.
	int data;
	struct n *next;
};
//burda diyiyoruzk ki struct içinde belirlediðimiz veriler bir bütün oluþturarak structý tanýmladý sonra typedef ile bu structýn artýk "isminde" bir veri yapýsý olmasýný istiyoruz int gibi.
// typedef struct n özelliklerine sahip bir veri yapýsý oluþtur ve buna int gibi global veri yapý isimleri yerine kendi belirlediðimiz node ismini ver ve bundan sonra ne zaman node çaðýrýlýrsa struct içinde veri yapýlarýna uygun yeni nesne tanýmlamalarý oluþtur.
typedef struct n node;

node *rootIdentifer(int data) {
	
	node *root = (node *) malloc(sizeof(node));
	root -> data = data;
	root -> next = NULL;
	
	return root;
}

void printLinkedList(node * root) {
	
	//root un kendisi null olana kadar donguye gýrerýz burda mantýk listenýn null dan yaný bosluktan býr onceký elemana kadar gýtmek.
	while (root != NULL) {
		printf("%d\n",root -> data);
		root = root-> next;
	}
}

void addElementInLinkedList(node * root,int element) {
	
	//eleman eklerken hep ayný yere eklememek için root dan baþlayýp listenin son kutucugunun nexti null gösteridiði yere kadar gideriz.
	//sonra bu yere elementi yerleþtiririz.
	//sonra bu yerýn nextine hafýzada bir kutuluk yer açarýz
	//açtýðýmýz kutunun nextini null eþitlerizki program sonsuz döngüye girmesin
	
	while (root -> next != NULL) {
		root = root -> next;
	}
	root -> next = (node *) malloc(sizeof(node));
	root -> next -> data = element;
	root -> next -> next = NULL;
}

void addBoxInLinkedList (node *root , int count, int data) {
	
	int i = 0;
	
	//linked listi while ile geziyoruz son elemanýn nexti null olana kadar
	//bu sýrada araya konulmak istenilen sýra deðerine geldiðinde boþ bir kutu elemaný oluþturuyoruz
	//o sýradan önceki elemanýn nexti geçici bir deðer ile saklýyoruz (temp)
	//sonra sýradaki elamanýn nexti boþ kutuya yönlendiriyoruz
	//sonra boþ kutunun datasýný dolduruyoruz
	//sonra boþ kutunun nextini sakladýðýmýz deðerin nextine eþitleyerek listenin sonundaki elamanlarý kaybetmemiþ oluyoruz.
	
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
	
	// bu fonksiyonu kullanýrken lütfen bir global node (root) deðiþkenine deðer olarak kullanýnýn çünkü bazý durumlarda root deðiþebiliyor.
	
	if(root == NULL) {
		//eðer gönderilen root boþ ise doldur;
		root = rootIdentifer(element);
		return root;
	}
	
	if (root -> data > element) {
		 		
		//eðer linked listte sadece bir eleman var ise ve biz bu elemandan daha küçük bir eleman eklemek istiyorsak listeye root u yani baþlangýç deðerini deðiþtirmiþ olucaz bu yüzden bu iþlemden sonra deðiþmis rootu return ederek dýþ dünyaya haber edicez.
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = element;
		temp -> next = root;
		root = temp;
		return root;
	}
	
	 
	//eðer link listte bir veya birden daha fazla elaman varsa bu elemanlarý gezecek bir iterater oluþtururuz ve bunu root a eþitleriz 
	node * iterater;
	iterater = root;
	//iteratrýn nexti null ve iteratýrn nextinin datasý listeye konulmak istenilen elementden kücük olana kadar ilerle.
	while (iterater -> next != NULL && iterater -> next -> data < element) {
		
		iterater = iterater -> next;
	}
	
	/*temp = iterater -> next;
	node *newBox = (node *) malloc(sizeof(node));
	iterater -> next = newBox;
	newBox -> data = element;
	newBox -> next = temp;
	*/ 
	// geçici bir temp deðeri oluþturuyoruz bu deðerin nextini iteratýrýn nexti yaparak listenin sonunun kaybolmasýný engelliyoruz.
	// daha sonra bu geçici degere bir data atýyoruz
	// daha sonra ise iteraterýn nextýný temp e eþitleyerek listenin baþýný güvence altýna alýyoruz
	node *temp = (node *) malloc(sizeof(node));
	temp -> next = iterater -> next;
	temp -> data = element;
	iterater -> next = temp;
	return root;
}

node *deleteElementInLinkedList (node *root , int element) {
	
	//bu fonkisyonu kullanýrken eðer baþtaki elemaný silme gibi bir durum var ise lütfen global bir node(root) objesýne deðer atarak kullanýn
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullaným ile
	
	node * iterater;
	iterater = root;
	node *temp = (node *) malloc(sizeof(node));
	if (root -> data == element) {
		temp = root;
		root = root -> next;
		free(temp);
		return root;
	}
	
	//iteraterýmýzý nexti nulldan farklý oldugu surece (yaný lýste býtmedýgý surece) ve iteraterýmýzýn nextinin datasý aradýðýmýz elemandan farklý oldugu surece don.
	//aradýðýmýz elemandan farklý olmasýnýn sebebý eger aradýgýmýz elemana esýt olsaydý dýye kosul koysaydýk iterater elemaný buldugunda kosuldan cýkmayýp sonsuz donguye gýrecektý.
	//linked listte eleman sýlmek ýcýn sýlmek ýstedýgýmýz elemandan býr onceký elemana gelmemýz lazým bu yuzde ýterater datasý degýlde ýteraterýn nextýnýn datasýna gore kosul koyuyoruz
	while (iterater -> next != NULL && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == NULL) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	//temp ile listenin silecegimiz elemaný tutuyoruzki iþlemlerden sonra ramdan free edelim
	//silecegimiz elemandan önceki elemanýn nextini sileceðimiz elemandan sonraki elemana eþitliyoruz
	temp = iterater -> next;
	iterater -> next = iterater -> next -> next;
	free(temp);
	return root;
}

//burdan sonrasý dairesel link list

node *rootCircleIdentifer(int element) {
	node *root = (node *) malloc(sizeof(node));
	root -> data = element;
	root -> next = root;
	return root;
}


void printCircleLinkedList(node * root) {
	
	//Dairesel baðlý listte gezici elemanýmýz iter tekrardan roota eþit oluncaya kadar listeye koyarýz.
	node * iterater = root -> next;
	printf("%d\n",root -> data);
	while (iterater != root) {
		printf("%d\n",iterater -> data);
		iterater = iterater -> next;
	}
}

void addElementInCircleLinkedList(node * root,int element) {
	
	//eleman eklerken hep ayný yere eklememek için rootun nextinden baþlayýp listenin son kutucugunun bir daha root u iþaret ettiði yere kadar gideriz.
	//sonra bu yere elementi yerleþtiririz.
	//sonra bu yerýn nextine hafýzada bir kutuluk yer açarýz
	//açtýðýmýz kutunun nextini roota eþitleriz ki daire kýrýlmasýn
	
	if(root == NULL) {
		//eðer gönderilen root boþ ise doldur
		//eðer sadece bir eleman var ise bu elemanýn nextini yine kendisene eþitliyoruz.
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
	
	// bu fonksiyonu kullanýrken lütfen bir global node (root) deðiþkenine deðer olarak kullanýnýn çünkü bazý durumlarda root deðiþebiliyor.
	
	if(root == NULL) {
		//eðer gönderilen root boþ ise doldur
		//eðer sadece bir eleman var ise bu elemanýn nextini yine kendisene eþitliyoruz.
		root = rootCircleIdentifer(element);
		return root;
	}
	
	if (root -> data > element) {
		 		
		//eðer circle linked listte sadece bir eleman var ise ve biz bu elemandan daha küçük bir eleman eklemek istiyorsak listeye root u yani baþlangýç deðerini deðiþtirmiþ olucaz bu yüzden bu iþlemden sonra deðiþmis rootu return ederek dýþ dünyaya haber edicez.
		node *temp = (node *) malloc(sizeof(node));
		temp -> data = element;
		temp -> next = root;
		node * iterater = root;
		//iteraterýmýzýn nexti roota eþit olana kadar dolaþýyoruz ve eþit olduðunda iteraterýn nexti koyacaðýmýz eleman yaparak rootu deðiþtiriyoruz.
		while (iterater -> next != root) {
			iterater = iterater -> next;
		}
		iterater -> next = temp;
		return temp;
	}
	
	 
	//eðer link listte bir veya birden daha fazla elaman varsa bu elemanlarý gezecek bir iterater oluþtururuz ve bunu root a eþitleriz 
	node * iterater;
	iterater = root;
	//iteratrýn nextini root a kadar götürüyoruz ve iteratýrn nextinin datasý listeye konulmak istenilen elementden kücük olana kadar ilerliyoruz.
	while (iterater -> next != root && iterater -> next -> data < element) {
		
		iterater = iterater -> next;
	}

	// geçici bir temp deðeri oluþturuyoruz bu deðerin nextini iteratýrýn nexti yaparak listenin sonunun kaybolmasýný engelliyoruz.
	// daha sonra bu geçici degere bir data atýyoruz
	// daha sonra ise iteraterýn nextýný temp e eþitleyerek listenin baþýný güvence altýna alýyoruz
	node *temp = (node *) malloc(sizeof(node));
	temp -> next = iterater -> next;
	temp -> data = element;
	iterater -> next = temp;
	return root;
}

node *deleteElementInCircleLinkedList (node *root , int element) {
	
	//bu fonkisyonu kullanýrken eðer baþtaki elemaný silme gibi bir durum var ise lütfen global bir node(root) objesýne deðer atarak kullanýn
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullaným ile
	
	node * iterater;
	iterater = root;
	node *temp = (node *) malloc(sizeof(node));
	if (root -> data == element) {
		//ilk elemaný silme durumu
		while (iterater -> next != root){
			iterater = iterater -> next;
		}
		//Iteraterýn nexti root olana kadar ilerledik.
		//sonra iteraterýn nextini rootun nexti yaptýk
		//sonra hafýzadan rootu free ettik.
		//sonra ise yeni root olan iteraterýn nextini dönderdik çünkü iterater hala daha root dan bir önceki elemaný gösteriyor.
		iterater -> next = root -> next;
		free(root);
		return iterater -> next;
	}
	
	//iteraterýmýzý nexti roottan farklý oldugu surece (yaný lýste býtmedýgý surece) ve iteraterýmýzýn nextinin datasý aradýðýmýz elemandan farklý oldugu surece dön.
	//aradýðýmýz elemandan farklý olmasýnýn sebebý eger aradýgýmýz elemana esýt olsaydý dýye kosul koysaydýk iterater elemaný buldugunda kosuldan cýkmayýp sonsuz donguye gýrecektý.
	//linked listte eleman sýlmek ýcýn sýlmek ýstedýgýmýz elemandan býr onceký elemana gelmemýz lazým bu yuzde ýterater datasý degýlde ýteraterýn nextýnýn datasýna gore kosul koyuyoruz
	while (iterater -> next != root && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == root) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	//temp ile listenin silecegimiz elemaný tutuyoruzki iþlemlerden sonra ramdan free edelim
	//silecegimiz elemandan önceki elemanýn nextini sileceðimiz elemandan sonraki elemana eþitliyoruz
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
	
	// doubly link list rootu tanýmlandý
	dnode *root = (dnode *) malloc(sizeof(dnode));
	root -> data = data;
	root -> next = NULL;
	root -> prew = NULL;
	
	return root;
}

void printDoublyLinkedList(dnode * root) {
	
	//root un kendisi null olana kadar donguye gýrerýz burda mantýk listenýn null dan yaný bosluktan býr onceký elemana kadar gýtmek.
	while (root != NULL) {
		printf("%d\n",root -> data);
		root = root-> next;
	}
}

dnode *addOrderElementInDoublyLinkedList(dnode * root , int element) {
	
	//boþ ise yeni bir kutu tanýmlýyoruz
	if(root == NULL) {
		
		root = rootDoublyIdentifer(element);
		return root;
	}
	
	//baþa ekle
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
	
	//bu fonkisyonu kullanýrken eðer baþtaki elemaný silme gibi bir durum var ise lütfen global bir node(root) objesýne deðer atarak kullanýn
	//node *root = delete(ElementInLinkedList(root,first) gibi bir kullaným ile
	
	dnode * iterater;
	iterater = root;
	dnode *temp = (dnode *) malloc(sizeof(dnode));
	if (root -> data == element) {
		temp = root;
		root = root -> next;
		free(temp);
		return root;
	}
	
	//iteraterýmýzý nexti nulldan farklý oldugu surece (yaný lýste býtmedýgý surece) ve iteraterýmýzýn nextinin datasý aradýðýmýz elemandan farklý oldugu surece don.
	//aradýðýmýz elemandan farklý olmasýnýn sebebý eger aradýgýmýz elemana esýt olsaydý dýye kosul koysaydýk iterater elemaný buldugunda kosuldan cýkmayýp sonsuz donguye gýrecektý.
	//linked listte eleman sýlmek ýcýn sýlmek ýstedýgýmýz elemandan býr onceký elemana gelmemýz lazým bu yuzde ýterater datasý degýlde ýteraterýn nextýnýn datasýna gore kosul koyuyoruz
	while (iterater -> next != NULL && iterater -> next -> data != element) {
		iterater = iterater -> next;
	}
	if (iterater -> next == NULL) {
		printf("silmek istediginiz eleman linkedlist'te bulunamadi!\n");
		return root;
	}
	
	//temp ile listenin silecegimiz elemaný tutuyoruzki iþlemlerden sonra ramdan free edelim
	//silecegimiz elemandan önceki elemanýn nextini sileceðimiz elemandan sonraki elemana eþitliyoruz
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
	//binary tree struct yapýsýnýn hangý ozellýklerý olucak o belirleniyor.
	int data;
	struct b *left;
	struct b *right;
};

typedef struct b bts;

bts *btsIdentifer(int data) {
	
	//baþlangýc olarak bts yý tanýmlýyoruz.
	bts *leaf = (bts *) malloc(sizeof(bts));
	leaf -> data = data;
	leaf -> left = NULL;
	leaf -> right = NULL;
	
	return leaf;
}

bts *addLeafInBts(bts *tree, int data) {
	
	if(tree == NULL) {
		//burada eðer agaç boþ ise kok degeri eklenýyor "56" diyelim.
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
		//aðaca eklemek istediðimiz deðer 215 ise 
		// ilk önce deðer 56 dan büyük mü diye bakýyor
		//büyük olduðu için fonkisyonu rekersüf bir þekilde dönderiyorlar ve dönderirken 56 nýn saðýný gönderiyor
		//bundan sonra tree deðerimiz yani kök deðerimiz 200
		//sonra kontrol ediyor eklemek istedðimiz 215 200 den büyükmü diye ve büyük olduðu için
		// 200 ün saðýný fonksiyona rekersüf bir biçimde dönderiyor ve artýk tree deðerimiz 213
		// daha sonra bir daha bakýyor 215 deðeri 213 den büyük mü diye büyük olduðu için
		// 213 ün saðýný ve eklemek istediðimiz data deðerini birlikte dönderiyor
		//213 saðý null olduðu için bundan önceki if e takýlýp orda yeni bir leaf oluþturuluyor ve bu leaf in içine 215 deðeri ekleniyor
		tree -> right = addLeafInBts(tree ->right, data);
		return tree;
		/*if (iter -> right != NULL) {
			return addLeafInBts(tree -> right , data);
		}
		if (iter -> left != NULL) {
			return addLeafInBts(tree -> left, data);
		}*/
	}
	//burda ise yukardaki iþlemlerin aynýsýný yapýyor sadece eklemek istediðimiz deger küçük ise bu kod parcasý calýsýyor	
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
	
	//eðer aðac boþ deðil ise aðacýn yaný kökün soluna gidiyoruz ve 26 yý görüp dönderiyoruz fonksiyona
	//daha sonra 26 nýn soluna bakýyoruz ve 18 i görüp 18 i fonksiyona geri dönderiyoruz
	//daha sonra 18 in soluna bakýyoruz 12 yi görüp 12 yi fonksiyona geri dönderiyoruz
	//daha sonra 12 nin solu boþ olduðu datasýný yazdýrýr (anlamadým burayý salladým :)))) 
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
	//bts de en sagdaký eleman en buyuk eleman oldugu ýcýn o elemana kadar bts yý dolasýyoruz
	while (tree -> right != NULL) {
		tree = tree -> right;
	}
	return tree -> data;
	
}

int min(bts *tree) {
	//bts de en soldaki eleman en küçük eleman oldugu ýcýn o elemana kadar bts yý dolasýyoruz
	while (tree -> left != NULL) {
		tree = tree -> left;
	}
	return tree -> data;
	
}

//soldakilerin en büyüðü saðdakilerin en küçüðü

bts *deleteLeafInBts(bts *tree, int key) {
	if (tree == NULL) {
		return NULL;
	}
	if (tree -> data == key) {
		if (tree -> left == NULL && tree -> right == NULL) {
			//eðer hem solu hem sagý boþ ise bu bir yapraktýr ve silindiði yere baþka bir eleman atamak zorunda olmadýðýmýz icin direk null a eþitleriz.
			return NULL;
		}
		if (tree -> right != NULL) {
			//silmek istediðimiz elemanýn saðý null deðil ise o elemanýn deðerini o aðactaki en küçük deðer yapýyoruz
			// ve daha sonra tre nin saðýndaki elemanlardan en küçügünü sileceðimiz tree nin yerine koyuyoruz
			//ve koydugumuz elemanýn altýndakýlerý treenýn rýghtýna baglýyoruz
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
		//silmek istediðimiz deðer treenin deðerinden büyükse fonksiyona treenin saðýný yolluyoruz.
		tree -> right = deleteLeafInBts(tree -> right,key);
		return tree;
	}
	//silmek istediðimiz deðer treenin deðerinden küçükse fonksiyona treenin solunu yolluyoruz.
	tree -> left = deleteLeafInBts(tree -> left,key);
	return tree;
}

void selectionSort(int array[], int size) {
	
	//Diziyi baþtan sona dolaþarak en küçük sayýyý bulur bulduðu sayý ile en kuçuk sayýnýn yerini deðiþtirir.
	//ornek olarak 5,4,2,1,3 olan bir dizi ilk etapta 1,4,2,5,3 olur.
	
	
	// ilk önce 3 ü tutar ve dizinin geri kalanýnda 3 ün küçüðünü arar bulursa yerlerini deðiþtirir.
	// daha sonra 44 ü tutar baþtan baþlamak yerine 44 den sonraki elemanlarý tarar ve en küçük elemaný bulunca yer deðiþtirir.
	
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
	
	//tuttuðu sayýya kadar olan sayýlarýn sýralý olduðunu kabul ederiz.
	// 33|44 21 83 56 73 22
	//taramaya devam edýnce sýrasýný bozmayan bir eleman ile karþýlaþtýðýnda duvarý bir birim ileri alýr.
	// 33 44 | 21 83 56 73 22
	//sýrasýný bozan býr sayý ile karþýlaþtýðýnda onu ondan önceki elemanlar ile karþýlaþtýrarak hareket ettirir.
	// 33 21 44 | 83 56 73 22
	// 21 33 44 | 83 56 73 22
	// 21 22 33 44 56 73 83 | sýralanmýþ halidir.
	
	int i,j,temp;
		
	// {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48}
	for (i = 0; i < size -1; i++) {
		//0.0843 big(0) = n^2
		//sýrayý bozan býr sayý ile karþýlaþýldýðýnda o elemandan sýranýn baþýna kadar hareket ederek gerekli düzenlemeler yapýlýr.
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
	
	//dizinin ikiþerli elemanlarýný deðerlendirip sýraya koyar.
	// 3 44 38 5 47 15  olan diziyi aþaðýdaki gibi sýralar
	// 3 38 5 44 15 47 dizinin birinci adaýmý boyle
	// 3 5 38 15 44 47 
	// 3 5 15 38 44 47 bu adýmlardan sonra diziyi sýralamýþ oluyor.
	
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
