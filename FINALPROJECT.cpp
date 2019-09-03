
#include <iostream>
#include<fstream>
#include <queue>
#include <stack>
using namespace std;

void DFS(int vertex, int **graph, int source, int *visited){

       stack <int> dfsStack;
        visited[source] = 1;
        dfsStack.push(source);
        while (!dfsStack.empty()) {
            int top = dfsStack.top();
            dfsStack.pop();
            for (int i = 0; i <vertex; i++) {
                if (graph[top][i] == 1) {
                    if (visited[i] == 0) {
                        dfsStack.push(i);
                        visited[i] = 1;
                    }
                }
            }


        }
}

int main()
{
    int m=0;
    int n=1;

    ifstream reader;
    reader.open("index.txt");
    int vertex, edges;
    reader >> vertex >> edges;

    int ** graph;
    graph=new int *[vertex];

    for(int i=0; i< vertex; i++){

        graph[i]=new int[vertex];
    }
    for(int i=0;i<vertex;i++)
		for(int j=0;j<vertex;j++)
			reader >> graph[i][j];





    int source=0;

    int *visited=new int[vertex];

    int *parent=new int[vertex];

        queue<int> bfsQ;
        visited[source] = 1;
        parent[source] = -1;

        bfsQ.push(source);
        while (!bfsQ.empty()) {
            int dequedElement = bfsQ.front();
            bfsQ.pop();
            for (int i = 0; i <vertex; i++) {
                if (graph[dequedElement][i] == 1) {
                   if (visited[i] == 0) {
                        bfsQ.push(i);
                        visited[i] = 1;
                        parent[i] = dequedElement;
                    }else{

                        m++;

                    }
                }
            }



        }
        cout<<"There are "<<m<<" cycles "<<endl<<endl;

    for(int i=0; i<vertex; i++){
        if(visited[i]==0){
           DFS(vertex,graph,i,visited);
           n++;

        }

    }
           cout<<"there are " <<n<<" connected components"<<endl<<endl;

if ((m==0) &&(n==1))
    cout<<"Hence the graph is a tree"<<endl;

 else
    cout<<" Hence the graph is not a tree"<<endl;

    return 0;
}
