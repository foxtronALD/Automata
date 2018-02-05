//AKASH AGRAWAL 20138058 IT1
//PROGRAM TO ELIMINATE NULL PRODUCTIONS
#include<stdio.h>
#include<string.h>


int main()
{
   int n,i,j,k,nulli[100],l;
   char str[100][10],null[100],newp[100][10];
   printf("enter the number of productions in the grammer  ");
   scanf("%d",&n);
   printf("\nenter all the productions in the grammer with first production as the starting one\n");
   printf("enter # for null\n");
   for(i=1;i<=n;i++)
   {
    printf("production no. %d   ",i);
    scanf(" %s",str[i]);
   }

   
   for(i=1,j=0;i<=n;i++)                
    {
      if(str[i][2] == '#')
       {
        null[++j] = str[i][0];          
       }
    }
    
    int num = 0;
    
    for(i=1;i<=j;i++)
     {
       for(l=1;l<=n;l++)
        {
          if(str[j][2] == '#')
           continue;

          for(k=2;str[l][k]!='\0';k++)
            {
               if(str[l][k] == null[i])
                {
                  num++;
                  str[l][k] = '\0';
                  strcpy(newp[num],str[l]);
                  strcat(newp[num],str[l]+k+1);
                  str[l][k] = null[i];
                }
             }
        }
     }               
    
    
    
    
    
     for(i=1;i<=j;i++)
     {
       for(l=1;l<=num;l++)
        {

          for(k=2;newp[l][k]!='\0';k++)
            {
               if(newp[l][k] == null[i])
                {
                  num++;
                  newp[l][k] = '\0';
                  strcpy(newp[num],newp[l]);
                  strcat(newp[num],newp[l]+k+1);
                  newp[l][k] = null[i];
                }
             }
        }
     } 
    
    
    
    
    
    
    
    
    
    printf("\n");
    
    printf("productions after the removal of null productions are\n\n");
    
    for(i=1;i<=n;i++)
     {
       if(str[i][2] == '#')
        continue;   
       printf("%s\n",str[i]);
     }
     
   for(i=1;i<=num;i++)
     printf("%s\n",newp[i]);
     
    return 0;
}
