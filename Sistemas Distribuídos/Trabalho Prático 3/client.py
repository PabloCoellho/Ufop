import socket
import random
import sys
import time


host = "127.0.0.1"
port = 8080
port2 = 8081
port3 = 8082
port4 = 8083
port5 = 8084
name = sys.argv[1]
server = "main"

ports = [port, port2, port3, port4, port5]

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client.connect((host, port))
        print(f'[CONNECTED] {name} connected to Server 1')
        server = "SERVER 1"
    except:
        client.connect((host, port2))
        print(f'[CONNECTED] {name} connected to Server 2')
        server = "SERVER 2"

    msg = name
    client.send(msg.encode("utf-8"))
    time.sleep(2)

    counter = 30
    connected = True
    while connected:
        x = random.randint(0, 9)
        y = random.randint(0 ,9)

        msg = str(x) + str(y)

        # Confirmando para o server que estou on antes de começar a tarefa
        try:
            confirm_client = client.recv(1024).decode("utf-8")
            time.sleep(0.5)
        except:
            print("[ERROR 00] Can't connect with server")
            print("[RECONNECTING] Trying again")
        
        if confirm_client == "connected?":        
            confirm_client = "ok"
            try:
                client.send(confirm_client.encode("utf-8"))
                time.sleep(0.5)
            except:
                print("[ERROR 01] Can't connect with server")
                print("[RECONNECTING] Trying to change the server")
                main()

        

        try:
            client.send(msg.encode("utf-8"))
            time.sleep(0.5)
        except:
            print("[ERROR 02] Can't connect with server")            
            print("[RECONNECTING] Try to change the server")
            main()

        

        # Confirmando para o server que estou on durante o processo da tarefa
        try:
            confirm_client = client.recv(1024).decode("utf-8")
            time.sleep(0.5)
        except:
            print("[ERROR 03] Can't connect with server")
            print("[RECONECTING] Try to change the server")
            main()
        
        if confirm_client == "connected?":        
            confirm_client = "ok"
            
            try:
                client.send(confirm_client.encode("utf-8"))
                time.sleep(0.5)
            except:
                print("[ERROR 04] Couldn't connect with server 1")
            

        try:
            msg = client.recv(1024).decode("utf-8")
            time.sleep(0.5)
            print(f"[{server}] {msg}")
        except:
            print("[ERROR 05] Server didn't answered")
            
            print("[RECONNECTING] Try to change the server")
            main()

        counter -= 1
        if counter == 0:
            break

    client.close()

def connect_to_server():
    pass

if __name__ == "__main__":
    main()