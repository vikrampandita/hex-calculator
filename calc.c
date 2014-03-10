/*
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.

*/

#include <stdio.h>
#include <stdlib.h>

#define TYPE unsigned long

int main(int argc, char **argv)
{
	TYPE data, i, j, k;
	char bits[9];

	bits[8] = 0;

	if (argc != 2) {
		printf("usage: a.out 0xZZZZYYYY\n");
		return -1;
	}

	if (argv[1][0] == '0' && argv[1][1] == 'x')
		sscanf(argv[1], "0x%lx", &data);
	else
		sscanf(argv[1], "%lx", &data);
		//for dec:
		//sscanf(argv[1], "%lu", &data);

	printf("\n(%lu B) (%lu KB) (%lu MB) (%lu GB) = %#lx\n\n",
			data,
			data/(1024),
			data/(1024*1024),
			data/(1024*1024*1024),
			data);

	i = 64;
	j = 0;
	k = 7;
	do {
		if ( (i!=64) && !(i%8)) {
			j = 0;
			printf("  0x%2lx",
				((data & (((TYPE)0xff) << (k*8)))) >> (k*8)
				) ;
			k--;
			printf("  %s", bits);
			printf("\n");

			if (k==3)
				printf("\n");
		}

		if (data & (((TYPE)1) << (i - 1))) {
			printf("%2lu ", i - 1);
			bits[j++] = '1';
		} else {
			printf("-- ");
			bits[j++] = '0';
		}
		i--;
	} while (i > 0);
	printf("  0x%2lx",(data & (0xff << (k*8))) >> (k*8));
	printf("  %s", bits);
	printf("\n\n");
}
