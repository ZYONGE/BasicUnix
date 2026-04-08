def printList(nlist):
    for i in nlist:
        print("성적=", i)
    
print("unit:", __name__)
if __name__ == "__main__":
    list = [1, 100, 50, 3]
    printList(list)