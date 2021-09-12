#include<bits/stdc++.h>
using namespace std;

struct point {
	int x, y;

	bool operator < (point &O) {
		if (O.x == x) return y < O.y;
		else return x < O.x;
	}
	bool operator == (point &O) {
		return (x == O.x && y == O.y);
	}
};


bool cw(point a, point b, point c) {

	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool ccw(point a, point b, point c) {

	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool collinear(point a, point b, point c) {

	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}


void convec_hull(vector<point> &p) {

	if (p.size() <= 2) return;

	sort(p.begin(), p.end());

	int i, n = p.size();

	point p1 = p[0], p2 = p[n - 1];
	// p1 is bottom left p and p2 is top right point
	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for (i = 1; i < n; i++) {
		// now check whether my current p is in lower half
		// or upper half

		if (i == n - 1 || !ccw(p1, p[i], p2)) {
			while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
				up.pop_back();
			}
			up.push_back(p[i]);
		}
		if (i == n - 1 || !cw(p1, p[i], p2)) {
			while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
				down.pop_back();
			}
			down.push_back(p[i]);
		}
	}

	p.clear();
	for (i = 0; i < up.size(); i++) {
		p.push_back(up[i]);
	}

	for (i = 0; i < down.size(); i++) {
		p.push_back(down[i]);
	}

	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
}
int main() {

	int n;
	cin >> n;
	vector<point> p(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	convec_hull(p);

	for (auto j : p) {
		cout << j.x << " " << j.y << "\n";
	}
	return 0;
}