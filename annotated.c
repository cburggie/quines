#include <stdio.h>


//shortens casting to char* to (s)
typedef char* s;


//usage "quine [output file]"
main(int c, s v[])
{
	
	/* We're immediately getting into some really aweful programming. The
	 * declaration of j is simple enough (j will be used later as an iterator),
	 * but things start to get really hairy in the initialization of f. This
	 * only works on a 32 bit, little-endian machine. Basically, I'm definine a
	 * string literal, putting ASCII values into consecutive bytes in the
	 * integer array. The string literal translates to the equivalent of
	 * "%s%s%s\n\0"\0\",\0w" which has four null characters. I use manual offsets
	 * below to access the corresponding 4 cstrings.
	 * */
	int j,
		f[] = {
			0x73257325,
			0x000a7325,
			0x2c220022,
			0x77007700
		};

	/* Here we wet up the output file, if not specified we'll print to stdout
	 * */
	FILE*of;if(c==2)of=fopen(v[1],(s)f+0xd);else of=stdout;
	
	/* p is simply a array of strings which store the source of the file.
	 * We only need to source a few double-quote characters and some newlines
	 * from the int array above to reconstruct the entire text.
	 * */
	s p[] = {
		"#include <stdio.h>",
		"typedef char* s;main(int c,s v[]){int j,f[]={0x73257325,0x000a7325,0x2c220022,0x77007700};FILE*of;if(c==2)of=fopen(v[1],(s)f+0xd);else of=stdout;s p[]={",
		"};for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+0xc,(s)f+0xc,p[j]);for(j=0;j<2;j++)fprintf(of,(s)f,(s)f+8,p[j],(s)f+0xa);fprintf(of,(s)f,(s)f+8,p[j],(s)f+8);fprintf(of,(s)f,p[j],(s)f+0xc,(s)f+0xc);"
		};
	



	/* Here we output the first two lines of the source. What's interesting is
	 * the style in which we go about the printing.
	 * 	   (s)f     -- string prototype decodes to "%s%s%s\n" - the first five
	 * 	               bytes of the int array f.
	 * 	   (s)f+0xc -- pointer to a null character, thus an empty string
	 * 	   p[j]     -- the jth line of the source.
	 * Thus, this for-loop prints the first two lines of the source code.
	 * */
	for(j=0;j<2;j++)
		fprintf(of,(s)f,(s)f+0xc,(s)f+0xc,p[j]);
	

	/* Similarly to the the above, we print the first two lines of source. This
	 * time, however, we don't print line+nullstring+nullstring+newline, but
	 * instead print "\""+line+"\","+newline giving us a line that looks like
	 * <"line",\n> instead of <line\n>
	 * */
	for(j=0;j<2;j++)
		fprintf(of,(s)f,(s)f+8,p[j],(s)f+0xa);

	/* We print the last line of source without the trailing comma.
	 * */
	fprintf(of,(s)f,(s)f+8,p[j],(s)f+8);

	/* We print the last line of source in the usual manner
	 * */
	fprintf(of,(s)f,p[j],(s)f+0xc,(s)f+0xc);
	
	//close file if we're printing to one
	if (c==2) fclose(of);
}
