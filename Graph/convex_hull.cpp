class Solution {
public:
    
struct point {
	int x, y;

	bool operator < (point &O) {
		if (O.x == x) return y < O.y;  // if x pts are same then compare according to y
		else return x < O.x;
	}
	bool operator == (point &O) {  // operator overloading for unique() func
		return (x == O.x && y == O.y);
	}
};

// if a, b, c are 3 three points then condition for clockwise angle is
// (b.x-a.x)/(b.y-a.y) > (c.x-b.x)/(c.y-b.y)
bool cw(point a, point b, point c) {  // clock wise

	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool ccw(point a, point b, point c) {   // counter clock wise

	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

void convec_hull(vector<point> &p) {
   // if there are atmost 2 pts
	if (p.size() <= 2) return;

	sort(p.begin(), p.end());

	int i, n = p.size();

	point p1 = p[0], p2 = p[n - 1];
	// p1 is bottom left point and p2 is top right point
	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);
    
	// divide the all pts in 2 parts - lower half and upper half of p1 and p2
	for (i = 1; i < n; i++) {
		// now check whether my current p is in lower half
		// or upper half

		if (i == n - 1 || !ccw(p1, p[i], p2)) { // check if not counter clock wise (it consider both clock wise and collinear pts)
			while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {  // check angle b/w (2nd last pt, last pt, current pt) from up vector
				up.pop_back();
			}
			up.push_back(p[i]);
		}
		if (i == n - 1 || !cw(p1, p[i], p2)) { // check if not clock wise  (it consider both counter clock wise and collinear pts)
			while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) { // check angle b/w (2nd last pt, last pt, current pt) from down vector
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
	p.resize(unique(p.begin(), p.end()) - p.begin());  // take only unique values
}
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<point> p(n);

	for (int i = 0; i < trees.size(); i++) {
		 p[i].x = trees[i][0];
         p[i].y = trees[i][1];
	}
        
	convec_hull(p);
        vector<vector<int>> ans;
        
        for(auto j: p){
            ans.push_back({j.x,j.y});
        }
        return ans;
    }
};

