#include <stdio.h>
#define PI 3.14
void getInputs(int* degree, int* n, int* exit);
double degreeCalc(double degree, int n);
int fact(int n);
double sine(int degree, int n);
double cosine(int degree, int n);


int main(void){
	
	int degree ,n,exit;
	

		getInputs(&degree,&n,&exit);	

		return 0;
}
void getInputs(int* degree, int* n, int* exit)
{	
	char chr;
	

		scanf("%d %d",degree, n);
		scanf(" %c",&chr);
			if(chr=='E' || chr=='e')
			{
			*exit=1;
			}
			else{
			*exit=0;	
			}
			if(*exit==1)
				{
			return;}


	
		sine(*degree,*n);
		cosine(*degree,*n);

	return;
}
	

double degreeCalc(double degree, int n)
{

	int i;
	double carpim;

	carpim=1.00 ;
	i=1;
			
	while( i<=n){
				
		carpim= carpim*degree;
		i++;
		
	}
	return carpim;
	
}




int fact(int n)
{
	int i,fact;
	
	fact=1;
	for(i=1; i<=n;  i++){
	fact*=i;
		}
	return fact;
}

double sine(int degree, int n)
{
	int   count;
	double sum1, calculate1 = 0.00;
	double newDeg;
	double a=1.00;
	double b=1.00;
	double c =1.00;
	degree=degree%360;
	newDeg = (degree * PI) / 180; 

	sum1=0.00;
		
	for(count=0; count<=n; count++)
	{
		b = degreeCalc(newDeg,((2*count)+1));
		a = degreeCalc((-1),count);
	 	c = fact((2*count)+1);

		calculate1 = (a*b)/c;
	
		sum1 = sum1 + calculate1;
							
	}
	if(degree>=180 && degree<=360)
	{
			return sum1*(-1);
	}
	if(degree>=90 && degree<=270)
	{
			return sum1*(+1);
	}
		printf("sin(%d) where n is %d = %.4f\n",degree, n, sum1);
	return sum1;
}

double cosine(int degree, int n)
{
	int   count;
	double sum2, calculate2 = 0.00;
	double newDeg;
	double a=1.00;
	double b=1.00;
	double c =1.00;
	degree=degree%360;
	newDeg = (degree * PI) / 180; 

	sum2=0.00;
		
	for(count=0; count<=n; count++)
	{
		b = degreeCalc(newDeg,(2*count));
		a = degreeCalc((-1),count);
	 	c = fact(2*count);

		calculate2 = (a*b)/c;
	
		sum2 = sum2 + calculate2;

		if(degree>=180 && degree<=360)
	{
			return sum2*(+1);
	}
	if(degree>=90 && degree<=270)
	{
			return sum2*(-1);
	}
							
	}
		printf("cos(%d) where n is %d = %.4f ",degree, n, sum2);
	return sum2;	
}



