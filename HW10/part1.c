/*---------------------------------------------------------------------------------------------------*/
/*HW10_131044055_EDA_BAHRIOGLU_part1.c                                                               */
/*Eda Bahrioglu tarafından 06.05.2016 tarihinde yazildi----------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program bir universitedeki bir bölümdeki ogrenciler,egitimciler ve dersler hakkinda bilgi verir.*/                                          
/*---------------------------------------------------------------------------------------------------*/
#include <stdio.h>

/*ogrenci bilgilerinin tutuldugu struct*/
typedef struct{

	int idOfSt;
	char nameOfSt[30];
	char surnameOfSt[30];

}student_t;

/*egitimci bilgilerinin tutuldugu struct*/
typedef struct{

	char degree[30];
	int idOfLc;
	char nameOfLc[30];
	char surnameOfLc[30];
	
}lecturer_t;

/*ders bilgilerinin tutuldugu struct*/
typedef struct{

	int codeOfLc;
	char nameOfLc[30];
	int idOfLc;

}lecture_t;

/*ders plani bilgilerinin tutuldugu struct*/
typedef struct{

	char class[30];
	char day[30];
	int startTime;
	int durationTime;
	int codeOfLc;

}schedule_t;

/*ogrencilerin aldigi derslerin tutuldugu struct*/
typedef struct{

	int idOfSt;
	int codeOfLc;

}course_t;


void writeTotxt(FILE * inp, FILE* outp);

int main(void)
{
	
	FILE *inp, *outp;

	inp=fopen("input.dat","rb");

	outp=fopen("output.txt","w");

	writeTotxt(inp,outp);

	fclose(inp);
	fclose(outp);

return 0;
}

void writeTotxt(FILE * inp, FILE* outp)
{

	int lineNumOfSt,lineNumOflecturer,lineNumOflecture,lineNumOfSchedule,lineNumOfcourse,i,j,count,count2,k,l,m;
	int array[150];

	student_t arrw[20];
	lecturer_t arrx[20];
	lecture_t arry[20];	
	schedule_t arrz[20];
	course_t arrt[20];
/*Binary tipindeki input dosyasindan okuma yapilir.*/	

	fread(&lineNumOfSt, sizeof(int),1,inp);          /*int sayi okunur.birinci structtaki satir sayisini verir.*/
	fread(arrw,sizeof(student_t),lineNumOfSt,inp);   /*birinci structin okundugu kisim*/

	
	fread(&lineNumOflecturer, sizeof(int),1,inp);           /*ikinci structtaki satir sayisini verir.*/
	fread(arrx,sizeof(lecturer_t),lineNumOflecturer,inp);   /*ikinci structin okundugu kisim*/


	fread(&lineNumOflecture, sizeof(int),1,inp);            /*ucuncu structtaki satir sayisini verir.*/
	fread(arry,sizeof(lecture_t),lineNumOflecture,inp);	    /*ucuncu structin okundugu kisim*/
														
	
	fread(&lineNumOfSchedule, sizeof(int),1,inp);           /*dorduncu structtaki satir sayisini verir.*/
	fread(arrz,sizeof(schedule_t),lineNumOfSchedule,inp);   /*dorduncu structin okundugu kisim*/

	
	fread(&lineNumOfcourse, sizeof(int),1,inp);             /*besinci structtaki satir sayisini verir.*/
	fread(arrt,sizeof(course_t),lineNumOfcourse,inp);	    /*besinci structin okundugu kisim*/
								
/*ders ve egitimci arasindaki iliskinin oldugu kisimdir*/

	k=0;
	fprintf(outp,"Lecture-Lecturer\n");

/*ders kodlarinin karsilastirilip counterda tutuldugu kisimdir.*/
/*hangi hocanin kac ders verdigini bulur.                      */

	for(i=0; i<lineNumOflecture; ++i)
	{
		count=0;

		for(j=0; j<lineNumOfcourse; ++j)
		{
			if(arry[i].codeOfLc==arrt[j].codeOfLc)

			{
				count++;
							
			}
						
		}
/*dersin egitimcinin isminin ve egitimcinin verdigi dersin sayisinin array de tutuldugu kisim*/

		for(m=0; m<lineNumOflecturer; m++)
		{
			if(arrx[m].idOfLc == arry[i].idOfLc)
			{
				array[k]=arrx[m].idOfLc;
				array[k+1]=arry[i].codeOfLc;
				array[k+2]=count;
				k=k+3;
			}
		}
	}
	
/*array de tutulan bigilere ulasilan ve cıktinin outputta goruldugu kisim*/

	for(j=0; j<lineNumOflecture; j++)
	{	
		for(i=0; i<lineNumOflecturer; i++)
		{
			if(arrx[i].idOfLc==arry[j].idOfLc)
			{
				for(l=0;l<=k;l+=3)
				{	
					if(arrx[i].idOfLc==array[l])
					{
						if(arry[j].codeOfLc==array[l+1])
						{
							count=array[l+2];
						}
					}

				}

				fprintf(outp,"%s %s %s %d\n",arry[j].nameOfLc, arrx[i].nameOfLc,arrx[i].surnameOfLc,count);
			}

		}

	}
		
	fprintf(outp,"\n");

/*ogrenci ders iliskisinin oldugu kisim                                                            */
/*ogrencilerin aldigi ders sayisini counter da tutar.ve ögrenci bilgileriyle birlikte ekrana basar.*/

	fprintf(outp,"Student-Lecture\n");

	for(i=0; i<lineNumOfSt; ++i)
	{
		count2=0;

		for(j=0; j<lineNumOfcourse; ++j)
		{
			if(arrw[i].idOfSt==arrt[j].idOfSt)

			{
				count2++;			
			}			
		}
		
		fprintf(outp,"%d %s %s %d\n",arrw[i].idOfSt,arrw[i].nameOfSt,arrw[i].surnameOfSt,count2);
	}


	fprintf(outp,"\n");

/*ögrenci ve derslerinin hangi gün oldugunu gösteren kisim*/

	fprintf(outp,"Student-Day\n");

	for(k=0; k<lineNumOfSt; k++)
	{
		fprintf(outp,"%d %s %s ",arrw[k].idOfSt,arrw[k].nameOfSt,arrw[k].surnameOfSt);
		
			for(j=0; j<lineNumOfcourse; ++j)
			{
				for(i=0; i<lineNumOfSchedule; ++i)
				{	
	
					if((arrw[k].idOfSt==arrt[j].idOfSt) && (arrt[j].codeOfLc==arrz[i].codeOfLc))
					{
						fprintf(outp,"%s",arrz[i].day);

						if(j<(lineNumOfSchedule-1))
						{
							fprintf(outp,",");
						}	
					}
					
				}
		
			
			}
		
		fprintf(outp,"\n");

	}	

}
/*				END_OF_HW010_Eda_Bahrioğlu_131044055_part1.c         	*/
