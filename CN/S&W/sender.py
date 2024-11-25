import socket
import time

def start_sender():
    sender_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sender_socket.connect(('localhost',5050))

    frame=0
    total_frames=5
    timeout_duration=2

    while frame<total_frames:
        print(f"Sending frame {frame}")
        sender_socket.sendall(str(frame).encode())
        sender_socket.settimeout(timeout_duration)

        try:
            ack=sender_socket.recv(1024).decode()
            if ack==f'ACK{frame}':
                print("ACK for frame",frame)
                frame+=1
            else:
                print("Unexpected ACK for frame",ack)
        except socket.timeout:
            print(f"Timeout for {frame}.Retransmitting")
            continue

    print("All frames sent successfully")
    sender_socket.close()

if __name__ == "__main__":
    start_sender()