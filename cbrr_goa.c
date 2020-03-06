/*
Linear 			O(n)			Insertion (best case)
Logarithmic 	O(log n)		Binary Insertion (best and medium cases)
n log n 		O(n log n)		Merge
Quadratic 		O(n^2)			Selection
Exponential 	O(2^n)			?
*/

#include <stdio.h>

// function declarations
int selectionSort();
void merge(int i, int j, int a[], int aux[]);
int mergeSort();
int insertionSort();
int binaryInsertion();

int main()
{
    int num = 0;
    printf("Choose your sort algorithm:\n1- Selection Sort (Quadratica) (O(n^2))\n2- Merge Sort ((O)n log n)\n3- Insertion (Linear) (O(n) in best case)\n4- Binary Insertion (Logaritmica) (O(log n) in best and medium cases)\n");
    scanf("%d", &num);
    printf("\n");

    int i, j, a[100], aux[100];
    switch(num){
        case 1:
            selectionSort();
            break;
        case 2:
            mergeSort();
            break;
        case 3:
            insertionSort();
            break;
        case 4:
            binaryInsertion();
            break;
        default:
            printf("Something is wrong, I can feel it!");
    }
    return 0;
} 

//  ### SELECTION SORT ###

int selectionSort()
{
    int array[100], size, c, d, position, t;

    printf("Enter number of elements:\n"); // array size
    scanf("%d", &size);

    printf("\nEnter %d integers\n", size);
    for (c = 0; c < size; c++) // add elements "size" times
        scanf("%d", &array[c]);

    for (c = 0; c < (size - 1); c++) // finding minimum element (size - 1) times
    {
        position = c;

        for (d = c + 1; d < size; d++)
        {
            if (array[position] > array[d])
                position = d;
        }
            if (position != c)
                {
                    t = array[c];
                    array[c] = array[position];
                    array[position] = t;
                }
    }

    printf("Sorted with selection sort:\n");

    for (c = 0; c < size; c++)
        printf("%d ", array[c]);

        printf("\n");
    return 0;
}

//  ### MERGE SORT ###

// function to sort the subsection a[i .. j] of the array a[]
void merge(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
    merge(i, mid, a, aux);     // sort the left sub-array recursively
    merge(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}

int mergeSort() {
    int a[100], aux[100], n, i;
 
    printf("Enter number of elements:\n");
    scanf("%d", &n);
 
    printf("\nEnter %d integers\n", n);
 
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
 
    merge(0, n - 1, a, aux);
 
    printf("\nSorted with merge sort:\n");
 
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}

//  ### INSERTION SORT ###

int insertionSort()
{
    int n, array[100], c, d, t, flag = 0;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("\nEnter %d integers\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    for (c = 1 ; c <= n - 1; c++) {
        t = array[c];

        for (d = c - 1 ; d >= 0; d--) {
            if (array[d] > t) {
                array[d+1] = array[d];
                flag = 1;
            }
            else
                break;
        }
        if (flag)
            array[d+1] = t;
    }

    printf("Sorted with insertion sort:\n");

    for (c = 0; c <= n - 1; c++) {
        printf("%d ", array[c]);
    }
    printf("\n");

  return 0;
}

// ### BINARY INSERTION ###

// A binary search based function to find the position 
// where item should be inserted in a[low..high] 
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low)
        return (item > a[low])?  (low + 1): low; 
    int mid = (low + high)/2;
  
    if(item == a[mid]) 
        return mid+1; 

    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
// Function to sort an array a[] of size 'n' 
void insertionSortForBinary(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        // find location where selected sould be inseretd 
        loc = binarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 
  
// Driver program to test above function 
int binaryInsertion() 
{ 
    int a[100], n, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("\nEnter %d integers\n", n);
 
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSortForBinary(a, n); 
  
    printf("Sorted with binary insertion sort: \n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", a[i]); 

    printf("\n");
  
    return 0; 
} 