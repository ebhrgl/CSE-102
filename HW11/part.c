/*---------------------------------------------------------------------------------------------------*/
/*HW11_131044055_EDA_BAHRIOGLU_part1.c                                                               */
/*Eda Bahrioglu tarafından 15.05.2016 tarihinde yazildi----------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program sadece veri tiplerinin degerlerinin ortalamasinin bilindigi bir binary dosyasindan      */
/*okuma yaparak veri tiplerinin ve sayisinin tahmin edildigi kodlama programidir.                    */                                          
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define DATASIZE 10

/*parametre olarak binary dosyasi ve output array alir*/
/*tahmin edilen structer kodunu döndürür.             */

int hwDecode(const char filename[], int arr_out[]);  

int main(void)
{
	FILE *inp;
	int* arr_out;
	const char filename;

		

		hwDecode(&filename,arr_out);	

		


		return 0;

}

int hwDecode(const char filename[], int arr_out[])
{
	
	FILE *inp;
	int x, sizeOfStruct, remainSize;
	int count=0,i;

	inp = fopen("data.bin","rb");

/*input dosyasinin olmadigi durumlarda return null degerini döndürür.*/

		if(inp==NULL)

		{	
			return -1;
		}

/*binary tipinde bi dosyadan dosya sonuna kadar okuma yapilir.*/
/*count degeri toplam byte sayisini verir.                    */	

		while(fread(&x, sizeof(int),1,inp)!=0)
		{	
			count++;
		}

/*1000 struct icinden sadece birinin yani tahmin edilenin toplam byte sayisini verir.*/

		sizeOfStruct = count/1000; 

/*1 struct icindeki toplam byte degerinden bilinen double tipindeki average */
/*byte inin cikarilmasi sonucu kalan veri tiplerinin byte size ini verir.   */

		remainSize = sizeOfStruct - sizeof(double);

	/* (sizeof(filename)==remainSize)*/


/*output arrayi icin yer ayrilir.*/

	arr_out = (int *)calloc(DATASIZE,sizeof(int));

/*structer average disinda 10 veri alani kadar yer kapladigindan her*/ 
/*10 satir icin 5 tipin size ine esit olup olmadigini kontrol eder. */
/*bos satirlar icin output array ine -1 atar diger durumlarda her   */
/*5 tipi 1 sayi temsil eder.
                                         */
		for(i=0; i<10; i++)
		{
/*dosyadaki i inci elamanin unsigned char olup olmadigini kontrol eder.*/
			if((remainSize - sizeof(filename[i]))==sizeof(unsigned char))
			{
				arr_out[i]=1;			
			}
/*dosyadaki i inci elamanin int olup olmadigini kontrol eder.*/
			if((remainSize - sizeof(filename[i]))==sizeof(int))
			{
				arr_out[i]=2;
			}
/*dosyadaki i inci elamanin long long int olup olmadigini kontrol eder.*/
			if((remainSize - sizeof(filename[i]))==sizeof(long long int))
			{
				arr_out[i]=3;
			}
/*dosyadaki i inci elamanin float olup olmadigini kontrol eder.*/
			if((remainSize - sizeof(filename[i]))==sizeof(float))
			{
				arr_out[i]=4;
			}
/*dosyadaki i inci elamanin double olup olmadigini kontrol eder.*/
			if((remainSize - sizeof(filename[i]))==sizeof(double))
			{
				arr_out[i]=5;
			}

			else
			{
				arr_out[i]=-1;
			}

		}
		
/*dinamik alanin bosaltilmasi.*/
	free(arr_out);

	fclose(inp);

	return 1;	
	
}

/*				END_OF_HW011_Eda_Bahrioğlu_131044055_part1.c         	*/
