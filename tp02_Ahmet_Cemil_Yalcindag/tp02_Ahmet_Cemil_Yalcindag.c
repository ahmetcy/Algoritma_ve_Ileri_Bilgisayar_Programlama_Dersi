#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

/* TODO: malloc() ve turevi fonksiyonlar icin gerekli baslik dosyasini ekleyin */
/* TODO: rasgele sayi uretmek icin gerekli baslik dosyalarini ekleyin */

/**** Ex1 ****/
void ex1_square(int *number) {
	/* TODO: Bu fonksiyon aldigi parametreyi gercekten degistirip icine
	 * sayinin karesini yazabiliyor mu? Duzeltmek icin gerekli islemleri
	 * hem bu fonksiyonda hem de ex1_test() fonksiyonunda yapin. */
	*(number) = *(number) * *(number);
	/*number'ı bir pointer'a dönüştürdüm*/
}

void ex1_test(void) {
	int x = 4, xkare = 4;
	ex1_square(&xkare);
	assert(xkare == x * x);
}

/* Ex2 ve Ex3 icin yardimci fonksiyonlar */
void print_array(int *pt,int a/*TODO: Bir tamsayi gostericisi ve o adresteki eleman sayisini gosteren tamsayi */) {
	/* TODO: Aldiginiz adresten, aldiginiz eleman sayisi kadar ileri giden bir dongu
	 * ile dizinin elemanlarini yanyana ekrana yazdirin. Ornek (7 elemanli dizi):
	 * 1 2 32 45 67 13 65
	 */
	for (int i=0; i<a; i++)
	{
		printf("%d ",*(pt+i));
	}
	printf("\n");
}

double mean_array(int *pt, int a/*TODO: Bir tamsayi gostericisi ve o adresteki eleman sayisini gosteren tamsayi */) {
	/* TODO: Aldiginiz adresteki elemanlarin aritmetik ortalamasini hesaplayip dondurun. */
	int toplam=0;
	for (int i=0; i<a; i++)
	{
		toplam+=*(pt+i);
	}
	int ortalama=toplam/a;
	return(ortalama);
}

/**** Ex2 ****/
void ex2(void) {
	printf("\nEX 2\n");
	int *heap_array;
	int array_size = 0;

	/* TODO: Kullaniciya dizi boyutunu sorup scanf() ile array_size'in icerisine okuyun. */
	printf("Dizi boyutunu giriniz: ");
	scanf("%d",&array_size);

	/* TODO: heap_array gostericisine, array_size adet integer icin malloc() ile yer isteyin
	 * malloc()'un donus degerini kontrol edin, hata olustuysa ekrana bir hata mesaji
	 * yazdirin, ve programi sonlandirin.*/
	heap_array=(int*)malloc(array_size*sizeof(int));
	if(heap_array == NULL)
	{
		printf("Alan oluşturulamadi.");
		return;
	}

	/* TODO: malloc() basarili olduysa ayrilan diziyi [0,100] araliginda ureteceginiz
	 *rasgele sayilar ile doldurun.*/
	else
	{
		srand(time(0));
		for (int i=0; i<array_size; i++)
		{
			heap_array[i]=(rand()%101);
		}
	}
	/* TODO: print_array() fonksiyonunu cagirip dizinin elemanlarini ekrana yazdirin. */
	print_array(heap_array,array_size);

	/* TODO: mean_array() fonksiyonunu cagirip dizinin aritmetik ortalamasini hesaplayin,
	 * ekrana yazdirin. */
	printf("%.2lf\n",mean_array(heap_array,array_size));

	/* TODO: malloc() ile ayirdiginiz alani serbest birakin. */
	free(heap_array);

}

/**** Ex3 ****/
void ex3(void) {
	printf("\nEX 3\n");
	int *heap_array;
	int array_size = 0;
	int new_array_size = 0;

	/* TODO: ex2'nin aynisi ama kullanicidan ikinci bir dizi boyutu daha isteyip eski
	 * dizinin boyutunu yenisine gore güncelleyin. Dizi boyutu buyuduyse arta kalan
	 * degiskenlere -1 degerini atayin. */

	printf("Dizi boyutunu giriniz: ");
	scanf("%d",&array_size);

	
	heap_array=(int*)malloc(array_size*sizeof(int));
	if(heap_array == NULL)
	{
		printf("Alan oluşturulamadi.");
		return;
	}

	else
	{
		srand(time(0));
		for (int i=0; i<array_size; i++)
		{
			*(heap_array+i)=(rand()%101);
		}
	}
	
	print_array(heap_array,array_size);

	printf("%.2lf\n",mean_array(heap_array,array_size));

	int new_size;
	
	printf("Yeni boyutu giriniz: ");
	scanf("%d",&new_size);

	heap_array=(int*)realloc(heap_array,new_size*sizeof(int));
	if(heap_array == NULL)
	{
		printf("Alan oluşturulamadi.");
		return;
	}
	else
	{
		if(new_size>array_size)
		{
			for (int i=array_size; i<new_size; i++)
			{
				*(heap_array+i)=-1;
			}
		}
		print_array(heap_array,new_size);
	}
	free(heap_array);
}

/**** Ex4 ****/
void ex4(int n) {
	printf("\nEX 4\n");
	int *heap_array;
	
	heap_array=(int*)malloc(n*sizeof(int));
	if(heap_array == NULL)
	{
		printf("Alan oluşturulamadi.");
		return;
	}

	else
	{
		srand(time(0));
		for (int i=0; i<n; i++)
		{
			heap_array[i]=(rand()%101);
		}
	}
	
	print_array(heap_array,n);

	
	printf("%.2lf\n",mean_array(heap_array,n));

	
	free(heap_array);

}

/******************* main() ********************/

int main(int argc, char *argv[]) {

	/* Ex1 TEST: ex1_test() fonksiyonunun icerisindeki assert() cagrisi
	 * square() fonksiyonu duzgun calismazsa tum programin calismasini durduracak
	 * ve hatali satiri ekrana yazdiracaktir. */
	
	ex1_test();
	

	/* Ex2 TEST */
	ex2();

	/* Ex3 TEST */
	ex3();

	/* Ex4 */
	/* TODO: Komut satirindan alinan argumani ex_4() fonksiyonuna parametre olarak gecirin. */
	if(argc<2)
	{
		printf("\nEX 4 icin eksik arguman girildi.");
	}
	else
	{
		ex4(atoi(argv[1]));
	}
	return 0;
}

