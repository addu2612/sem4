# Server (Token Bucket)
import socket
import time
import threading

def server():
    # Create server socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 12345))
    server_socket.listen(5)
    
    # Token bucket parameters
    bucket_size = 10      # Maximum tokens
    token_rate = 2        # Tokens added per second
    current_tokens = bucket_size  # Start with full bucket
    
    def add_tokens():
        nonlocal current_tokens
        while True:
            time.sleep(1/token_rate)  # Wait according to token rate
            if current_tokens < bucket_size:
                current_tokens += 1
                print(f"Token added. Current tokens: {current_tokens}")
    
    # Start token generator thread
    token_thread = threading.Thread(target=add_tokens)
    token_thread.daemon = True
    token_thread.start()
    
    print("Server started. Waiting for connections...")
    
    client_socket, addr = server_socket.accept()
    print(f"Connection from {addr}")
    
    try:
        while True:
            # Receive packet
            data = client_socket.recv(1024).decode()
            if not data:
                break
                
            print(f"\nReceived: {data}")
            
            # Check if token is available
            if current_tokens > 0:
                current_tokens -= 1
                print(f"Token used. Remaining tokens: {current_tokens}")
                client_socket.send("Packet transmitted".encode())
            else:
                print("No tokens available! Packet dropped.")
                client_socket.send("Packet dropped".encode())
    
    except KeyboardInterrupt:
        print("\nServer shutting down...")
    finally:
        client_socket.close()
        server_socket.close()

if __name__ == "__main__":
    server()

