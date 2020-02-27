// CSC A48 - Winter 2020 - UTSC
// F. Estrada, Feb. 2020

// Our goal here is to learn a little bit about the
// built-in sorting functions that are provided by
// the C standard libraries. In particular, we'll
// have a look at Quick Sort.

#include<stdio.h>
#include<stdlib.h>

double *makeRandomArray(int N)
{
  // This allocates an array of size N
  // and fills it up with random floating
  // point numbers.

 double *arr;
 arr=(double *)calloc(N,sizeof(double));
 if (arr==NULL)
 {
  printf("Sorry! no memory left!\n");
  return NULL;
 }

 for (int i=0; i<N; i++)
 {
   // This is cross-platform, if you're using Linux
   // or Mac, feel free to use drand48() instead.
   *(arr+i)=(1.0*(double)rand()/(double)RAND_MAX);
 }

 return arr;
}

int compare_function(const void *a, const void *b)
{
  // Pay attention to this function. qsort() is meant
  // to work with *any* data type, but it requires us
  // to provide a function to compare two entries in
  // the array being sorted. That function has as
  // input two 'const void *' - What on Earth are
  // these things?
  //
  // a) void * - it's a pointer to 'something'
  //             with no defined type. It has to
  //             be void because qsort doesn't
  //             know the data type of the
  //             data it is sorting! we will
  //             convert it *inside* this function
  //             to the data type we are sorting.
  // b) 'const' - indicates that this function will
  //              NOT change the value of the
  //              data it is being given pointers to.
  //              This is important, it allows us to
  //              be sure that qsort() won't change
  //              the values in our array.
  //
  // The function returns an int, the value is negative
  // if a < b, zero if a==b, and positive if a > b.
  //

  const double *A, *B;

  A=(const double *)a;	// Now we have the right data type!
  B=(const double *)b;

  // Now we will compare the values stored at memory locations
  // given by A and B, which we now know are of type 'double',
  // we will return -1 if the value at A is less than the value at B,
  // 0 if the values are equal, and +1 otherwise.
  if (*(A) < *(B)) return -1;
  if (*(A) > *(B)) return 1;
  return 0;
  // The comparisons above can be written more compactly ;) and the
  // return values do not have to be +/- 1, any negative and positive
  // number will do.

  // The above is a classic prototype for *any* comparison
  // function for qsort(), all you need to do to use qsort()
  // with a different data type, is to write a comparison
  // function which uses that data type instead of 'double'
  // and knows how to compare your data type (e.g. in the case
  // your data type is a CDT, it knows what field(s) to
  // compare and how to compare them)
}

int main()
{
  // Let's create a little array and sort it!

  double *array;
  int N=100;

  array=makeRandomArray(N);
  if (array==NULL)
  {
    printf("Sorry, we could not find memory for this array!\n");
    return 0;
  }

  // Let's print it
  printf("Original array:\n");
  for (int i=0; i<N; i++)
   printf("%f\n",*(array+i));

  // Now let's use qsort() to sort it
  qsort(array,N,sizeof(double),compare_function);
  // The first parameter is a pointer to the first entry in our array
  // The second is the number of elements in the array
  // The third is the size (in bytes) of each element, it corresponds
  //   to the size of the data type of the values in the array
  // The last parameter is the name of the comparison function that
  //   qsort() needs to use to sort the array.

  // And that's how it always is with qsort()!

  // Let's print the sorted array
  printf("Sorted array\n");
  for (int i=0; i<N; i++)
   printf("%f\n",*(array+i));

  // Don't forget to free the memory we requested for the array!
  free(array);

  // Done!
  return 0;
}

