choice=int(input("Enter \n1:Code Gen\n2:Error Detection"))

if choice==1:
    data=list(map(int,input("Enter 5 digit data:")))

    if len(data)!=5:
        print("Error!")
    else:
        code_array=[0,0,data[0],0,data[1],data[2],data[3],0,data[4]]

        code_array[0]=(code_array[2]+code_array[4]+code_array[6]+code_array[8])%2
        code_array[1]=(code_array[2]+code_array[5+code_array[6]])%2
        code_array[3]=(code_array[4]+code_array[5]+code_array[6])%2
        code_array[7]=(code_array[8])%2

        code=''.join(str(i) for i in code_array)
        print(f'Hamming code :{code}')

elif choice==2:
    code_array=list(map(int,input("Enter 9 digit data:")))
    if len(code_array)!=9:
        print("Error!")
    else:

        p1=(code_array[0]+code_array[2]+code_array[4]+code_array[6]+code_array[8])%2
        p2=(code_array[1]+code_array[2]+code_array[5+code_array[6]])%2
        p4=(code_array[3]+code_array[4]+code_array[5]+code_array[6])%2
        p8=(code_array[7]+code_array[8])%2

        error=p8*8+p4*4+p2*2+p1

        if error==0:
            print("No error")
        else:
            print("Error detected at position",error)
            code_array[error-1]=(code_array[error-1]+1)%2
            corrected_code=''.join(str(i) for i in code_array)
            print("Corrected code:",corrected_code)
else:
    print("Invalid choice!")

