#include <stdio.h>
#include <string.h>
char * matcher(char *hay, char *ned);

int main (void)

{
	char hay[50]="lorem ipsum dolor sit amet";
	char ned[30]="lerom";

	matcher(hay,ned);
	printf("%s\n",matcher(hay,ned));
	return 0;
}


char * matcher(char *hay, char *ned)
{
	int i ,b, j;

	for(i=0; i<strlen(hay); i++)
	{
	
		if(ned[0]==hay[i])
		{
			b=i;
			for(j=0;j<strlen(ned);j++)
			{
				if(ned[j]==hay[b])
				{	
					j=j+1;
					b=b+2;
					printf("%d   %d\n",j,b);

					if(j>=strlen(ned))
					{
						return( &hay[i]);
						
					}
				
				}
				else
				{	
					j=strlen(ned);
					
				}
			}
			
		}
			
	}
	return '\0';
}
