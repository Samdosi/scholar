
#include <stdio.h>
#include <stdlib.h>

// function prototype
int CountBook(long long* arr, long long maxRead, long long NumBooks);
void MergeSort(long long* arr, long long start, long long end);
void MergeArray(long long* arr, long long start, long long mid, long long end);

int main() {
    int testcases, Maxbook=0;
    long long numBooks, MaxRead;
    long long* arr=NULL;
    // getting the number of test cases
    scanf("%d", &testcases);
    while(testcases!=0)
    {
        // reseting max number of book to read to 0
        Maxbook=0;
        scanf("%lld %lld",&numBooks, &MaxRead);
        // allocating memory space enough for all the books
        arr=(long long*)malloc(numBooks*sizeof(long long));
        for(int i=0; i<numBooks; i++)
        {
            //getting the number of pages
            scanf("%lld",&arr[i]);
        
        }
        // sorting the array in ascending order using merge sort
        MergeSort(arr, 0, numBooks-1);
        // calculating the max number of books to read
        Maxbook=CountBook(arr, MaxRead, numBooks);
        printf("%d\n", Maxbook);
        // free the memory
        free(arr);
        testcases --;
    }
    
    return 0;
}
// calculate the max number of books to read and return a int
int CountBook(long long* arr, long long maxRead, long long NumBooks)
{
    long long count=0;
    int count_book=0;
    for(int i=0; i<NumBooks; i++)
    {
        //adding the page numbers and store them into count
        count+=arr[i];
        // break if count is more than maximum number of pages he wants to read
        if(count>maxRead)
            break;
        // otherwise increase the count book
        count_book++;
    }
    // return the maximum numbers of books
    return count_book;
}

void MergeSort(long long* arr, long long start, long long end)
{
  // making sure there are more than one items to sort
  if(start<end)
  {
    long long mid;
    // find the mid value
    mid=(start+end)/2;
    // sort the right side of array
    MergeSort(arr, start, mid);
    // sort the left side of array
    MergeSort(arr,mid+1, end);
    // put everything in one array
    MergeArray(arr, start, mid+1,end);

  }
}

void MergeArray(long long* arr, long long start, long long mid, long long end)
{
  // finding the length of the array
  long long length=end-start+1;
  // allocating enough space for the array
  long long *temp=(long long*)malloc(length*sizeof(long long));
  //index to the sorted arrays
  long long i=start;
  long long j=mid;
  //this is the index number of the temp array
  int index=0;
  // copying the sorted values into temp array
  while((i<mid) || (j<=end))
  {
    // filling up the first half of the array
    if((i<mid && arr[i]<arr[j]) || j>end)
    {
      temp[index]=arr[i];
      i++;
      index++;
    }
    // filling up the second half of the array
    else
    {
      temp[index]=arr[j];
      j++;
      index++;
    }
  }
  //copy everthing into the main array
  for(long long k=start; k<=end; k++)
  {
    arr[k]=temp[k-start];
  }
  // free the memory
  free(temp);
}
