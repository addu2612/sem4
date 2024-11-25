import socket
import time
import random

def server():
    socket_server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    socket_server.bind(('localhost',12345))
    socket_server.listen(5)

    bucket_size=10
    overflow_rate=2
    current_size=0

    print("Server started")

    client_socket,addr=socket_server.accept()
    print(f"Connection from {addr}")

    try:
        while True:
            #recv packet

            data=client_socket.recv(1024).decode()
            if not data:
                break
            print("Received:{data}")

            if current_size<bucket_size:
                current_size+=1
                print(f"Packet added to bucket.Current Size{current_size}")
                client_socket.send("packet accepted".encode())
            else:
                print(f"Bucket overflowing")
                client_socket.send("packet dropped".encode())

            time.sleep(1/overflow_rate)

            if current_size>0:
                current_size-=1
                print(f"Packet processed.Current size: {current_size}")
    except KeyboardInterrupt:
        print("bye")
    
    finally:
        client_socket.close()
        socket_server.close()

if __name__ == "__main__":
    server()