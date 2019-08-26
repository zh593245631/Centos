FLAG = -std=c++11
.PHONY:all
all:server client

server:server.cc udp_server.hpp
	g++ $^ -o $@ $(FLAG)
client:client.cc udp_client.hpp
	g++ $^ -o $@ $(FLAG)
