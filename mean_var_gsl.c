#include<gsl/gsl_statistics_float.h> //header file from GSL
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "mean_var.h"
void main()
{
int i;
float mnvar[2]; //declaration of an array
float* pgsl=(float*)malloc(100*sizeof(float)); 
float mean,var;
for(i=0;i<100;i++)
{
pgsl[i]=pow(i+1,2);
}
mnvar[0]=*mean_var(pgsl,100);
mnvar[1]=*(mean_var(pgsl,100)+1);
mean=gsl_stats_float_mean(pgsl,1,100);
var=gsl_stats_float_variance(pgsl,1,100);  // variance and mean from GSL
printf("The mean calculated from user defined funtion:%f \n",mnvar[0]);
printf("The mean from GSL:%f \n",mean);
printf("The variance calculated from user defined funtion:%f \n",mnvar[1]);
printf("The variance from GSL:%f \n",var);
free(pgsl);
}
