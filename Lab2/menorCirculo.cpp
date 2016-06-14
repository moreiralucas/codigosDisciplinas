// Menor circulo que engloba um conjunto de pontos.
// −> soh funciona para pontos que facam parte do convex hull do conjunto!!!!!!!
void min_circle(Polygon p, int n) {
int i = 0, j = 1, k, posmin;
double PI = acos(−1.0), min, a;
while (1) {
min = PI;
for (k=0; k < n; k++) {
if (k != i && k != j) {
a = acos(((p[i].x−p[k].x)*(p[j].x−p[k].x)+(p[i].y−p[k].y)*(p[j].y−p[k].y)) /
(sqrt((p[i].x−p[k].x)*(p[i].x−p[k].x)+(p[i].y−p[k].y)*(p[i].y−p[k].y))*
sqrt((p[j].x−p[k].x)*(p[j].x−p[k].x)+(p[j].y−p[k].y)*(p[j].y−p[k].y))));
if (a < min) min = a, posmin = k;
}
}
if (min+EPS > PI/2) {
x = (p[i].x + p[j].x) / 2.0; y = (p[i].y + p[j].y) / 2.0;
r = sqrt((p[i].x−p[j].x)*(p[i].x−p[j].x) +
(p[i].y−p[j].y)*(p[i].y−p[j].y)) / 2;
return;
}
if (acos(((p[posmin].x−p[i].x)*(p[j].x−p[i].x)+(p[posmin].y−p[i].y)*
(p[j].y−p[i].y)) / (sqrt((p[posmin].x−p[i].x)*(p[posmin].x−p[i].x)+
(p[posmin].y−p[i].y)*(p[posmin].y−p[i].y))*sqrt((p[j].x−p[i].x)*
(p[j].x−p[i].x)+(p[j].y−p[i].y)*(p[j].y−p[i].y))))−EPS > PI/2)
i = posmin;
else if (acos(((p[i].x−p[j].x)*(p[posmin].x−p[j].x)+(p[i].y−p[j].y)*
(p[posmin].y−p[j].y)) / (sqrt((p[i].x−p[j].x)*(p[i].x−p[j].x)+
(p[i].y−p[j].y)*(p[i].y−p[j].y))*sqrt((p[posmin].x−p[j].x)*(p[posmin].x
−p[j].x)+(p[posmin].y−p[j].y)*(p[posmin].y−p[j].y))))−EPS > PI/2)
j = posmin;
else { find_circle(&p[i],&p[j],&p[posmin]); return; }
}
}