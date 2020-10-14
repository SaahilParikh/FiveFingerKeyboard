import sys
import fileinput

def main():
    dic = {}
    char = 'a'
    for line in fileinput.input():
        f = open(line[:-1])
        while(char):
            char = f.read(1)
            dic[char] = dic.get(char, 0) + 1
        char = 'a'
    printdic(dic)
    return 0

def printdic(dic):
    dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)
    for item in dic:
        print(str(item) + '\t'+ str(item[1]))


if __name__ == "__main__":
    main()
