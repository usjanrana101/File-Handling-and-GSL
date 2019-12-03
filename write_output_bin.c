#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float* mean_var(float*,int);          //Funtion declaration that take a pointer and a int variable and returns a pointer variable
void main()
{
int n=100,i;  //Declaration of variables to to get the no of elements
float* pntr;
float* re_pntr;
FILE *fp=fopen("mean_var.bin","w");   // creating a file to store the output in .bin file
// Memory allocation of the array of 100 float elements using Malloc
pntr=(float*)malloc(n*sizeof(float));
re_pntr=(float*)malloc(2*sizeof(float));
// When there is insufficient memory
 if(pntr==NULL)
 {
   printf("Memory is not allocated ");
   exit(0); //exit() funtion with 0 as argument terminates the execution of whole program 
 }
 else
 {
 for(i=0;i<n;i++)
   pntr[i]=pow(i+1,2);  // Assignning the value into the array
 }
re_pntr[0]=*mean_var(pntr,n);    // funtion calling
re_pntr[1]=*(1+mean_var(pntr,n));
fprintf(fp,"%s\t%f \n %s\t%f","Mean of the elements of the given array is",re_pntr[0],"variance of the elements of the given array is",re_pntr[1]); // writing data into the file created
printf("Mean of the elements of the given array is %f \n",re_pntr[0]);
printf("Variance of the elements of the given array is %f \n",re_pntr[1]);
// Doing memory allocation free
free(pntr);
}
// definition of the dealared funtion
float* mean_var(float* ptr,int n)  // 'ptr' and'n' are the local variables
{
float* re_ptr;
float sum_lin=0,sum_sqr=0;
int i;
re_ptr=(float*)malloc(2*sizeof(float));
for(i=0;i<n;i++)
 { sum_lin=sum_lin+ptr[i];
  sum_sqr=sum_sqr+pow(ptr[i],2);
  }
re_ptr[0]=sum_lin/n;
re_ptr[1]=sum_sqr/n-pow(sum_lin/n,2); //Formulaue for variance
return (re_ptr);

}

