no_packets = int(input("No of packets: "))
output = ''
for i in range(no_packets) :
    msg = input("Enter the msg:")
    output = output + f'{len(msg)+1}{msg}'
print (output)