#Restoring Divison of Unsigned Numbers

# Function to compute the two's complement of a binary number
def twosComplement(num):
    onesComp = ""
    # Invert each bit in the binary number
    for i in num:
        if i == "0":
            onesComp += "1"
        else:
            onesComp += "0"
    # Add 1 to the inverted binary number to get the two's complement
    return bin(int(onesComp, 2) + int("1", 2)).replace('0b', "")

# Taking input for the dividend and divisor
num1 = int(input('Enter dividend: '))
num2 = int(input('Enter divisor: '))

# Convert the absolute values of the numbers to binary and remove the '0b' prefix
binNum1 = bin(abs(num1)).replace("0b", '')
binNum2 = bin(abs(num2)).replace("0b", '')

# Determine the maximum length of the binary numbers
maxlen = max(len(binNum1), len(binNum2))

# Fill the binary numbers with leading zeros to make them of equal length
binNum1 = binNum1.zfill(maxlen)
binNum2 = binNum2.zfill(maxlen + 1)

# Calculate the two's complement of the divisor
binCompNum2 = twosComplement(binNum2)
binCompNum2 = binCompNum2.zfill(maxlen)

# Initialize variables for the algorithm
count = maxlen
m = binNum2
minusm = binCompNum2
q = binNum1
a = "0"
a = a.zfill(maxlen + 1)
leftshift = ""

# Print the table header
print("Count" + " " * maxlen + "A" + " " * maxlen + "Q" + " " * (maxlen + 1) + "M" + " " * (maxlen + 1) +
      "M2" + " " * (maxlen + 1) + "A+M2" + " " * (maxlen + 1) + "Left Shift")

# Main loop for the division algorithm
while count > 0:
    # Merge A and Q for left-shifting
    merged = a + q
    leftshift = merged[1:]
    a = leftshift[:maxlen + 1]

    # Subtract M or -M from A based on the first bit of A
    a = bin(int(a, 2) + int(minusm, 2)).replace("0b", "")
    if len(a) > maxlen + 1:
        a = a[1:]
    a = a.zfill(maxlen + 1)

    # Determine the next bit of Q and update A and Q
    if a[0] == "0":
        leftshift = a + q[1:]
        leftshift += "1"
    else:
        a = bin(int(a, 2) + int(m, 2)).replace("0b", "")
        if len(a) > maxlen + 1:
            a = a[1:]
        a = a.zfill(maxlen + 1)
        leftshift = a + q[1:]
        leftshift += "0"

    a = leftshift[:maxlen + 1]
    q = leftshift[maxlen + 1:]
    count -= 1

    # Calculate M2 and A+M2
    M2 = twosComplement(m).zfill(maxlen + 1)
    AM2 = bin(int(a, 2) + int(M2, 2)).replace("0b", "").zfill(maxlen + 1)

    # Print the current state of the algorithm
    print(str(count) + " " * maxlen + a + " " * maxlen + q + " " * (maxlen + 1) + m + " " * (
            maxlen + 1) + binCompNum2 + " " * (maxlen + 1) + AM2 + " " * (maxlen + 1) + leftshift)

# If the final result is negative, add M to A
if a[0] == "1":
    a = bin(int(a, 2) + int(m, 2)).replace("0b", "")
    if len(a) > maxlen + 1:
        a = a[1:]

# Print the final result
print("\nResult:")
print("Quotient:", int(q, 2))
print("Remainder:", int(a, 2))