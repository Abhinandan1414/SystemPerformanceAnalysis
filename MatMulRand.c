/* Dr. Abhinandan H. Patil */
/* System Performance Evaluation */

/* Try entering l and m as 100 X 100 */
/* Try entering n and o as 100 X 100 */

/* We are not interested in resultant matrix but we just want to load the CPU */

#include<stdio.h>
#include<time.h>
int main()
{ 
	int i,j,k,l,m,n,o;
	int first[100][100], second[100][100], result[100][100];
	clock_t start, end;
	double cpu_time_used;
	start = clock ();
	printf("Enter the order of first matrix\n");
	scanf("%d %d", &l,&m);
	printf("Enter the order of second matrix\n");
	scanf("%d %d", &n, &o);
	if(m != n)
	{
		printf("Matrices cannot be multiplied\n");
		return -1;
	}
	printf("Enter the elements of first matrix\n");
	for (int i=0; i< l; i++)
		for(int j =0; j < m; j++)
			//scanf("%d", &first[i][j]);
			first[i][j] = rand();
	printf("Enter the elements of second matrix\n");
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			//scanf("%d", &second[j][k]);
			second[j][k] = rand();
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
			printf("%d	",result[i][k]);
		}
		printf("\n");
	}
        end = clock ();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf ("CPU TIME USED %f", cpu_time_used);
}
