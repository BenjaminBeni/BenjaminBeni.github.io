class List:
    def __init__(self, node = None):
        self.head = node
        self.tail = node

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def printB(l):
    n = l.tail
    while n != None:
        print(n.data,'', end = '')
        n = n.prev
    print()

def lenl(l):
    n = l.head
    count = 0
    while n != None:
        count += 1
        n = n.next
    return count

def printl(l):
    if(l.head == None):
        print("List is empty")
    else:
        n = l.head
        while n:
            print(n.data,'', end='')
            n = n.next
    print()

def push(l, d):
    n = Node(d)
    if(l.head == None):
        l.head = n
        l.tail = n
    else:
        n.next = l.head
        l.head.prev = n
        l.head = n

def add(l, d):
    n = Node(d)
    if(l.head == None):
        l.head = n
        l.tail = n
    else:
        n.prev = l.tail
        l.tail.next = n
        l.tail = n

def insertl(l, d, poz):
    n = Node(d)
    if(poz < 0):
        print("Use a positive position")
    else:
        if l.head == None:
            l.head = n
            l.tail = n
        else:
            m = l.head
            count = 0
            if poz == 0:
                push(l, d)
            else:
                while m.next != None and count < poz:
                    m = m.next
                    count += 1
                if m.next == None:
                    n.prev = m
                    m.next = n
                    l.tail = n
                else:
                    n.prev = m
                    n.next = m.next
                    m.next.prev = n
                    m.next = n

def reml(l, poz):
    if lenl(l) == 0:
        print("List is empty")
    else:
        if poz == 0:
            l.head = l.head.next
            if l.head != None:
                l.head.prev = None
        elif poz >= lenl(l) - 1:
            l.tail = l.tail.prev
            if l.tail != None:
                l.tail.next = None
        else:
            n = l.head
            count = 0
            while n != None and count < poz:
                count += 1
                n = n.next
            
            n.prev.next = n.next
            n.next.prev = n.prev 

def searchS(l, d):
    if l.head == None:
        return -2
    else:
        n = l.head
        count = 0
        while n != None:
            if n.data == d:
                return count
            count += 1
            n = n.next
        return -1

def searchM(l, d, nr = None):
    array = []
    if l.head != None:
        n = l.head
        count = 0
        nrf = 0
        if nr == None:
            nr = lenl(l)
        while n != None and nrf <= nr:
            if n.data == d:
                array.append(count)
                nrf += 1
            count += 1
            n = n.next
        return array

def mergel(l, l2):
    if l2.head != None:
        n = l2.head
        while n != None:
            add(l, n.data)
            n = n.next

arr1 = [5,2,3,5,1]
arr2 = [4,8,6,9,7]
L1 = List()
L2 = List()
for i in arr1:
    add(L1, i)
for j in arr2:
    add(L2, j)

mergel(L1, L2)
printl(L1)

