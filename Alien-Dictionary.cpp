//
// Created by pianocoder on 16/5/8.
//

/**
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you.
 You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this
 new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
 **/


#include <vector>
#include <string>
using namespace std;

class Solution_toplogical_graph {
	void construct_graph(const string& word1, 
						 const string& word2, 
						 unordered_map<char, unordered_set<char>>* in_degree,
						 unordered_map<char, unordered_set<char>>* out_degree) {
		const int len = min(word1.length(), word2.length());
		for (int i = 0; i < len; i++) {
			if (word1[i] != word2[i]) {
				(*in_degree)[word2[i]].emplace(word1[i]);
				(*out_degree)[word1[i]].emplace(word2[i]);
				break;
			}
		}
	}
public:
    string alienOrder(vector<string>& words) {
    	unordered_set<char> nodes;
    	unordered_map<char, unordered_set<char>> in_degree, out_degree;
    	queue<char> zero_in_degree_queue;
    	/** store all the existing char into the set **/
    	for (const auto& word : words) {
    		for (const auto& c : word) {
    			nodes.emplace(c);
    		}
    	}
    	/** construct the graph that directed edges represent the letter order information **/
    	for (int i = 1; i < words.size(); i++) {
    		construct_graph(words[i - 1], words[i], &in_degree, &out_degree);
    	}
    	/** record all the no-in-degree-node to do the topological traversal **/
    	for (const auto& node : nodes) {
    		if (in_degree.find(node) == in_degree.end()) {
    			zero_in_degree_queue.emplece(node);
    		}
    	}

    	string result;
    	while (!zero_in_degree_queue.empty()) {
    		/** fetch the zero-in-degree-node **/
    		const auto& precedence = zero_in_degree_queue.front();
    		zero_in_degree_queue.pop();
    		result.push_back(precedence);
    		/** update all the related nodes' out degree **/
    		if (out_degree.find(precedence) != out_degree.end()) {
    			for (const auto& c : out_degree[precedence]) {
    				in_degree[c].erase(precedence);
    				if (in_degree[c].empty()) {
    					zero_in_degree_queue.emplace(c);
    				}
    			}
    			out_degree.erase(precedence);
    		}
    	}

    	if (!out_degree.empty()) {
    		return "";
    	}

    	return result;
    }
};

class Solution_dfs {
		typedef unordered_map<char, unordered_set<char>> graph;

		graph make_graph(vector<string>& words) {

			graph g;
			int n = words.size();
			for (int i = 1; i < n; i ++) {
				/** for every word pairs, we need to add a edge from smaller letter to the bigger one **/
				bool found = false;
				string word1 = words[i - 1], words2 = words[i];
				int l1 = word1.length(), l2 = word2.length(), l = max(l1, l2);
				for (int j = 0; j < l; j++) {
					if (j < l1 && g.find(word1[j]) == g.end())
						g[word1[j]] = unordered_set<char>();
					if (j < l2 && g.find(word2[j]) == g.end()
						g[word2[j]] = unordered_set<char>();
					if (j < l1 && j < l2 && word1[j] != word2[j] && !found) {
						g[word1[j]].insert(word2[j]);
						found = true;
					}
				}
			}
			return g;
		}

		unordered_map<char, int> compute_indegree(graph& g) {
			unordered_map<char, int> degrees;
			for (auto adj : g) {
				//if (!degrees[adj.first]);
				for (char neigh : adj.second)
					degrees[neigh]++;
			}
			return degrees;
		}

public:
    string alienOrder(vector<string>& words) {
    	if (words.size() == 1) return words[0];
    	graph g = make_graph(words);
    	unordered_map<char, int> degrees = compute_indegree(g);
    	int numNodes = degrees.size();
    	string order;
    	queue<char> toVisit;
    	for (auto node : degrees) {
    		if (!node.second)
    			toVisit.push(node.first);
    	}
    	
    }
};