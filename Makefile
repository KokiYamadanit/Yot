OBJS = main.o yatzy.o
OBJT = test_point.o yatzy.o

main: $(OBJS)
	gcc $(OBJS) -o main

%.o: %.c
	gcc -c $< -o $@

test: $(OBJT)
	gcc $(OBJT) -o test_point

%.o: %.c
	gcc -c $< -o $@

.PHONY: all clean
all: main test

clean:
	rm -f main $(OBJS)
	rm -f main $(OBJT)