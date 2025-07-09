#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int len)
{
  for (int i = 0; i < len - 2; i++)
    {
      int min = i;
      for (int j = i + 1; j < len - 1; j++)
        {
          if (array[j] < array[min])
          {
            min = j;
          }
        }
      if(min != i)
      {
        int t = array[i];
        array[i] = array[min];
        array[min] = t;
      }
    }
}

void insertionSort(int array[], int len)
{
  for(int i=0; i<len-1; i++)
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

void arrayReset(int buffer[], int array[],int len)
{
    for(int i=0; i<len; i++)
    {
        array[i]=buffer[i];
    }
}

int main()
{
    int array1k[1000];
    int array10k[10000];

    int barray1k[1000];
    int barray10k[10000];

    for (int i=0; i<1000; i++)
    {
        barray1k[i] = rand()%1000;
    }

    for (int i=0; i<10000; i++)
    {
        barray10k[i] = rand()%10000;
    }

    arrayReset(barray1k, array1k, 1000);
    arrayReset(barray10k, array10k, 10000);

    double tot_merge1k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        mergeSort(array1k,1000);
        end=clock();
        tot_merge1k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray1k,array1k,1000);
    }
    double ort_merge1k=tot_merge1k/5;
    
    double tot_merge10k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        mergeSort(array10k,10000);
        end=clock();
        tot_merge10k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray10k,array10k,10000);
    }
    double ort_merge10k=tot_merge10k/5;

    double tot_selection1k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        selectionSort(array1k,1000);
        end=clock();
        tot_selection1k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray1k,array1k,1000);
    }
    double ort_selection1k=tot_selection1k/5;

    double tot_selection10k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        selectionSort(array10k,10000);
        end=clock();
        tot_selection10k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray10k,array10k,10000);
    }
    double ort_selection10k=tot_selection10k/5;

    double tot_insertion1k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        insertionSort(array1k,1000);
        end=clock();
        tot_insertion1k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray1k,array1k,1000);
    }
    double ort_insertion1k=tot_insertion1k/5;

    double tot_insertion10k=0;
    for (int i=0; i<5; i++)
    {
        double start, end;
        start=clock();
        insertionSort(array10k,10000);
        end=clock();
        tot_insertion10k+=(end-start)/CLOCKS_PER_SEC;
        arrayReset(barray10k,array10k,10000);
    }
    double ort_insertion10k=tot_insertion10k/5;

    printf("1K int icin ortalama Merge Sort suresi: %lf \n", ort_merge1k);
    printf("10K int icin ortalama Merge Sort suresi: %lf \n", ort_merge10k);
    printf("1K int icin ortalama Selection Sort suresi: %lf \n", ort_selection1k);
    printf("10K int icin ortalama Selection Sort suresi: %lf \n", ort_selection10k);
    printf("1K int icin ortalama Insertion Sort suresi: %lf \n", ort_insertion1k);
    printf("10K int icin ortalama Insertion Sort suresi: %lf \n", ort_insertion10k);

    return 0;
}