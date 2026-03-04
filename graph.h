#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Graph {
private:
	std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
public:
	bool addVertex(std::string vertex) {
		if (adjList.count(vertex) == 0) {
			adjList[vertex];
			return true;
		}
		return false;
	}

	bool addEdge(std::string vertex1, std::string vertex2) {
		if (adjList.count(vertex1) && adjList.count(vertex2)) {
			adjList.at(vertex1).insert(vertex2);
			adjList.at(vertex2).insert(vertex1);
			return true;
		}
		return false;
	}

	bool removeEdge(std::string vertex1, std::string vertex2) {
		if (adjList.count(vertex1) && adjList.count(vertex2)) {
			adjList.at(vertex1).erase(vertex2);
			adjList.at(vertex2).erase(vertex1);
			return true;
		}
		return false;
	}

	bool removeVertex(std::string vertex1) {
		if (adjList.count(vertex1) == 0) return false;
		for (auto otherVertex : adjList.at(vertex1)) {
			adjList.at(otherVertex).erase(vertex1);
		}
		adjList.erase(vertex1);
		return true;
	}



	void printGraph() {
		unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
		while (kvPair != adjList.end()) {
			cout << kvPair->first << ": [ ";  // this prints out the vertex
			unordered_set<string>::iterator edge = kvPair->second.begin();
			while (edge != kvPair->second.end()) {
				cout << edge->data() << " ";  // this prints out edges
				edge++;
			}
			cout << "]" << endl;
			kvPair++;
		}
	}
};
