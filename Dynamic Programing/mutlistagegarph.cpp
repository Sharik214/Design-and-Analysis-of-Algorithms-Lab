#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <limits> 
using namespace std; 

const int INF = numeric_limits<int>::max(); 


int multistage_shortest_path(vector<pair<int, 
							unordered_map<int, int>>>& graph, 
							int source, int target, int k) { 

	vector<int> d(graph.size(), INF); 
	d[target] = 0; 

	for (int i = k - 1; i > 0; i--) { 
	
		for (int v = 0; v < graph.size(); v++) { 
		
			if (graph[v].first != i) { 
				continue; 
			} 

			for (const auto& u : graph[v].second) { 
				d[v] = min(d[v], u.second + d[u.first]); 
			} 
		} 
	} 

	
	return d; 
} 

int main() { 
 
	vector<pair<int, unordered_map<int, int>>> graph = { 
		{0, {}}, 
		{1, {{3, 2}, {4, 9}}}, 
		{1, {{3, 6}, {4, 3}}}, 
		{2, {{4, 1}}}, 
		{2, {{5, 4}}}, 
		{3, {{5, 7}}}, 
		{3, {{6, 2}}}, 
		{4, {{5, 1}, {6, 5}}}, 
		{4, {{6, 6}}}, 
		{5, {}}, 
		{5, {}}, 
		{6, {}}, 
		{6, {}} 
	}; 


	int shortest_path_distance = multistage_shortest_path(graph, 0, 12, 7); 
	cout << "Shortest path distance from vertex 0 to vertex 12: " << 
	shortest_path_distance << endl; 

	return 0; 
} 
