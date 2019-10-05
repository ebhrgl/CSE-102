/*---------------------------------------------------------------------------------------------------*/
/*HW8_131044055_EDA_BAHRIOGLU_part1.c                                                                */
/*Eda Bahrioglu 23.04.2016 tarafından yazildi--------------------------------------------------------*/
/*Tanimlama                                                                                          */
/*Bu program bir satranç oyununun calismasini gösterir                                               */
/*---------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BOARD_SIZE 8

void initBoard(char *board);/*satranc tahtasi icin arrayin icini doldurdugumuz fonksiyondur*/
int isEmpty(char* board, int indexOfSource);/*oyunun hamleleri icin tasin gidecegi yerin bos mu dolu mu oldugunu kontrol eder.*/
int getIndex(char col, int row);/*arraydaki indexleri bulur.*/
void getPosition(char *col, int *row);/*girilen pozisyon degerlerini verir.*/
int isValidCell(char col, int row);/*girilen satir ve sutun degerlerinin .*/
void printBoard(char *board);/*satranc tahtasını ekrana basar.*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);/*hareket kontrollerinin yapildigi fonksiyondur*/
int isInCheck(char* board);/*kontrol fonksiyonu*/
char getPlayer(char *board, char sc, int sr);
int isBlack(char currPlayer);/*renk kontrol fonksiyonu*/
int isWhite(char currPlayer);/*renk kontrol fonksiyonu*/
int makeMove(char *board, char sc, int sr, char tc, int tr);/*check durumuna göre kontrolün yapildigi fonksiyon*/
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*at tasinin hareketlerini yapar.*/
int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*kale tasinin hareketlerini yapar.*/
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*vezir tasinin hareketlerini yapar.*/
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*fil tasinin hareketlerini yapar.*/
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*sah tasinin hareketlerini yapar.*/
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);/*piyon tasinin hareketlerini yapar.*/

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}


void initBoard(char *board)
{
	
	board[0]='r';
	board[1]='n';
	board[2]='b';
	board[3]='q';
	board[4]='k';
	board[5]='b';  
	board[6]='n';       /*array in icinin dolduruldugu kisim.*/
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
/*target indeksinin bos olup olmadigini kontrol eden fonksiyondur.*/
int isEmpty(char *board, int indexOfSource)   
{

	if(((board[indexOfSource] >= 'a' && board[indexOfSource] <='z') || (board[indexOfSource] >= 'A' && board[indexOfSource] <= 'Z')) ||    
		board[indexOfSource]==' '){
		return 1;
	}
	else{
		return 0;
		}
}
/*boardtaki tüm index leri hesaplayan fonksiyondur.*/
int getIndex(char col, int row)
{
	int i;
	int a=0;
	int b=1;
	int c=2;
	int d=3;                
	int e=4;
	int f=5;
	int g=6;
	int h=7;
	
	if(col=='a'){
	i=((8-row)*8)+a;
	}
		
	if(col=='b'){
	i=((8-row)*8)+b;
	}

	if(col=='c'){
	i=((8-row)*8)+c;
	}

	if(col=='d'){
	i=((8-row)*8)+d;        
	}

	if(col=='e'){
	i=((8-row)*8)+e;
	}

	if(col=='f'){
	i=((8-row)*8)+f;
	}

	if(col=='g'){
	i=((8-row)*8)+g;
	}

	if(col=='h'){
	i=((8-row)*8)+h;
	}
	
	return i;
}

/*taslarin pozisyon degerlerinin alindigi fonksiyondur.*/
void getPosition(char *col, int *row)
{
 	*col=0;                         
	*row=0;
	scanf(" %c %d",col,row);

	
}
/*girilen pozisyonun boardta gecerli olup olmadigini kontrol eden fonksiyondur.*/
int isValidCell(char col, int row)
{
	if((col=='a' || col=='b' || col=='c' || col=='d' || col=='e' || col=='f' || col=='g' || col=='h') &&  (row==8 || row==7 || row==6 || row==5 || row==4 || row==3 || row==2 || row==1))
	
		{
		
		return 1;
		}                          

	else {
		return 0;
	}

}
/*boardu ekrana basan fonksiyondur.*/
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
	
}	
/*tas fonksiyonlarinin cagirilarak hareketlerinin yaptirildigi oyunun oynandigi fonksiyondur.*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{	
	int fonk = 0;
	int indexOfSource;
	int indexOfTarget;

        
	
	if(isValidCell(sc, sr)==0)
	{
		return 0;
	}
	if(isValidCell(tc,tr)==0)
	{
		return 0;
	}
	/*index fonksiyonu cagirilarak pozisyon yerleri ögrenilir.*/
	indexOfSource=getIndex(sc,sr);
	indexOfTarget=getIndex(tc,tr);
    /*gidilecek pozisyonda tas olup olmadigini kontrol eder.*/
	if(((board[indexOfSource] >= 'a' && board[indexOfSource] <='z') && (board[indexOfTarget] >= 'A' && board[indexOfTarget] <= 'Z')) ||
		((board[indexOfSource] >='A' && board[indexOfSource] <= 'Z') && (board[indexOfTarget] >= 'a' && board[indexOfTarget] <= 'z')) ||
		board[indexOfTarget]==' ')
	{

	
			if(board[indexOfSource]=='r' || board[indexOfSource]=='R')
			{
				fonk=isRookMovable(board,sc,sr,tc,tr);
			}
	
			if(board[indexOfSource]=='n' || board[indexOfSource]=='N')
			{
				fonk=isKnightMovable(board,sc,sr,tc,tr);
			}                                                                             
	
			if(board[indexOfSource]=='b' || board[indexOfSource]=='B')
			{
				fonk=isBishopMovable(board,sc,sr,tc,tr);
			}
	
			if(board[indexOfSource]=='q' || board[indexOfSource]=='Q')
			{
				fonk=isQueenMovable(board,sc,sr,tc,tr);
			}

			if(board[indexOfSource]=='k' || board[indexOfSource]=='K')
			{
				fonk=isKingMovable(board,sc,sr,tc,tr);
			}
	
			if(board[indexOfSource]=='p' || board[indexOfSource]=='P')
			{
				fonk=isPawnMovable(board,sc,sr,tc,tr);
			}
		
	}
	return fonk;
			
}
/*at fonksiyonudur.l seklinde hareketin yapildigi fonksiyondur.*/
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	
	int x, y;
	int indexOfSource;
	int indexOfTarget;
	
	
	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfTarget=getIndex(targetCol,targetRow);              
	
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;

