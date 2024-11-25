choice = int(input('Enter \n1 : Code Generation \n2 : Error detection and correction \n : '))
if(choice == 1):
    data  = list(map(int, input("Enter a 4 digit data : ")))
    code_array = [data[0],data[1],data[2],0,data[3],0,0]
    code_array[7-1] = (code_array[7-7] + code_array[7-5] + code_array[7-3])%2
    code_array[7-2] = (code_array[7-7] + code_array[7-6] + code_array[7-3])%2
    code_array[7-4] = (code_array[7-7] + code_array[7-6] + code_array[7-5])%2
    code = ''
    for i in code_array:
        code += str(i)
    print(f'code : {code}')
elif(choice == 2):
    code = list(map(int, input("Enter a 7 digit code : ")))
    p4 = (code[7-7] + code[7-6] + code[7-5])%2
    p2 = (code[7-7] + code[7-6] + code[7-3])%2
    p1 = (code[7-7] + code[7-5] + code[7-3])%2
    p4 = (p4 + code[7-4])%2
    p2 = (p2 + code[7-2])%2
    p1 = (p1 + code[7-1])%2
    error = p4*4 + p2*2 + p1
    if(error == 0):
        print("\nNo error\n")
    else:
        print(f"\nError at : {error}\n")
        code[7-error] = (code[7-error] + 1)%2
        c = ''
        for i in code: 
            c += str(i)
        print(f"Corrected hamming code : {c}\n") 