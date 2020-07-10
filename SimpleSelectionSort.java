// Simple Selection Sort 
// DO NOT USE IT FOR MORE THAN 10,000 instances to sort
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class SimpleSelectionSort
{
  SimpleSelectionSort()
  {
  ;
  }
  public static void main (String[]args)
  {
    int maxSize = 100000; //AHP BUMPED IT UP 
    int[] theArray = new int[maxSize];
    int temp = 0;
    // ref to array theArray
    int nElems = 0;
    // number of data items
    int count = 0;
    long start, end;
    start = System.currentTimeMillis();
    for(count = 0; count< maxSize; count++)
    theArray[count] = maxSize-count;
  
    for(count = 0; count< maxSize; count++)
	    System.out.print(" "+theArray[count]);
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
	    System.out.print(" "+theArray[count]);
    end = System.currentTimeMillis();
    System.out.println("Total time taken for 100000 iteration in milli seconds is \n"+ (end-start));

  }				// end main()
}				// end class 
