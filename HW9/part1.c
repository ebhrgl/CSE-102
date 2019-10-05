/*---------------------------------------------------------------------------------------------------*/
/*HW9_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrioglu 29.04.2016 tarafından yazildi--------------------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program dünya sehirleri hakkinda bilgileri tutar.                                               */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

/*struct tanimlama*/

typedef struct
{
	char name[25];
	int population;
	int areaOfSquare;
	int numberOfSoldiers;
	char neighbor[10][25];

}country_t;


void fonkA(country_t arr[],int i); /*kosul a ise calisir.*/
void fonkB(country_t arr[]);       /*kosul b ise calisir.*/
void fonkC(country_t arr[]);       /*kosul c ise calisir.*/

int main(void)
{
	char letter;
	country_t arr[100];
	int i=0;
	
	printf("Make your choice:\n");
	scanf(" %c",&letter);

/*kosul e iken program sonlanir diger durumlarda calisir.*/

	while(letter!='e')

	{	
		if(letter=='a')
		{
			fonkA(arr,i);
			printf("Make your choice:\n");
			scanf(" %c",&letter);
			++i;
			
		}
			
		if(letter=='b')
		{	
			fonkB(arr);
			printf("Make your choice:\n");
			scanf(" %c",&letter);
		}	

		if(letter=='c')
		{	
			fonkC(arr);
			printf("Make your choice:\n");
			scanf(" %c",&letter);
		}					
	
	}
	
			printf("Good Bye");

	return 0;

}


void fonkA(country_t arr[],int i)
{

	int j,flag;
	flag=1;
		
		
			scanf("%s %d %d %d", arr[i].name,
								&arr[i].population,
								&arr[i].areaOfSquare,						
								&arr[i].numberOfSoldiers);
								
		
		for(j=0; j<10  &&  flag!=0; ++j)
		{
			scanf("%s",arr[i].neighbor[j]);
		
/*komsulari alirken -1 degeri girilirse girilen kosul sonlanır.*/

			if((strcmp(arr[i].neighbor[j],"-1"))==0){
				flag=0;
			}

			else{
				flag=1;
			}
			
		}
			
}

/*girilen ülkelerin komsu olup olmadigini kontrol ederek komsuysa askeri güc karsilastirmasi yapar.*/
/*askeri gücü fazla olani ekrana basar.tek ülke girilmisse karsilastirma yapmadan onu ekrana basar.*/

void fonkB(country_t arr[])

{
	int i,k,j;
	int max;

	for(i=0; i<100; ++i)
	{
		scanf("%s",arr[i].name);
		for(k=0; k<100; ++k)
		{
		
			for(j=0; j<10; ++j)
			{
				if((arr[i].name)==(arr[k].neighbor[j]))
				{
					max=arr[0].numberOfSoldiers;
					
				
					if(arr[i+1].numberOfSoldiers > max)
					{
						max=arr[i+1].numberOfSoldiers;
						
						printf("%s",arr[i+1].name);
					}
				}
			
					
			}	
				
		}

		if((arr[i].name)!=(arr[k].neighbor[j]))
		{
			printf("%s",arr[i].name);
		}
	}


}

/*girilen ülkelerin komsu olup olmadigini kontrol ederek komsuysa ülkenin kapladigi alanlari karsilastirir.*/
/*kapladigi alani fazla olani ekrana basar.tek ülke girilmisse karsilastirma yapmadan onu ekrana basar.*/

void fonkC(country_t arr[])

{
	int i,k,j;
	int max;

	for(i=0; i<100; ++i)
	{
		scanf("%s",arr[i].name);
		for(k=0; k<100; ++k)
		{
		
			for(j=0; j<10; ++j)
			{
				if((arr[i].name)==(arr[k].neighbor[j]))
				{
					max=arr[0].areaOfSquare;
					
					if(arr[i+1].areaOfSquare > max)
					{
						max=arr[i+1].areaOfSquare;
						
						printf("%s",arr[i+1].name);
					}

	
				}
			}

		}
	
		if((arr[i].name)!=(arr[k].neighbor[j]))
		{
			printf("%s",arr[i].name);
		}
	}	
	


}
/*				END_OF_HW09_Eda_Bahrioğlu_131044055_part1.c         	*/
