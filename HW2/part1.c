/*---------------------------------------------------------------------------------------------------*/
/*HW2_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*created by Eda Bahrioglu 28.02.2016----------------------------------------------------------------*/
/* Description                                                                                       */
/*Bu program fonksiyon kullanarak ogrencilerin tüm notlari ve odevlerinin yüzdeliklerini alarak      */
/*ortalama not hesabi yapar.                                                                         */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>

void calculateLastGrade();

int main(void){

	
	 
	calculateLastGrade();  /*ogrenci icin not hesabi yapar.*/
	

	return 0;
	
}	 
void calculateLastGrade()

{	
	int mw1, hw1, fw, mg1, hg1, fg;    /*kullanicidan alinan not ve etki oranlari degiskenleri*/
	double studentGrade;

	printf("Please enter the 1. midterm weight:");
	scanf("%d",&mw1);                                       
	printf("Please enter the 1. homework weight:");
	scanf("%d",&hw1);
	printf("Please enter the final exam weight:");
	scanf("%d",&fw);	
	printf("Please enter the 1. midterm grade:");
	scanf("%d",&mg1);
	printf("Please enter the 1. homework grade:");
	scanf("%d",&hg1);
	printf("Please enter the final exam grade:");
	scanf("%d",&fg);
	printf("Your final grade is:");

	studentGrade = (mw1*mg1)/100.0 + (hw1*hg1)/100.0 + (fw*fg)/100.0;  /*bir ogrencinin final vize ve odev etkileriyle toplam notunun hesaplanmasi.*/
	
	printf("%f\n",studentGrade);

}


/*				END_OF_HW02_Eda_Bahrioğlu_131044055_part1.c         	*/
