// NOTE: For information on OS X (OS X 10.11.6) versions of <fcntl.h> and <unistd.h> see:
//           - http://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/sys/unistd.h
//           - http://opensource.apple.com/source/xnu/xnu-3248.60.10/bsd/sys/fcntl.h

// NOTE: For inforation on OSMalloc see:
//           - https://developer.apple.com/library/mac/documentation/Darwin/Conceptual/KernelProgramming/vm/vm.html#//apple_ref/doc/uid/TP30000905-CH210-CHDHIIJF

/*@ -retvalint -type */

#include <time.h>   // used to time process

#include "minstdio.h"

int main(void) {

	FILE *fp;
	char x;
	clock_t start = clock();

	putstring("Hello World!\n");
	fflush(stdout);

	fp = fopen("results.txt", "w");
	puts("Hello World!", fp);
	fclose(fp);

	fp = fopen("results.txt", "a");
	puts(" (Wow! Deja vu!)\n", fp);
	fclose(fp);

	fp = fopen("results.txt", "r");
	while ((x = getc(fp)) != EOF)
		if (x != '\0')
			putchar(x);
	fclose(fp);
	fflush(stdout);

	// Get out of Dodge City, Kansas returning the running time in ticks
	return (unsigned)(clock() - start);
}