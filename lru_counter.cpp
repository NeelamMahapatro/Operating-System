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
	vector<int> counter;
	
	cout<<"Enter the string\n";
	for(int i=0; i<n; i++)
	{
		cin>>string[i];
	}
	
	int it, time=1;
	for(int i=0; i<n; i++)
	{
		bool flag = true;
		for(int j=0; j<cache.size(); j++)
		{
			if(cache[j] == string[i])
			{
				flag = false;
				it = j;
				break;
			}
		}
		if(flag == true)
		{
			int min=9999,itr;
			
			if(cache.size() < f)
			{
				cache.push_back(string[i]);
				counter.push_back(time);
			}
			else
			{
				for(int k=0; k<cache.size(); k++)
				{
					if(counter[k] < min)
					{
						min = counter[k];
						itr = k;	
					}
				}
				cache.erase(cache.begin() + itr);
				counter.erase(counter.begin() + itr);
				
				cache.push_back(string[i]);
				counter.push_back(time);
			}
		}
		if(flag == false)
		{
			counter[it] = time;		
		}
		
		time++;
		for(int k=0; k<cache.size(); k++)
		{
			cout<<cache[k]<<"("<<counter[k]<<")"<<"  ";
		
		}
		cout<<endl;
	}

return 0;
}
