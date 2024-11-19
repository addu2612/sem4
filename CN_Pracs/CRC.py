def crc(diff):
    # Input data and divisor as lists of integers
    dividend = list(int(ch) for ch in list(input("Enter the data: ")))
    divisor = list(int(ch) for ch in list(input("Enter the divisor: ")))
    
    # Append zeros to the dividend if `diff` is 0
    if diff == 0:
        for i in range(len(divisor) - 1):
            dividend.append(0)
    
    remainder = []  # Temporary list to hold the remainder
    lst = dividend[0:len(divisor)]  # Initial part of the dividend
    
    # Perform binary division
    for i in range(len(dividend) - len(divisor) + 1):
        if lst[0] == 1:
            comp = divisor  # Use the divisor if the first bit is 1
        else:
            comp = [0] * len(divisor)  # Use all 0s if the first bit is 0
        
        # XOR operation between `lst` and `comp`
        remainder = [(lst[c] ^ comp[c]) for c in range(len(divisor))]
        
        # Remove the first bit and append the next bit from the dividend
        lst = remainder[1:]
        if i != (len(dividend) - len(divisor)):
            lst.append(dividend[i + len(divisor)])
    
    # Return the final remainder and dividend
    return lst, dividend


# Main flow of the program
print("For initial data: ")
l, d = crc(0)  # Compute CRC for the initial data
rem = "".join(map(str, l))
print("Remainder: ", rem)

# Combine data with CRC remainder to form encoded data
enc_data = d[:len(d) - len(l)] + l
print("Encoded data: ", "".join(map(str, enc_data)))

print("For transmitted data: ")
l2, d2 = crc(1)  # Compute CRC for transmitted data
rem2 = int("".join(map(str, l2)))
print("Remainder: ", rem2)

# Check for transmission errors
if rem2 != 0:
    print("Error in transmission")
else:
    print("No error")
