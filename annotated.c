#include<stdio.h>

static const int QuineSize = 14;
static const char * Quine[] = {
	"#include<stdio.h>",
	"main(){int a,b[]={0x73257325,0x000a7325},c=0x00000022,d=0x00002c22;",
	"char *f=(char*)b,*q=(char*)&c,*m=(char*)&d,*z=1+(char*)&c,*p[]={",
	"\"#include<stdio.h>\",",
	"\"main(){int a,b[]={0x73257325,0x000a7325},c=0x00000022,d=0x00002c22;\",",
	"\"char *f=(char*)b,*q=(char*)&c,*m=(char*)&d,*z=1+(char*)&c,*p[]={\",",
	"\"};for(a=0;a<3;a++) printf(f,z,z,p[a]);\",",
	"\"for(a=0;a<6;a++) printf(f,q,p[a],m);\",",
	"\"printf(f,q,p[6],q);\",",
	"\"for(a=3;a<7;a++)printf(f,z,z,p[a]);}\"",
	"};for(a=0;a<3;a++) printf(f,z,z,p[a]);",
	"for(a=0;a<6;a++) printf(f,q,p[a],m);",
	"printf(f,q,p[6],q);",
	"for(a=3;a<7;a++)printf(f,z,z,p[a]);}"
};

int main(int argc, char *argv[])
{
	if (argc != 2) return 1;
	FILE * of = fopen(argv[1],"w");
	if (!of) return 1;

	int i; for (i = 0; i < QuineSize; i++)
	{
		fprintf(of,"%s\n",Quine[i]);
	}

	fclose(of);

	return 0;

}
