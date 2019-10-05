/*---------------------------------------------------------------------------------------------------*/
/*HW5_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrioglu 06.04.2016 tarafından yazildi--------------------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program satranc oyunundaki taslarin hareketini gösterir. oyunun ilk hamlesi icin calisir.       */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void initBoard(char *board);/*satranc tahtasi icin arrayin icini doldurdugumuz fonksiyondur*/
int isEmpty(char* board, int indexOfSource);/*oyunun hamleleri icin tasin gidecegi yerin bos mu dolu mu oldugunu kontrol eder.*/
int getIndex(char col, int row);/*arraydaki indexleri bulur.*/
void getPosition(char *col, int *row);/*girilen pozisyon degerlerini verir.*/
int isValidCell(char col, int row);/*girilen satir ve sutun degerlerinin .*/
void printBoard(char *board);/*satranc tahtasını ekrana basar.*/
int isPieceMovable(char *board);/*hareket kontrollerinin yapildigi fonksiyondur*/
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*at tasinin hareketlerini yapar.*/
int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*kale tasinin hareketlerini yapar.*/
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*vezir tasinin hareketlerini yapar.*/
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*fil tasinin hareketlerini yapar.*/
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*sah tasinin hareketlerini yapar.*/
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*piyon tasinin hareketlerini yapar.*/

int main()
{
	char board[64];
	char col;
	int row;

	isPieceMovable(board);
	
	return 0;
}

void initBoard(char *board)
{
	
	board[0]='r';
	board[1]='n';
	board[2]='b';
	board[3]='q';
	board[4]='k';
	board[5]='b';   /*array in icinin dolduruldugu kisim.*/
	board[6]='n';
	board[7]='r';
	
	board[8]='p';
	board[9]='p';
	board[10]='p';
	board[11]='p';
	board[12]='p';
	board[13]='p';
	board[14]='p';
	board[15]='p';
	
	board[16]=' ';
	board[17]=' ';
	board[18]=' ';
	board[19]=' ';
	board[20]=' ';
	board[21]=' ';
	board[22]=' ';
	board[23]=' ';

	board[24]=' ';
	board[25]=' ';
	board[26]=' ';
	board[27]=' ';
	board[28]=' ';
	board[29]=' ';
	board[30]=' ';
	board[31]=' ';

	board[32]=' ';
	board[33]=' ';
	board[34]=' ';
	board[35]=' ';
	board[36]=' ';
	board[37]=' ';
	board[38]=' ';
	board[39]=' ';

	board[40]=' ';
	board[41]=' ';
	board[42]=' ';
	board[43]=' ';
	board[44]=' ';
	board[45]=' ';
	board[46]=' ';
	board[47]=' ';

	board[48]='P';
	board[49]='P';
	board[50]='P';
	board[51]='P';
	board[52]='P';
	board[53]='P';
	board[54]='P';
	board[55]='P';

	board[56]='R';
	board[57]='N';
	board[58]='B';
	board[59]='Q';
	board[60]='K';
	board[61]='B';
	board[62]='N';
	board[63]='R';

				
}

int isEmpty(char *board, int indexOfSource)    /*tasin önünde baska tas var mı kontrolü yapar.*/  
{

	if(((board[indexOfSource] >= 'a' && board[indexOfSource] <='z') && (board[indexOfSource] >= 'A' && board[indexOfSource] <= 'Z')) ||
		board[indexOfSource]==' '){
		return 1;
	}
	else{
		return 0;
		}
}
int getIndex(char col, int row)
{
	int i;
	int a=0;
	int b=1;
	int c=2;
	int d=3;                /*sutunlarin int degere atandigi kisim*/
	int e=4;
	int f=5;
	int g=6;
	int h=7;
	
	if(col=='a'){
	i=(8-row)*8+a;
	}
		
	if(col=='b'){
	i=(8-row)*8+b;
	}

	if(col=='c'){
	i=(8-row)*8+c;
	}

	if(col=='d'){
	i=(8-row)*8+d;         /*indis hesabi*/
	}

	if(col=='e'){
	i=(8-row)*8+e;
	}

	if(col=='f'){
	i=(8-row)*8+f;
	}

	if(col=='g'){
	i=(8-row)*8+g;
	}

	if(col=='h'){
	i=(8-row)*8+h;
	}
	
	return i;
}


