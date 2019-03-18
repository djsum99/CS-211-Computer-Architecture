OUTPUT=first
CFLAGS=-Wall -Werror -fsanitize=address -std=c99

%: %.c %.h
	gcc $(CFLAGS) -o $@ $<

%: %.c
	gcc $(CFLAGS) -o $@ $< -g

all: $(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)
