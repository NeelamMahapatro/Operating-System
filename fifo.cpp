#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter length of reference string\n";
	cin>>n;
	cout<<"Enter string\n";
	int arr[n];
	queue<int> cache, temp;
	
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
			if(arr[i] == temp.front())
			{
				flag = false;
				break;
			}
			temp.pop();
			
		}
		if(flag == true)
		{
			
			if(cache.size() < 3)
			{
				cache.push(arr[i]);
				
			}
			else
			{
				cache.pop();
				cache.push(arr[i]);
			}
			
		}
		temp=cache;
		while (!temp.empty())
		  {
		    std::cout << ' ' << temp.front();
		    temp.pop();
		  }
		cout<<endl;
	}
return 0;
}
