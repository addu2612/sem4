import socket
import time
import random

def client():
    client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client_socket.connect(('localhost',12345))

    try:
        packet_numnber=1
        while True:
            #send packet

            message=f"Packet{packet_numnber}"
            client_socket.send(message.encode())

            #recv packet

            response=client_socket.recv(1024).decode()
            print(f"Sent:{message}")
            print(f"Server response:{response}")

            packet_numnber+=1

            time.sleep(random.uniform(0.1,1))
        
    except KeyboardInterrupt:
        print("bye")
    
    finally:
        client_socket.close()

if __name__ == "__main__":
    client()