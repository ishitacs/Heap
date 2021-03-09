#include <bits/stdc++.h>

using namespace std;

class heap{
vector<int>v; bool m;
bool comp(int a,int b)
{
    if(m) return a<b;
    return a>b;
}
void heapify(int idx)
{
    int left= 2*idx;
    int right= left+1;
    int minidx=idx;
    int last= v.size()-1;
    if(left<=last && comp(v[left],v[idx])) {minidx=left;}
    if(right<=last && comp(v[right],v[idx])){minidx=right;}
    if(minidx!=idx) {swap(v[idx],v[minidx]); heapify(minidx);}

}
public: heap(int s=10, bool type=true){ v.reserve(s); v.push_back(-1); m=type;}
void push(int d)
{
    v.push_back(d);
    int idx=v.size()-1;
    int p=idx/2;
    while(idx>1 && comp(v[idx],v[p]))
    {
        swap(v[idx],v[p]);
        idx=p;
        p=p/2;
    }
}

int top(){return v[1];}

void pop(){
int last=v.size()-1;
swap(v[1], v[last]);
v.pop_back();
heapify(1);
}
bool empty()
{
    return v.size()==1;
}
};

int main()
{
 heap h;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {int d;
     cin>>d;
     h.push(d);
 }
 while(!h.empty())
 {

     cout<<h.top()<<" ";
     h.pop();
 }
    return 0;
}
