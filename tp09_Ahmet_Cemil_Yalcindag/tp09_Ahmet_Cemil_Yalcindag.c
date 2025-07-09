#include <stdio.h>
#include <assert.h>

/* macro pour l'operation de swap */
static int _temp;
#define SWAP(a,b) do { \
  _temp = a; \
  a = b; \
  b = _temp; \
} while (0)

/* la taille de heap */
static int SIZE = 10;

/* affiche les elements de heap
 * array: heap,
 * size: nombre des elements de heap */
void print_heap(int *arr, int size);

/* pseudocode est sur les slides
 * array: heap,
 * index: l'indice de l'element qui
 * viole la propriete de heap,
 * size: nombre des elements de heap */
void max_heapify(int *arr, int index, int size);


/* pseudocode est sur les slides
 * array: heap,
 * size: nombre des elements de heap */
void build_max_heap(int *arr, int size);

/* pseudocode est sur les slides
 * array: heap,
 * size: nombre des elements de heap */
int extractMax(int *arr, int size);

/* pseudocode est sur les slides
 * array: heap,
 * key: valeur de l'element a inserer */
void max_heap_insert(int *arr, int key);

/* pseudocode est sur les slides
 * array: heap,
 * index: indice de l'element
 * key: valeur de l'element a inserer */
void heap_increase_key(int *arr, int index, int key);

/* pseudocode est sur les slides
 * array: heap,
 * size: nombre des elements de heap */
void heapsort(int *arr, int size);

int main() {

	int arr1[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	int arr2[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int heap[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
	int sorted[] = { 1, 2, 3, 4, 7, 8, 9, 10, 14, 16, 19 };

	/* appeler max_heapify pour l'element de
	 * arr1 qui viole la propriete de heap */
	printf("\n>> appel a max_heapify pour arr1\n");
	// TODO
	max_heapify(arr1,1,SIZE);

	// afficher le contenu de heap
	printf("heap: ");
	// TODO
	print_heap(arr1, SIZE);

	int i;
	// test pour max_heapify
	for (i = 0; i < SIZE; i++)
		assert(arr1[i] == heap[i]);
	printf("\n>> max_heapify checked...\n\n");

	// appeler build_max_heap pour arr2
	printf(">> appel a build_max_heap pour arr2\n");
	// TODO
	build_max_heap(arr2,SIZE);

	// afficher le contenu de heap
	printf("heap: ");
	// TODO
	print_heap(arr2, SIZE);

	// test pour build_max_heap
	for (i = 0; i < SIZE; i++)
		assert(arr2[i] == heap[i]);
	printf("\n>> build_max_heap checked...\n\n");

	// inserer 23 a heap
	// TODO
	printf(">> insertion : 23\nheap: ");
	max_heap_insert(heap, 23);
	

	// afficher le contenu de heap
	// TODO
	printf("\n\n");
	print_heap(heap,SIZE);

	// inserer 19 a heap
	// TODO
	printf(">> insertion : 19\nheap: ");
	max_heap_insert(heap,19);
	

	// afficher le contenu de heap
	// TODO
	printf("\n\n");
	print_heap(heap,SIZE);

	// supprimer l'element max de heap
	int max=extractMax(heap,SIZE);;
	// TODO
	printf(">> extracted max = %d\nheap: ", max);
	
	

	// afficher le contenu de heap
	// TODO
	printf("\n");
	print_heap(heap,SIZE);


	// trier les elements par heapsort
	int size_initial = SIZE;
	// TODO
	heapsort(heap,SIZE);

	// afficher le heap trie
	printf("\n>> sorted: ");
	// TODO
	print_heap(heap,SIZE);
	printf("\n");

	// test pour heapsort
	for (i = 0; i < size_initial; i++)
		assert(heap[i] == sorted[i]);
	printf(">> heapsort checked...\n");

	return 0;
}

void print_heap(int *arr, int size) {
	for (int i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
}

void max_heapify(int *arr, int index, int size) {
	int l=2*index+1;
	int r=2*index+2;
	int largest;
	if (l < size && arr[l] > arr[index])
	{
		largest = l;
	}
	else largest = index;
	if (r < size && arr[r] > arr[largest])
	{
		largest = r;
	}
	if (largest != index)
	{
		SWAP(arr[index], arr[largest]);
		max_heapify(arr, largest, size);
	}
}

void build_max_heap(int *arr, int size) {
	for (int i=size/2; i>=0; i--)
	{
		max_heapify(arr, i, size);
	}
}

int extractMax(int *arr, int size) {
	int max = arr[0];
	arr[0] = arr[--SIZE];
	max_heapify(arr,0,11);
	return max;
}

void max_heap_insert(int *arr, int key) {
	arr[SIZE]= -9999999;
	heap_increase_key(arr, SIZE++, key);
}

void heap_increase_key(int *arr, int index, int key) {
	if (key < arr[index])
	{
		printf("New key must be larger than current key");
		return;
	}
	arr[index] = key;
	while (index > 0 && arr[(index-1)/2] < arr[index])
	{
		SWAP(arr[index], arr[(index-1)/2]);
		index = (index-1)/2;
	}
}

void heapsort(int *arr, int size) {
	build_max_heap(arr, size);
	for (int i = size-1; i>0; i--)
	{
		SWAP(arr[0], arr[i]);
		size--;
		max_heapify(arr, 0, size);
	}
}
