//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double INF = 987654321;
int n;
double position[100][2];
double dist[100][100];
double weight[100];
bool visited[100];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> position[i][0] >> position[i][1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = sqrt(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2));
	for (int i = 1; i < n; i++)
		weight[i] = INF;
	weight[0] = 0;
	int startIdx = 0;
	double cost = 0;
	while (true) {
		double minWeight = INF;
		int minIdx = -1;
		for (int i = 0; i < n; i++) {
			//cout << "w:" << weight[i] << endl;
			if (!visited[i]) {
				if (minWeight > weight[i]) {
					minWeight = weight[i];
					minIdx = i;
				}
			}
		}
		if (minIdx == -1)
			break;
		cost += dist[startIdx][minIdx];
		//cout << minIdx << endl;
		visited[minIdx] = true;
		for (int i = 0; i < n; i++) {
			if (dist[i][minIdx] == 0)
				continue;
			if (dist[i][minIdx] < weight[i]) {
				weight[i] = dist[i][minIdx];
			}
		}
		startIdx = minIdx;
	}
	cout << fixed;
	cout.precision(2);
	cout << cost << '\n';
}