// Interseccao de retas e segmentos.
int intersect(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double *x, double *y) {
	double a1, b1, a2, b2;
	if (equals(x0,x1) && equals(x2,x3))return 0; // tratar retas verticais?
	if (!equals(x0,x1)) a1 = (y1−y0)/(x1−x0), b1 = y0 − a1*x0;
	if (!equals(x2,x3)) a2 = (y3−y2)/(x3−x2), b2 = y2 − a2*x2;
	if (equals(x0,x1)) *x = x0, *y = a2*x0 + b2;
	else
		if (equals(x2,x3)) *x = x2, *y = a1*x2 + b1;
		else {
			if (equals(a1,a2)) return 0; // tratar retas colineares?
			*x = (b2 − b1) / (a1 − a2), *y = a1*(*x) + b1;
		}
//	if (!equals(dist_pp(*x,*y,x0,y0)+dist_pp(*x,*y,x1,y1),dist_pp(x0,y0,x1,y1)))
//		return 0; // se (p0,p1) eh segmento
//	if (!equals(dist_pp(*x,*y,x2,y2)+dist_pp(*x,*y,x3,y3),dist_pp(x2,y2,x3,y3)))
//		return 0; // se (p2,p3) eh segmento
	return 1;
}
int intersect2(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3){
	//XOR: Operador lógico no qual a resposta da operação é verdade (1) quando as variáveis assumirem valores diferentes entre si.
	
	XOR(esquerda(C,D,A), esquerda(C,D,B)) AND XOR(esquerda(A,B,C), esquerda(A,B,D)). 
}
int main(){
	return 0;
}