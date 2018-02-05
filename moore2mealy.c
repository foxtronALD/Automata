// Write a program to convert Moore machine into Mealy machine.

  #include<stdio.h>

  int main()
  {	
	int n,input;
  	printf("Enter number of STATES\n");
  	scanf("%d",&n);
  	printf("Enter number of Input symbols(integer)\n");
  	scanf("%d",&input);
  	
  	printf("Enter set of Input symbols\n");
	int k,set[input];  	
	for(k=1;k<=input;k++)
    		scanf("%d",&set[k]);
  
	int mooreinput[n][input];
	int mooreoutput[n];
	int i,j,ansi,anso;                                 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=input;j++)
		{
		  printf("Enter transition state of State %d when %d input arrives\n",i,set[j]);
		  scanf("%d",&ansi);
		  mooreinput[i][j]=ansi;  
		}  

		printf("Enter output of State %d moore machine\n",i);
		scanf("%d",&anso);
		mooreoutput[i]=anso;
	}

	int output1[n][input];
   	for(i=1;i<=n;i++)
        {    for(j=1;j<=input;j++)
                output1[i][j]=mooreoutput[mooreinput[i][j]];
      	}
   	
	printf("\n****TRANSITION TABLE OF EQUIVALENT MEALY MACHINE:****\n");
   	for(i=1;i<=n;i++)
        {  
           for(j=1;j<=input;j++)
           {
	      printf("For STATE %d---",i);
	      printf("On Input symbol %d, transition State reached is %d\n",set[j],mooreinput[i][j]);
 	      printf("It's corresponding output is %d\n",output1[i][j]);
           }
        }  
  
	return 0;
}
