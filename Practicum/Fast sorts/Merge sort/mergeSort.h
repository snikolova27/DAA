#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED


void merge(int arr[], int p, int q, int r)    // left and right are already sorted
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];

  for (size_t i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (size_t j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

// Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

// Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
    if( l < r)
    {
       int middle = l + (r-l)/2;
       mergeSort(arr, l, middle);
       mergeSort(arr, middle + 1,r);
       merge(arr, l, middle, r);
    }
}

#endif // MERGESORT_H_INCLUDED
