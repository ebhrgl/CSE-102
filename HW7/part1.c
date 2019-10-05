/*---------------------------------------------------------------------------------------------------*/
/*HW7_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrioglu tarafindan 15.04.2016 tarihinde yazildi----------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program recursive olarak polindrom bulma islemini yapar.                                        */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
int isPalindrome(char * str);

int main(void)
{	
	char str[]="ab, cd!ed~cb%a ";

	printf("%d\n",isPalindrome(str));

	return 0;

}

int isPalindrome(char * str)
{
	int i,count,length,j=0;

/*arrayin dolduruldugu kisimdir.a dan z ye tüm harf karakterlerini alir.*/

	for(i=0; str[i]!='\0'; i++)
	{
		
		if(str[i]>='a' && str[i]<='z')

		{ 
			
			str[j]=str[i];
			++j;		
		}


		if(str[i]>='A' && str[i]<='Z')

		{ 
			str[j]=str[i]+32;
			++j;
			
		}

	}
		str[j] = '\0';
/* stringin uzunlugunu hesaplar.*/

	count=0;

	for(i=0; str[i]!='\0'; i++)
	{
		count++;
		length=count;
	}
/*stringteki harfleri recursive kullanarak karsilastirma yapar.*/

    
	if((str[0]!='\0') && (str[length-1]!='\0'))
	{
		if(str[0]!=str[length-1])
		{
			return 0;
		}
		else if(str[0]==str[length-1])
		{
			str[length-1] = '\0';
			
			return isPalindrome(&str[1]);
			
		}
	}
			return 1;
		
}
/*				END_OF_HW07_Eda_Bahrioglu_131044055_part1.c         	*/
