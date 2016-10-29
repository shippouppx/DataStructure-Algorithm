#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getnextarray(char* m)
{
	int mnum=strlen(m);
	int* next=(int*)malloc(mnum*sizeof(int));
	next[0]=-1;
	next[1]=0;
	int pos=2;
	int cn=0;
	while(pos<mnum)
	{
		if(m[pos-1]==m[cn])
		{
			next[pos++]=++cn;
		}
		else if(cn>0)
		{
			cn=next[cn];
		}
		else
		{
			next[pos++]=0;
		}
	}
	return next;
}

int getindexof(char* s,char* m)
{
	int snum=strlen(s);
	int mnum=strlen(m);
	int si=0,mi=0;
	int* next=getnextarray(m);
	while(si<snum && mi<mnum)
	{
		if(s[si]==m[mi])
		{
			si++;
			mi++;
		}
		else if(next[mi]==-1)
		{
			si++;
		}
		else
		{
			mi=next[mi];
		}
	}
	return mi==mnum? si-mi:-1;
}

int main(int argc, char const *argv[])
{
	char* s="nihaomawohenhao";
	char* m="hen";
	printf("%d\n",getindexof(s,m));
	return 0;
}