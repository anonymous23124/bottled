cc = gcc

dirs = src .

files = $(wildcard src/*.c)
objs  = $(notdir $(patsubst %.c,%.o,$(files)))

VPATH = $(dirs)

all: bottled

bottled: $(objs)
	gcc $+ -o $@

%.o: %.c
	gcc -c $<

test: bottled
	@./bottled 3 >/dev/null
	@echo Trivial test passed

install: bottled
	cp bottled /usr/local/sbin
	cp etc/xinetd /etc/xinetd.d/bottled
	echo "bottled	31337/tcp		# Bottle task daemon" >> /etc/services

clean:
	rm *.o bottled
