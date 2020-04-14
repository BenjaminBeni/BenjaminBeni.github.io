import math
numar = input("Introduceti un numar: ")

def citireprec():
    x = int(input("Precizitate (minim 2) = "))
    return x
precizitate = citireprec()
while precizitate < 2:
    print("Precizitatea sa fie minim 2!")
    precizitate = citireprec()
if numar[0] == '-':
    semn = '-'
    numar = numar[1:]
else:
    semn = ''
rest = ""
cat = ""
i = 0
while i < len(numar) and numar[i] != '.':
    cat += numar[i]
    i += 1
i += 1
while i < len(numar):
    rest += numar[i]
    i += 1
#print(cat, rest)
cat = cat.lower()
rest = rest.lower()

def truncate(f, precizitate):
    return str(math.floor(f * 10 ** precizitate) / 10 ** precizitate)

def labaza10(c,r, b1):
    #print(c)
    #print(r)
    if b1 == 10:
        if r == '':
            n2 = c
            rest2 = ''
        else:
            n2 = c + '.' + r
            rest2 = '0.' + r
        cat2 = c

    else:
        global precizitate
        p = len(c) - 1
        n2 = ""
        suma = 0
        for i in c:
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
            suma += x * b1**p
            p -= 1
            #print(suma)
        n2 = str(suma)
        cat2 = n2
        rest2 = ''
        if r != '':
            n2 += '.'
            suma = 0
            for i in r:
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
                suma += x * b1**p
                
                p -= 1
            #print(suma)
            suma = truncate(suma, precizitate)
            n2 += suma[suma.find('.') + 1:]
            rest2 = '0.' + suma[suma.find('.') + 1:]
        else:
            rest2 = r
        #print(n2, rest2)
    return n2,cat2,rest2

def labazaBX(c, r, b2):
    global precizitate
    cifhex = "0123456789abcdef"
    rez = ""
    if c.count('0') == len(c):
        rez = rez + '0'
    else:
        c = int(c)
        p = 1
        while c != 0:
                cif = c % b2
                if cif == 10:
                    x = 'a'
                elif cif == 11:
                    x = 'b'
                elif cif == 12:
                    x = 'c'
                elif cif == 13:
                    x = 'd'
                elif cif == 14:
                    x = 'e'
                elif cif == 15:
                    x = 'f'
                else:
                    x = str(cif)
                rez = x + rez
                c = c // b2
    #print(rez, r)
    if r != '':
            rez = rez + '.'
            x3 = 0
            #print(r, type(r))
            r = float(r)
            while x3 < precizitate:
                r = r * b2
                rez += cifhex[int(str(r)[0: str(r).find('.')])]
                if int(str(r)[0: str(r).find('.')]) > 0:
                    r = float('0.'+str(r)[str(r).find('.') + 1:])
                if str(r)[str(r).find('.') + 1:] == '0':
                    break
                x3 += 1
    return rez


minim = 0

for i in numar:
    if i != '.':
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
        if x > minim:
            minim = x

minim += 1
if minim == 1:
    minim = 2
print("Baza minima in care se poate afla numarul este : ", minim)

def baza1():
    b1 = int(input("Introduceti baza in care se afla numarul : "))
    return b1


b1 = baza1()
while b1 < minim:
    print("Baza introdusa este mai mica decat : ", minim)
    b1 = baza1()

def baza2():
    b2 = int(input("Introduceti baza in care vreti sa il transformati numarul : "))
    return b2

b2 = baza2()

numar2,cat,rest = labaza10(cat, rest, b1)
#print("Numarul in baza 10 este ", numar2)
#print(cat, rest)

if b2 != 10:
    numar2 = labazaBX(cat, rest, b2)
    #print(numar2)
"""if '.' in numar2:
    while numar2[-1] == '0' or numar2[-1] == '.':
        numar2 = numar2[:len(numar2)-1]"""

print("Numarul in baza ", b2, " este ",semn + numar2)
