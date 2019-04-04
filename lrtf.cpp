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
        	vect.push_back( make_pair(b, make_pair(i,a))); 
		visit[i]=tq;
  	}
 
   
       // sort(vect.begin(), vect.end()); 
	int time=0;
	bool flag = true;
	while(flag)
	{
		int count=0;
		int inner =1;
		sort(vect.begin(), vect.end()); 
		for(int i=n-1; i>=0; i--)
		{
			if(vect[i].first != 0 && time >= vect[i].second.second && inner==1)
			{
				
		
				time = time+1;
				vect[i].first = vect[i].first -1;			
				inner = 0;
				count++;
				cout<<"p"<<vect[i].second.first<<" ";
			}
		}
	if(count == 0)
		flag=false;
	
	}
cout<<endl;
    return 0; 
} 


