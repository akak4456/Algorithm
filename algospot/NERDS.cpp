#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const double PI = 2.0 * acos(0.0);
struct vector2{
	double x,y;
	explicit vector2(double x_ =0,double y_ =0):x(x_),y(y_){
	}
	bool operator == (const vector2& rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const{
		return x != rhs.x ? x<rhs.x:y<rhs.y;
	}
	vector2 operator +(const vector2& rhs) const{
		return vector2(x+rhs.x,y+rhs.y);
	}
	vector2 operator - (const vector2& rhs) const{
		return vector2(x-rhs.x,y-rhs.y);
	}
	vector2 operator* (double rhs) const{
		return vector2(x*rhs,y*rhs);
	}
	
	double norm() const{return hypot(x,y);}
	vector2 normalize() const{
		return vector2(x/norm(),y/norm());
	}
	double polar() const{return fmod(atan2(y,x)+2*PI,2*PI);}
	double dot(const vector2& rhs) const{
		return x * rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const{
		return x*rhs.y - rhs.x*y;
	}
	vector2 project(const vector2& rhs) const{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
const double EPSILON = 1e-9;
const double INFTY = 1e200;
typedef vector<vector2> polygon;
bool lineIntersection(vector2 a,vector2 b,vector2 c,vector2 d,vector2& x){
	double det = (b-a).cross(d-c);
	if(fabs(det) < EPSILON) return false;
	x = a + (b-a) * ((c-a).cross(d-c)/det);
	return true;
}
double ccw(vector2 a,vector2 b){
	return a.cross(b);
}
double ccw(vector2 p,vector2 a, vector2 b){
	return ccw(a-p,b-p);
}
polygon cutPoly(const polygon& p,const vector2& a,const vector2& b){
	int n = p.size();
	vector<bool> inside(n);
	for(int i=0;i<n;i++)
		inside[i] = ccw(a,b,p[i]) >= 0;
	polygon ret;
	for(int i=0;i<n;i++){
		int j = (i+1)%n;
		if(inside[i]) ret.push_back(p[i]);
		if(inside[i] != inside[j]){
			vector2 cross;
			lineIntersection(p[i],p[j],a,b,cross);
			ret.push_back(cross);
		}
	}
	return ret;
}
polygon intersection(const polygon& p,double x1,double y1,double x2,double y2){
	vector2 a(x1,y1),b(x2,y1),c(x2,y2),d(x1,y2);
	polygon ret = cutPoly(p,a,b);
	ret = cutPoly(ret,b,c);
	ret = cutPoly(ret,c,d);
	ret = cutPoly(ret,d,a);
	return ret;
}
double area(const polygon& p){
	double ret = 0;
	for(int i=0;i<p.size();i++){
		int j = (i+1)%p.size();
		ret += p[i].x* p[j].y- p[j].x * p[i].y;
	}
	return fabs(ret)/2.0;
}
polygon giftWrap(const polygon& points){
	int n = points.size();
	polygon hull;
	vector2 pivot = *min_element(points.begin(),points.end());
	hull.push_back(pivot);
	while(true){
		vector2 ph = hull.back(),next = points[0];
		for(int i=1;i<n;i++){
			double cross = ccw(ph,next,points[i]);
			double dist = (next-ph).norm() - (points[i]-ph).norm();
			
			if(cross > 0 || (cross == 0 && dist < 0))
				next = points[i];
		}
		if(next == pivot) break;
		hull.push_back(next);
	}
	return hull;
}
bool isInside(vector2 q,const polygon& p){
	int crosses = 0;
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		if((p[i].y > q.y) != (p[j].y > q.y)){
			double atX = (p[j].x- p[i].x) * (q.y-p[i].y)/(p[j].y-p[i].y)+p[i].x;
			if(q.x < atX){
				++crosses;
			}
		}
	}
	return crosses % 2 > 0;
}
bool parallelSegments(vector2 a,vector2 b,vector2 c,vector2 d,vector2& p){
	if(b< a) swap(a,b);
	if(d < c) swap(c,d);
	if(ccw(a,b,c) != 0 || b < c || d < a) return false;
	
	if(a < c) p = c; else p = a;
	return true;
}
bool inBoundingRectangle(vector2 p,vector2 a,vector2 b){
	if(b < a) swap(a,b);
	return p == a || p == b || (a<p&&p<b);
}
bool segmentIntersects(vector2 a,vector2 b,vector2 c,vector2 d,vector2& p){
	if(!lineIntersection(a,b,c,d,p))
		return parallelSegments(a,b,c,d,p);
	return inBoundingRectangle(p,a,b) && inBoundingRectangle(p,c,d);
}
bool polygonIntersects(const polygon& p,const polygon& q){
	int n = p.size(),m=q.size();
	if(isInside(p[0],q)||isInside(q[0],p))return true;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			vector2 tmp;
			if(segmentIntersects(p[i],p[(i+1)%n],q[j],q[(j+1)%m],tmp))
				return true;
		}
			
	return false;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		int n;
		polygon p,q;
		cin >> n;
		for(int i=0;i<n;i++){
			int t;
			vector2 tmp;
			cin >> t >> tmp.x >> tmp.y;
			if(t == 0){
				p.push_back(tmp);
			}else{
				q.push_back(tmp);
			}
		}
		p = giftWrap(p);
		q = giftWrap(q);
		if(polygonIntersects(p,q)){
			cout << "THEORY IS INVALID\n";
		}else{
			cout << "THEORY HOLDS\n";
		}
	}
}