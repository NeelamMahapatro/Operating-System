#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter length of reference string\n";
	cin>>n;
	cout<<"Enter string\n";
	int arr[n];
	vector<int> cache, temp;
	int it;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	for(int i=0; i<n; i++)
	{
		bool flag = true;
		temp = cache;
		for(int k=0; k<temp.size(); k++)
		{
			if(arr[i] == temp[k])
			{
				flag = false;
				it = k;
				cout<<"true";
				break;
			}
			
		}
		if(flag == true)
		{
			
			if(cache.size() < 3)
			{
				cache.push_back(arr[i]);
				
			}
			else
			{
				cache.erase(cache.begin());
				cache.push_back(arr[i]);
			}
			
		}
		else
		{
			cache.erase(cache.begin()+ it);	
			cache.push_back(arr[i]);
		}
		temp=cache;
		for(int k=0; k<temp.size(); k++)
		{
			cout<<temp[k]<<" ";
		}
		cout<<endl;
	}
return 0;
}
