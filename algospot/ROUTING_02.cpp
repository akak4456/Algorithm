//result:정답
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <float.h>
using namespace std;
 
#define NOTHING -1
 
#define VISITED 1
#define DIDNT_VISIT -1
 
#define MIN(X,Y) X<Y?X:Y
 
vector<vector<pair<double, int>>> adj;
priority_queue <pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> noise;
vector<double>visit;
 
//while문을 왜 계속 돌지 않을까?
//min을 구하는 것이기 때문에
//크면 자동으로 들어가지 않음 -> 즉 visit[]안에 값을 저장하지만 크면 들어가지 않는 특징을 이용하여 visit대신 사용가능
double Dijkstra_Algorithm()
{
    visit[0] = 1;
 
    //첫번째는 1로 해야 곱해도 자기자신이 나옴
    //가장작은 noise와 그것의 index
    noise.push(make_pair(1.0, 0));
 
    //priority_queue가 empty일때까지
    while (!noise.empty())
    {
        //proirity에서 noise가 가장 작은 값
        double distance = noise.top().first;
        int index = noise.top().second;
        noise.pop();
 
        if (distance > visit[index]) continue;
 
        //그 노드에 연결되어 있는 자식의 noise모두 확인
        for (int j = 0; j < adj[index].size(); j++)
        {
            //현재 visit에 있는 값보다 priority에 있는 가장 작은 distance값*index의 자식들의 값
            if (adj[index][j].first*distance<visit[adj[index][j].second])
            {
                //갱신
                visit[adj[index][j].second] = adj[index][j].first*distance;
                //queue에 삽입
                noise.push(make_pair(visit[adj[index][j].second], adj[index][j].second));
            }
        }
    }
 
    //맨 마지막 값 return
    return visit[adj.size() - 1];
}
 
int main()
{
    int For_Count, Node_Count, Edge_Count;
    cin >> For_Count;
 
    for (int i = 0; i < For_Count; i++)
    {
        cin >> Node_Count >> Edge_Count;
 
        adj = vector<vector<pair<double, int>>>(Node_Count);
        visit = vector<double>(Node_Count, DBL_MAX);
 
        int Node1, Node2; long double Edge;
 
        for (int j = 0; j < Edge_Count; j++)
        {
            cin >> Node1 >> Node2 >> Edge;
            adj[Node1].push_back(make_pair(Edge, Node2));
            adj[Node2].push_back(make_pair(Edge, Node1));
        }
 
        printf("%0.10f \n", Dijkstra_Algorithm());
 
    }
}