#include<stdio.h>
char Rle[1000];
int main ( )
{
	int i=0;
	//char ch , str [ 100 ] ;
	FILE *fptr;
    char filename[25], c;
    printf("Enter the filename to open \n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    c = fgetc(fptr);
    while (c != EOF)
    {
    	Rle[i]=c;
        c = fgetc(fptr);
        i++;
    }
    fclose(fptr);
	printf("\n\n1 =>: Run - Length Encoding.\n\n2 =>: Run - Length Decoding.\n\n3 =>: Exit the Program.\n\nEnter your Choice =>:");
	scanf("%d",&i);
	switch(i)
	{
		case 1: RLEcompression();break;
		case 2: RLEdecompression();break;
		case 3: exit(0);break;
		default: printf("Please select the correct option");
	}
}
int RLEcompression()
{
	FILE *outfile;
	int count=0,setcount=1,len;
	outfile=fopen("out.txt","w");
	len=strlen(Rle);
	while(count<len)
	{
    	if(Rle[count]==Rle[count+1])
    	{
    		setcount++;
    		count++;
    	}
    	else
    	{
   			printf("%c%d\t",Rle[count],setcount);
    		fprintf(outfile, "%c%d ", Rle[count],setcount);
    		setcount=1;
    		count++;
    	}
	}
}
int RLEdecompression()
{
FILE *outfile;
int count,i,len,j;
outfile=fopen("out1.txt","w");
len=strlen(Rle);
for(i=1;i<len;i=i+3)
{
	count=Rle[i]-'0';
	for(j=1;j<=count;j++)
	{
		printf("%c",Rle[i-1]);
		fprintf(outfile, "%c", Rle[i-1]);
	}
}
}
