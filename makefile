TITLE = “Cmpt201-22F A1 1.00 2022/9/10 Benjamin Kwon”
CFLAGS = -Wall -std=c89
CC = gcc

all:	monthofyear sameChars primepairs compress echoUpper

monthofyear: monthofyear.c
	echo $(TITLE)
	echo Compiling monthofyear.c
	$(CC) monthofyear.c -o monthofyear $(CFLAGS)

sameChars: sameChars.c
	echo $(TITLE)
	echo Compiling sameChars.c
	$(CC) sameChars.c -o sameChars $(CFLAGS)

primepairs: primepairs.c
	echo $(TITLE)
	echo Compiling primepairs.c
	$(CC) primepairs.c -o primepairs $(CFLAGS)

compress: compress.c
	echo $(TITLE)
	echo Compiling compress.c
	$(CC) compress.c -o compress $(CFLAGS) -g

echoUpper: echoUpper.c
	echo $(TITLE)
	echo Compiling echoUpper.c
	$(CC) echoUpper.c -o echoUpper $(CFLAGS)

tar: 
	tar -czf A1.tar.gz *.c makefile A1_tests

test:
	echo Testing monthofyear
	./monthofyear < moy_in.txt > moy_out.txt
	#diff moy_out.txt moy_correct.txt

	echo Testing sameChars
	./sameChars < sc1_in.txt > sc1_out.txt
	diff sc1_out.txt sc1_correct.txt
	./sameChars < sc2_in.txt > sc2_out.txt
	diff sc2_out.txt sc2_wrong.txt

	echo Testing primepairs
	./primepairs < pp_in.txt > pp_out.txt
	diff pp_out.txt pp_correct.txt

	echo Testing compress
	./compress < c_in.txt > c_out.txt
	diff c_out.txt c_correct.txt

	echo Testing echoUpper
	./echoUpper < eu_in.txt > eu_out.txt
	diff eu_out.txt eu_correct.txt
