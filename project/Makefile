CFLAGS := -g;
INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

%.o: %.c
all: gyroblock inputtest outputtest

gyroblock: main.o input.o output.o
	cc -o gyroblock input.o output.o main.o $(LDFLAGS)
main.o: main.c project.h
	cc -c main.c $(INCLUDE)
inputtest: inputtest.o input.o
	cc -o inputtest inputtest.o input.o $(LDFLAGS)
inputtest.o: inputtest.c
	cc -c inputtest.c $(INCLUDE)
outputtest: outputtest.o output.o
	cc -o outputtest outputtest.o output.o $(LDFLAGS)
outputtest.o: outputtest.c
	cc -c outputtest.c $(INCLUDE)
input.o: input.c project.h
	cc -c input.c $(INCLUDE)
output.o: output.c project.h
	cc -c output.c $(INCLUDE)
run:
	./gyroblock

clean:
	rm -rf *.o gyroblock inputtest outputtest
