#ifndef ALGORITHM_TREE_DTREE
#define ALGORITHM_TREE_DTREE
#include<vector>
#include<utility>


namespace algorithm::tree {

	template<typename F>
	struct DtreeNode {
		std::vector<F> features;
		std::vector<int> labels;
		int max_depth;
		int current_depth; // current tree level of this node

		unsigned samples; // the total number of samples (sum of this->value)
		std::vector<unsigned> value; // the number of samples for each label. e.g. [100, 50, 25] 
		float gini; // gini value for this node

		int selected_features_idx;
		int selected_label_idx;

		explicit DtreeNode(std::vector<F> x, std::vector<int> y, int mDepth, int cDepth) {}
		// create this->value from this->labels
		void create_value();
	};

	template<typename F>
	class DecisionTree {
	private:
		DtreeNode<F>* root;
		int maxDepth;
	public:
		explicit DecisionTree(int mDepth) {}
		void fit(std::vector<F> x, std::vector<int> y);
		int predict(std::vector<F> data);
	};
}

#endif // !ALGORITHM_TREE_DTREE
