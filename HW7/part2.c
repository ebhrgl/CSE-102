/*---------------------------------------------------------------------------------------------------*/
/*HW7_131044055_EDA_BAHRIOGLU_part2.c                                                                */
/*Eda Bahrioglu tarafindan 15.04.2016 tarihinde yazildi----------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program bir hokey similasyonununun calismasini gösterir.                                        */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

int randNumber(int angle);
int reflection(int angle);
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double kickAngle, double ballRadius, double goalWidth);

int main(void)
{
	int disk;
	disk = kickDisc(10, 26,2 ,40 ,1 ,2  );
	printf("%d\n",disk);

	
	return 0;

}
/*rastgele bi numaranın dondugu fonksiyondur.degiskendir.*/
int randNumber(int angle)
{
	srand(angle);

	return rand();
	
}

/*random sayinin araliginin ve verilen acinin araliginin kontrolunun yapildigi fonksiyondur.*/
int reflection(int angle)
{
	int valueOfrand;

	valueOfrand=randNumber(angle);

		angle=angle+(-5+valueOfrand%10);
	
		if(angle>175)
		{
			angle=175;
		}

		if(angle<5)
		{
			angle=5;
		}

	return angle;

}
/*recursive olarak toun carpma ve gol olma durumunu gosteren fonksiyondur*/
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double kickAngle, double ballRadius, double goalWidth)
{

	 double acrossOfangle,controlOfgoal;

	  reflection(kickAngle);

/*topun sag tarafa olan hareketini kontrol eder.*/		
	if(kickAngle<90 )
	{
		/*verilen acinin karsisindaki ilk yükseklik degeri (acrossOfangle) */
		 acrossOfangle = (wallWidth - ballCenterX - ballRadius) * (tan((kickAngle*PI)/180));
		
		if(wallHeight >acrossOfangle)
		{
			
			return (kickDisc(wallWidth, (wallHeight-acrossOfangle), ballCenterX, kickAngle,  ballRadius,  goalWidth));

			/*topun kaleye girip girmediginin kontrolü icin gerekli olan yatay kenar (controlOfgoal) */
			controlOfgoal = wallHeight - ballRadius * (1 / (tan((90-kickAngle*PI)/180)));

			/*gol olup olmadiginin kontrol edildigi aralik*/
			if((controlOfgoal > (wallHeight - goalWidth)/2) && (controlOfgoal < (wallHeight + goalWidth)/2))
			{
				return 1;
			}
	
			else
			{
				return 0;
			}
		
		}

	}

/*topun sol tarafa olan hareketini kontrol eder.*/
	else if(kickAngle>90)
	{
		 acrossOfangle = ballCenterX - ballRadius * (tan((kickAngle*PI)/180));
		
		if(wallHeight >acrossOfangle)
		{			
			return (kickDisc(wallWidth, (wallHeight-acrossOfangle), ballCenterX, kickAngle,  ballRadius,  goalWidth));
			
			controlOfgoal = wallHeight - ballRadius* (1 / (tan(90-(kickAngle*PI)/180)));

			if((controlOfgoal > (wallHeight - goalWidth)/2) && (controlOfgoal < (wallHeight + goalWidth)/2))
			{
				return 1;
			} 
	
			else
			{
				return 0;
			}
		
		}

	}

/*topun düz olarak yaptigi hareketi kontrol eder.*/	
	else if(kickAngle==90)
	{
		if(ballCenterX <= goalWidth)
		{
			return 0;
		}
		if(ballCenterX > goalWidth)
		{
			return 1;
		}

	}
	
	return 1;

}
/*				END_OF_HW07_Eda_Bahrioglu_131044055_part2.c         	*/
