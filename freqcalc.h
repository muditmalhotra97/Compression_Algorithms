int freq[95] = {0};
int findFrequency()
{
    FILE *fptr;
    char filename[25], ch;
    int c = 0;
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
		}
        ch = fgetc(fptr);
    }
/*    for (c = 0; c < 95; c++)
    {     
	  	if (count[c] != 0)
        	printf("Frequency of %c is %d\n\n",c+' ',freq[c]);  
   }*/
   fclose(fptr);
   return 0;
}
