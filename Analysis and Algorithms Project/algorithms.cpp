#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define SWAP(x, y) { int temp = x; x = y; y = temp; }

void insertionSort(int list_arr[], int a)
{
	
	int b, c, d;
	
	for (b = 1; b < a; b++) {
		
		c = list_arr[b];
		d = b - 1;

		while (d >= 0 && list_arr[d] > c) {
			list_arr[d + 1] = list_arr[d];
			d = d - 1;
		}
		
		list_arr[d + 1] = c;
		
	}
}


void show_array(int list_arr[], int length, int a)
{
	int b;
	for (b = 0; b < length; b++)
		printf("%d ", list_arr[b]);
	printf("\n");
	printf("kth: %d",list_arr[a-1]);
}


void show_Max_Array(int list_arr[], int length, int a)
{
	int b;
	for (b = 0; b < length; b++)
		printf("%d ", list_arr[b]);
	printf("\n");
	printf("kth max: %d",list_arr[length-a]);
}


void merge(int list_arr[], int z, int e, int d)
{
	int a, t, r;
	int u = e - z + 1;
	int y = d - e;
	int A[u], C[y];
	for (a = 0; a < u; a++)
		A[a] = list_arr[z + a];
	for (t = 0; t < y; t++)
		C[t] = list_arr[e + 1 + t];

	a = 0;
	t = 0; 
	r = z;
	
	while (a < u && t < y) {
		if (A[a] <= C[t]) {
			list_arr[r] = A[a];
			a++;
		}
		else {
			list_arr[r] = C[t];
			t++;
		}
		r++;
	}

	while (a < u) {
		list_arr[r] = A[a];
		a++;
		r++;
	}


	while (t < y) {
		list_arr[r] = C[t];
		t++;
		r++;
	}
}


void mergeSort(int list_arr[], int e, int y)
{
	if (e < y) {		
		int q = e + (y - e) / 2;
		mergeSort(list_arr, e, q);
		mergeSort(list_arr, q + 1, y);
		merge(list_arr, e, q, y);
	}
}


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int seperate (int list_arr[], int min, int max)
{
	int pivot = list_arr[max]; 
	int a = (min - 1); 
	int b;
	for (b = min; b <= max - 1; b++)
	{
		if (list_arr[b] < pivot)
		{
			a++; 
			swap(&list_arr[a], &list_arr[b]);
		}
	}
	swap(&list_arr[a + 1], &list_arr[max]);
	return (a + 1);
}



void quickSort(int list_arr[], int min, int max)
{
	if (min < max)
	{
		int pi = seperate(list_arr, min, max);
		quickSort(list_arr, min, pi - 1);
		quickSort(list_arr, pi + 1, max);
	}
}


void selectionSort(int list_arr[], int a) {
	int b;
  for (b = 0; b < a - 1; b++) {
    int e = a;
    for (int i = b + 1; i < a; i++) {

     
      if (list_arr[i] < list_arr[e])
        e = i;
    }
    swap(&list_arr[e], &list_arr[b]);
  }
}


void heap_alg(int list_arr[], int a, int b) {
   
    int max = b;
    int e = 2 * b + 1;
    int c = 2 * b + 2;
  
    if (e < a && list_arr[e] > list_arr[max])
      max = e;
  
    if (c < a && list_arr[c] > list_arr[max])
  		max = c;
  
    
    if (max != b) {
      swap(&list_arr[b], &list_arr[max]);
      heap_alg(list_arr, a, max);
    }
  }


void heapSort(int list_arr[], int length) {
  int a;
    for (a = length / 2 - 1; a >= 0; a--)
      heap_alg(list_arr, length, a);
  
    for (a = length - 1; a >= 0; a--) {
      swap(&list_arr[0], &list_arr[a]);

      heap_alg(list_arr, a, 0);
    }
  }
  

int seperate(int e[], int a, int w, int d)
{
    int pivot = e[d];
 
    SWAP(e[d], e[w]);
 
    d = a;
 	int i;
    for (i = a; i < w; i++)
    {
        if (e[i] <= pivot)
        {
            SWAP(e[i], e[d]);
            d++;
        }
    }
 
    SWAP(e[d], e[w]);
 
    return d;
}
 
 
int quick_select_sort(int list_arr[], int a, int b, int e)
{   
    if (a == b) {
        return list_arr[a];
    }
    int w = a + rand() % (a - a + 1);
    w = seperate(list_arr, a, b, w);
    if (e == w) {
        return list_arr[e];
    }
 
    else if (e < w) {
        return quick_select_sort(list_arr, a, w - 1, e);
    }
    else {
        return quick_select_sort(list_arr, w + 1, b, e);
    }
}

int Seperate(int list_arr[], int e, int d)
{
	int r = list_arr[d], i = e, u = e;
	while (u < d) {
		if (list_arr[u] < r) {
			swap(&list_arr[i], &list_arr[u]);
			i++;
		}
		u++;
	}
	swap(&list_arr[i], &list_arr[d]);
	return i;
}

int seperate_rand(int list_arr[], int a, int e)
{
	int d = e - a + 1;
	int pivot = rand() % d;
	swap(&list_arr[a + pivot], &list_arr[e]);
	return Seperate(list_arr, a, e);
}

void med(int list_arr[], int x, int y, int z, int& a, int& b)
{
	if (x <= y) {
		int id = seperate_rand(list_arr, x, y);
		if (id == z) {
			b = list_arr[id];
			if (a != -1)
				return;
		}

		else if (id == z - 1) {
			a = list_arr[id];
			if (b != -1)
				return;
		}

		if (id >= z)
			return med(list_arr, x, id - 1, z, a, b);

		else
			return med(list_arr, id + 1, y, z, a, b);
	}

	return;
}


void findMedian(int list_arr[], int length)
{
	int search, x = -1, y = -1;

	if (length % 2 == 1) {
		med(list_arr, 0, length - 1, length / 2, x, y);
		search = y;
	}


	else {
		med(list_arr, 0, length - 1, length / 2, x, y);
		search = (x + y) / 2;
	}
	printf("Median : %d",search);
}


int main()
{
	int list_arr[] = { 10, 3, 18, 7, 6, 44, 31, 14, 59, 77, 43, 61, 88, 99, 17, 120, 156, 123,874, 444, 321, 100, 432, 212, 81 };
	int a = sizeof(list_arr) / sizeof(list_arr[0]);
	int y;
	
	printf("Please enter the element that looking for: ");
	scanf("%d",&y);
	printf("insertion sort: ");
	insertionSort(list_arr, a);
	show_array(list_arr, a, y);
	puts("");
	printf("merge sort: ");
	mergeSort(list_arr, 0, a - 1);
	show_array(list_arr, a, y);
	puts("");
	printf("quick sort: ");
	quickSort(list_arr, 0, a - 1);
	show_array(list_arr,a,y);
	puts("");	
	printf("selection sort: ");
	selectionSort(list_arr,a);
	show_array(list_arr,a,y);
	puts("");
	printf("heap sort: ");
	heapSort(list_arr,a);
	show_Max_Array(list_arr,a,y);
	puts("");
	printf("Element that min: %d\n", quick_select_sort(list_arr, 0, a - 1, y - 1));
	findMedian(list_arr, a);
	return 0;
}
