import time
import random

class SelectiveRepeat:
    def __init__(self, window_size, total_frames):
        self.window_size = window_size
        self.total_frames = total_frames
        self.sent_frames = [None] * total_frames  # None indicates frame has not been sent yet
        self.ack_received = [False] * total_frames  # False means ACK not received yet
        self.current_frame = 0  # Keeps track of the frame currently being processed

    def send_frame(self, frame_num):
        if self.sent_frames[frame_num] is None:  # If frame hasn't been sent yet
            print(f"Sending frame {frame_num}")
            self.sent_frames[frame_num] = True
            time.sleep(1)  # Simulate time for sending

    def receive_ack(self, frame_num):
        ack = random.choice([True, False])  # Simulate random ACK/NACK
        if ack:
            print(f"ACK received for frame {frame_num}")
            self.ack_received[frame_num] = True
        else:
            print(f"NACK for frame {frame_num}")

    def send_frames(self):
        while not all(self.ack_received):  # Keep sending until all ACKs are received
            # Send all frames in the window that have not been acknowledged
            for i in range(self.window_size):
                frame_num = (self.current_frame + i) % self.total_frames
                if not self.ack_received[frame_num]:
                    self.send_frame(frame_num)
            
            # Simulate receiving ACKs for sent frames
            for i in range(self.window_size):
                frame_num = (self.current_frame + i) % self.total_frames
                if not self.ack_received[frame_num]:
                    self.receive_ack(frame_num)

            # Move window forward by one frame
            self.current_frame = (self.current_frame + 1) % self.total_frames

if __name__ == "__main__":
    sr = SelectiveRepeat(window_size=4, total_frames=10)
    sr.send_frames()
