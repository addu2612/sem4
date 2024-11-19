def calculate_parity_bits(data_length):
    """Calculate the number of parity bits required for the given data length."""
    r = 0
    while (2 ** r) < (data_length + r + 1):
        r += 1
    return r


def generate_hamming_code(data):
    """Generate the Hamming code for the given data."""
    data = list(map(int, data))
    m = len(data)
    r = calculate_parity_bits(m)
    n = m + r  # Total length of the Hamming code

    # Initialize the Hamming code array with placeholders
    hamming_code = [None] * n
    data_index = 0

    # Place data and parity bits
    for i in range(1, n + 1):
        if (i & (i - 1)) == 0:  # Check if position is a power of 2
            hamming_code[i - 1] = 0  # Placeholder for parity bit
        else:
            hamming_code[i - 1] = data[data_index]
            data_index += 1

    # Calculate parity bits
    for p in range(r):
        parity_position = 2 ** p
        parity_sum = 0
        for i in range(1, n + 1):
            if i & parity_position == parity_position:  # Include positions in parity calculation
                parity_sum += hamming_code[i - 1]
        hamming_code[parity_position - 1] = parity_sum % 2

    return ''.join(map(str, hamming_code))


def detect_and_correct_hamming_code(received_code):
    """Detect and correct errors in the given Hamming code."""
    received_code = list(map(int, received_code))
    n = len(received_code)
    r = 0

    # Determine the number of parity bits
    while (2 ** r) < n:
        r += 1

    # Calculate parity bits
    error_position = 0
    for p in range(r):
        parity_position = 2 ** p
        parity_sum = 0
        for i in range(1, n + 1):
            if i & parity_position == parity_position:  # Include positions in parity calculation
                parity_sum += received_code[i - 1]
        if parity_sum % 2 != 0:
            error_position += parity_position

    if error_position == 0:
        print("\nNo error detected.\n")
    else:
        print(f"\nError detected at position: {error_position}\n")
        # Correct the error
        received_code[error_position - 1] = (received_code[error_position - 1] + 1) % 2
        print(f"Corrected Hamming code: {''.join(map(str, received_code))}\n")

    return ''.join(map(str, received_code))


# Menu for user choice
choice = int(input('Enter \n1 : Code Generation \n2 : Error detection and correction\n: '))

if choice == 1:
    data = input("Enter binary data (e.g., 1101): ")
    hamming_code = generate_hamming_code(data)
    print(f"Hamming code: {hamming_code}")

elif choice == 2:
    received_code = input("Enter received Hamming code (e.g., 0111001): ")
    corrected_code = detect_and_correct_hamming_code(received_code)
