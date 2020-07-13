
// Dr. Abhinandan H. Patil. Dont forget to gcc -lm (As in math library) 
// I wanted one workload involving floating point operations
#include <stdio.h>
#include <time.h>
#include <math.h>

#define LOADLOOP 10000 //Does nothing meaningful other than loading CPU with Floating Point Operations

//SYNOPSIS
//#include <math.h>

//double pow(double x, double y);
//
//Funny signature, because 178.9^178.9 we cannot hold the result in double could have used lpow. Leave it.

double customPow( double a, int b)
{
	int i;
	double retResult = 1;
	for(i =0; i<b; i++)
	{
		retResult *= a;
	}
	return retResult;
	
}	
int main()
{
	int loadLoop;
	float dummy;
        clock_t start, end;
        double cpu_time_used;
        start = clock ();                                                /* Lets mark start of CPU calculations */

	double a,b,result,customResult;
	printf("On this Architecture\n");
	printf("Size of float %d\n",sizeof(dummy));
	printf("Size of long is %d\n",sizeof(result));
	printf("Enter two numbers\n");
	scanf("%lf %lf",&a,&b);
	for (loadLoop = 0; loadLoop < LOADLOOP; loadLoop++)
	{	
		result = pow(a,b);
		printf("Result is %lf\n",result);
		customResult = customPow(a,(int)b);       //Down casting b to int
		printf("Custom Result is %lf\n",customResult);
		printf("Loss of Accuracy %lf\n",(result-customResult));
        }
        end = clock ();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf ("CPU TIME USED %f", cpu_time_used);

}
