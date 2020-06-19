
#include <cstdint>
#include <iostream>
#include <cstdio>
#include <map>

#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unorderd_map>
using namespace std;

struct Node {
	int value;
	list<Node*> neighbors;
	bool visited = false;
	int assigned_color = 0;
	Node(int val) :value(val) {}
};

void graph_coloring(list<Node*>& input_graph, vector<int>& colors) {
	//vector<int> ret;

	if (input_graph.empty()) return;

	list<Node*> queue;
	queue.push_back(input_graph.front());

	while (!(queue.empty())) {
		Node* const current = queue.front();
		queue.pop_front();
		current->visited = true;

		unordered_map<int, int> neighbor_color_map;
		//list<node*>::iterator neigh_it = current->neighbors.begin();
		for (auto& neighbor : current->neighbors) {
			if (!(neighbor->visited)) {
				queue.push_back(neighbor);
			}
			else {
				neighbor_color_map.insert({ neighbor->assigned_color, neighbor->assigned_color });
			}
		}
		if (!neighbor_color_map.empty()) {
			for (const auto& color : colors) {
				if (neighbor_color_map.find(color) != neighbor_color_map.end()) {
					continue;
				}
				else {
					current->assigned_color = color;
					break;
				}
			}
		}
		else current->assigned_color = colors[0];
	}
}


int main() {
	Node* const n1 = new Node(1);
	Node* const n2 = new Node(2);
    Node* const n3 = new Node(3);
	Node* const n4 = new Node(4);
	Node* const n5 = new Node(5);

	list<Node*> l1 = { n2, n3, n4 };
	n1->neighbors = l1;

	list<Node*> l2 = { n4, n5, n1 };
	n2->neighbors = l2;

	list<Node*> l3 = { n1, n4 };
	n3->neighbors = l3;

	list<Node*> l4 = { n1, n2, n3, n5 };
	n4->neighbors = l4;

	list<Node*> l5 = { n2, n4 };
	n5->neighbors = l5;

	list<Node*> all_nodes = { n1, n2, n3, n4, n5 };
	//graph g; g.all_nodes = all_nodes;

	vector<int> colors = { 1, 2, 3, 4 };
	graph_coloring(all_nodes, colors);

	//auto node_it = std::begin(all_nodes);
	for (const auto& node : all_nodes) {
		cout << (node)->assigned_color << endl;
	}
	cin.get();
}
