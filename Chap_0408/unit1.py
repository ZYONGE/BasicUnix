def readlist():
    nlist = []
    flag = True
    while flag:
        number = int(input("Enter a number: "))
        if number < 0:
            flag = False
        else:
            nlist.append(number)
    return nlist

print("unit:", __name__)
if __name__ == "__main__":
    print(readlist())