void getPosition(char *col, int *row)
{
	*col=0;                         /*pozisyon degerleri alinir.*/
	*row=0;
	scanf(" %c%d",col,row);
	
	
}

int isValidCell(char col, int row)
{
	if((col=='a' || col=='b' || col=='c' || col=='d' || col=='e' || col=='f' || col=='g' || col=='h') &&  (row==8 || row==7 || row==6 || row==5 || row==4 || row==3 || row==2 || row==1))
	
		{
		return 1;
		}                          /*alinan pozisyon degerlerinin array icinde gecerli olup olmadigini bulur.*/

	else {
		return 0;
	}

}

void printBoard(char *board)
{
	
	int i,j,k;
	printf("  a b c d e f g h\n");
	printf("  ");

		for(i=0;i<8;i++){
			printf("- ");
		}
			printf("\n");
		
		k=0;

		for(i=8; i>0; i--){
			printf("%d|", i);

			j=0;
			while(j<8){
                                          /*tabloyu ekrana basar.*/
				if(j<7){
					printf("%c ",board[k]);
				}
				else{
					printf("%c",board[k]);
				}
			
				k++;
				j++;
			}
				printf("|");
				printf("\n");
		}

			printf(" ");
		for(i=0;i<8;i++){
			printf(" -");
		}
			printf("\n");
	
	

int isPieceMovable(char *board)
{	
	int fonk = 0,j;
	int indexOfSource;
	int indexOfTarget;
	
	char sourceCol,targetCol;
	int sourceRow,targetRow;
	
	
	getPosition(&sourceCol, &sourceRow);
	getPosition(&targetCol,&targetRow);           /*asil isin yapildigi kisimdir.ilk olarak hedef pozisyonun dolu olup olmadigini kontrol eder.hareket yapilacagi zaman hangi tasin 													cagrilacaginin belirlendigi fonksiyondur.*/
	
	isValidCell(sourceCol, sourceRow);
	isValidCell(targetCol,targetRow);
	
	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfTarget=getIndex(targetCol,targetRow);

	if(((board[indexOfSource] >= 'a' && board[indexOfSource] <='z') && (board[indexOfTarget] >= 'A' && board[indexOfTarget] <= 'Z')) ||
		((board[indexOfSource] >='A' && board[indexOfSource] <= 'Z') && (board[indexOfTarget] >= 'a' && board[indexOfTarget] <= 'z')) ||
		board[indexOfTarget]==' ')
	{

	
		for(j=0; j<64; j++){

			if(board[j]=='r' || board[j]=='R')
			{
				fonk=isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}
	
			if(board[j]=='n' || board[j]=='N')
			{
				fonk=isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}                                                                              /*cagirilacak tasin kontrolünün yapildigi kisimdir.*/
	
			if(board[j]=='b' || board[j]=='B')
			{
				fonk=isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}
	
			if(board[j]=='q' || board[j]=='Q')
			{
				fonk=isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}

			if(board[j]=='k' || board[j]=='K')
			{
				fonk=isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}
	
			if(board[j]=='p' || board[j]=='P')
			{
				fonk=isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow);
			}
		}
	}
	return fonk;
			
}

int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	
	int x, y;
	int indexOfSource;
	int indexOfTarget;
	
	
	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfTarget=getIndex(targetCol,targetRow);              /*atin hareketini l seklinde yaptigini gösteren fonksiyon.burada tekrardan hareket konrolü yapilmaz çünkü her durumda at hareket 																	edebilir.*/
	
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;

	if((abs(x)==1 && abs(y)==2) || (abs(x)==2 && abs(y)==1))
	{
		indexOfTarget=indexOfSource+(x+y)*8;

		board[indexOfSource]=board[indexOfTarget];
	}

	
		return 1;		
}


int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int indexOfSource;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);            /*kalenin hareketini ilk hamle için kontrol eder normalde her yöne hareket edebilen kale ilk durum için hareket edemez.*/
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;
	
		if(isEmpty(board,indexOfSource))
		{
			if(x==0){

				indexOfTarget=indexOfSource+(y*8);
				board[indexOfSource]=board[indexOfTarget];
			}
			if(y==0){
				indexOfTarget=indexOfSource+(x);
				board[indexOfSource]=board[indexOfTarget];
			}
			return 1;
		}
		
		else{
			return 0;
		}
	
}

