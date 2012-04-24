#include <stdio.h>
#include <stdlib.h>

#define TYPE unsigned int

main(int argc, char **argv)
{
	TYPE data, i, j, k;
	char bits[9];

	bits[8] = 0;

	if (argc != 2) {
		printf("usage: hex [0x]ZZZZYYYY\n");
		return -1;
	}

	if (argv[1][0] == '0' && argv[1][1] == 'x') {
		sscanf(argv[1], "0x%x", &data);
	} else {
		sscanf(argv[1], "%x", &data);
	}

	printf("\n%ld = %#lx\n\n",
			data,
			data);

	i = 32;
	j = 0;
	k = 3;
	do {
		if ( (i!=32) && !(i%8)) {
			j = 0;
			printf("  0x%2x",(data & (0xff << (k*8))) >> (k*8));
			k--;
			printf("  %s", bits);
			printf("\n");
		}

		if (data & (1 << (i - 1))) {
			printf("%2d ", i - 1);
			bits[j++] = '1';
		} else {
			printf("-- ");
			bits[j++] = '0';
		}
		i--;
	} while (i > 0);
	printf("  0x%2x",(data & (0xff << (k*8))) >> (k*8), k);
	printf("  %s", bits);
	printf("\n\n");
}
