
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
//定义顺序表
typedef struct{
	int item[10005],len;
}Seqlist; 
//初始化顺序表
void SeqlistInit(Seqlist* &L){
	L=(Seqlist*)malloc(sizeof(Seqlist));
	L->len=0;
} 
//创建顺序表
void SeqlistCreate(Seqlist* &L){
	int n,x;cin>>n;
	while(n--){
		cin>>x;
		L->item[L->len++]=x;
	} 
}
//查找数据 
void SeqlistFind(Seqlist* &L){
	int x,maxn=-1,minn=100005,Lmax,Lmin;
	for(int i=0;i<L->len;i++){
		if(L->item[i]>maxn){
			maxn=L->item[i];
			Lmax=i;
		}
		if(L->item[i]<minn){
			minn=L->item[i];
			Lmin=i;
		}
	}
	cout<<"Lmax="<<Lmax<<endl<<"Lmin="<<Lmin;
}
int main(){
	Seqlist *L;
	SeqlistInit(L);
	SeqlistCreate(L);
	SeqlistFind(L); 
	return 0;
}