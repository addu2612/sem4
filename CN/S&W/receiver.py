import socket
import time

def start_recv():
    recv_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    recv_socket.bind(('localhost',5050))
    recv_socket.listen(1)

    print("Reciever is waiting for connection")

    connection,client_addr=recv_socket.accept()
    print("Receiver connected to",client_addr)

    try:
        expected_frame=0
        while True:
            data=connection.recv(1024).decode()
            if not data:
                break
            frame_no=int(data)
            print(f"Received frame number {frame_no}")
            if frame_no==expected_frame:
                print(f"Acknowledging frame {frame_no}")
                connection.sendall(f"ACK{frame_no}".encode())
                expected_frame+=1
            else:
                print("Frame out of order")
    finally:
        connection.close()


if __name__ == "__main__":
    start_recv()