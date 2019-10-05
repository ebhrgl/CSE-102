/*---------------------------------------------------------------------------------------------------*/
/*HW6_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrıoglu tarafindan yazildi.09.04.2016--------------------------------------------------------*/
/* Tanımlama                                                                                         */
/*Bu program string icinde girilen harf rakam ve karakterlerin bulunma sikligini hesaplar            */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void freq(char* str, int* fr);

int main (void)
{
	char str[100];
	int fr[37]={0};
	freq("abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |", fr);
	return 0;
}

void freq(char* str, int* fr)
{
	int i,x;
	char y;
/*girilen harflerin bulunma sikligini hesaplar.*/		
		for(i=0; str[i]!='\0'; i++)
		{
			

			if(str[i]>='A' && str[i]<='Z'){
				
				if(str[i]!=str[i]+32){   /*buyuk harf kucuk harfe cevrilir.*/
					fr[str[i]-'A']++;	
				}
				
			}
		
			
			if(str[i]>='a' && str[i]<='z'){
				
				if(str[i]!=str[i]-32){   /*kucuk harf buyuk harfe cevrilir.*/
					fr[str[i]-'a']++;	
				}
				
			}
			
		}

		for(i=0; i<26; i++)
		{
			
			if(fr[i]!=0)                /*ilk 26 deger olarak harf alıir.*/
			{
				
				y=i+'A';
				x=fr[i];
				printf("%c=>%d\n",y,x);
			}
		}

/*rakamlarin sikliğinin bulundugu kisimdir*/

		for(i=0; str[i]!='\0'; i++)
		{
			if(str[i]>='0' && str[i]<='9')
				{	
					fr[str[i]-'0']++;
					
					
				
				}

		}
		for(i=0; i<10; i++)
		{
				y=i+(int)'0';
				x=fr[i];
				printf("%c %d\n",y,x-1);				

		}
		
		
}
/*				END_OF_HW06_Eda_Bahrioğlu_131044055_part1.c         	*/
