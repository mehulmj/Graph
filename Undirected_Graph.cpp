#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> graph;
void addVertex()
{
  cout<<"Nodes before adding vertex: "<<graph.size()<<endl;
  graph.push_back({});
  cout<<"Nodes after adding vertex: "<<graph.size()<<endl;
}
void addEdge(int node1,int node2)
{
  if(node1+1>graph.size())
  {
    cout<<"Node you want to create edge from does not exist"<<endl;
    return;
  }
  else
  {
    if(node2+1>graph.size())
    {
      cout<<"Node you want to create edge to does not exist"<<endl;
      return;
    }
    else
    {
      graph[node1].push_back({node2});
      graph[node2].push_back({node1});
    }
  }
}
void print(int node)
{
  int i;
  for(int i=0;i<graph[node].size();i++)
  {
    cout<<node<<"-";
    cout<<graph[node][i]<<endl;
  }
  cout<<endl;
}
int find_next_node(int n,bool visited[])
{
    int i;
    int flag=0;
    for(i=0;i<graph[n].size();i++)
    {
      if(visited[graph[n][i]]==false)
      {
        flag=1;
        break;
      }
    }
    if(flag==0)
    return -1;
    return graph[n][i];
}
void dfs_traversal(int n,bool visited[graph.size()],vector<int> traverse_dfs)
{
  //cout<<"The value of the vertex is: "<<n<<endl;
  if(traverse_dfs.size()==0)
  return;
  else
  {
    int next;
    next=find_next_node(n,visited);
    if(next==-1)
    {
      traverse_dfs.pop_back();
      dfs_traversal(traverse_dfs[traverse_dfs.size()-1],visited,traverse_dfs);
      
    }
    else
    {
      cout<<next<<"->";
      visited[next]=true;
      traverse_dfs.push_back(next);
      dfs_traversal(next,visited,traverse_dfs);
    }
  }
}
void dfs(int n,bool visited[])
{
    vector<int> traverse_dfs;
    visited[n]=true;
    traverse_dfs.push_back(n);
    cout<<n<<"->";
    dfs_traversal(n,visited,traverse_dfs);
}
void bfs_traversal(int n,bool visited[],vector<int> traversal_bfs)
{
  if(traversal_bfs.size()==0)
  {
    return;
  }
  else
  {
    for(int i=0;i<graph[n].size();i++)
    {
      if(visited[graph[n][i]]==false)
      {
        cout<<graph[n][i]<<"->";
        traversal_bfs.push_back(graph[n][i]);
        visited[graph[n][i]]=true;
      }
    }
    traversal_bfs.erase(traversal_bfs.begin());
    if(traversal_bfs.size()!=0)
    {
      bfs_traversal(traversal_bfs[0],visited,traversal_bfs);
    }
  }
}
void bfs()
{
  int n;
  cout<<"Enter the node you want to start dfs from"<<endl;
  cin>>n;
  if(n>=graph.size())
  {
    cout<<"Enter a valid choice"<<endl;
    bfs();
    return;
  }
  else
  {
    bool visited[graph.size()];
    vector<int> traverse_bfs;
    for(int i=0;i<graph.size();i++)
    {
      visited[i]=false;
    }
    visited[n]=true;
    traverse_bfs.push_back(n);
    cout<<n<<"->";
    bfs_traversal(n,visited,traverse_bfs);
  }
}
void connected_components(bool visited[])
{
  int count=0;
  for(int i=0;i<graph.size();i++)
  {
    if(!visited[i])
    {
      count++;
      dfs(i,visited);
      cout<<endl;
    }
  }
  cout<<"The number of connected components are: "<<count;
}
void check_cycles(bool visited[])
{
    if(!visited[])
    for(int i=0;i<graph.size();i++)
    {

    }
}
int main() {
  cout<<"Welcome to graph api";
  cout<<endl<<"------------------------------------"<<endl;
  while(1)
  {
    int ch;
    cout<<"What operation do you want to do?"<<endl;
    cout<<"1)Add a node/vertex"<<endl;
    cout<<"2)Add an edge to a node"<<endl;
    cout<<"3)Print the edges of a node"<<endl;
    cout<<"4)Depth first search"<<endl;
    cout<<"5)Breadth first search"<<endl;
    cout<<"6)Connected components"<<endl;
    cout<<"7)Check if the graph has cycles"<<endl;
    cin>>ch;
    bool visited[graph.size()];
    vector<int> traverse_dfs;
    for(int i=0;i<graph.size();i++)
    {
      visited[i]=false;
    }
    switch(ch)
    {
      case 1:
      {
        addVertex();
        break;
      }
      case 2:
      {
        int node1,node2;
        cout<<"Enter node1"<<endl;
        cin>>node1;
        cout<<"Enter node2"<<endl;
        cin>>node2;
        addEdge(node1,node2);
        break;
      }
      case 3:
      {
        int node;
        cout<<"Enter the node you want to print the adjacent vertex for: "<<endl;
        cin>>node;
        print(node);
        break;
      }
      case 4:
      {
        int n;
        cout<<"Enter the node you want to start dfs from"<<endl;
        cin>>n;
        while(n>=graph.size())
        {
        cout<<"Enter a valid choice"<<endl;
        cout<<"Enter the node you want to start dfs from"<<endl;
        cin>>n;    
        }
        dfs(n,visited);
        cout<<endl;
        break;
      }
      case 5:
      {
        bfs();
        cout<<endl;
        break;
      }
      case 6:
      {
        connected_components(visited);
        cout<<endl;
        break;
      }
      case 7:
      {
        check_cycles(visited);
        cout<<endl;
        break;
      }
      default:
      {
        cout<<"Enter a valid option"<<endl;
      }
    }
}
}
