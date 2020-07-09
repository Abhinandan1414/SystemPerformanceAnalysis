/* Dr. Abhinandan H. Patil */
/* System Performance Evaluation */

/* Pre-requisite MatMulRand.c understanding */
/* Demo to show rand() is inexpensive and printfs are expensive */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{ 
	int i,j,k,l,m,n,o;
	int first[500][500], second[500][500], result[500][500];
	clock_t start, end;
	double cpu_time_used;
	printf("Enter the order of first matrix\n");
	scanf("%d %d", &l,&m);
	printf("Enter the order of second matrix\n");
	scanf("%d %d", &n, &o);
	start = clock ();
	if(m != n)
	{
		printf("Matrices cannot be multiplied\n");
		return -1;
	}
	printf("Enter the elements of first matrix\n");
	for (int i=0; i< l; i++)
		for(int j =0; j < m; j++)
			//scanf("%d", &first[i][j]);
			//first[i][j] = rand();
			first[i][j] = 100;                          /* Hard coded */
	printf("Enter the elements of second matrix\n");
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			//scanf("%d", &second[j][k]);
			//second[j][k] = rand();
			second[j][k] = 1414;                       /* Hard coded*/
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			result[j][k]=0;	
	for(int i =0; i< l; i++)
	{
		for(int j=0; j<m; j++)
		{
			for (int k= 0; k <o; k++)
			{
                        	result[i][k] += first[i][j]*second[j][k];   
				                                            /* I am multiplying */
			}
		}
	}
	printf("The resultant matrix is \n");
	for(int i =0;i<l;i++)
	{
		for(int k =0;k< o; k++)
		{
			//printf("%d	",result[i][k]);           
			//Printfs are commented to show that they take micro seconds as opposed to assignments of nano seconds order 
		                                          
		}
		//printf("\n");
	}
        end = clock ();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf ("CPU TIME USED %f", cpu_time_used);
}
