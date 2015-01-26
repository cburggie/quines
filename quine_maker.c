#include<stdio.h>
main()
{
	int a,
		b[]={0x73257325,0x000a7325}, // format string, "%s%s%s\n" in memory
		c=0x00000022,// quotation mark "\"\0\0" in  memory
		d=0x00002c22; // quote and comma "\"," in memory
	char	*f=(char*)b,  //format string
			*q=(char*)&c, //quote string
			*m=(char*)&d, //comma string
			*z=1+(char*)&c,//nullstring
			*p[]=
			{
				//first part
				"#include<stdio.h>",
				"main(){int a,b[]={0x73257325,0x000a7325},c=0x00000022,d=0x00002c22;",
				"char *f=(char*)b,*q=(char*)&c,*m=(char*)&d,*z=1+(char*)&c,*p[]={",
				//second part
				"};for(a=0;a<3;a++) printf(f,z,z,p[a]);",
				"for(a=0;a<6;a++) printf(f,q,p[a],m);",
				"printf(f,q,p[6],q);",
				"for(a=3;a<7;a++)printf(f,z,z,p[a]);}"
			};
	
	//print header straight out
	for(a=0;a<3;a++) printf(f,z,z,p[a]);
	
	//wrap program contents in quotes, comma terminate
	for(a=0;a<6;a++) printf(f,q,p[a],m);
	
	//don't comma-terminate the last line in quotes
	printf(f,q,p[6],q);

	//print the rest of the program
	for(a=3;a<7;a++) printf(f,z,z,p[a]);
}

