// Lazy propagation in segment tree

// optimization to do "range updates" in log n time
//IDEA - postpone the updates to descendants of a node untill the descendants
//themselves need to be accessed

// updated + queries

#include<iostream>
#include<climits>
using namespace std;

int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {

	//before going down resolve the value if it exits
	if (lazy[index] != 0) {
		tree[index] += lazy[index];

		//non leaf node
		if (ss != se) {

			// pass lazy values to its children
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0; //clear the lazy value at current node
	}

	//no overlap
	if (ss > r || l > se) {
		return;
	}

	// complete overlap
	if (ss >= l && se <= r) {
		tree[index] += inc;

		//create a new lazy value of children node
		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}

	//partial overlap
	int mid = (ss + se) / 2;
	updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	//update the current node
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {

	//resolve the lazy value
	//before going down resolve the value if it exits
	if (lazy[index] != 0) {
		tree[index] += lazy[index];

		//non leaf node
		if (ss != se) {

			// pass lazy values to its children
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0; //clear the lazy value at current node
	}

	// no overlap
	if (ss > qe || se < qs) {
		return INT_MAX;
	}

	//complete overlap
	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	//partial overlap
	int mid = (ss + se) / 2;
	int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
	int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);

}


// build tree in bottom up manner -means post order traversal
//o(n)
void buildTree(int *a, int s, int e, int *tree, int index) {

	if (s == e) {
		tree[index] = a[s];
		return;
	}

	//recursive case
	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * index); //left
	buildTree(a, mid + 1, e, tree, 2 * index + 1); //right
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);

	return;
}


int main() {

	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];

	buildTree(a, 0, n - 1, tree, 1);

	// print tree array
	for (int i = 1; i <= 13; i++) {
		cout << tree[i] << " ";
	}
	cout << "\n";
	updateRangeLazy(tree, 0, n - 1, 0, 2, 10, 1);
	updateRangeLazy(tree, 0, n - 1, 0, 4, 10, 1);
	cout << "Q1 1-1 " << queryLazy(tree, 0, n - 1, 1, 1, 1) << "\n";
	updateRangeLazy(tree, 0, n - 1, 3, 4, 10, 1);
	cout << "Q1 3-5 " << queryLazy(tree, 0, n - 1, 3, 5, 1) << "\n";

	return 0;
}
