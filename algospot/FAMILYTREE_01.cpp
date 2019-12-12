//result:오답
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define swap(a,b){int t = a; a = b; b = t;}
#define MAX_NODE 100001

using namespace std;

// depth :: 노드의 깊이(레벨)
// ac[x][y] :: x의 2^y번째 조상을 의미
int depth[MAX_NODE];
int ac[MAX_NODE][20];

typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];

int max_level;

// DP(ac)배열 만드는 과정
void getTree(int here, int parent)
{
	// here의 깊이는 부모노드깊이 + 1
	depth[here] = depth[parent] + 1;

	// here의 1번째 조상은 부모노드
	ac[here][0] = parent;

	// MAX_NODE에 log2를 씌어 내림을 해준다.
	max_level = (int)floor(log2(MAX_NODE));

	for (int i = 1; i <= max_level; i++)
	{
		// tmp :: here의 2^(i-1)번째 조상
		/*
			즉, ac[here][i] = ac[tmp][i-1]은
			here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
			예를들어 i = 3일때
			here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
			i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
		*/
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}

	// dfs 알고리즘
	int len = graph[here].size();
	for (int i = 0; i < len; i++)
	{
		int there = graph[here][i];
		if (there != parent)
			getTree(there, here);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int n, q;
		cin >> n >> q;
		// 양방향 그래프 형성
		for (int i = 1; i < n; i++)
		{
			int from, to;
			from = i+1;
			cin >> to;
			to++;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		// make_tree에 1,0이 들어가기때문에 0은 -1로 지정
		depth[0] = -1;
		// 루트 노드인 1번 노드부터 트리 형성
		getTree(1, 0);
		/*
		for (int i = 0; i <= n; i++) {
			cout << depth[i] << " "
				;
		}
		cout << endl;
		*/
		// 쿼리문 시작
		while (q--)
		{
			int a, b;
			cin >> a >> b;
			a++;
			b++;
			int A = a, B = b;
			if (depth[a] != depth[b])
			{
				// depth[b] >= depth[a]가 되도록 swap
				if (depth[a] > depth[b])
					swap(a, b);

				// b를 올려서 depth를 맞춰준다.
				/*
					이렇게하면 만약 max_level이 4라면
					2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식으로 찾아갈텐데
					결국 1, 2, 3, 4, 5 ..., 31까지 모두 찾는 방식과 같아진다.
					예를들어, i가 4일때와 1일때 만족했다 치면
					depth[a] <= depth[ac[b][4]]에 의해
					b = ac[b][4];가 되어 b는 b의 16번째 조상을 보고 있을 것이고
					depth[a] <= depth[ac[b][1]]에 의해(현재 b는 처음 b의 16번째 조상인 b로 바뀌었다.)
					b = ac[b][1];이 되어 b는 b의 2번째 조상을 보게 된다.
					즉, b의 16번째 조상의 2번째 조상을 보는 것이니 b의 18번째 조상을 보게 된다.
					(하고자 하는 말은 3번째, 7번째, 11번째 이런 조상들도 모두 볼 수 있다는 의미이다.)
				*/
				for (int i = max_level; i >= 0; i--)
				{
					// b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고간다.
					if (depth[a] <= depth[ac[b][i]])
						b = ac[b][i];
				}
			}

			int lca = a;

			// a와 b가 다르다면 현재 깊이가 같으니
			// 깊이를 계속 올려 서로 다른 노드의 조상이 같아질 때까지 반복한다.
			// 즉, 서로 다른 노드(2,3)의 조상이 1로 같다면 lca = ac[2][0]에 의해 2의 조상이 1임을 알 수 있고
			// 마찬가지로 ac[3][0] 또한 3의 조상이 1임을 알게되며 알고리즘이 끝이난다.
			if (a != b)
			{
				for (int i = max_level; i >= 0; i--)
				{
					if (ac[a][i] != ac[b][i])
					{
						a = ac[a][i];
						b = ac[b][i];
					}
					lca = ac[a][i];
				}
			}
			int ret = depth[A] - depth[lca] + depth[B] - depth[lca];
			cout << ret << endl;
			//cout <<A<<" "<<B<<" "<< lca << endl;
			//cout << depth[A] << " "<<depth[B] << " " << depth[lca] << endl;
		}
		return 0;
	}
}