//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double INF = 987654321;
int n;
double position[100][2];
double dist[100][100];
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
	int startIdx = 0;
	int minIdx = -1;
	double cost = 0;
	cout << fixed;
	cout.precision(2);
	do {
		double minDist = INF;
		minIdx = -1;
		for (int j = 0; j < n; j++) {
			if (!visited[j] && minDist > dist[startIdx][j]) {
				minDist = dist[startIdx][j];
				minIdx = j;
			}
		}
		if (minIdx != -1) {
			visited[minIdx] = true;
			cost += dist[startIdx][minIdx];
			startIdx = minIdx;	
		}
	}while (minIdx != -1);
	cout << cost << '\n';
}