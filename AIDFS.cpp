#include <iostream>
#include <vector>
#include <queue>

using namespace std ;

class Graph {
    int v ;
    vector<vector<int>> adj ;

    public:

    Graph(int v){
        this->v= v ;
        adj.resize(v);

    };

    void addEdge (int v , int u ){
        adj[v].push_back(u);
        adj[u].push_back(v);
    };

    void DFSutils(int start , vector<bool>&visited){
        visited[start]= true ;
        cout <<start<<" ";
        
        for (int neib : adj[start]){
            if (!visited[neib]){
                visited[neib]=true ;
                DFSutils(neib , visited);
            }
        }
    }

    void DFS (int start){

        vector<bool> visited(v ,false);

        cout << "DFS of the given graph is :";
        DFSutils(start , visited);
        cout<< endl;


    }



    void BFS (int start ){
        queue<int> q;
        vector<bool> visited(v , false) ;

        cout << "BFS of the given graph is :";

        visited[start]=true ;
        q.push(start);

        while(!q.empty()){
            int f =q.front();
            q.pop();
            cout << f <<" ";

            for ( int neib : adj[f]){
                if(!visited[neib]){
                    visited[neib]= true ;
                    q.push(neib);

                }
            }

        }
        cout<<endl ;
    };


};

int main (){

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.DFS(0);
    g.BFS(0);
}