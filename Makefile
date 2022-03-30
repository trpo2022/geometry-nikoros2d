CFLAGS = -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Wshadow -Wno-unused-parameter

all: bin/main

obj/src/main/testmain2.o: test/testmain2.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

obj/src/main/main_test2.o: test/main_test2.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

test2: obj/src/main/testmain2.o obj/src/main/main_test2.o
	gcc $(LDLAGS) -o $@ $^ -lm -o bin/tests2 

obj/src/main/testmain.o: test/testmain.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

obj/src/main/main_test.o: test/main_test.c
	gcc -c $(CCFLAGS) -o $@ $< -lm

test: obj/src/main/testmain.o obj/src/main/main_test.o
	gcc $(LDLAGS) -o $@ $^ -lm -o bin/tests 

bin/main: obj/src/main/main.o obj/src/libmake/libmake.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/main/main.o: src/main/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmake/libmake.a: obj/src/libmake/functions.o 
	ar rcs $@ $^

obj/src/libmake/functions.o: src/libmake/functions.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm


.PHONY: clean

clean:
	rm obj/src/libmake/*.a obj/src/libmake/*.o bin/main
