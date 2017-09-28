struct Prob{
char chara;
float probability;
}probb[95];
int tn=0;
int FreqCalc()
{
    FILE *fptr;
    char ch;
	char filename[25];
    int freq[95]={0};
	int c = 0;
	float p,uni=0;
    printf("Enter the filename to open \n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr); 
    while (ch != EOF)
    {
        if (ch >=' ' && ch <= '~') 
		{
			freq[ch-' ']++;
			uni++;
		}
        ch = fgetc(fptr);
    }
    
   for (c = 0; c < 95; c++)
    {     
	  	if (freq[c] != 0)
		  	{
		  		p=(float)freq[c]/uni;
				probb[tn].chara=c+' ';	
		  		probb[tn].probability=p;
		  		tn++;
			  }	  
   }
   //for(c=0;c<95;c++)
  //		printf("probability of %c is %f\n",probb[c].chara,probb[c].probability);
   fclose(fptr);
   return 0;
}
