target = ytt
glade = glade/main.glade
compiler = gcc
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -g -O3 `pkg-config --cflags --libs gtk4`

all: $(target) $(glade)

$(target): main.c $(obj)
	$(compiler) $^ $(flags) -o $@

%.o: %.c
	$(compiler) -c $(flags) $^ -o $@

$(glade): glade/main3.glade
	gtk4-builder-tool simplify --3to4 $< > $@

clean:
	rm -rfv src/*.o $(target)