int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int indexOfSource;
	int indexOfSource2;
	int indexOfSource3;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol,sourceRow-1);
	indexOfSource2=getIndex(sourceCol+1,sourceRow+1);
	indexOfSource3=getIndex(sourceCol-1,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);
	
	x = targetCol-sourceCol;                          /*vezir hareketi kale ve fil hareketi gibidir.ilk durum icin hareket etmez.her yöne istedigi kadar gider.*/
	y = targetRow-sourceRow;

	
	if(isEmpty(board,indexOfSource) || isEmpty(board,indexOfSource2) || isEmpty(board,indexOfSource3))
	{

		if(x==0){

			indexOfTarget=indexOfSource+(y*8);
			board[indexOfSource]=board[indexOfTarget];
		}
		if(y==0){
			indexOfTarget=indexOfSource+(x);
			board[indexOfSource]=board[indexOfTarget];
		}

		if(abs(x+y)==9)
		{
			indexOfTarget=indexOfSource+(y*9);
			board[indexOfSource]=board[indexOfTarget];
		}

		if(abs(x+y)==7)
		{
			indexOfTarget=indexOfSource+(y*7);
			board[indexOfSource]=board[indexOfTarget];
		}

	
		return 1;
	}
	else{
		return 0;
	}


}
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	int indexOfSource;
	int indexOfSource2;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol+1,sourceRow+1);
	indexOfSource2 = getIndex(sourceCol-1,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);
	
	x = targetCol-sourceCol;                                          /*fil capraz hareket eder.ilk durum icin hareket edemez.*/
	y = targetRow-sourceRow;
	if(isEmpty(board,indexOfSource) || isEmpty(board,indexOfSource2) )
	{
		if(abs(x+y)==9)
		{
			indexOfTarget=indexOfSource+(y*9);
			board[indexOfSource]=board[indexOfTarget];
		}

		if(abs(x+y)==7)
		{
			indexOfTarget=indexOfSource+(y*7);
			board[indexOfSource]=board[indexOfTarget];
		}

		return 1;
	}
	else{
		return 0;
	}
}
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{

	int indexOfSource;
	int indexOfSource2;
	int indexOfSource3;
	int indexOfTarget;
	int x, y;

	
	indexOfSource=getIndex(sourceCol,sourceRow+1);
	indexOfSource2=getIndex(sourceCol+1,sourceRow+1);
	indexOfSource3=getIndex(sourceCol-1,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);                   /*her yöne at hareketi disinda birer birer gider.ilk durumda hareket etmez.*/
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;

	if(isEmpty(board,indexOfSource) || isEmpty(board,indexOfSource2) || isEmpty(board,indexOfSource3))
	{
		if(x==1){

			indexOfTarget=indexOfSource+(y*8);
			board[indexOfSource]=board[indexOfTarget];
		}
		if(y==1){

			indexOfTarget=indexOfSource+(x);
			board[indexOfSource]=board[indexOfTarget];

		}

		if(abs(x+y)==9)
		{
			indexOfTarget=indexOfSource+(y*9);
			board[indexOfSource]=board[indexOfTarget];
		}

		if(abs(x+y)==7)
		{
			indexOfTarget=indexOfSource+(y*7);
			board[indexOfSource]=board[indexOfTarget];
		}
		return 1;
	}
	else{
		return 0;
			}
}

int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int indexOfSource;
	int indexOfSource2;
	int indexOfSource3;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfSource2=getIndex(sourceCol+1,sourceRow+1);
	indexOfSource3=getIndex(sourceCol-1,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);                             /*piyon ilk durumda da hareket edebilir.düz öne hareket eder.Ancak caprazında tas varsa onu yer.*/
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;

	if(x==0 && y==1)
	{
		indexOfTarget=indexOfSource+(y*8);
		board[indexOfSource]=board[indexOfTarget];
	}
	
	if(x==1 && y==0){

		indexOfTarget=indexOfSource+(x);
		board[indexOfSource]=board[indexOfTarget];
	}
	if(!isEmpty(board,indexOfSource2) || !isEmpty(board,indexOfSource3))
	{
	if(abs(x+y)==9)
		{
			indexOfTarget=indexOfSource+(y*9);
			board[indexOfSource]=board[indexOfTarget];
		}

		if(abs(x+y)==7)
		{
			indexOfTarget=indexOfSource+(y*7);
			board[indexOfSource]=board[indexOfTarget];
		}
	}
	return 1;
}

/*				END_OF_HW05_Eda_Bahrioğlu_131044055_part1.c         	*/
