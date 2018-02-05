// Write a program to convert Mealy machine into Moore machine.
  
   #include<stdio.h>
   #include<stdlib.h>
   int cnt[100];
   int main()
   {
  	int n,input;
  	printf("Enter number of STATES\n");
  	scanf("%d",&n);
  	printf("Enter number of Input symbols(integer)\n");
  	scanf("%d",&input);

  	int set[input],k;
  	printf("enter set of input alphabates\n");
  	for(k=0;k<input;k++)
  	  scanf("%d",&set[k]);
  
	int dup[n][2];  
	int arr[n][input]; //input of mealy 
	int output[n][input]; //corresponding output of mealy
	int i,j,anso,ansi;
	int z=n;

	intn output1[100];	
	  for(j=0;j<n;j++)
	      output1[j]=-1;

	  for(i=0;i<n;i++)
	     {
	    	 printf("enter State %d info\n",i+1);
	    	 for(j=0;j<input;j++)
		       {
			       printf("enter transition state when %d arrives\n",set[j]);
			       scanf("%d",&ansi);
       			       arr[i][j]=ansi;  
    	 		       printf("enter output of moore machine\n");
       			       scanf("%d",&anso);
       		               output[i][j]=anso;

       				if(output1[arr[i][j]]!=output[i][j])
       				{
					cnt[arr[i][j]]++; 
					if(cnt[arr[i][j]]==2)
						 {
							dup[arr[i][j]][0]=1;
		       					dup[arr[i][j]][1]=output[i][j];
		       					arr[i][j]=z++;  
						 }
		       			if(cnt[arr[i][j]]==1) 
	       					output1[arr[i][j]]=output[i][j];
	       			}        
     			}	
	    }	     	    
      
	printf("\n*******Transition table of mealy machine is:********\n");
        printf("     %d     o/p    %d    o/p\n",0,1);
        for(i=0;i<n;i++)
     		{
	     	  printf("%d",i);
	     	  for(j=0;j<input;j++)
	       	        printf("     %d     %d",arr[i][j],output[i][j]);
		  printf("\n");
	    	}
     	int n1=n;
  	  for(i=0;i<n;i++)
	     	{
		   if(cnt[i]>1)
		    n1++;
	      	}
     	printf("\n**********Transition table for moore machine is*********** \n");
        printf("     %d     %d    o/p\n",0,1);
        int temp=n1;
    	for(i=0;i<n;i++)
	    	{
	    	  printf("%d",i);
	    	  for(j=0;j<input;j++)
		       printf("     %d",arr[i][j]);    
		  printf("     %d\n",output1[i]);
		  if(dup[i][0]==1)
			  {        
			    printf("%d     %d     %d     %d\n",n1-1,arr[i][j-2],arr[i][j-1],dup[i][1]);
			    n1++;
			  }
		}    
	return 0;	     
    }   
