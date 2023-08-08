OBJS = main.o yatzy.o

main: $(OBJS)
	gcc $(OBJS) -o main

%.o: %.c
	gcc -c $< -o $@


.PHONY: all clean
all: main
clean:
	rm -f main $(OBJS)