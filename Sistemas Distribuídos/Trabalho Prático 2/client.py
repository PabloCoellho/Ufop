import pickle
from random import randint, uniform
import sys
import threading
import socket
from utility import Types
from time import sleep


MAX_AC_TIME = 1
REQ_COMPLETED = True

def check_max_ac_time():
    pass

lock = threading.Lock()
def main(username):

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port = '127.0.1.1'
    try:
        client.connect((port, 8085))
    except Exception as e:
        return print(f'Houve problema na tentatia de conexao {e}')
    
    print(f'<{username}> foi conectado com sucesso')

    thread1 = threading.Thread(target=receiveMessage,args=[client])
    thread2 = threading.Thread(target=sendMessage,args=[client, username])

    thread1.start()
    thread2.start()

def receiveMessage(client):
    global REQ_COMPLETED
    global MAX_AC_TIME

    while True:
        try:
            content = client.recv(1024)
            [index, type, msg, username, is_my_req] = pickle.loads(content)

            if type == Types.FINISH and is_my_req:
                lock.acquire()
                REQ_COMPLETED=True
                lock.release()

            print(msg)
        except Exception as e:
            sleep(1)
            return
            print(f'erro no recebiment cliente {e}')


def sendMessage(client, username):
    global REQ_COMPLETED
    global MAX_AC_TIME
    i = 25 
    #i = randint(5, 10)
    sleep(1)
    j = 1
    while i > -1:

        try:
            if REQ_COMPLETED and i > 0:
                msg = f'{MAX_AC_TIME} => <{username}>: Fez um acquare'
                content = pickle.dumps([MAX_AC_TIME, Types.ACQUARE, msg, username]) #Types.ACQUARE, msg, username
                client.send(content)
                i-=1
                lock.acquire()
                sleep(uniform(0.5,2.5))
                REQ_COMPLETED=False
                MAX_AC_TIME+=1
                lock.release()
            else:
                if i==0:
                    break

        except Exception as e:
            print(f'erro no envio cliente {e}')
            return

        content = pickle.dumps([Types.NOTIFY, msg,username])

    lock.acquire()
    sleep(4)
    lock.release()
    client.send(content)
    #msg = f'O cliente <{username}> saiu'
    #print(msg)
    #client.close()
    return 

if __name__ == '__main__':
    usernmane = sys.argv[1]
    main(usernmane)