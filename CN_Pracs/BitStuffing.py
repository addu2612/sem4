# Get the input binary message from the user
msg = input("Enter the binary message: ")

output = ""
i = 0

# Iterate through the message
while i < len(msg):
    # Check for five consecutive '1's
    if msg[i:i+5] == '11111':
        # Add '0' after five consecutive '1's
        output += '111110'
        i += 5  # Move the pointer by 5
    else:
        # Add the current bit to the output
        output += msg[i]
        i += 1  # Move the pointer by 1

# Print the bit-stuffed output
print("Bit-stuffed message:", output)
