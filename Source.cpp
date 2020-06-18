
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

using namespace std;

struct Node {
	int value;
	list<const Node*> neighbors;
	bool visited = false;
	int assigned_color = 0;
	Node(int val):value(val) {}
};

void graph_coloring(const list<const Node*>& input_graph,const vector<int>& colors) {
	//vector<int> ret;

	if (input_graph.size() == 0) return;
	
	list<const Node*> queue;
	queue.push_back(input_graph.all_nodes.front());

	while (!(queue.empty())) {
		const Node* current = queue.front();
		queue.pop_front();
		current->visited = true;

		unordered_map<int, int> neighbor_color_map;
		//list<node*>::iterator neigh_it = current->neighbors.begin();
		for (const& neighbor:current->neighbors) {
			if (!(neighbor->visited)) {
				queue.push_back(neighbor);
			}
			if (neighbor->visited) {
				neighbor_color_map.insert({ neighbor->assigned_color, neighbor->assigned_color });
			}
		}
		if (neighbor_color_map.size() != 0) {
			for (const& color:colors) {
				if (neighbor_color_map.find(color) != neighbor_color_map.end()) {
					continue;
				} else {
					current->assigned_color = colors[i];
					break;
				}
			}
		}
		else current->assigned_color = colors[0];
	}
}


int main() {
	node* n1 = new Node(1);
	node* n2 = new Node(2);
	node* n3 = new Node(3);
	node* n4 = new Node(4);
	node* n5 = new Node(5);

	list<Node*> l1 = {n2, n3, n4};
	n1->neighbors = l1;

	list<Node*> l2 = {n4, n5, n1};
	n2->neighbors = l2;

	list<Node*> l3 = {n1, n4};
	n3->neighbors = l3;

	list<Node*> l4 = {n1, n2, n3, n5};
	n4->neighbors = l4;

	list<Node*> l5 = {n2, n4};
	n5->neighbors = l5;

	list<Node*> all_nodes = {n1, n2, n3, n4, n5};
	//graph g; g.all_nodes = all_nodes;

	vector<int> colors = { 1, 2, 3, 4 };
	graph_coloring(all_nodes, color);

	//auto node_it = std::begin(all_nodes);
	for (const& node:all_nodes) {
		cout << (node)->assigned_color << endl;
	}
	cin.get();
}
