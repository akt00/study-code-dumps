#pragma once
#include <vector>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <unordered_map>
#include <set>
#include <deque>


namespace algorithm::graph {
	using mat = std::vector<std::vector<uint8_t>>;
	enum Attribute {
		UNDIRECTED = 0,
		DIRECTED = 2,
		WEIGHTED = 4,
	};

	class DenseGraph {
	public:
		DenseGraph(Attribute attr) {
			graph_attributes = attr;
			std::vector<uint8_t> row(UINT8_MAX, 0);
			adj_list = std::move(mat(UINT8_MAX, row));
		}

		void AddVertex(uint8_t key) {

			assert(vertex_list.find(key) == vertex_list.end());
			vertex_list.insert({ key, {} });
		}

		void AddWeightedRelations(uint8_t key, std::vector<std::pair<uint8_t, uint8_t>> vertices) {

			assert(vertex_list.find(key) != vertex_list.end());

			for (auto i : vertices) {

				auto idx = i.first;
				assert(vertex_list.find(idx) != vertex_list.end());
				auto weight = i.second;
				adj_list[key - 1][idx - 1] = weight;
			}
		}
		
		void InitVertices() {
			for (auto& i : vertex_list) {
				i.second.distance = -1;
				i.second.is_visited = -1;
				i.second.parent = -1;
			}
		}

		std::deque<uint8_t> BreathFirstSearch(int key) {
			if (vertex_list.find(key) == vertex_list.end()) return {};

			InitVertices();
			vertex_list[key].distance = 0;
			vertex_list[key].is_visited = 0;
			vertex_list[key].parent = -1;
			std::deque<uint8_t> q;
			q.push_back(key);
			decltype(q) tmp;
			while (!q.empty()) {
				auto u = q.front();
				q.pop_front();

				for (auto i = 0; i < adj_list[u - 1].size();i++) {
					if (adj_list[u - 1][i] != 0 && vertex_list[i + 1].is_visited == -1) {
						vertex_list[i+1].is_visited = 0;
						vertex_list[i+1].distance = vertex_list[u].distance + 1;
						vertex_list[i+1].parent = u;
						q.push_back(i + 1);
					}
				}
				vertex_list[u].is_visited = 1;
				tmp.push_back(u);
			}
			return tmp;
		}

		std::deque<uint8_t> dfs() {
			InitVertices();
			int time = 0;
			for (auto i : vertex_list) {
				if (i.second.is_visited == -1) DfsVisit(i.first, time);
			}
		}

		void DfsVisit(uint8_t u, int& time) {
			time += 1;
			vertex_list[u].distance = time;
			vertex_list[u].is_visited = 0;
			for (auto i = 0; i < adj_list[u - 1].size(); i++) {
				if (i != 0 && vertex_list[i + 1].is_visited == -1) {
					vertex_list[i + 1].parent = u;
					DfsVisit(i + 1, time);
				}
			}
			vertex_list[u].is_visited = 1;
			time += 1;
		}

		bool IsDirected() const { return (graph_attributes & 2); }

		bool IsWeighted() const { return (graph_attributes & 4); }

		void ShowVertexList() const {
			for (auto i : vertex_list) std::cout << (unsigned) i.first << " "
				<< i.second.distance << std::endl;
		}

		void ShowGraphAttributes() const {
			if(graph_attributes & 2) std::cout << "Directed: " << "true" << std::endl;
			else std::cout << "Directed: " << "false" << std::endl;
			if (graph_attributes & 4) std::cout << "Weighted: " << "true" << std::endl;
			else std::cout << "Weighted: " << "false" << std::endl;
		}

	private:
		struct VertexInfo {
			int is_visited;
			int parent;
			int distance;
		};
		int graph_attributes;
		mat adj_list;
		std::unordered_map < uint8_t, VertexInfo > vertex_list;
	};

	class SparseGraph {
	public:
	private:
	};
}