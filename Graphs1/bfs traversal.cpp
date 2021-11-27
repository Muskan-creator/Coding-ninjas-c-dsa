#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue> 
using namespace std;

void printBFS(int **graph,int V,int sv,bool * visited){
   queue<int> pn; 
    
     pn.push(sv);
       visited[sv]=true;
    while(!pn.empty()){
        int current=pn.front();
        pn.pop();
        cout<<current<<" ";
        for(int i=0;i<V;i++){
            
            if(i==current){
                continue;
            }
            if(graph[current][i]==1 && !visited[i])
            { pn.push(i);
             visited[i]=true;
            }
        }
    }

  
}
void BFS(int ** graph,int V)
{
     bool * visited = new bool[V];
    for ( int i=0 ;i<V ;i++){
        visited[i]=false;}
    for(int i=0;i<V;i++){
        if(!visited[i]){
               printBFS(graph,V,i,visited);
        }
    }
    delete[]visited;
    
}

int main()
{
  int V, E;
  cin >> V >> E;
 
    int** graph = new int * [V];
    for( int i=0 ;i<V ;i++)
    {
        graph[i]= new int[V];
        for( int j=0 ;j<V ;j++)
            graph[i][j]=0;

    }
    for (int i=0 ;i<E ;i++)
    {
		int x ,y ;
        cin>>x>>y ;
        graph[x][y]=1;
        graph[y][x]=1;
    }
     BFS(graph,V);
 
   

for(int i=0 ;i<V ;i++)
{
    delete [] graph[i];
}
    delete [] graph;
    
 

}
