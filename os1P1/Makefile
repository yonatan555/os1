CC=gcc
FLAG=-Wall
AR=ar
fPIC=-fPIC
Hello = hello_Ariel.o

all: main1_1 main1_2 main1_3

main1_1: main1_1.c hello_Ariel.c
	$(CC) $(FLAG) main1_1.c hello_Ariel.c -g -o main1_1

main1_2: main1_2.o hello_ariel.so
	$(CC) $(FLAG) -g -o main1_2 main1_2.o ./hello_ariel.so

main1_3: main1_3.c
	$(CC) $(FLAG) main1_3.c -ldl -o main_lib

hello_ariel.so: $(Hello)
	$(CC) -shared $(Hello) -o hello_ariel.so

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAG) $(fPIC) -g -c  hello_Ariel.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAG) -g -c main1_2.c

.PHONY: clean
clean:
	rm -f *.o *.a *.so main1_1 main1_2 hello_Ariel main_lib
