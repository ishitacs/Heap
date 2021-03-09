 #include<bits/stdc++.h>
using namespace std;
#define node pair<int,pair<int,int>>

vector<int> merge(vector<vector<int>> arr, int k)
{ vector<int> result;
priority_queue<node, vector<node>,greater<node>> pq;
for(int i=0;i<k;i++)
{
	pq.push({arr[i][0],{i,0}});
}
while(!pq.empty())
{

	node front =pq.top();
	pq.pop();
	result.push_back(front.first);
	int x= front.second.first;
	int y= front.second.second;
	if(y+1<arr[x].size()) {pq.push({arr[x][y+1],{x,y+1}});}

}
return result;

}



int main() {
int k,n;
cin>>k>>n;
vector<vector<int>>arr(k,vector<int>(n));
for(int i=0;i<k;i++)
{
	for(int j=0;j<n;j++)
	{
		cin>>arr[i][j];
	}
}
vector<int> o= merge(arr,k);
for(auto i:o)
cout<<i<<" ";
	return 0;
}
