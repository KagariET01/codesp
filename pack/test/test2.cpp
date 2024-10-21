#include<vector>
#include<future>
#include<iostream>
namespace ET01{
	template<typename T,typename INT=long long int>class matrix{
		private:
			INT n,m;
			std::vector<std::vector<T>>a;
		public:
			matrix(){}
			matrix(INT n,INT m):n(n),m(m){
				a.resize(n,std::vector<T>(m));
			}
			matrix(std::vector<std::vector<T>>a):a(a){
				n=a.size();
				m=a[0].size();
			}
			T&operator[](std::pair<INT,INT>p){
				return a[p.first][p.second];
			}
			std::vector<T>&operator[](INT x){
				return a[x];
			}
			std::vector<std::vector<T>>&operator()(){
				return a;
			}
			typename std::vector<std::vector<T>>::iterator begin(){
				return a.begin();
			}
			typename std::vector<std::vector<T>>::iterator end(){
				return a.end();
			}
			typename std::vector<std::vector<T>>::const_iterator begin() const{
				return a.cbegin();
			}
			typename std::vector<std::vector<T>>::const_iterator end() const{
				return a.cend();
			}
			typename std::vector<std::vector<T>>::const_iterator cbegin(){
				return a.cbegin();
			}
			typename std::vector<std::vector<T>>::const_iterator cend(){
				return a.cend();
			}
			typename std::vector<std::vector<T>>::reverse_iterator rbegin(){
				return a.rbegin();
			}
			typename std::vector<std::vector<T>>::reverse_iterator rend(){
				return a.rend();
			}
			typename std::vector<std::vector<T>>::const_reverse_iterator rbegin() const{
				return a.crbegin();
			}
			typename std::vector<std::vector<T>>::const_reverse_iterator rend() const{
				return a.crend();
			}
			typename std::vector<std::vector<T>>::const_reverse_iterator crbegin(){
				return a.crbegin();
			}
			typename std::vector<std::vector<T>>::const_reverse_iterator crend(){
				return a.crend();
			}
			bool empty(){
				return a.empty();
			}
			void resize(INT n,INT m){
				this->n=n;
				this->m=m;
				a.resize(n,std::vector<T>(m));
			}
			void resize(std::pair<INT,INT>p){
				resize(p.first,p.second);
			}
			std::pair<INT,INT>size(){
				return std::pair<INT,INT>(n,m);
			}
			void clear(){
				a.clear();
				n=m=0;
			}
			void add_fast(matrix&a,matrix&b,std::vector<T>&re,INT row){
				INT tm=a.size().second;
				for(INT j=0;j<tm;j++)re[j]=a[row][j]+b[row][j];
				// std::cout<<row<<" ";
				return;
			}
			matrix operator+(matrix b){
				if(b.size()!=size())throw("ET01::matrix::operator+(): 不同大小的矩阵無法相加");
				matrix c(n,m);
				for(INT i=0;i<n;i++){
					this->add_fast(*this,b,c[i],i);
					// std::cout<<"i:"<<i<<" c:"<<std::endl;
					// std::cout<<c<<std::endl;
				}
				// std::cout<<"return"<<std::endl;
				return c;
			}
	};
	template<typename T,typename INT=long long int>std::istream&operator>>(std::istream&in,matrix<T,INT>&a){
		for(std::vector<T>&i:a)for(T&j:i)in>>j;
		return in;
	}
	template<typename T,typename INT=long long int>std::ostream&operator<<(std::ostream&out,const matrix<T,INT>&a){
		for(const std::vector<T>&i:a){
			for(const T&j:i)out<<j<<' ';
			out<<std::endl;
		}
		return out;
	}
};

#include<iostream>
#define INT long long int
using namespace std;
int main(){
	INT n,m;
	cin>>n>>m;
	ET01::matrix<INT> a(n,m),b(n,m);
	cin>>a>>b;
	cout<<"=========================="<<endl;
	cout<<(a+b);
}

