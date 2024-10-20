print(*[(lambda x:abs(x[0]-x[1]))(list(map(int,input().split())))for i in range(int(input()))],sep='\n')

