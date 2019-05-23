.PHONY:all
all:client server

client:clientPipe.c
	gcc -o $@ $^
server:serverPipe.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf client server mypipe
