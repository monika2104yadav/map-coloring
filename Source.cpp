
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

struct node {
	int value;
	list<node*> neighbors;
	bool visited = false;
	int assigned_color = 0;
	node(int val):value(val) {}
};

void graph_coloring(const list<node*>& input_graph,const vector<int>& colors) {
	//vector<int> ret;

	list<node*> queue;
	queue.push_back(input_graph.all_nodes.front());

	while (!(queue.empty())) {
		node* current = queue.front();
		queue.pop_front();
		current->visited = true;

		map<int, int> neighbor_color_map;
		list<node*>::iterator neigh_it = current->neighbors.begin();
		for (neigh_it; neigh_it != current->neighbors.end(); ++neigh_it) {
			if ((*neigh_it)->visited == false) {
				queue.push_back(*neigh_it);
			}
			if ((*neigh_it)->visited == true) {
				neighbor_color_map.insert({ (*neigh_it)->assigned_color, (*neigh_it)->assigned_color });
			}
		}
		if (neighbor_color_map.size() != 0) {
			for (int i = 0; i < colors.size(); i++) {
				if (neighbor_color_map.find(colors[i]) != neighbor_color_map.end()) {
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
	node* n1 = new node(1);
	node* n2 = new node(2);
	node* n3 = new node(3);
	node* n4 = new node(4);
	node* n5 = new node(5);

	list<node*> l1;
	l1.push_back(n2);
	l1.push_back(n3);
	l1.push_back(n4);

	n1->neighbors = l1;

	list<node*> l2;
	l2.push_back(n4);
	l2.push_back(n5);
	l2.push_back(n1);
	n2->neighbors = l2;

	list<node*> l3;
	l3.push_back(n1);
	l3.push_back(n4);
	n3->neighbors = l3;

	list<node*> l4;
	l4.push_back(n1);
	l4.push_back(n2);
	l4.push_back(n3);
	l4.push_back(n5);
	n4->neighbors = l4;

	list<node*> l5;
	l5.push_back(n2);
	l5.push_back(n4);
	n5->neighbors = l5;

	list<node*> all_nodes;
	all_nodes.push_back(n1);
	all_nodes.push_back(n2);
	all_nodes.push_back(n3);
	all_nodes.push_back(n4);
	all_nodes.push_back(n5);

	//graph g; g.all_nodes = all_nodes;

	vector<int> colors = { 1, 2, 3, 4 };
	graph_coloring(all_nodes, color);

	auto node_it = std::begin(all_nodes);
	for (node_it:all_nodes) {
		cout << (*node_it)->assigned_color << endl;
	}
	cin.get();
}
