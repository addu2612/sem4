def add(x,y):
    max_len=max(len(x),len(y))
    result=""
    carry=0
    for i in range(max_len-1,-1,-1):
        r=carry
        if x[i]=="1":
            r+=1
        if y[i]=="1":
            r+=1
        if r%2 ==1:
            result="1"+result
        else:
            result="0"+result
        if r<2:
            carry=0
        else:
            carry=1
    return result

def twoc(num):
    l=list(num)
    for i in range(len(l)):
        if l[i]=="0":
            l[i]="1"
        else:
            l[i]="0"
    b="0"*(len(l)-1)+"1"
    return add("".join(l),b)

num1 = int(input('Enter dividend: '))
num2 = int(input('Enter divisor: '))

a=bin(num1).replace("0b","")
b=bin(num2).replace("0b","")

maxlen=max(len(a),len(b))

a=a.zfill(maxlen)
b=b.zfill(maxlen+1)

b2c=twoc(b)
b2c=b2c.zfill(maxlen)

count=maxlen
Mp=b
Mn=b2c
Q=a
AC="0"
AC=AC.zfill(maxlen+1)

leftshift=""

print("Count" + " " * maxlen + "M" + " " * (maxlen + 1) + "AC" + " " * (maxlen+1) + "Q" + " " * (maxlen) +
       "Operation")
print(str(count)+ " " * maxlen + Mp + " " * (maxlen + 1) + AC + " " * (maxlen+1) + Q + " " * (maxlen) +
       "Init.")


while count>0:
    merged =AC+Q
    leftshift=merged[1:]
    AC=leftshift[:maxlen+1]
    Op="LS AQ"

    AC=add(AC,Mn)
    if len(AC)>maxlen+1:
        AC=AC[1:]
    AC=AC.zfill(maxlen+1)

    if AC[0]=="0":
        leftshift=AC+Q[1:]
        leftshift+="1"
        Op="Q0=1"
    else:
        AC=add(AC,Mp)
        if(len(AC)>maxlen+1):
            AC=AC[1:]
        AC=AC.zfill(maxlen+1)
        leftshift=AC+Q[1:]
        leftshift+="0"
        Op="Q0=0 Restore AC"

    AC=leftshift[:maxlen+1]
    Q=leftshift[maxlen+1:]
    count=count-1

    print(str(count)+ " " * maxlen + Mp + " " * (maxlen + 1) + AC + " " * (maxlen+1) + Q + " " * (maxlen) +
       Op)
        
print("\nResult:")
print("Quotient:", int(Q, 2))
print("Remainder:", int(AC, 2))