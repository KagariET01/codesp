# [`CF 1966 pE`](https://codeforces.com/contest/1966/problem/E) Folding Strip
## 標籤

## 題解
先想像有一個table，上面有一行、無限多格的格子  
編號為偶數的格子上面寫0，奇數的寫1  
它應該會長這樣  
```txt
╭──┬──┬──┬──┬──┬──┬──╥──┬──┬──┬──┬──┬──┬──┬──╮
│-7│-6│-5│-4│-3│-2│-1║ 0│ 1│ 2│ 3│ 4│ 5│ 6│ 7│
├──┼──┼──┼──┼──┼──┼──╫──┼──┼──┼──┼──┼──┼──┼──┤
│ 1│ 0│ 1│ 0│ 1│ 0│ 1║ 0│ 1│ 0│ 1│ 0│ 1│ 0│ 1│
╰──┴──┴──┴──┴──┴──┴──╨──┴──┴──┴──┴──┴──┴──┴──╯
```
編號允許負數  
接著，我們把輸入看成一張紙條，並把他立在格子0和-1之間（想像這張紙條和地面垂直）（如同上表雙線地方，將紙條立在那裡）  

> 如果第一個號碼是0，和第0格格子一樣，那我們就把第一個號碼貼在格子0上面  
> 當然，那張紙條也會被移到格子0和1之間  

> 如果第一個號碼是1，和第-1格格子一樣，那我們就把第一個號碼貼在格子-1上面  
> 當然，那張紙條也會被移到格子-2和-1之間

> 重複以上動作，目前要黏的紙條數字和哪個格子對應，就黏到該格子上

這個動作可以想像成正在黏膠帶，然後年到一半，剩餘的膠帶沒有貼到紙上  

最後，我們只需要看成品的長度，就可以得知答案


## 程式碼
```cpp


#include<bits/stdc++.h>
using namespace std;
#define INT long long int
#define superINT INT
#define read(n) reader<n>()
#define PII pair<INT,INT>
#define PPIIPII pair<PII,PII>
#define pit(n) #n<<":"<<n
#define MP(n,m) make_pair(n,m)
#define endl '\n'
#define F first
#define S second
#define mins(a,b) a=min(a,b)
#define maxs(a,b) a=max(a,b)

template<typename T>auto(reader)=[](){T(re);return(cin>>re,re);};

//PII
template<typename T1,typename T2>pair<T1,T2>operator+(pair<T1,T2>a,pair<T1,T2>b){
	return pair<T1,T2>(a.F+b.F,a.S+b.S);
}
template<typename T1,typename T2>pair<T1,T2>operator+=(pair<T1,T2>&a,pair<T1,T2>b){
	return a=a+b;
}
template<typename T1,typename T2>pair<T1,T2>operator-(pair<T1,T2>a,pair<T1,T2>b){
	return pair<T1,T2>(a.F-b.F,a.S-b.S);
}
template<typename T1,typename T2>pair<T1,T2>operator-=(pair<T1,T2>&a,pair<T1,T2>b){
	return a=a-b;
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator*(pair<T1,T2>a,T3 b){
	return pair<T1,T2>(a.F*b,a.S*b);
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator*=(pair<T1,T2>&a,T3 b){
	return a=a*b;
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/(pair<T1,T2>a,T3 b){
	return pair<T1,T2>(a.F/b,a.S/b);
}
template<typename T1,typename T2,typename T3>pair<T1,T2>operator/=(pair<T1,T2>&a,T3 b){
	return a=a/b;
}

template<typename T1,typename T2>ostream&operator<<(ostream&ou,pair<T1,T2>p){
	return ou<<"["<<p.first<<","<<p.second<<"]";
}
template<typename T1,typename T2>istream&operator>>(istream&in,pair<T1,T2>&p){
	return in>>p.first>>p.second;
}

//deque
template<typename T1,typename T2>ostream&operator<<(ostream&ou,deque<T1,T2>&que){
	bool o=0;
	ou<<"[";
	for(T1(i):que){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"]");
}

//stack
template<typename T1,typename T2>ostream&operator<<(ostream&ou,stack<T1,T2>st){
	deque<T1>dq;
	while(!st.empty()){
		dq.push_front(st.top());
		st.pop();
	}
	return(ou<<dq);
}

//queue
template<typename T1,typename T2>ostream&operator<<(ostream&ou,queue<T1,T2>que){
	bool o=0;
	ou<<"[";
	while(!que.empty()){
		if(o)ou<<",";
		ou<<que.front();
		o=1;
		que.pop();
	}
	return(ou<<"]");
}

//priority_queue
template<typename T1,typename T2,typename T3>ostream&operator<<(ostream&ou,priority_queue<T1,T2,T3>pq){
	deque<T1>dq;
	while(!pq.empty()){
		dq.push_front(pq.top());
		pq.pop();
	}
	return(ou<<dq);
}

//vector
template<typename T>istream&operator>>(istream&in,vector<T>&vec){
	for(T&i:vec)in>>i;
	return in;
}
template<typename T>ostream&operator<<(ostream&ou,vector<T>vec){
	bool o=0;
	ou<<"[";
	for(T(i):vec){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return(ou<<"]");
}

//array
template<typename T,std::size_t N>ostream&operator<<(ostream&ou,array<T,N>&a){
	bool o=0;
	ou<<"[";
	for(T&i:a){
		if(o)ou<<",";
		ou<<i;
		o=1;
	}
	return ou<<"]";
}
template<typename T,std::size_t N>istream&operator>>(istream&in,array<T,N>&a){
	for(T&i:a)in>>i;
	return in;
}

//list
template<typename T,std::size_t N>istream&operator>>(istream&in,T(&a)[N]){
	for(T&i:a)in>>i;
	return in;
}



//map
template<typename T1,typename T2>ostream&operator<<(ostream&ou,map<T1,T2>mp){
	bool o=0;
	ou<<"{";
	for(pair<T1,T2>i:mp){
		if(o)ou<<",";
		ou<<i.first<<":"<<i.second;
		o=1;
	}
	return(ou<<"}");
}

//io
template<typename T>ostream&operator>>(ostream&ou,T a){
	return ou<<a;
}
template<typename T>istream&operator<<(istream&in,T a){
	return in>>a;
}









#define PBI pair<bool,INT>
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	INT t;
	cin>>t;
	while(t--){
		INT n;
		cin>>n;
		string str;
		cin>>str;
		INT mn=0,mx=0,cnt=0;
		for(char c:str){
			if(abs(cnt%2)==(c=='1')){
				cnt++;
			}else{
				cnt--;
			}
			mins(mn,cnt);
			maxs(mx,cnt);
		}
		cout<<(mx-mn)<<endl;
	}
	return 0;
}




```
