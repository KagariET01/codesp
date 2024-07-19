t=int(input())
def superpow(a,b):
	if(a==0):
		return 0;
	if(b==0):
		return 1;
	re=1
	x=a
	while(b):
		if(b%2==1):
			re*=x
		x*=x
		b//=2
		b=int(b)
	return re
def fans(target,nw):
	if(target>1 and nw==1):
		return -1
	l=0
	r=target+1
	while(l<r):# 計算op次數
		# print("\t",l,r)
		mid=(r-l)//2+l
		mid=int(mid)
		if(not target<superpow(nw,1<<mid)):
			l=mid+1
		else:
			r=mid
	return l
for _ in range(t):
	n=int(input())
	a=list(map(int,input().split(' ')))
	# print("input completed")
	ans=0
	for i in range(n):
		if not i:
			continue
		# print("fansing",i)
		nw=fans(a[i-1],a[i])
		if(nw==-1):
			ans=-1
			break
		else:
			ans+=nw
			a[i]=superpow(a[i],1<<nw)
	print(ans)

