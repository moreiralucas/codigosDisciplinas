#include <vector>
#include <iostream>

using namespace std;
int cmp(const bigint& x = 0) const {
	int i = max(n, x.n), t = 0;
	while (1)
		if ((t = ::cmp(v[i], x.v[i])) || i-- == 0)
			return t;
}
struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) { return x * q.x + y * q.y; }
	double operator %(point q) { return x * q.y - y * q.x; }
	int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
	friend ostream& operator <<(ostream& o, point p) {
	return o << "(" << p.x << ", " << p.y << ")";
	}
	static point pivot;
};
point point::pivot;

//double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }
typedef vector<point> polygon;
_inline(int ccw)(point p, point q, point r) {
	return cmp((p - r) % (q - r));
}
_inline(double angle)(point p, point q, point r) {
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}
////////////////////////////////////////////////////////////////////////////////
// Decide se q está sobre o segmento fechado pr.
//
bool between(point p, point q, point r) {
return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}
////////////////////////////////////////////////////////////////////////////////
// Decide se os segmentos fechados pq e rs têm pontos em comum.
//
bool seg_intersect(point p, point q, point r, point s) {
	point A = q - p, B = s - r, C = r - p, D = s - q;
	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);
	if (a == 3 || a == -3 || b == 3 || b == -3) return false;
	if (a || b || p == r || p == s || q == r || q == s) return true;
	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}
int main(){
	cout << "executou" << endl;
	return 0;
}