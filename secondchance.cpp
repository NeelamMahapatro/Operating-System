#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter length of reference string\n";
	cin>>n;
	cout<<"Enter string\n";
	int arr[n];
	map<int, int>ref;
	
	for(int i=0; i<5; i++)
	{
		ref[i] = 0;	
	}
	int ptr =0;

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
			
			if(cache.size() < 5)
			{
				ref[cache.size()] =1;
				cache[cache.size()] = arr[i];
				ptr++;				
			}
			else
			{
				if(ref[ptr] == 0)
				{
					cache[ptr] = arr[i];
					ref[ptr]=1;
					ptr++;
				}
				else
				{
					bool found = false;
					int r;
					for(int l=0; l<5; l++)
					{
						if(ref[l] == 0)
						{
							r = l;
							found = true;
						}
					}
					if(found == false)
					{
						cache[ptr] = arr[i];
						ref[ptr] = 1;
						for(int l=ptr+1; l<5; l++)
						{
							ref[l] = 0;
						}
						ptr = 0;
					}
					else
					{
						for(int l=ptr; l<r; l++)
							ref[l] = 0;
						ptr = r+1;
					}	
				}
				if(ptr == 5)
					ptr = 0;	
			}
			
		}
		else
		{
			ref[it] = 1;
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
