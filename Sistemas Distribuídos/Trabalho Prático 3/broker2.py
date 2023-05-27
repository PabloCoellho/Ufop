import socket
import threading
import time

host = "127.0.0.1"
port = 8081
port2 = 8082
port3 = 8083
port4 = 8080

results = []

def main():
    print("[STARTING] Server 2 is starting...")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        server.bind((host, port))
        server.listen()
        print(f"[LISTENING] Server 2 Server listening on port {port}")
    except:
        return print("[ERROR 00] Connection problem. Couldn't initialize Server 2!")

    connected = True
    while connected:
        conn, addr = server.accept()
        
        name = conn.recv(1024).decode("utf-8")
        time.sleep(0.5)
        if(name == "backup"):
            try: 
                thread = threading.Thread(target=handle_backup, args=(conn, addr))
                thread.start()
            except:
                print("[ERROR] Couldn't connect with backup server")
    
        else:
            try:
                thread = threading.Thread(target=handle_client, args=(conn, name))
                thread.start()
            except:
                return print("[ERROR 01] Connection problem")

    server.close()

def handle_closing(conn, name):
    print(f"[CLOSING CONNECTION] {name} has finished its job")
    conn.close()

def handle_client(conn, name):
    
    print(f"[NEW CONNECTION] {name} connected")

    client2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client3 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:        
        client2.connect((host, port2))
        
    except:
        print("Não foi possível conectar com o Server 3")
    try:        
        client3.connect((host, port3))
        
    except:
        print("Não foi possível conectar com o Server 4")

    time.sleep(0.5)
    is_server3_banned = 0
    is_server4_banned = 0

    connected = 30
    while connected > 0:

        # Checando se o cliente caiu
        try:
            confirm_client = "connected?"
            conn.send(confirm_client.encode("utf-8"))
            time.sleep(0.5)

            confirm_client = conn.recv(1024).decode("utf-8")
            time.sleep(0.5)
        
        except:
            print("[ERROR 03] Couldn't connect with client")
            print("Finishing client")
            break 
          
        if confirm_client == "ok":
            
            # Recebendo data do cliente
            try:
                numbers = conn.recv(1024).decode("utf-8")
                time.sleep(0.5)
            except:
                print("[ERROR 02] Couldn't receive data")
                print("Trying to connect to client...")

            try:
                confirm_client = "connected?"
                conn.send(confirm_client.encode("utf-8"))
                time.sleep(0.5)
                
                confirm_client = conn.recv(1024).decode("utf-8")
                time.sleep(0.5)
            except:
                print("[ERROR 03] Couldn't connect with client")
                print("Finishing client")
                break 

            result_main_server = int(numbers[0]) + int(numbers[1])

            # ele vai mandar os números pros outros servidores
            # Checando broker 3

            if is_server3_banned == 0:
                try:
                    client2.send(numbers.encode("utf-8"))
                    time.sleep(0.2)
                except:
                    print("[ERROR] Couldn't send numbers to server 3")

                result_server3 = 0
                try:
                    result_server3 = int(client2.recv(1024).decode("utf-8"))
                    time.sleep(0.2)
                except:
                    print("[ERROR] Couldn't receive answer from server 3")

            # Checando broker 4
            if is_server4_banned == 0:
                try:
                    client3.send(numbers.encode("utf-8"))
                    time.sleep(0.2)
                except:
                    print("[ERROR] Couldn't send numbers to server 4")

                result_server4 = 0
                try:
                    result_server4 = int(client3.recv(1024).decode("utf-8"))
                    time.sleep(0.2)
                except:
                    print("[ERROR] Couldn't receive answer from server 4")


            # Bizantino and Blockchain
            final_result = result_main_server
            broken_broker = 0

            if is_server3_banned == 0 and is_server4_banned == 0:
                if result_main_server == result_server3:
                    final_result = result_main_server
                    if result_main_server != result_server4:
                        broken_broker = 4
                
                if result_main_server == result_server4:
                    final_result = result_main_server
                    if result_main_server != result_server3:
                        broken_broker = 3

                if result_server3 == result_server4 and result_server3 != result_main_server:
                    final_result = result_server3

                if result_main_server != result_server3 and result_main_server != result_server4:
                    final_result = "unreliable result"
                    broken_broker = 5

            elif is_server3_banned == 0 and is_server4_banned == 1 and result_main_server != result_server3:
                final_result = "unreliable result"
                broken_broker = 3                    
            
            elif is_server3_banned == 1 and is_server4_banned == 0 and result_main_server != result_server4:
                final_result = "unreliable result"
                broken_broker = 4

            if broken_broker != 0:
                if broken_broker == 3:
                    print("[UNRELIABLE SERVER] Shutting off server 3")
                    is_server3_banned = 1
                    client2.close()

                elif broken_broker == 4:
                    print("[UNRELIABLE SERVER] Shutting off server 4")
                    is_server4_banned = 1
                    client3.close()

                elif broken_broker == 5:
                    print("[UNRELIABLE SERVER] Shutting off server 3 and 4")
                    is_server3_banned = 1
                    is_server4_banned = 1
                    client2.close()
                    client3.close()


            try:
                print(f"{name}: {int(numbers[0])} + {int(numbers[1])} = {final_result}")
                msg_to_send = f"Result: {final_result}"
                
                conn.send(msg_to_send.encode("utf-8"))
                time.sleep(0.5)
                
            except:
                print("[ERROR 04] Couldn't connect with client")
                break 
        else:
            print("Não entrou no confirm_client")

        connected -= 1
    
    handle_closing(conn, name)
    
def handle_backup(conn, addr):
    connected = 5

    while connected > 0:
        try:            
            variavel = conn.recv(1024).decode("utf-8")
            time.sleep(0.5)
        except:
            print("[ERRO] Did not receive data from Server 1. Awaiting contact...")
            break

        print(f"[BACKUP] {variavel}")
        connected -= 1

if __name__ == "__main__":
    main()
