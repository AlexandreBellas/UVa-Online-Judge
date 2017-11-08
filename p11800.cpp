#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
#define EPS 1e-6
 
struct Point{
    int x, y;
    Point(){}
    Point(int a, int b) {
        x = a;
        y = b;
    }
    double norma() {
        return sqrt(x*x + y*y);
    }
    Point operator + (Point v) {
        return Point(v.x + x, v.y + y);
    }
    Point operator - (Point v) {
        return Point(x - v.x, y - v.y);
    }
    double operator * (Point v) {
        return x * v.x + y * v.y;
    }
 
};
 
Point p[4];

double det(Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}
 
double dpp(Point a, Point b){
    //cout << "passoudpp" << endl;
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int cmp(Point a, Point b) {
    Point P = a - p[0];
    Point Q = b - p[0];
    return (Point(1, 0) * P)/P.norma() < (Point(1, 0) * Q)/Q.norma();
    // quanto maior o produto escalar, menor será o ângulo, pois o produto escalar da a norma da projeção desse vetor na horizontal
}

string resposta(){
	Point a = p[1] - p[0];
	Point b = p[2] - p[1];
	Point c = p[3] - p[2];
	Point d = p[0] - p[3];

	if(a.norma() == b.norma() && b.norma() == c.norma() && c.norma() == d.norma()){
		if(a*b == 0 && b*c == 0 && c*d == 0 && d*a == 0)
			return "Square";
		else
			return "Rhombus";
	}
	else{
		if(a*b == 0 && b*c == 0 && c*d == 0 && d*a == 0)
			return "Rectangle";

		if(det(a,c) == 0 && det(b,d) == 0)
			return "Parallelogram";
		else if(det(a,c) == 0 || det(b,d) == 0)
			return "Trapezium";
		else
			return "Ordinary Quadrilateral";
	}
}
 
int main(){
    int T;
    int i;
    cin >> T;
    int cont = 1;
    while(T--){ 
        int j = 0;
        for(int i = 0; i < 4; ++i) {
            int x, y;
            cin >> x >> y;
            if((y == p[j].y and x < p[j].x) or y < p[j].y) j = i;
            p[i] = Point(x, y);
        }
        swap(p[0], p[j]);
        sort(p + 1, p + 4, cmp);
        p[4] = p[0];
 
        /*cout << "Pontos ordenados" << endl;
        for(int i = 0; i < 4; i++){
            cout << p[i].x << " " << p[i].y << endl;
        }
        cout << endl;
        */
 
        string resp;

        resp = resposta();
 
        cout << "Case " << cont << ": " << resp << endl;
        cont++;
        // if(T != 0)
             // cout << endl;
    }
 
 
    return 0;
}