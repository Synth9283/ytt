target = ytt
compiler = gcc
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -g -O3 `pkg-config --cflags --libs gtk+-3.0`

all: $(target)

$(target): main.c $(obj)
	$(compiler) $^ $(flags) -o $@

%.o: %.c
	$(compiler) -c $(flags) $^ -o $@

clean:
	rm -rfv src/*.o $(target)
