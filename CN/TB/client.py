# Client (Packet Sender)
import socket
import time
import random

def client():
    # Create client socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))
    
    try:
        packet_number = 1
        while True:
            # Send packet
            message = f"Packet {packet_number}"
            client_socket.send(message.encode())
            
            # Receive response
            response = client_socket.recv(1024).decode()
            print(f"Sent: {message}")
            print(f"Server response: {response}\n")
            
            packet_number += 1
            
            # Random delay between packets (0.1 to 1 second)
            time.sleep(random.uniform(0.1, 1))
    
    except KeyboardInterrupt:
        print("\nClient shutting down...")
    finally:
        client_socket.close()

if __name__ == "__main__":
    client()