VPATH = ../:../../

test:test_allocator.o allocator.o
	g++ -o test test_allocator.o allocator.o

test_allocator.o:test_allocator.cpp allocator.cpp allcator.h
	g++ -c test_allocator.cpp allocator.cpp -o test_allocator

allocator.o:allocator.h allocator.h

.PHONY:clean

clean:
	rm -rf test test_allocator.o allocator.o