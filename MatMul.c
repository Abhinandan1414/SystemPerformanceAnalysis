/* Dr. Abhinandan H. Patil */
/* Why this 10th Standard problem in Git Hub?? */


/* Answer : This assignment was marked with 0 marks in one of the Institute of Eminence */

#include<stdio.h>
int main()
{ 
	int i,j,k,l,m,n,o;
	int first[10][10], second[10][10], result[10][10];
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
			scanf("%d", &first[i][j]);
	printf("Enter the elements of second matrix\n");
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			scanf("%d", &second[j][k]);
	for(int j =0;j<n;j++)
		for(int k =0;k< o; k++)
			result[j][k]=0;	
	for(int i =0; i< l; i++)
	{
		for(int j=0; j<m; j++)
		{
			for (int k= 0; k <o; k++)
			{
                        	result[i][k] += first[i][j]*second[j][k];   /* This is where Assoc Professor got confused. Watch the order in which*/
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
}


