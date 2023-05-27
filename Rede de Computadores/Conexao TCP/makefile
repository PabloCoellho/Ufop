output: server_.o client_.o
	gcc server_.o -o ./D/servidor_.exe
	gcc client_.o -o ./O/cliente_.exe
	rm *.o

server_.o: ./D/server_.c
	gcc -c ./D/server_.c

client_.o: ./O/client_.c
	gcc -c ./O/client_.c
	
s:
	./D/servidor_.exe

c:
	./O/cliente_.exe
	
rm:
	rm ./*/*.exe