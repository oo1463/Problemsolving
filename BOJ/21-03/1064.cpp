// https://www.acmicpc.net/problem/1064

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

double dist(int x1, int y1, int x2, int y2){
    double a = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(a);
}

double bigger(double a, double b){
    return a>b?a:b;
}
double smaller(double a, double b){
    return a<b?a:b;
}

int main() {
    FAIO;

    int a,b,c,d,e,f;

    cin >> a >> b >> c >> d >> e >> f;
    
    double len[3];
    len[0] = dist(a,b,c,d);
    len[1] = dist(a,b,e,f);
    len[2] = dist(e,f,c,d);

    sort(len, len+3);
    cout<<fixed;
    cout.precision(16);
    double answer = 2*len[2]- 2*len[0];
    double m1 = 10000, m2 = 10000;

    if(a != c) m1 = (double)(b-d)/(a-c);
    if(c != e) m2 = (double)(d-f)/(c-e);
    if(m1 == m2){
        answer = -1;
    }

    cout << answer;
    return 0;
}
