import socket
import threading
import time

host = "127.0.0.1"
port = 8082
port2 = 8080
port3 = 8081

def main():
    print("[STARTING] Server 3 is starting...")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        server.bind((host, port))
        server.listen()
        print(f"[LISTENING] Server 3 listening on port {port}")
    except:
        return print("[ERROR 00] Connection problem. Couldn't initialize Server 3!")

    connected = True
    while connected:
        conn, addr = server.accept()
 
        thread = threading.Thread(target=handle_security_operation, args=(conn, addr))
        thread.start()

        if KeyboardInterrupt:
            server.close()  # Libera a porta.
            break

    server.close()

def handle_security_operation(conn, addr):
    connected = 30
    while connected > 0:
        try:
            numbers = conn.recv(1024).decode("utf-8")
            time.sleep(0.2)
            result = int(numbers[0]) + int(numbers[1])
            print(f"[OPERATION] {numbers[0]} + {numbers[1]} = {result}")
        except:
            print("[ERROR 00] Couldn't connect with Server")
            print("Awaiting new connection...")
            time.sleep(1)
            main()

        try:
            conn.send(str(result).encode("utf-8"))
            time.sleep(0.2)
        except:
            print("[ERROR 01] Couldn't connect with Server")
            print("Awaiting new connection...")
            time.sleep(1)
            main()
        
        connected -= 1

if __name__ == "__main__":
    main()