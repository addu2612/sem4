def xorbit(divisor, dividend):
    """Perform XOR operation for CRC."""
    x = ''
    if dividend[0] == '1':
        for i in range(len(divisor)):
            x += str((int(divisor[i]) + int(dividend[i])) % 2)
    else:
        x = dividend
    return x[1:]

choice = int(input("Enter (1/2)\n1. Data to Transmit\n2. Error Detection\n: "))

if not (choice == 1 or choice == 2):
    print("Invalid input. Please enter 1 or 2.")
else:
    old_data = input("Enter data: ")
    divisor = input("Enter divisor: ")

    len_divisor = len(divisor)
    data = old_data + '0' * (len_divisor - 1)  # Append n-1 zeros to the data
    len_data = len(data)

    # Perform CRC division
    dividend = data[:len_divisor]
    i = len_divisor
    while i < len_data:
        prod = xorbit(divisor=divisor, dividend=dividend)
        dividend = prod + data[i]
        i += 1
    else:
        remainder = xorbit(divisor=divisor, dividend=dividend)

    # Choice 1: Data Transmission
    if choice == 1:
        print(f"The Data Transmitted: {old_data}{remainder}")

    # Choice 2: Error Detection
    elif choice == 2:
        remainder = int(remainder)
        if remainder:
            print(f"Error detected as the remainder is {remainder}.")
        else:
            print("No Error detected as the remainder is 0.")
