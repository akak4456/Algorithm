//result:오답
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int adj[100][100];
int C;
int N;
vector<string> words;
void makeGraph() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (words[i][words[i].size() - 1] == words[j][0])
				adj[i][j] = 1;
		}
	}
}
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < 100; there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				adj[i][j] = 0;
		words.clear();
		words.resize(N);
		for (int i = 0; i < N; i++)
			cin >> words[i];
		makeGraph();
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cout << adj[i][j] << ' ';
			cout << endl;
		}
		*/
		int originAdj[100][100];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				originAdj[i][j] = adj[i][j];
		bool isCan = false;
		for (int i = 0; i < N; i++) {
			vector<int> circuit;
			getEulerCircuit(i, circuit);
			/*
			for(int i=0;i<circuit.size();i++)
			cout << words[circuit[i]] << endl;
			
			for (int i = 0; i < circuit.size(); i++) {
				cout << words[circuit[i]] << ' ';
			}
			cout << endl;
			*/
			if (circuit.size() == N+1) {
				isCan = true;
				for (int i = 1; i <= N; i++) {
					cout << words[circuit[i]] << ' ';
				}
				cout << endl;
				break;
			}
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					adj[i][j] = originAdj[i][j];
		}
		if (!isCan) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}