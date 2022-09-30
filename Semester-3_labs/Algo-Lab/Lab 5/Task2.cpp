#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Please enter the number of cupcakes: ";
	cin>>n;
	vector<int> v(n);
	cout<<"Respective calorie counts of each cupcake: ";
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v[i]=x;
	}
	sort(v.begin(),v.end(),greater<int>());
	cout<<"Marc should walk atleast : ";
	int result=0;
	int j=0;
	for (int i = 0; i < n; ++i)
	{
		result += (pow(2,j) * v[i]);
		j++;
	}
	cout<<result<<endl;
	cout<<"The order in which mark should eat : ";
	for(auto i: v){
		cout<<i<<" ";
 	}
 	cout<<endl;

}