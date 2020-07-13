
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
	int loadLoop, loadLoopInner;
	float dummy;
        clock_t start, end, startCust, endCust;
        double cpu_time_used;

	double a,b,result,customResult;
        double xValues[10] = {7.1,9.1,8.9,10.5,14.5,17.9,18.1,20.4,25.2,30.0};
	double yValues[10] = {2.0,2.5,3.0,3.1,4.2,5.3,6.4,7,8.3,9.0}; 

        /*
	printf("On this Architecture\n");
	printf("Size of float %d\n",sizeof(dummy));
	printf("Size of double is %d\n",sizeof(result));
	*/
	printf("xvalues,yvalues,Result,CPUtime,customPowResult,CPUtimeCust,LossofAccuracy\n");
	for (loadLoop = 0; loadLoop < 10; loadLoop++)
	{
	   for(loadLoopInner = 0; loadLoopInner < 10; loadLoopInner++)
	   {	  
		printf("%f,%f,", xValues[loadLoop],yValues[loadLoopInner]); 
                start = clock ();                                                /* Lets mark start of CPU calculations */
		result = pow(xValues[loadLoop],yValues[loadLoopInner]);
		printf("%lf,",result);
                end = clock ();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf ("%f,", cpu_time_used);


                startCust = clock ();                                                /* Lets mark start of CPU calculations */
		customResult = customPow(xValues[loadLoop],(int)yValues[loadLoop]);
		printf("%lf,",customResult);
                endCust = clock ();
                cpu_time_used = ((double) (endCust - startCust)) / CLOCKS_PER_SEC;
                printf ("%f,", cpu_time_used);
		printf("%f\n",(result-customResult));
	   }
        }

}
