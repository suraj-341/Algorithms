#include<bits/stdc++.h>
using namespace std;

vector<int> lst[6];
bool visited[6];
queue<int>q;




void addEdge(int x,int y){
	lst[x].push_back(y);
	lst[y].push_back(x);
}

void bfs(int s)
{
	
	q.push(s);
	visited[s]=true;
	while(!q.empty())
	{
		int x=q.front();
		cout<<x;
		q.pop();
		for (auto u:lst[x])
		{
			if(!visited[u]){
				q.push(u);
				visited[u]=true;
			} 
				
			else
			{
			   continue;
			}

		}



	}

}











/* void display(int nodes){
	for (int i = 0; i < nodes; ++i)
	{ 	`
		cout<<"The head node is "<<i<<endl;
		for (auto x:lst[i])
		{
			cout<<"The nodes adjacent are "<<x<<endl;
		}
	}

}
*/





int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

// write your program from here-----/
    for ( int i=0; i<6 ;i++)
    {
	visited[i]=false;
    }

	int v=6 ;
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,5);
    addEdge(4,3);

    

    bfs(0);


    //display(v);







  return 0;




	
}
