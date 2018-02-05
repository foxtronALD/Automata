//DFA minimization

#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    printf("Enter number of states\n");
    scanf("%d",&n);

    int state[n],i;
    for(i=0;i<n;i++)
    	state[i]=0;

    state[0]=1;
    
    int j,a[n][2];
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<2;j++)
     	{
    		printf("Enter where State %d should go for %d input\n",i,j);
    		scanf("%d",&a[i][j]);
    		state[a[i][j]]=1;
	}	
    }

	int no;
	printf("Enter number of final states\n");
	scanf("%d",&no);
	
	int f[no];
	printf("Enter final states\n");
	for(i=0;i<no;i++)
		{
			scanf("%d",&f[i]);
			state[f[i]]=2;
		}

	for(i=0;i<n;i++)
	{
 		if(state[i]==0)
  		{	for(j=0;j<2;j++)
    				a[i][j]=-1;
      		}
    	}
        
	int flag,f1;
	int grp[n];
 	while(1)
 	{
		f1=1;
     		flag=0;
      		for(i=0;i<n;i++)
      			grp[i]=0;
      		for(i=0;i<n;i++)
       		{
        		if(grp[i]==0&&a[i][0]!=-1)
        		{
        			grp[i]=f1++;
        			for(j=i+1;j<n;j++)
        			{
        				if(state[i]==state[j])
        				{
        					if(a[j][0]!=-1&&state[a[j][0]]==state[a[i][0]]&&state[a[j][1]]==state[a[i][1]])
        						grp[j]=grp[i];
        				}
        			}
        		}
		}
  		
		for(i=0;i<n;i++)
  		{
			if(state[i]!=grp[i])
  			{
  				state[i]=grp[i];
  				flag=1;
  			}
  		}
	
	 	if(flag==0)
  			break;
  	}
 	
	for(i=0;i<n;i++)
  		printf("State %d is in group->%d\n",i,grp[i]);
  	
	return 0;
}




