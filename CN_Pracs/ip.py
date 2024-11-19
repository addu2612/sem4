ip = input("Enter IP Address: ")
f = int(ip.split('.')[0])


if 0 <= f <= 127:
    ipclass = 'A'
    subnet = "255.0.0.0"
elif 128 <= f <= 191:
    ipclass = 'B'
    subnet = "255.255.0.0"
elif 192 <= f <= 223:
    ipclass = 'C'
    subnet = "255.255.255.0"
elif 224 <= f <= 239:
    ipclass = 'D'
elif 240 <= f <= 255:
    ipclass = 'E'
else:
    print("Invalid IP address")

if ipclass == 'A' or ipclass == 'B' or ipclass == 'C':
    print("Class:", ipclass)
    print("Subnet mask:", subnet)
elif ipclass == 'D':
    print("Class:", ipclass)
    print("Reserved for Multicast")
elif ipclass == 'E':
    print("Class:", ipclass)
    print("Experimental purposes")

mask = subnet.split('.')
ip_add = ip.split('.')
subnet_address = ""
for i in range(len(mask)):
    a = int(mask[i])&int(ip_add[i])
    subnet_address += str(a) + '.'

print("Subnet Address: ",subnet_address)