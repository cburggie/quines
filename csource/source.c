#include <stdio.h>
typedef char* s;main(int c,s v[]){int j,f[]={0x73257325,0x000a7325,0x2c220022,0x77007700};FILE* of;if(c==2)of=fopen(v[1],(s)f+0xd);else of=stdout;s p[]={

"#include <stdio.h>",
"typedef char* s;main(int c,s v[]){int j,f[]={0x73257325,0x000a7325,0x2c220022,0x77007700};FILE* of;if(c==2)of=fopen(v[1],(s)f+0xd);else of=stdout;s p[]={",

"};for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+0xc,(s)f+0xc,p[j]);for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+8,p[j],(s)f+0xa);fprintf(of,(s)f,(s)f+8,p[j],(s)f+8);fprintf(of,(s)f,p[j],(s)f+0xc,(s)f+0xc);if(c==2)fclose(of);}"

};for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+0xc,(s)f+0xc,p[j]);for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+8,p[j],(s)f+0xa);fprintf(of,(s)f,(s)f+8,p[j],(s)f+8);fprintf(of,(s)f,p[j],(s)f+0xc,(s)f+0xc);if(c==2)fclose(of);}
