/* Dr. Abhinandan H. Patil */
/* System Performance Evaluation */

/* Try entering l and m as 1000 X 1000 */
/* Try entering n and o as 1000 X 1000 */

/* What are we doing here?? */
/* We are not interested in resultant matrix but we just want to load the CPU */
/* We are also trying to analyze BigO calculations etc */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{ 
	int i,j,k,l,m,n,o;
	int first[500][500], second[500][500], result[500][500];
	clock_t start, end;
	double cpu_time_used;
	start = clock ();                                                /* Lets mark start of CPU calculations */
	printf("Enter the order of first matrix\n");
	scanf("%d %d", &l,&m);
	printf("Enter the order of second matrix\n");
	scanf("%d %d", &n, &o);                                         /* For the time being enter square matrices*/
	if(m != n)
	{
		printf("Matrices cannot be multiplied\n");
		return -1;
	}
	printf("Enter the elements of first matrix\n");
	for (int i=0; i< l; i++)
		for(int j =0; j < m; j++)
			//scanf("%d", &first[i][j]);
			first[i][j] = rand();                          /* This Block is of order n^2: 500X500 will lead to 250,000 assignments */ 
	                                                               /* and rand() is inexpensive */
				 
	printf("Enter the elements of second matrix\n");
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			//scanf("%d", &second[j][k]);
			second[j][k] = rand();                         /* This Block is of order n^2: 500X500 will lead to 250,000 assignments */ 
	                                                               /* and rand() is inexpensive */
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			result[j][k]=0;                               /* Again order n^2 */	
	for(int i =0; i< l; i++)
	{
		for(int j=0; j<m; j++)
		{
			for (int k= 0; k <o; k++)
			{
                        	result[i][k] += first[i][j]*second[j][k];  /* This is order n^3. Important */ 
				                                            /* I am multiplying */
			}
		}
	}
	printf("The resultant matrix is \n");
	for(int i =0;i<l;i++)
	{
		for(int k =0;k< o; k++)
		{
			printf("%d	",result[i][k]);              /* Order n^2. Printf are expensive as they involve I/O */
		}
		printf("\n");
	}
        end = clock ();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf ("CPU TIME USED %f", cpu_time_used);
}


/* Observations for my hardware configuration, underline configuration  ---------------------------------
 *  For 10X10 and 10X10 matrices Execution time is 0.000928 seconds
 *  For 50X50 and 50X50 matrices Execution time is 0.011533 seconds
 *  For 100X100 and 100X100 matrices Execution time is 0.027701 seconds
 *  For 500X500 and 500X500 matrices Execution time is 0.909846 seconds
 *  Characteristic equation for the whole snippet is an^3+3bn^2+cn^2 
 *  Please note I am approximating all assignments as same even though two involve library call
 *  AND printf is characterized as separate cn^2 
 *  Simple calculations reveal that assignments are of the order nano seconds and printfs are micro seconds
 *  This we the embedded programmers always knew and our coding guidelines prevent I/O until and unless must
 * -------------------------------------------------------------------------------------------------------
 */
