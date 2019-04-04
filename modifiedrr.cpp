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
	cout<<"Give time quantum\n";
	cin>>tq;
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
  
    // using modified sort()
    sort(vect.begin(), vect.end()); 
  	cout<<vect.size()<<endl;

	int time=0;
	bool flag = true;
	while(flag)
	{
		int count=0;
		for(int i=0; i<n; i++)
		{
			if(vect[i].second.second != 0)
			{
				int temp = visit[i];
				visit[i] = visit[i] *2;
				time = time + min(temp, vect[i].second.second);
				cout<<"p"<<vect[i].second.first<<" ";
				if(temp<= vect[i].second.second)
					vect[i].second.second = vect[i].second.second-temp;
				else
					vect[i].second.second = 0;
				count++;
			}
		}
	if(count == 0)
		flag=false;

	}
    return 0; 
} 


