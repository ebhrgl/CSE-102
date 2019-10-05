#include <stdio.h>

void line1(int satir,int digit,char chr);
void line2(int satir,int digit,char chr);
void line3(int satir,int digit,char chr);
void line4(int satir,int digit,char chr);
void line5(int satir,int digit,char chr);
int bas(int num);
void getInputs(int* num, int* borderwidth, char* chr);
int printNumber(int num,int borderwidth,char chr);

int main(void)
{
	int num,borderwidth;
	char chr;
	
	

	getInputs(&num, &borderwidth, &chr);
	printNumber( num, borderwidth,chr);

	return 0;

}

void line1(int satir,int digit,char chr)
{
	
	if(digit==1){				
		printf("   %c   ",chr);	
		}
	else if(digit==4){
		printf("  %c %c  ",chr,chr);
		}
	else{
		printf("  %c%c%c  ",chr,chr,chr);
		}
	
	
}
void line2(int satir,int digit,char chr)
{
	
	if(digit==1){
		printf("  %c%c   ",chr,chr);	
		}
	else if(digit==2 || digit==3 || digit==7){
		printf("    %c  ",chr);
	}
	else if(digit==5  || digit==6){
		printf("  %c    ",chr);
		}
	else {
		printf("  %c %c  ",chr,chr);	
		}
	
	
}
void line3(int satir,int digit,char chr)
{
	
	if(digit==1){		
		printf("   %c   ",chr);		
	}
	else if(digit==3){
		printf("   %c%c  ",chr,chr);
	}	
	else if(digit==7){
		printf("    %c  ",chr);
	}
	else if(digit==0){
		printf("  %c %c  ",chr,chr);
	}
	else{
		printf("  %c%c%c  ",chr,chr,chr);
	}
	
	
}
void line4(int satir,int digit,char chr)
{	
	

	if(digit==1){
		printf("   %c   ",chr);
		
	}
	else if(digit==2){
        printf("  %c    ",chr);
	}
	else if(digit==6 || digit==8 || digit==0){
		printf("  %c %c  ",chr,chr);
	}
	else{
		printf("    %c  ",chr);
		
	}
	
}
void line5(int satir,int digit,char chr)
{
	
	if(digit==4  || digit==7){
		printf("    %c  ",chr);
	}
	else{
		printf("  %c%c%c  ",chr,chr,chr);
	}
	
}


int bas(int num)
{	
	int basamak=1;                   
	
	while(num>=10)
	{

		num=num/10.0;                                          
		basamak++;

	}

	return basamak;
}

void getInputs(int* num, int *borderwidth, char* chr)
{
	
	
	scanf("%d",num);
	scanf("%d",borderwidth);
	scanf(" %c",chr);
		
	

}
 
int printNumber(int num,int borderwidth,char chr)
{	
	
	int i,j,temp,digit;
	int satir;
	

	for(j=1; j<=borderwidth;j++)
	{	
		for(i=1; i<=(bas(num)*7)+(2*borderwidth); i++){
			printf("%c",chr);
		}
			printf("\n");
	}
	
	for(i=1; i<=borderwidth; i++){
		printf("%c",chr);}	
	for(i=1; i<=(bas(num)*7); i++){
		printf(" ");}
	for(i=1; i<=borderwidth; i++){
		printf("%c",chr);
		}
			printf("\n");


		if(0>num && num>99999 && borderwidth<0 )
		{
			return 0;
		}
		
				temp=num;		
				digit = num;

	
			for(satir=1; satir<=5;satir++)
			{
				for(i=1; i<=borderwidth; i++){
					printf("%c",chr);}
			
				while(temp>0){
				
					digit=temp%10;
					temp/=10;
					
					if(satir==1){				
						line1(satir,digit,chr);		
						}
					else if(satir==2){	
						line2(satir,digit,chr);
						}
					else if(satir==3){
						line3(satir,digit,chr);
						}
					else if(satir==4){

						line4(satir,digit,chr);
						}
					else if(satir==5){
				
						line5(satir,digit,chr);
						}
				
				}
					for(i=1; i<=borderwidth; i++){
					printf("%c",chr);}
					printf("\n");
					temp = num;
	
			}

	
			for(i=1; i<=borderwidth; i++){
				printf("%c",chr);}
			for(i=1; i<=(bas(num)*7); i++){
				printf(" ");}
			for(i=1; i<=borderwidth; i++){
				printf("%c",chr);
				}
					printf("\n");

			for(j=1; j<=borderwidth;j++)
			{
	
				for(i=1; i<=(bas(num)*7)+(2*borderwidth); i++){
					printf("%c",chr);
				}
					printf("\n");
			}

	
		return 1;

}	


