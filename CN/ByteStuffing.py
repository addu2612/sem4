msg = input('Enter the message: ')
start = input('Enter the start string: ')
end = input('Enter the end string: ')
escape = input('Enter the escape character: ')

# Initialize output with the start flag
output = f'{start}'

# Iterate through the message for byte stuffing
for i in msg:
    if i == start or i == end or i == escape:
        # Add escape character before reserved characters
        output += f'{escape}{i}'
    else:
        output += i

# Append the end flag
output += f'{end}'
print(output)
