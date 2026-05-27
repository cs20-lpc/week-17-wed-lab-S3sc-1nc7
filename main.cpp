#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct Edge
{
	int target;
	int weight;
};

typedef pair<int, int> intpair;

vector<int> dijkstra(int source, const vector<vector<Edge>>& graph) {
    int numVertices = graph.size();
	vector<int> distance(numVertices, INT_MAX);

	priority_queue<intpair, vector<intpair>, greater<intpair>> pq;

	distance[source] = 0; // dist source
	pq.push({0,source});

	while (!pq.empty()) // while not empty
	{
        int dist = pq.top().first;
		int vertex = pq.top().second;
		
		pq.pop();

		if (dist > distance[vertex]) continue; // better path exists

		for (const auto& edge : graph[vertex])
		{
			int v = edge.target;
			int w = edge.weight;

			if (distance[vertex] + w < distance[v])
			{
				distance[v] = distance[vertex] + w;
				pq.push({distance[v], v});
			}
		}
	}
    return distance;
}


void printDistances(int source, const vector<int>& dist) {
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < (int)dist.size(); i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "Unreachable";
        } else {
            cout << dist[i];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<vector<Edge>> graph(6);
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 9});
    graph[0].push_back({4, 2});

    graph[1].push_back({3, 1});
    graph[1].push_back({2, 2});

    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});

    graph[3].push_back({5, 1});

    graph[4].push_back({2, 3});
    graph[4].push_back({5, 8});

    vector<int> distFrom0 = dijkstra(0, graph);
    vector<int> distFrom1 = dijkstra(1, graph);

    printDistances(0, distFrom0);
    printDistances(1, distFrom1);

    return 0;
}
