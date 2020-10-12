#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class Graph{
	unordered_map<T, list<pair<T,int> > > m;
public:
	void addEdge(T u,T v,int dist,bool bidr=true )
	{
		m[u].push_back(make_pair(v,dist));
		if(bidr)
		{
			m[v].push_back(make_pair(u,dist));
		}

	}
	void printedge()
	{
		for (auto j: m){

			cout<<j.first<<"-->";

			for (auto l:j.second){

				cout<<"("<<l.first<<","<<l.second<<")";
			}
			cout<<endl; 
		}

	}
	void dijkatras(T src){
		unordered_map<T,int> dist;
		for (auto j:m){
			dist[j.first]=INT_MAX;

		}
		set<pair<int,T>> s;
		dist[src]=0;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto p=*(s.begin());
			T node =p.second;
			int nodedist=p.first;
			s.erase(s.begin());

			//Now iterate over every child node of current node
			for (auto childpair:m[node]){
				if(nodedist+childpair.second<dist[childpair.first]){

					 T dest=childpair.first;
					 auto f=s.find(make_pair(dist[dest],dest));
					 if(f!=s.end()){
					 	s.erase(f);
					 }

				//insert nwe paie with update value
					 dist[dest]=nodedist+childpair.second;
					 s.insert(make_pair(dist[dest],dest));



				}

			}


			
		}
		for (auto d:dist){
			cout<<d.first<<" is located at "<<d.second<<endl;
		}


	}
};

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
	#endif

	 Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printedge();
    g.dijkatras(1);










}