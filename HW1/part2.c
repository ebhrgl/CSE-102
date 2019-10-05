/*---------------------------------------------------------------------------------------------------*/
/*HW1_131044055_EDA_BAHRIOGLU_part2.c                                                                */
/*created by Eda Bahrıoglu 23.02.2016----------------------------------------------------------------*/
/* Description                                                                                       */
/*Bu program ilk adimda bir kisinin yasini toplam gun cinsinden hesaplar.                            */
/*ikinci adimda baska bir gezegende kisinin kac yil kac ay ve kac gün yasadigini hesaplar.           */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#define SAAT 24
#define YIL 365
#define AY 30

int main(void){

	int currentYear, currentMonth, currentDay;   /*kullanicinin girdigi günümüz yil,ay ve gunu*/
	int birthYear, birthMonth, birthDay;         /*kullanıcının girdigi kisinin dogum yili ayi ve gunu*/
	int farkYear, farkMonth, farkDay, livedDay;  
	
	int planetHour, planetDay, planetMonth;   /*baska gezegendeki saat, gun ve ay*/
	int day, month, year;                     
	int x,y;

	printf("Please enter the current date.\n");
	printf("Year:");
	scanf("%d",&currentYear);                   
	printf("Month:");
	scanf("%d", &currentMonth);
	printf("Day:");
	scanf("%d",&currentDay);

	printf("Please enter your birthday.\n");
	printf("Year:");
	scanf("%d",&birthYear);
	printf("Month:");
	scanf("%d",&birthMonth);                   
	printf("Day:");
	scanf("%d",&birthDay);


	farkYear = (currentYear - birthYear);     /*kisinin kac yildir yasadıgini bulma hesabi*/
	farkMonth = (currentMonth - birthMonth);  /*kisinin yasadigi yıla ek olarak kac ay yasadiginin hesabi*/
	farkDay = (currentDay - birthDay);        /*kisinin yasadigi yıl ve aya ek olarak kac gun yasadiginin hesabı*/

	livedDay = (farkYear*YIL) + (farkMonth*AY) + farkDay; /*kisinin dogum tarihinin tamamini gün cinsinden hesaplar.*/
                                                          /* yasadigimiz gezegene gore 1 yil 365 gun 1 ay da 30 gun olarak alindi.Yili gune 365 ile ayi de 30 ile cevirir.*/

	printf("You have lived %d days.\n", livedDay);

	
	printf("Please enter about the time of another planet\n");
	printf("How many hours is a day?");
	scanf("%d", &planetHour);

	printf("How many days is a month?");
	scanf("%d", &planetDay);

	printf("How many months is a year?");
	scanf("%d", &planetMonth);

    /*kisi baska gezegende yasarsa yasadigi toplam yili bulma */     
                                
	
	day = (livedDay*SAAT)/planetHour;                /*yasadigimiz gezegende 1 gün 24 saat olarak kabul edilir.Burada kabul edilen saat dilimine gore gun hesabi*/ 
	month = day/planetDay;                         /*bulunan gunu yeni gezegendeki gun dilimine bolerek ay hesabi*/
	year = month/planetMonth;                      /*bulunan ayi yeni gezegendeki ay dilimine bolerek yil hesabı*/


	
	/*kisi baska gezegende yasarsa yasadigi yila ek olarak kac ay yasadigini hesaplama.*/
	x=(((livedDay*SAAT)/planetHour)/planetDay)%planetMonth;

  
	/*kisi baska gezegende yasarsa yasadigi yila ve aya ek olarak kac gun yasadigini hesaplama.*/
	y=((livedDay*SAAT)/planetHour)%planetDay;

	
	printf("If you lived in a planet where a day is %d hours, a month is %d days and a year is %d months: you  were %d years, %d months and %d days old\n",
planetHour, planetDay, planetMonth, year , x, y);

	return 0;


}

/*				END_OF_HW01_Eda_Bahrioğlu_131044055_part2.c         	*/
