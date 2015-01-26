#include <stdio.h>
typedef char* s;main(){int j,f[]={0x73257325,0x000a7325,0x2c220022,0x100};s p[]={
"#include <stdio.h>",
"typedef char* s;main(){int j,f[]={0x73257325,0x000a7325,0x2c220022,0x100};s p[]={",
"};for(j=0;j<2;j++)printf((s)f,(s)f+0xc,(s)f+0xc,p[j]);for(j=0;j<2;j++)printf((s)f,(s)f+8,p[j],(s)f+0xa);printf((s)f,(s)f+8,p[j],(s)f+8);printf((s)f,p[j],(s)f+0xc,(s)f+0xc);"
};for(j=0;j<2;j++)printf((s)f,(s)f+0xc,(s)f+0xc,p[j]);for(j=0;j<2;j++)printf((s)f,(s)f+8,p[j],(s)f+0xa);printf((s)f,(s)f+8,p[j],(s)f+8);printf((s)f,p[j],(s)f+0xc,(s)f+0xc);}
