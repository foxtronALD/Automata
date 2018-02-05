//PROGAM TO REMOVE USELESS SYMBOLS FROM THE GIVEN GRAMMER
//AUTHOR-AMAN VERMA
//REG NO 20138047
//CSA-1
#include<stdio.h>
#include<string.h>
char str[10][10];
int num;
int scan(int );
int check(char c,int k)
{
int i;
for(i=0;;i++)
		if(i!=k)
		{
		if(str[i][0]==c && i<num )
		return scan(i);
		if(i==num)
		return 0;
		
		}

}
int scan(int i)
{
int j=2,flag=1;
while(str[i][j]!='\0')
{
	if(str[i][j]>='A' && str[i][j]<='Z')
	{
		flag=check(str[i][j],i);
		
	}
j++;
}
return flag;
}
int main()
{
int i,f,j=0,ter[10];
printf("Enter no. of production: ");
scanf("%d",&num);
for(i=0;i<num;i++)
{
	printf("Enter %d production: ",i+1);
	scanf("%s",str[i]);
}
for(i=0;i<num;i++)
{
	f=scan(i);
	if(f)
	{
	ter[i]=1;
	}
}
printf("The new production after removing of non-terminal grammer\n");

for(i=0;i<num;i++)
{
if(ter[i]==1)
	printf("%s\n",str[i]);
}
return 0;
}






















