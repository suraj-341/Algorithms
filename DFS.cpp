#include<bits/stdc++.h>
using namespace std;

vector<int> lst[6];
bool visited[6];




void addEdge(int x,int y){
	lst[x].push_back(y);
	lst[y].push_back(x);
}

void dfs(int s)
{
	if(!visited[s])
	{
		visited[s]=true;
		cout<<s;
		for (auto u : lst[s])
		{
			dfs(u);

		}
		

	}
	else{
		return;
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

    

    dfs(4);


    //display(v);







  return 0;




	
}
