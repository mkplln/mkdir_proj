
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_TRIES	(26)

char pathName[255] = "/home/mp/mkdir_proj/";

char dirOptions[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
;

int main()
{
	int i = 0;

	int rv = -1;
	
	char testPathName[255] = "";

	/* Set umask to 0 and return the current umask to process_mask */
	mode_t process_mask = umask(0);

	printf("pathName=%s...\n", pathName);
	printf("testPathName=%s...\n", testPathName);

/*
	for (i = 0; i < MAX_TRIES; i++)
	{
		sprintf(testPathName, "%s%c", pathName, dirOptions[i]);
		printf("dirOptions[%d of %d]=%c - testPathName=%s...\n", i, MAX_TRIES, dirOptions[i], testPathName);
	}
*/

	sprintf(testPathName, "%s%c", pathName, dirOptions[i]);
	i++;

	printf("Test %d: path name: %s...\n", (i-1), testPathName);

	rv = mkdir(testPathName, S_IRWXU | S_IRWXG | S_IRWXO);

	while ((i < MAX_TRIES) && rv != 0)
	{	
		sprintf(testPathName, "%s%c", pathName, dirOptions[i]);
		i++;
		printf("Test %d: path name: %s...\n", (i-1), testPathName);
		rv = mkdir(testPathName, S_IRWXU | S_IRWXG | S_IRWXO);
	}

	if (i < MAX_TRIES)
	{
		printf("Directory created: %s...\n", testPathName);
	}
	else
	{
		printf("Directory creation unsuccessful...\n");
	}

	/* Restore umask to original value */
	umask(process_mask);
	
	printf("Done...\n");

	return 0;
}
