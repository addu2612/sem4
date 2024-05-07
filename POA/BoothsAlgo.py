#Booth's Algorithm
# Function to convert a decimal number to a binary string with a specified number of bits
def conversion(a): 
    q = ""  # Initialize an empty string to store the binary representation
    current_n = len(a)  # Calculate the length of the input binary string
    temp = count - current_n  # Calculate the number of zero padding required
    if current_n != count:  # Check if padding is needed
        q = "0" * temp + a  # Add zero padding if necessary
    return q  # Return the binary string

# Function to add two binary numbers represented as strings
def add(x, y): 
    max_len = max(len(x), len(y))  # Find the maximum length of the two binary strings
    result = ''  # Initialize an empty string to store the result
    carry = 0  # Initialize the carry variable to 0
    for i in range(max_len - 1, -1, -1):  # Iterate over the binary strings from right to left
        r = carry  # Set the result to the current carry value
        if x[i] == '1':  # If the current bit of x is 1, add 1 to the result
            r += 1
        if y[i] == '1':  # If the current bit of y is 1, add 1 to the result
            r += 1 
        if r % 2 == 1:  # If the result modulo 2 is 1, set the current bit of the result to 1
            result = "1" + result 
        else: 
            result = "0" + result  # Otherwise, set the current bit of the result to 0
        if r < 2:  # If the result is less than 2, set the carry to 0
            carry = 0
        else: 
            carry = 1  # Otherwise, set the carry to 1
    return result  # Return the result

# Function to find the two's complement of a binary number
def twoc(a):
    l = list(a)  # Convert the binary string to a list of characters
    for i in range(len(l)):
        if l[i] == "1":
            l[i] = "0"  # If the current bit is 1, change it to 0
        else: 
            l[i] = "1"  # If the current bit is 0, change it to 1
    b = "0" * (len(l) - 1) + "1"  # Create a string representing the value 1 with the same length as the original binary string
    return add("".join(l), b)  # Add the original binary string and the string representing 1

# Function to perform a right shift operation on AC, Q, and Q1
def right_shift(ac, q, q1): 
    a = ac[0]  # Set the first bit of a to the first bit of AC
    for i in range(1, len(ac)):  # Iterate over the remaining bits of AC
        a += ac[i - 1]  # Append the previous bit of AC to a
    b = ac[-1]  # Set the first bit of b to the last bit of AC
    for j in range(1, len(q)):  # Iterate over the remaining bits of Q
        b += q[j - 1]  # Append the previous bit of Q to b
    c = q[-1]  # Set c to the last bit of Q
    return a, b, c  # Return the shifted values of AC, Q, and Q1

# Taking input and assigning values
x = int(input("Enter the multiplicand:"))  # Prompt the user to enter the multiplicand
y = int(input("Enter the multiplier:"))  # Prompt the user to enter the multiplier
a = bin(x).replace("0b", "")  # Convert the multiplicand to binary
b = bin(y).replace("0b", "")  # Convert the multiplier to binary
negative_a = 0  # Initialize a variable to track if the multiplicand is negative
negative_b = 0  # Initialize a variable to track if the multiplier is negative
if a[0] == "-":  # Check if the first bit of the multiplicand is negative
    a = a.replace("-", "")  # Remove the negative sign
    negative_a = 1  # Set the variable to indicate that the multiplicand is negative
if b[0] == "-":  # Check if the first bit of the multiplier is negative
    b = b.replace("-", "")  # Remove the negative sign
    negative_b = 1  # Set the variable to indicate that the multiplier is negative

if len(a) > len(b):  # Determine the length of the longer binary number
    count = len(a) + 1  # Set the count variable to the length of the longer binary number plus 1
else: 
    count = len(b) + 1  # Set the count variable to the length of the longer binary number plus 1
count1 = count  # Store the value of count in count1
firstP = conversion(a)  # Convert the positive representation of the multiplicand to binary
secondP = conversion(b)  # Convert the positive representation of the multiplier to binary
firstN = twoc(firstP)  # Calculate the two's complement of the positive multiplicand
secondN = twoc(secondP)  # Calculate the two's complement of the positive multiplier

# Booth's algorithm implementation
if negative_a == 0:  # Check if the multiplicand is positive
    M = firstP  # Set M to the positive representation of the multiplicand
    M2 = firstN  # Set M2 to the two's complement of the positive multiplicand
else: 
    M = firstN  # Set M to the two's complement of the positive multiplicand
    M2 = firstP  # Set M2 to the positive representation of the multiplicand
if negative_b == 0:  # Check if the multiplier is positive
    Q = secondP  # Set Q to the positive representation of the multiplier
else: 
    Q = secondN  # Set Q to the two's complement of the positive multiplier
AC = conversion("0")  # Set AC to the binary representation of 0
Q1 = "0"  # Initialize Q1 to 0
print("The table for the Booth's algorithm is as follow:")
print("Count" + " " * count1 + "AC" + " " * count1 + "Q" + " " * count1 + "Q1" + " " * count1 + "Operation")
print(str(count) + " " * count1 + AC + " " * count1 + Q + " " * count1 + Q1 + " " * count1 + "initial")
print("\n")

while (count>0):
    compare = Q[-1] + Q1
    if compare[0]==compare[-1]:
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "right shift" 
    elif compare =="10":
        AC = add(AC,M2)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC-M and right shift"
    elif compare == "01":
        AC = add(AC,M)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC+M and right shift"
    
    print(str(count) +" "*count1 + AC +" "*count1 + Q +" "*count1 + Q1 +" "*count1 + Op)
    print("\n")
    count = count-1
answer = AC+Q
if negative_a==negative_b:
    ans_d = str(int(answer,2))
else:
    ans_d = "-" + str(int(twoc(answer),2))

print("The product in binary is:" + answer)
print("Decimal conversion:" + ans_d)