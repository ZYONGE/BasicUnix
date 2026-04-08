### FILE: unit2.py
def processList(nlist):
    nlist.sort()
    return nlist

if __name__ == "__main__":
    list = [1, 100, 50, 3]
    print (processList(list))