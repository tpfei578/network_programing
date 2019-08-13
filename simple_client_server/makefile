all:test_client test_server
.PHONY : all 

COMPILE_OPTS = -Wall -g
CC = g++

test_client : test_client.o 
	$(CC) $(COMPILE_OPTS) -o test_client test_client.o
test_client.o :

test_server : test_server.o readn.o 
	$(CC) $(COMPILE_OPTS) -o test_server test_server.o readn.o

test_server.o : 

readn.o : 

.PHONY : clean
clean : 
	-rm -f test_client test_server *.o