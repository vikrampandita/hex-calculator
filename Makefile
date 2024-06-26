hex: calc.c dec.c
	gcc calc.c -o hex
	gcc dec.c -o dec
clean:
	rm -rf hex dec
