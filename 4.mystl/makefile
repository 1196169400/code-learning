#vpath test_allocator.cpp ../
#vpath allocator.cpp ../../.
#vpath allocator.h ../../.
#vpath construct.h ../../.

test:test_allocator.o allocator.o
	g++ -o test test_allocator.o allocator.o

test_allocator.o:test_allocator.cpp allocator.cpp allocator.h
	g++ -c test_allocator.cpp allocator.cpp -o test_allocator.o

allocator.o:allocator.h construct.h

.PHONY:clean

clean:
	rm -rf test test_allocator.o allocator.o