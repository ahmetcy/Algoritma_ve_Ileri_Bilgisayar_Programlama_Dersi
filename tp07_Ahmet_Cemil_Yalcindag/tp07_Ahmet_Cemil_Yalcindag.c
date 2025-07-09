#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int n) 
{
    int i, j;
    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
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
  for (int i = 0; i < len; i++)
    {
      printf("%d ", array[i]);
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
  for(int i=0; i<len; i++)
  {
    printf("%d ", array[i]);
  }
}

int main()
{
  //1 12 7 15 18 9 20 8 13
  //A  L G  O  R I  T H  M

  int data[9] = {1, 12, 7, 15, 18, 9, 20, 8, 13};
  bubbleSort(data, 9);
  printf("\n");
  selectionSort(data, 9);
  printf("\n");
  insertionSort(data, 9);
    return 0;
}