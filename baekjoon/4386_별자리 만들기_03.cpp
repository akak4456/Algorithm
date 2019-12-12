//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;
const int FALSE = 0;
const int TRUE = 1;
double weight[100][100];
int selected[100]; // 선택된 정점의 정보를 담을 배열, 선택이 됐는지 안됐는지를 표시한다.
int dist[100]; // 최소의 거리 정보만을 담는 배열, 새로운 최소거리가 나올 때마다 갱신된다.
int N;
// 최소 dist[v]값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i; // 정점의 정보를 저장할 변수 v, 반복문을 위한 변수 i
	for (i = 0; i < n; i++)
	{
		if (selected[i] == FALSE) {
			v = i;  // 아직 선택되지 않은 정점의 번호를 v에 저장, 각 함수 실행별 0부터 n - 1까지 차례대로 저장된다.
			break;
		}
	}
	// 위에서 선택된 정점이 과연 최소거리를 지니고 있는 정점인지를 확인한다.
	for (i = 0; i < n; i++)
	{
		// 선택되지 않은 정점들을 순회하면서 최소거리를 가진 정점을 찾아낸다.
		if (selected[i] == FALSE && (dist[i] < dist[v]))
			v = i;  // 더 적은 거리가 존재한다면 해당 정점을 저장한다.
	}

	return(v);  // 최소의 거리를 갖는 정점이 선택됐으므로 정점 번호를 리턴한다.
}
double cost = 0;
// Prim, s는 시작 정점
void prim(int s, int n){
	int i, u, v;
	for (u = 0; u < n; u++)  // dist배열과 selected배열의 정보를 초기화
	{
		dist[u] = INF;
		selected[u] = FALSE;
	}
	dist[s] = 0;  // 시작정점과 시작정점간의 거리는 0이다. 자기자신을 순환하는 경로는 없다고 가정한다.
	int start = s;
	for (i = 0; i < n; i++)
	{
		// 리턴된 정점 번호를 u에 저장한다. u는 최소거리를 가지는 정점. 손으로 썻을 때 선택하는 효과를 가져온다.
		u = get_min_vertex(n);
		selected[u] = TRUE; // 최소거리를 갖는 정점의 정보(u)를 알아냈으니 해당 정점을 선택했다고 표시한다.

		// 만약 경로가 없다면 함수를 종료한다. 정상적인 신장트리의 정보가 들어왔다면 실행될 일은 없을 것이다.
		if (dist[u] == INF) return;
		cost += weight[u][start];
		start = u;

		for (v = 0; v < n; v++)  // 이 과정은 우리가 새롭게 발견한 정보를 저장하는 과정이다.
		// 직접적인 경로가 발견되어 INF 에서 상수거리로 바뀌는 과정과
		// 기존의 상수거리보다 더 짧은 거리가 발견되 그 정보를 갱신하는 과정이 포함되어 있다.
		{
			// 선택된 u 정점을 기준으로 정점(u)과 연결되어 있는 정점까지의 거리를 각각 비교한다.
			if (weight[u][v] != INF)  // 정점 u와 연결이 되어있고
			{
				// 아직 선택되지 않았으며 해당 변(weight[u][v])의 길이가 기존의 dist[v] 값보다 작다면
				if (selected[v] == FALSE && weight[u][v] < dist[v])
					dist[v] = weight[u][v]; // dist[v]의 값을 갱신해준다.

				  // 새롭게 발견되는 정점들이 초반에 저장될 수 있는 건 INF를 1000으로 설정해줬기 때문이다.
				  // 우리가 만든 그래프의 경로값들은 전부 100이하의 값이기 때문에 새롭게 발견되는 정점이 있다면
				  // 우선 등록되고 그 후 더 짧은 거리가 등장하면 갱신되는 형태로 이 프로그램은 작동한다.
			}
		}
	}
}
double position[100][2];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> position[i][0] >> position[i][1];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			weight[i][j] = sqrt(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2));
	prim(0, N);  // 정점 개수가 7개인 그래프에서 0번 정점을 출발하여 얻을 수 있는 최소비용신장트리를 찾아라.
	cout << fixed;
	cout.precision(2);
	cout << cost << endl;
}