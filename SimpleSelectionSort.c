#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  int main ()
  {
    int maxSize = 1000000; 
    int theArray[maxSize];
    int temp = 0;
    // ref to array theArray
    int nElems = 0;
    // number of data items
    int count = 0;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for(count = 0; count< maxSize; count++)
    theArray[count] = maxSize-count;
  
    for(count = 0; count< maxSize; count++)
	    printf("%d  ",theArray[count]);
    for (int p =0; p < maxSize; p++)
    {
	for (int q = p; q < maxSize; q++)
	{
		if ( theArray[p] > theArray[q])
		{
		    temp = theArray[p];
		    theArray[p] = theArray[q];
		    theArray[q] = temp;
		}
	}

     }
    for(count = 0; count< maxSize; count++)
	    printf("%d  ",theArray[count]);
    end = clock ();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf ("CPU TIME USED %f", cpu_time_used);
    return 0;
    // display items again
  }				// end main()
