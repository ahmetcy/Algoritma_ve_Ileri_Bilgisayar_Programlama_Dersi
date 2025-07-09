#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DOSYAYI TERMİNALDE GİRMEK GEREKİYOR

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arr_length(int arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

void bubbleSort(int array[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}

void selectionSort(int array[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            int t = array[i];
            array[i] = array[min];
            array[min] = t;
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
}

void insertionSort(int array[], int len)
{
  for(int i=0; i<=len-1; i++)
    {
      int x= array[i];
      int j=i;
      while(j>0 && array[j-1]>array[j])
        {
          int t = array[j];
          array[j]=array[j-1];
          array[j-1]=t;
          j=j-1;
        }
      array[j]=x;
    }
  for(int i=0; i<len; i++)
  {
    printf("%d ", array[i]);
  }
}

void shellSort1(int array[], int len)
{
    int i , j , k , h , v ;
    int cols[] = {488 , 187 , 72 , 27 , 10 , 4 , 1};
    for(k =0;k <7; k++) 
    {
        h = cols[k];
        for (i=h; i<len; i++) 
        {
            v = array[i];
            j=i;
            while (j >= h && array[j-h] > v) 
            {
                array[j]=array[j-h];
                j=j-h ;
            }
            array[j]=v;
        }
    }   
    for(int i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
}

void shellSort2(int array[], int len)
{
    int i , j , k , h , v ;
    int cols[] = {65 , 33 , 17 , 9 , 5 , 3 , 1};
    for(k =0;k <7; k++) 
    {
        h = cols[k];
        for (i=h; i<len; i++) 
        {
            v = array[i];
            j=i;
            while (j >= h && array[j-h] > v) 
            {
                array[j]=array[j-h];
                j=j-h ;
            }
            array[j]=v;
        }
    }
    for(int i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    } 
}


void merge(int left[], int right[], int array[], int nL, int nR)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nL && j < nR)
    {
        if (left[i] < right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];  
    }
    while (i < nL) array[k++] = left[i++];
    while (j < nR) array[k++] = right[j++];
}

void mergeSort(int array[], int len)
{
    if (len < 2) return;
    int middle = len / 2;
    int left[middle];
    int right[len - middle];

    for (int i = 0; i < middle; i++) left[i] = array[i];
    for (int i = middle; i < len; i++) right[i - middle] = array[i];
    
    mergeSort(left, middle);
    mergeSort(right, len - middle);
    merge(left, right, array, middle, len - middle);
}

int partition1 (int array[], int start, int end)
{
    int i;
    int p;
    int firsthigh;
    p = end;
    firsthigh = start;
    for(i = start; i<end; i++)
    {
        if(array[i] < array[p])
        {
            swap(&array[i], &array[firsthigh]);
            firsthigh++;
        }
    }
    swap(&array[p], &array[firsthigh]);
    return(firsthigh);
}

void quickSort1(int array[], int start, int end)
{
    int p;
    if ((end-start)>0)
    {
        p = partition1(array, start, end);
        quickSort1(array, start, p-1);
        quickSort1(array, p+1, end);
    }
}

int partition2 (int array[], int start, int end)
{
    int i;
    int p;
    int firsthigh;
    p = start + rand() % (end-start);
    firsthigh = start;
    swap(&array[p], &array[end]);
    for(i = start; i<end; i++)
    {
        if(array[i] < array[end])
        {
            swap(&array[i], &array[firsthigh]);
            firsthigh++;
        }
    }
    swap(&array[end], &array[firsthigh]);
    return(firsthigh);
}

void quickSort2(int array[], int start, int end)
{
    int p;
    if ((end-start)>0)
    {
        p = partition2(array, start, end);
        quickSort2(array, start, p-1);
        quickSort2(array, p+1, end);
    }
}




int main(int argc, char** argv) {

    //DOSYAYI TERMİNALDE GİRMEK GEREKİYOR

    srand(time(NULL));

    clock_t start_t, end_t;
    double bubble_t, selection_t, insertion_t, shell1_t, shell2_t, merge_t, quick1_t, quick2_t;

    if(argc < 2) {
        printf("Duzenlenecek dosyayi girmediniz!");
    } else {
        FILE *data = fopen(argv[1], "r");
        FILE *bubbleout = fopen("bubblesort.txt", "w");
        FILE *selectionout = fopen("selectionsort.txt", "w");
        FILE *insertionout = fopen("insertionsort.txt", "w");
        FILE *shellout1 = fopen("shellsort1.txt", "w");
        FILE *shellout2 = fopen("shellsort2.txt", "w");
        FILE *mergeout = fopen("mergesort.txt", "w");
        FILE *quickout1 = fopen("quicksort1.txt", "w");
        FILE *quickout2 = fopen("quicksort2.txt", "w");

        int bubblebank[1000];
        int selectionbank[1000];
        int insertionbank[1000];
        int shellbank1[1000];
        int shellbank2[1000];
        int mergebank[1000];
        int quickbank1[1000];
        int quickbank2[1000];

        if(bubbleout && selectionout && insertionout && shellout1 && shellout2 && mergeout && quickout1 && quickout2) {
            int i = 0;
            while (fscanf(data, "%d", &bubblebank[i]) == 1 && i < 1000) i++;
            printf("Bubble Sort sonucu:\n");
            start_t=clock();
            bubbleSort(bubblebank, i);
            end_t=clock();
            bubble_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(bubbleout, "%d\n", bubblebank[j]);


            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &selectionbank[i]) == 1 && i < 1000) i++;
            printf("\n\n Selection Sort sonucu:\n");
            start_t = clock();
            selectionSort(selectionbank, i);
            end_t=clock();
            selection_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(selectionout, "%d\n", selectionbank[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &insertionbank[i]) == 1 && i < 1000) i++;
            printf("\n\n Insertion Sort sonucu:\n");
            start_t=clock();
            insertionSort(insertionbank, i);
            end_t=clock();
            insertion_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(insertionout, "%d\n", insertionbank[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &shellbank1[i]) == 1 && i < 1000) i++;
            printf("\n\n Shell Sort sonucu (4.0816 x 8.5714^(k/2.2449)):\n");
            start_t=clock();
            shellSort1(shellbank1, i);
            end_t=clock();
            shell1_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(shellout1, "%d\n", shellbank1[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &shellbank2[i]) == 1 && i < 1000) i++;
            printf("\n\n Shell Sort sonucu (2^k+1):\n");
            start_t=clock();
            shellSort2(shellbank2, i);
            end_t=clock();
            shell2_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(shellout2, "%d\n", shellbank2[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &mergebank[i]) == 1 && i < 1000) i++;
            printf("\n\n Merge Sort sonucu:\n");
            start_t=clock();
            mergeSort(mergebank,1000);
            for(int j=0; j<i; j++)
            {
                printf("%d ", mergebank[j]);
            }
            end_t=clock();
            merge_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(mergeout, "%d\n", mergebank[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &quickbank1[i]) == 1 && i < 1000) i++;
            printf("\n\n Quick Sort sonucu:\n");
            start_t=clock();
            quickSort1(quickbank1,0,999);
            for(int j=0; j<i; j++)
            {
                printf("%d ", quickbank1[j]);
            }
            end_t=clock();
            quick1_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(quickout1, "%d\n", quickbank1[j]);

            i = 0;
            fseek(data, 0, SEEK_SET);
            while (fscanf(data, "%d", &quickbank2[i]) == 1 && i < 1000) i++;
            printf("\n\n Quick Sort (Random) sonucu:\n");
            start_t=clock();
            quickSort2(quickbank2,0,999);
            for(int j=0; j<i; j++)
            {
                printf("%d ", quickbank2[j]);
            }
            end_t=clock();
            quick2_t= (double)(end_t-start_t)/CLOCKS_PER_SEC;
            for (int j = 0; j < i; j++) fprintf(quickout2, "%d\n", quickbank2[j]);


            printf("Algoritma              Calisma Suresi\n");
            printf("Bubble sort               %lf\n", bubble_t);
            printf("Selection sort            %lf\n", selection_t);
            printf("Insertion Sort            %lf\n", insertion_t);
            printf("Shell sort (h1)           %lf\n", shell1_t);
            printf("Shell sort (h2)           %lf\n", shell2_t);
            printf("Merge sort                %lf\n", merge_t);
            printf("Quick sort (Standart)     %lf\n", quick1_t);
            printf("Quick sort (Random)       %lf\n", quick2_t);

        } else {
            printf("Data icin yer acilamadi!");
            fclose(bubbleout);
            fclose(selectionout);
            fclose(insertionout);
            fclose(shellout1);
            fclose(shellout2);
            fclose(mergeout);
            fclose(quickout1);
            fclose(quickout2);
            fclose(data);
            return 1;
        }
        fclose(bubbleout);
        fclose(selectionout);
        fclose(insertionout);
        fclose(shellout1);
        fclose(shellout2);
        fclose(mergeout);
        fclose(quickout1);
        fclose(quickout2);
        fclose(data);
        return 0;
    }
}
