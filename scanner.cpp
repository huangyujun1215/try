#include <stdio.h>
#include <string.h>
void swap(char **a,char **b)             //定义二级指针 因为本身的p[j]即二维数组的一行的首地址，因而对其再次取地址即是二级指针 
{
	char *t;
	 t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	int n,i,j,k,t=0;
	char s1[1000][100],s2[1000][100],s3[1000][100];
	char *p[1000];
	while (scanf("%d\n",&n),n!=0)               //两层输入写法会造成输出超限 
	{
		
		for (i=0;i<n;i++)
		{
			gets(s1[i]);
		}
		for (i=0;i<n;i++)
		{
			j=strlen(s1[i]);
			if (s1[i][j-1]=='e'&&s1[i][j-2]=='x'&&s1[i][j-3]=='e'&&s1[i][j-4]=='.')
			{
				for (k=0;k<j-4;k++)
				{
					s2[i][k]=s1[i][k];
				}
				for (k=0;k<n;k++)
				{
					if (strcmp(s1[k],s2[i])==0)
					{
						strcpy(s3[t++],s1[i]);
					}
				}
			}
		}
		for (i=0;i<t;i++)
		{
			p[i]=s3[i];
		}
		for (i=0;i<t;i++)
		{
			for (j=t-1;j>i;j--)
			{
				if (strcmp(p[j],p[j-1])<0)
				{
					swap(&p[j],&p[j-1]);          //对两个字符串的一级指针即地址进行交换，事实上p[j]和p[j-1]所指的内容已经发生了交换 
				}
			}
		}
		for (i=0;i<t;i++)
		    printf("%s\n",p[i]);
		t=0;
	}
	return 0;
}
