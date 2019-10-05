/*---------------------------------------------------------------------------------------------------*/
/*HW3_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrioglu tarafindan 08.03.2016 tarihinde yazildi.---------------------------------------------*/
/*Tanimlama :                                                                                        */
/*Bu program kullanici tarafindan girilen pozitif bir sayininin faktoriyel,tek sayi veya narcissistic*/
/*sayi olup olmadigini bulur.                                                                        */                                                                         
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

void allFunction(int num);
void oddNumber(int num);
void factorialNumber(int num);
int fonk(int num);
void narcissisticNumber(int num);

int main(void)
{
	int num;
	char ch;

		printf("*****************************************************\n");
		printf("*              WELCOME !                            *\n");
		printf("*    This program checks whether the given number   *\n");
		printf("* is an odd, a factorial or a narcissistic number   *\n");	
		printf("*                                                   *\n");
		printf("*****************************************************\n");
		
		printf("Please enter a positive integer: ");
		scanf("%d",&num);
		
		allFunction(num);

		printf("Do you want to continue (y/n)?");
		scanf(" %c",&ch);
		
	while(ch=='y')
	{
		printf("Please enter a positive integer: "); /*konrol kismidir.y oldugunda dongu devam eder.*/
		scanf("%d",&num);
		
		allFunction(num);
		
		printf("Do you want to continue (y/n)?");
		scanf(" %c",&ch);
	}
		
	if(ch=='n')
	{                                   /*programi sonlandiran komuttur.*/
		printf("Good bye!\n");
	}


	return 0;

}

void allFunction(int num)                /*Bu fonksiyon asil is yapan kısımdır.Degerleri girme komutlari bulunur ve secim yaparak fonksiyonlarin calistirildigi kisimdir.*/
{
	int secim;
	

	if(num>0){
					
		printf("Which property would you like to check?\n");
		printf("1)Odd number \n");                                   /*girilen sayinin pozitif oldugu durumlarda calisir.*/
		printf("2)Factorial number \n");
		printf("3)Narcissistic number \n");

		printf("Please enter(1/2/3):");
		scanf("%d",&secim);
		
			switch(secim){
	
			case 1:
				oddNumber(num);
				break;
		
			case 2:
			 	factorialNumber(num);
				break;
		
			case 3:
				narcissisticNumber(num);
				break;
			
			default:
				printf("ERROR");

						}
			
			}

		else{
			
			printf("The entered number is not positive.\n");  /*Girilen sayinin negatif oldugu durumlarda calisir.*/
				
			}
				
}

void oddNumber(int num)
{

	if((num%2==1))
		{
		printf("%d is an odd number\n",num);
		}                                               /*Girilen pozitif sayının tek sayi olup olmadigini kontrol eder.*/

	else{
		printf("%d is not odd number\n",num);
		}

}

void factorialNumber(int num)
{	                                                   
	int i=1;
	int x=num;                                    /*Girilen pozitif sayinin faktoriyel bir sayi olup olmadigini kontrol eder.*/

	while((x%i)==0)

	{
		x = x/i;
		i++;
		
	}	
	if(x==1)
		printf("%d is a factorial number\n",num);
	else
		printf("%d is not a factorial number\n",num);
		

}


int fonk(int num)
{	
	int basamak=1;                    /*Bu fonksiyon narcissistic sayi hesabi için sayinin kac basamakli oldugunu hesaplar.*/
	
	while(num>=10)
	{

		num=num/10;                                          
		basamak++;

	}

	return basamak;
}


void narcissisticNumber(int num)
{
	int y,sum=0,digit;
	int j=1;
                                        /*Girilen pozitif sayinin narcissistic bir sayi olup olmadigini hesaplar.*/
		y=num;
		digit=fonk(num);

	while(j<y)
	{

		y=(y/j)%10;
		j*=10;
		sum = sum +pow(y,digit);
		y=num;
	
	}
	
	if(sum==y){
		printf("%d is a narcissistic number\n",num);
		}
	else{
		printf("%d is not a narcissistic number\n",num);
		}
	
}
/*				HW03_SON_Eda_Bahrioğlu_131044055_part1.c         	*/
