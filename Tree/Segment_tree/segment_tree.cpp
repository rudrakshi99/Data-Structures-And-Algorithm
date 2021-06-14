// Data structure for range based queries and updates
// 3 aproaches -
// 1. Brute force
// 2. Table based
// 3. segment tree (best) - based on Divide and conqure

/*
     s,e
     /\
    /  \
 s,mid  mid+1,e

 */

#include<iostream>
#include<climits>
using namespace std;

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

// o(log n)
int query(int *tree, int ss, int se, int qs, int qe, int index) {

	// complete overlap
	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	//No overlap
	if (qe < ss || qs > se) {
		return INT_MAX;
	}

	// Partial overlap
	int mid = (ss + se) / 2;
	int left = query(tree, ss, mid, qs, qe, 2 * index);
	int right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);

}

//point update - o(log n)
void update(int *tree, int ss, int se, int i, int increment, int index) {

	//case where i is out of bounds
	if (i > se || i < ss) {
		return;
	}

	//leaf node
	if (ss == se) {
		tree[index] += increment;
		return;
	}

	//otherwise
	int mid = (ss + se) / 2;
	update(tree, ss, mid, i, increment, 2 * index);
	update(tree, mid + 1, se, i, increment, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);

}

//o(n)
void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {


	//out of bounds
	if (l > se || r < ss) {
		return;
	}

	//leaf node
	if (ss == se) {
		tree[index] += inc;
	}

	//recursive case
	int mid = (ss + se) / 2;
	updateRange(tree, ss, mid, l, r, inc, 2 * index);
	updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);
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

	// update node

	update(tree, 0, n - 1, 3, 10, 1);
	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(tree, 0, n - 1, l, r, 1) << "\n";
	}

	return 0;
}