/*l hareketi*/

	if((abs(x)==1 && abs(y)==2) || (abs(x)==2 && abs(y)==1))
	{
		indexOfTarget=indexOfSource+(x+y)*8;

		board[indexOfTarget]=board[indexOfSource];

		return 1;
	}
		
	else 
	{
		return 0;
	}		
}

/*kale fonksiyonudur.her yöne düz hareket eder. */
int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int indexOfSource;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfTarget=getIndex(targetCol,targetRow);           
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;
	
/*düz hareket*/		
			if(x==0){

				indexOfTarget=indexOfSource+(y*8);
				board[indexOfTarget]=board[indexOfSource];
				return 1;
			}

			if(y==0){
				indexOfTarget=indexOfSource+(x);
				board[indexOfTarget]=board[indexOfSource];
				return 1;
			}
			
		
		
		else{
			return 0;
		}
	
}
/*vezir fonksiyonudur.kale gibi her yöne  düz hareket edebilir fi gibi capraz hareket edebilir. */
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
	
	x = targetCol-sourceCol;                          
	y = targetRow-sourceRow;

	
	if(isEmpty(board,indexOfSource)==0 || isEmpty(board,indexOfSource2)==0 || isEmpty(board,indexOfSource3)==0)
	{
/*düz hareket*/

		if(x==0){

			indexOfTarget=indexOfSource+(y*8);
			board[indexOfSource]=board[indexOfTarget];
		}
		if(y==0){
			indexOfTarget=indexOfSource+(x);
			board[indexOfSource]=board[indexOfTarget];
		}
/*capraz hareket*/


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
/*fil fonksiyonudur capraz hareket yapar.*/
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	
	int indexOfSource;
	int indexOfSource2;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol+1,sourceRow+1);
	indexOfSource2 = getIndex(sourceCol-1,sourceRow-1);
	indexOfTarget=getIndex(targetCol,targetRow);
	
	x = targetCol-sourceCol;                                        
	y = targetRow-sourceRow;
	if(isEmpty(board,indexOfSource)==0 || isEmpty(board,indexOfSource2)==0 )
	{
/*capraz hareket*/
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
/*kral fonksiyonudur.capraz hareket eder ve birer birer her yöne hareket edebilir. */
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
	indexOfTarget=getIndex(targetCol,targetRow);                  
	
	x = targetCol-sourceCol;
	y = targetRow-sourceRow;

	if(isEmpty(board,indexOfSource)==0 || isEmpty(board,indexOfSource2)==0 || isEmpty(board,indexOfSource3==0))
	{

/*düz hareket tek hamle olarak*/

		if(x==1){

			indexOfTarget=indexOfSource+(y*8);
			board[indexOfSource]=board[indexOfTarget];
		}
		if(y==1){

			indexOfTarget=indexOfSource+(x);
			board[indexOfSource]=board[indexOfTarget];

		}
/*capraz hareket*/

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
/*piyon fonksiyonudur. düz birer birer hareket eder.caprazinde karsi takimin tasi varsa capraz gider ve yer.*/
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	int indexOfSource;
	int indexOfTarget;
	int x, y;

	indexOfSource=getIndex(sourceCol,sourceRow);
	indexOfTarget=getIndex(targetCol,targetRow);                            
	
	x = abs(targetCol-sourceCol);
	y = abs(targetRow-sourceRow);

	if(x==1 && y==0)
	{
		indexOfTarget=indexOfSource+(y*8);
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

/*oynanan tasin hangisi oldugunu bize söyler.*/
char getPlayer(char *board, char sc, int sr)
{
		
	int indexOfSource;
	char ch;
	          
	indexOfSource=getIndex(sc,sr);
	ch=board[indexOfSource];
	
	return ch;
	
	
}
/*tasin siyah oldugunu ifade eden fonksiyondur.*/
int isBlack(char currPlayer)
{
	if(currPlayer=='r' ||currPlayer=='n' ||currPlayer=='b' ||currPlayer=='q' ||currPlayer=='k' ||currPlayer=='p'  )
	{
		return 1;
	}
	else	
	{

 		return 0;
	}
}
/*tasin beyaz oldugunu ifade eden fonksiyondur.*/
int isWhite(char currPlayer)
{
	
	if(currPlayer=='R' ||currPlayer=='N' ||currPlayer=='B' ||currPlayer=='Q' ||currPlayer=='K' ||currPlayer=='P'  )
	{
		return 1;
	}
	else
	{
 		return 0;
	}

}
/*kralin check olma durumunu kontrol eden fonksiyondur.*/
/*beyaz kral check durumundaysa return 1 döndürür.     */
/*siyah kral check durumundaysa return 2 döndürür.     */
/*check olmama durumunda return 0 döndürür.            */

int isInCheck(char* board)
{
	int indexOfKing,indexOfTarget,indexOfSource,i,j,sr,tr,fonk;
	char sc,tc;

/*siyah kiralin indisini bulan döngü*/	
	for(i=0; i<64; i++)
	{
		if(board[i]=='k')
		{
			indexOfKing = i;
		}

	}

/*beyaz kiralin indisini bulan döngü*/
	for(j=0; j<64; j++ )
	{
		if(board[j]=='K')
		{
			indexOfKing = j;
		}

	}

	tr = (8-(indexOfKing/8));	
	tc = indexOfKing + 'a';	

	
	for(i='a'; i<='h'; i++)
	{
		sc=i;


		for(j=1; j<=8; j++)
		{
			sr=j;
			
		indexOfSource=getIndex(sc,sr);
		indexOfTarget=getIndex(sc,sr);

		fonk = isPieceMovable(board, sc, sr,  tc, tr);

/*hedef pozisyonun kral pozisyonuna esit olma durumu*/

				if(fonk==1)

				{	
					if(board[indexOfKing]=='K')
					{	
						if((board[indexOfSource]=='p') || (board[indexOfSource]=='r') || (board[indexOfSource]=='n') || (board[indexOfSource]=='b') || (board[indexOfSource]=='q'))
						{
							if((board[indexOfKing])==(board[indexOfTarget]))
							{
								return 1;
							}
						}
					}
	

					if(board[indexOfKing]=='k')
					{	
						if((board[indexOfSource]=='P') || (board[indexOfSource]=='R') || (board[indexOfSource]=='N') || (board[indexOfSource]=='B') || (board[indexOfSource]=='Q'))
						{
							if((board[indexOfKing])==(board[indexOfTarget]))
							{
								return 2;
							}
						}
					}

				}
			
		}
	}
 
	return 0;
}
/*kralin check olma durumuna göre hareket durumunu da kontrol eder.                          */
/*eger hareket gecersizse return 0 döndürür.                                                 */
/*eger hareket gecersizse ve kralin check durumu mevcutsa return 1 döndürür.                 */
/*hareket gecerliyse return 2 döndürür.                                                      */
/*hareket gecerliyse ve karsidaki oyuncunun kralinda check durumu mevcutsa return 3 döndürür.*/

int makeMove(char *board, char sc, int sr, char tc, int tr)
{
	int indexOfSource,indexOfTarget;

	indexOfSource=getIndex(sc,sr);
	indexOfTarget=getIndex(tc,tr);
	
	if(isInCheck(board)==2)
	{	
		return 1;
	}
	if(isPieceMovable(board, sc, sr,  tc, tr)==1)
	{
		board[indexOfTarget]=board[indexOfSource];
		board[indexOfSource]=' ';
	
		return 2;
	}
	
	if(isInCheck(board)==1)
	{
		return 3;
	}
	else
	{
		 return 0;
	}
}
/*				END_OF_HW08_Eda_Bahrioğlu_131044055_part1.c         	*/
