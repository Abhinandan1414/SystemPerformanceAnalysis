/* Dr. Abhinandan H. Patil */
/* System speed bench mark */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#define NO_OF_RANDOM_NOS 100000
int randCustom (int seed);
/* Variables for the program */
int randomNumberArray[NO_OF_RANDOM_NOS], iter,
  iter1, dupValue = 0, dupValueBuiltIn = 0;
int
  builtInRandomNumberArray[NO_OF_RANDOM_NOS],
  dupFlag[NO_OF_RANDOM_NOS], dupBuiltInFlag[NO_OF_RANDOM_NOS];
long customStart, customEnd, builtInStart, builtInEnd;
//structCustomStart, structCustomEnd, structBuiltInStart,structBuiltInEnd;
int
main ()
{
  clock_t start, end;
  double cpu_time_used;
  start = clock ();
// srand (time (NULL));
  for (iter = 0; iter < NO_OF_RANDOM_NOS; iter++)
    {
      randomNumberArray[iter] = 0;
      builtInRandomNumberArray[iter] = 0;
      dupFlag[iter] = 0;
      dupBuiltInFlag[iter] = 0;
    }
//customStart = times (&structCustomStart);
    for (iter = 0; iter < NO_OF_RANDOM_NOS; iter++)
    {
      randomNumberArray[iter] = randCustom (NO_OF_RANDOM_NOS * iter + 1);
      printf (": %d \n", randomNumberArray[iter]);
/* randomNumberArray = randCustom (iter); */
    }
//customEnd = times (&structCustomEnd);
//printf ("\n Custom number generation time = %ld",customEnd - customStart);
//builtInStart = times (&structBuiltInStart);
  for (iter = 0; iter < NO_OF_RANDOM_NOS; iter++)
    {
      builtInRandomNumberArray[iter] = rand ();
      printf (": %d \n", builtInRandomNumberArray[iter]);
    }
//builtInEnd = times (&structBuiltInEnd);
//printf ("\n built in number generation time = %ld",builtInEnd - builtInStart);
  for (iter = 0; iter < NO_OF_RANDOM_NOS; iter++)
    {
      for (iter1 = 0; iter1 < NO_OF_RANDOM_NOS; iter1++)
	{
	  if (iter == iter1)
	    continue;
	  if (randomNumberArray[iter] == randomNumberArray[iter1])
	    {
	      dupFlag[iter] = 1;
	    }
	  if (builtInRandomNumberArray[iter]
	      == builtInRandomNumberArray[iter1])
	    {
	      dupBuiltInFlag[iter] = 1;
	    }
	}
    }
  dupValue = 0;
  dupValueBuiltIn = 0;
  for (iter = 0; iter < NO_OF_RANDOM_NOS; iter++)
    {
      if (dupFlag[iter] == 1)
	dupValue++;
      if (dupBuiltInFlag[iter] == 1)
	dupValueBuiltIn++;
    }
  printf ("The number of duplicates in the custom array %d\n", dupValue);
  printf ("The number of duplicates in the built in array %d\n", dupValueBuiltIn);
  end = clock ();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf ("CPU TIME USED %f", cpu_time_used);
  return 0;
}

int
randCustom (int seed)
{
  static long temp = 100001;
  if (seed == 0)
    return 1;
  temp = (temp * 125) % 2796203;
  return ((temp % seed) + 1);
}
