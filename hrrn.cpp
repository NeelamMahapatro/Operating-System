#include<bits/stdc++.h>

using namespace std;
int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}
  
int main() 
{ 
    // Declaring vector of pairs 
    vector< pair <int,pair <int,int> > > vect; 
	map<int,int> visit;
  	int n,tq;
	cout<<"Enter number of process\n";
	cin>>n;
	
	cout<<"Give arrival and burst time\n";
    	for (int i=0; i<n; i++) 
	{
		int a,b;
		cin>>a>>b;
        	vect.push_back( make_pair(a, make_pair(i,b))); 
		visit[i]=tq;
  	}
 
    for (int i=0; i<n; i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " " 
            << vect[i].second.first <<" "<<vect[i].second.second << endl; 
    } 
  
	int time=0;
	bool flag = true;
	while(flag)
	{
		int count=0, pro, t;
		float max=0, priority;
		for(int i=0; i<n; i++)
		{
			if(vect[i].second.second != 0 && time >= vect[i].first)
			{
				priority = 1 + ((time- vect[i].first) / vect[i].second.second);
				if(priority > max)
				{
					max=priority;
					pro = i;
					t = vect[i].second.second;	
				}
				
				
				count++;
			}
		}
	if(count == 0)
		flag=false;
	else
	{
		cout<<"p"<<pro<<" ";
		time = time+ t;
		vect[pro].second.second = 0;
	}
	}
cout<<endl;
    return 0; 
} 


