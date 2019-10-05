/*---------------------------------------------------------------------------------------------------*/
/*HW2_131044055_EDA_BAHRIOGLU_part2.c                                                                */
/*created by Eda Bahrıoglu 28.02.2016----------------------------------------------------------------*/
/* Description                                                                                       */
/*Bu program dikdortgen,kare ve çember gibi geometrik sekillerin alan ve cevrelerini fonksiyonlar    */
/* araciligiyla hesaplar.                                                                            */
/*                                                                                                   */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#define PI 3.14

int areaOfRectangle(int width, int height);
int perimeterOfRectangle(int width, int height);
int areaOfSquare(int edgeLength);
int perimeterOfSquare(int edgeLength);
double areaOfCircle(int radius);
double perimeterOfCircle(int radius);

int main(void){

	int w,h,r;                  /*kullanicidan alinan degerler*/
	int aR, pR, aS, pS;
	double aC, pC; /*alan ve cevre hesabi yapan fonksiyonlari tanimlar.*/

	printf("Please enter the width of the rectangle:");
	scanf("%d",&w);
	printf("Please enter the height of the rectangle:");
	scanf("%d",&h);

	printf("The area of the rectangle is:");
	aR = areaOfRectangle(w, h);
	printf("%d\n",aR);

	printf("The perimeter of the rectangle is:");           /*islem sonuclarini fonksiyon cagirilarak ekrana basar.*/
	pR = perimeterOfRectangle(w, h);
	printf("%d\n",pR);

	printf("Please enter the width of the square:");
	scanf("%d",&w);
	printf("The area of the square is:");
	aS = areaOfSquare(w);
	printf("%d\n",aS);

	printf("The perimeter of the square is:");
    pS = perimeterOfSquare(w);
	printf("%d\n",pS);

	printf("Please enter the radius of the circle:");
	scanf("%d",&r);
	printf("The area of the circle is:");
	aC = areaOfCircle(r);
	printf("%.2f\n",aC);

	printf("The perimeter of the circle is:");
    pC = perimeterOfCircle(r);
	printf("%.2f\n",pC);

	return 0;
}

int areaOfRectangle(int width, int height)

{
	double areaR;
	
	areaR = width*height;                        /*bu fonksiyon dikdortgen alanini hesaplar. */

	return areaR;

}


int perimeterOfRectangle(int width, int height)

{
	double perimeterR;
	
	perimeterR = 2*(width+height);              /*bu fonksiyon dikdortgen cevresini hesaplar.buradaki 2 cevre (2*a*b)formülünden gelir. */

	return perimeterR;

}


int areaOfSquare(int edgeLength)

{
	double areaS;   
	                                            /*bu fonksiyon kare alanini hesaplar.*/
	areaS = (edgeLength*edgeLength);

	return areaS;

}


int perimeterOfSquare(int edgeLength)
{
	double perimeterS;   
	                                            /*bu fonksiyon kare cevresini hesaplar.Karenin 4 kenari bulunur.*/
	perimeterS = (4*edgeLength);
	
	return perimeterS;

}

double areaOfCircle(int radius)

{
    
	double areaC;   
	                                            /*bu fonksiyon daire alanini hesaplar*/
	areaC = (PI*radius*radius);

	return areaC;

}

double perimeterOfCircle(int radius)
                                                /*bu fonksiyon cember cevresini hesaplar.*/
{
	double perimeterC;
	
	perimeterC = (2.0*PI*radius);

	return perimeterC;

}

/*				END_OF_HW02_Eda_Bahrioğlu_131044055_part2.c         	*/
