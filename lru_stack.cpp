#include<bits/stdc++.h>

using namespace std;

int main()
{
	int f,n;
	cout<<"Enter number of frames\n";
	cin>>f;
	cout<<"Enter length of string\n";
	cin>>n;
	int string[n];
	vector<int> cache, temp;
	
	cout<<"Enter the string\n";
	for(int i=0; i<n; i++)
	{
		cin>>string[i];
	}
	
	int it;
	for(int i=0; i<n; i++)
	{
		bool flag=true;
		for(int j=0; j<cache.size(); j++)
		{
			if(cache[j] == string[i])
			{
				it = j;
				flag = false;
				break;
			}
		
		}
		if(flag == true)
		{
			if(cache.size() < f)
				cache.push_back(string[i]);
			else
			{
				cache.erase(cache.begin());
				cache.push_back(string[i]);
			
			}
		
		}
		if(flag == false)
		{
			cache.erase(cache.begin() + it);
			cache.push_back(string[i]);
		}
		temp = cache;
		for(int k=0; k<temp.size(); k++)
		{
			cout<<temp[k]<<" ";
		}
		cout<<endl;
	}

return 0;
}
