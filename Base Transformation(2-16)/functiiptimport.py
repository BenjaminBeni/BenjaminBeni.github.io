def laMS(nr, s, n):
    ms = []
    for i in range(0, n):
        ms.append('0')
    poz = 0
    if s == '-':
        ms[0] = '1'
    for i in range(len(ms) - len(nr), len(ms)):
        ms[i] = nr[poz]
        poz += 1
    return ms

def laC1(nr, s, n):
    c1 = []
    for i in range(0, n):
        c1.append('0')
    poz = 0
    if s == '-':
        c1[0] = '1'
        for i in range(1, len(c1) - len(nr)):
            c1[i] = '1'
        for i in range(len(c1) - len(nr), len(c1)):
            if nr[poz] == '0':
                c1[i] = '1'
            else:
                c1[i] = '0'
            poz += 1
    else:
        for i in range(len(c1) - len(nr), len(c1)):
            c1[i] = nr[poz]
            poz += 1
    return c1

def laC2(l, s, n):
    c2 = []
    for i in range(0, n):
        c2.append('0')
    if s == '-':
        c2[0] = '1'
        l = l[::-1]
        for i in range(0, len(l) - 1):
            if l[i] == '1':
                l[i] = '0'
            else:
                l[i] = '1'
                break
        c2 = l[::-1]
        return c2
    return l

def labaza2(n):
    n = int(n)
    n2 = ""
    while n != 0 :
        n2 = str(n % 2) + n2
        n = n // 2
    return n2 

def labaza10(n, b1):
    p = len(n) - 1
    n2 = 0
    for i in n:
        if i == 'a':
            x = 10
        elif i == 'b':
            x = 11
        elif i == 'c':
            x = 12
        elif i == 'd':
            x = 13
        elif i == 'e':
            x = 14
        elif i == 'f':
            x = 15
        else:
            x = int(i)
        n2 += x * b1**p
        p -= 1
    n2 = str(n2)
    return n2

def adunareC1(c1, C1, s1, s2, n):
    c3 = []
    for i in range(0, n):
        c3.append('0')
    bit = 0
    for i in range(len(c1) - 1, -1, -1):
        if c1[i] == '1' and C1[i] == '1':
            if bit == 1:
                c3[i] = '1'
            else:
                c3[i] = '0'
                bit = 1
        elif c1[i] == '1' and C1[i] == '0':
            if bit == 1:
                c3[i] = '0'
            else:
                c3[i] = '1'
        elif c1[i] == '0' and C1[i] == '1':
            if bit == 1:
                c3[i] = '0'
            else:
                c3[i] = '1'
        
        elif c1[i] == '0' and C1[i] == '0':
                if bit == 1:
                    c3[i] = '1'
                else:
                    c3[i] = '0'
                bit = 0
    
    #print(bit)
    #print(c3)
    if bit == 1:
        for i in range(len(c3)-1, -1, -1):
            if c3[i] == '0':
                c3[i] = '1'
                break
            else:
                c3[i] = '0'
    return c3

def adunareC2(c2,C2,s1,s2, n):
    c3 = []
    for i in range(0, n):
        c3.append('0')
    bit = 0
    for i in range(len(c2) - 1, -1, -1):
        if c2[i] == '1' and C2[i] == '1':
            if bit == 1:
                c3[i] = '1'
            else:
                c3[i] = '0'
                bit = 1
        elif c2[i] == '1' and C2[i] == '0':
            if bit == 1:
                c3[i] = '0'
                bit = 1
            else:
                c3[i] = '1'
        elif c2[i] == '0' and C2[i] == '1':
            if bit == 1:
                c3[i] = '0'
                bit = 1
            else:
                c3[i] = '1'
        else:
            if c2[i] == '0' and C2[i] == '0':
                if bit == 1:
                    c3[i] = '1'
                else:
                    c3[i] = '0'
                bit = 0
    return c3

