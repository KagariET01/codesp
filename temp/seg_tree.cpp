#include<functional>
#include<vector>
//#include<iostream>
//#include<sstream>


template<typename T,typename INT=int>struct itseg{
	//==========變數區===============
		struct node{
			T v;//值
			T addv;//懶標
			INT l=0,r=0;//左邊、右邊有多少點
			node *lc=NULL,*rc=NULL;//左子樹、右子樹
			node *up=NULL;
			bool subl=0,subr=0;//左、右子樹有沒有懶標
			bool haddv=0;
			node *gl(){//  建立新子節點
				if(lc==NULL){
					lc=new itseg<T,INT>::node;
				}
				lc->reset();
				lc->up=this;
				return lc;
			}
			node *gr(){//  建立新子節點
				if(rc==NULL){
					rc=new itseg<T,INT>::node;
				}
				rc->reset();
				lc->up=this;
				return rc;
			}
			void reset(){
				l=0,r=0,subl=0,subr=0,haddv=0;
			}
			INT size(){
				return std::max(l+r,(INT)1);
			}
			T &getv(){
				doland(merge,add);
				return v;
			}
		};
		//===operator===
		node *root=new node;
		std::function<T(T,T)> merge=[](T a,T b){//  計算函式
			return a+b;//  取和
		};
		std::function<T(T,INT)> add=[](T a,INT n){//  懶標合併到值
			return a*n;
		};
		T zero=0;
		INT size=0;
		#define pit(n) #n<<"="<<n<<" "
	
	//==========內部函數區============
	/*
		void DBG(node *now=NULL,INT lv=0){
			if(now==NULL)now=root;
			std::cout<<"<details open> <summary> <blockquote><table>";
			std::cout<<"<tr><td>v</td><td>"<<now->v<<"</td></tr>";
			std::cout<<"<tr><td>addv</td><td>"<<now->addv<<"</td></tr>";
			std::cout<<"<tr><td>l</td><td>"<<now->l<<"</td></tr>";
			std::cout<<"<tr><td>r</td><td>"<<now->r<<"</td></tr>";
			std::cout<<"<tr><td>subl</td><td>"<<(now->subl?"True":"False")<<"</td></tr>";
			std::cout<<"<tr><td>subr</td><td>"<<(now->subr?"True":"False")<<"</td></tr>";
			std::cout<<"<tr><td>haddv</td><td>"<<(now->haddv?"True":"False")<<"</td></tr>";
			std::cout<<"</table></blockquote></summary><table><tr>";
			if(now->l){std::cout<<"<td>";DBG(now->lc,lv+1);std::cout<<"</td>";}
			if(now->r){std::cout<<"<td>";DBG(now->rc,lv+1);std::cout<<"</td>";}
			std::cout<<"</tr></table></details>";
		}
	*/
		void DBG(){}
		node *landdown(node *now){//  將自己的懶標加入值
			if(now->haddv){
				now->v+=add(now->addv,now->size());
				if(now->l){now->lc->addv+=now->addv;now->lc->haddv=1;}
				if(now->r){now->rc->addv+=now->addv;now->rc->haddv=1;}
				now->addv=zero;
				now->haddv=0;
			}
			return now;
		}

		node *doland(node *now){//  將子樹、自己的懶標加入值
			if(now->subl){doland(now->lc);now->subl=0;}
			if(now->subr){doland(now->rc);now->subr=0;}
			if(now->l)now->v=merge(now->lc->v,now->rc->v);
			landdown(now);
			return now;
		}

		T build(const std::vector<T> &vec,INT l,INT r,node *now){
			//l,r:當前節點的左右邊界
			if(r-l==1){
				now->v=vec[l];
				now->l=now->r=0;
				now->lc=now->rc=NULL;
				return now->v;
			}
			now->l=(r-l)/2;
			now->r=(r-l)-(now->l);
			INT mid=now->l+l;

			now->gl();
			now->gr();
			now->v=merge(build(vec,l,mid,now->lc),build(vec,mid,r,now->rc));
			return now->v;
		}

		bool in(INT l1,INT r1,INT l2,INT r2){//兩區間有無交集
			return r1>l2&&r2>l1;
		}

		T getv(INT l,INT r,node *now,INT i){
			doland(now);
			if(r-l==1 && l==i){return doland(now)->v;}
			INT mid=l+now->l;
			bool hl=l<=i && i<mid;
			bool hr=mid<=i && i<r;
			if(hl){
				return getv(l,mid,now->lc,i);
			}else{
				return getv(mid,r,now->rc,i);
			}
		}
		
		T getv(INT l,INT r,node *now,INT fl,INT fr){
			doland(now);
			if(fl<=l && r<=fr){doland(now);return now->v;}
			INT mid=l+now->l;
			bool hl=l<fr && fl<mid;
			bool hr=mid<fr && fl<r;
			if(hl && hr){
				return merge(getv(l,mid,now->lc,fl,fr),getv(mid,r,now->rc,fl,fr));
			}else if(hl){
				return getv(l,mid,now->lc,fl,fr);
			}else if(hr){
				return getv(mid,r,now->rc,fl,fr);
			}else{
				return 0;
			}
		}

		void mdy(INT l,INT r,node *now,T v,INT i){
			doland(now);
			if((r-l)==1 && i==l){
				now->reset();
				now->v=v;
				return;
			}else if(r-l==1 || !(l<=i && i<r))return;
			INT mid=l+now->l;
			bool hl= l<=i && i<mid;
			bool hr= mid<=i && i<r;
			if(hl)mdy(l,mid,now->lc,v,i);
			if(hr)mdy(mid,r,now->rc,v,i);
			now->v=merge(now->lc->v,now->rc->v);
		}
		
		void mdy(INT l,INT r,node *now,T v,INT ld,INT rd){
			if(ld<=l && r<=rd){
				now->addv+=v;
				now->haddv=1;
				return;
			}else if(!in(ld,rd,l,r))return;
			INT mid=l+now->l;
			bool hl=in(ld,rd,l,mid);
			bool hr=in(ld,rd,mid,r);
			if(hl){mdy(l,mid,now->lc,v,ld,rd);now->subl=1;}
			if(hr){mdy(mid,r,now->rc,v,ld,rd);now->subr=1;}
		}

		void ist(INT l,INT r,node *now,T v,INT i){//  在位置i的左邊插入，也就是說插入後，itseg[i]=v
			doland(now);
			if((r-l)==1 && i==l){
				doland(now);
				now->l=1;
				now->r=1;
				now->gl();
				now->gr();
				now->lc->v=v;
				now->rc->v=now->v;
				now->v=merge(now->lc->v,now->rc->v);
				return;
			}else if(r-l==1 || !(l<=i && i<r))return;
			INT mid=l+now->l;
			bool hl= l<=i && i<mid;
			bool hr= mid<=i && i<r;
			if(hl){
				ist(l,mid,now->lc,v,i);
				now->l++;
			}else{
				ist(mid,r,now->rc,v,i);
				now->r++;
			}
			now->v=merge(doland(now->lc)->v,doland(now->rc)->v);
			return;
		}

		void ist(INT l,INT r,node *now,const std::vector<T> &v,INT i){//  在位置i的左邊插入，也就是說插入後，itseg[i]=v[0]
			doland(now);
			if(r-l==1 && l==i){
				doland(now)->v;
				now->l=v.size();
				now->r=1;
				now->gl();
				now->gr();
				now->rc->v=now->v;
				build(v,0,v.size(),now->lc);
				now->v=merge(now->lc->v,now->rc->v);
				return;
			}else if(r-l==1 || !(l<=i && i<r))return;
			INT mid=l+now->l;
			bool hl= l<=i && i<mid;
			bool hr= mid<=i && i<r;
			if(hl){
				ist(l,mid,now->lc,v,i);
				now->l+=v.size();
			}else{
				ist(mid,r,now->rc,v,i);
				now->r+=v.size();
			}
			now->v=merge(doland(now->lc)->v,doland(now->rc)->v);
		}

	//=================給使用者用的函數===============
		/*verify*/itseg(){//  初始化，沒指定初始值
			root->reset();
			root->l=root->r=0;
			root->lc=root->rc=NULL;
		}	

		/*verify*/itseg(const std::vector<T> &vec){//  初始化，初始值為一個vec
			root->reset();
			size=INT(vec.size());
			build(vec,0,size,root);
		}

		itseg(const std::vector<T> &vec,const std::function<T(T,T)> &merge_fn){//  初始化，初始值為一個vec，並自訂merge函式
			merge=merge_fn;
			root->reset();
			size=INT(vec.size());
			build(vec,0,size,root);
		}

		/*verify*/void rebuild(const std::vector<T> &vec){//  重新初始化
			root->reset();
			size=INT(vec.size());
			build(vec,0,size,root);
		}

		/*verify*/T operator[](INT i){//  查單值
			return getv(0,size,root,i);
		}

		/*verify*/T get(INT l,INT r){//  查區間op  l~r r那個值不計算
			return getv(0,size,root,l,r);
		}

		/*verify*/void modify(T v,INT i){//  單值修改
			mdy(0,size,root,v,i);
		}

		void modify(T v,INT l,INT r){//  區間修改
			mdy(0,size,root,v,l,r);
		}

		/*verify*/void insert(T v,INT i){//  插入
			ist(0,size,root,v,i);
			size++;
		}

		/*verify*/void insert(const std::vector<T> &vec,INT i){//  插入
			ist(0,size,root,vec,i);
			size+=vec.size();
		}

};

#include<iostream>

using namespace std;
int main(){
	// int a,b,c,d;
	// cin>>a>>b>>c>>d;
	// itseg<int,int> seg;
	// cout<<seg.in(a,b,c,d)<<"\n";
	vector<int> vec(15,0);
	itseg<int> seg;
	seg.rebuild(vec);

	for(int i=0;i<seg.size;i++){
		cout<<seg[i]<<",";
	}
	cout<<"\n";
	
	seg.modify(1,5,11);
	seg.modify(2,4,8);
	seg.modify(4,8,12);

	seg.DBG();

	for(int i=0;i<seg.size;i++){
		cout<<seg[i]<<",";
	}
	cout<<"\n";
	// cout<<"success";
	return 0;
}
