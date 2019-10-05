/*---------------------------------------------------------------------------------------------------*/
/*HW1_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*created by Eda Bahrıoglu 23.02.2016----------------------------------------------------------------*/
/* Description                                                                                       */
/*Bu program ogrencilerin tüm notlari ve odevlerinin yüzdeliklerini alarak ortalama not hesabi yapar.*/
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>

int main(void){

	int mw1, mw2, mw3;  /*ogrencilerin vize agirlikleri*/
	int hw1, hw2;       /*ögrencilerin odev agirlikleri*/
	int fw;             /*ogrencilerin final agirligi*/
	
	int mg1, mg2, mg3;  /*ogrencilerin vize notlari*/
	int hg1, hg2;       /*ogrencilerin odev notlari*/
	int fg;             /*ogrencilerin final notları*/
	
	double midterm;
	double homework;
	double final;
	double totalGrade;

	printf("Please enter the 1. midterm weight:");
	scanf("%d",&mw1);
	printf("Please enter the 2. midterm weight:");        /*kullanici tarafindan odev ve not yüzdelikleri girilir*/
	scanf("%d",&mw2);
	printf("Please enter the 3. midterm weight:");
	scanf("%d",&mw3);
	printf("Please enter the 1. homework weight:");
	scanf("%d",&hw1);
	printf("Please enter the 2. homework weight:");
	scanf("%d",&hw2);
	printf("Please enter the final exam weight:");
	scanf("%d",&fw);
	
	
	printf("Please enter the 1. midterm grade:");
	scanf("%d",&mg1);
	printf("Please enter the 2. midterm grade:");
	scanf("%d",&mg2);                                     /*kullanici tarafindan odev ve not degerleri girilir*/
	printf("Please enter the 3. midterm grade:");
	scanf("%d",&mg3);
	printf("Please enter the 1. homework grade:");
	scanf("%d",&hg1);
	printf("Please enter the 2. homework grade:");
	scanf("%d",&hg2);
	printf("Please enter the final exam grade:");
	scanf("%d",&fg);
	

	midterm = (mw1*mg1)/100.0 + (mw2*mg2)/100.0 + (mw3*mg3)/100.0; /* tum vizelerin yuzdeliklerini hesaplama*/
	homework = (hw1*hg1)/100.0 + (hw2*hg2)/100.0;                  /*tum odevlerin yuzdeliklerini hesaplama*/
	final = (fw*fg)/100.0;                                         /*final notlarinin yuzdeligini hesaplama*/
	
	totalGrade = midterm + homework + final;                       /*odev ve sinavların etki oranlarini alarak toplam notu hesaplama*/
	
	printf("Your final grade is: %f\n",totalGrade);
	
	return 0;
	
}	 

/*				END_OF_HW01_Eda_Bahrioğlu_131044055_part1.c         	*/
