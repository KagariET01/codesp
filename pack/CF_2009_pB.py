print(*[(lambda x:x[:len(x)-1])("".join((lambda x:[str(x[len(x)-i-1])+" "for i in range(len(x))])([input().find('#')+1 for _ in range(int(input()))])))for _ in range(int(input()))],sep='\n')
