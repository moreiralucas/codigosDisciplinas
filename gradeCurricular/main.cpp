#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

#define debug 0
#define TAM 40

using namespace std;
using namespace cv;
Mat checked, imgOrig;
std::vector<Point> pilha;

int coluna[8] = {58, 185, 312, 439, 566, 693, 820, 947};
int linha[6] = {170, 260, 350, 440, 530, 620};

void getNear(int &x, int &y){
	int pos_x, menor_x = 10000;
	int pos_y, menor_y = 10000;
	for (int i = 0; i < 8; ++i){ //coluna
		if(abs(coluna[i] - y) < menor_y){
			menor_y = abs(coluna[i] - y);
			pos_y = coluna[i];
		}
	}
	for (int i = 0; i < 6; ++i){ //linha
		if (abs(linha[i] - x) < menor_x){
			menor_x = abs(linha[i] - x);
			pos_x = linha[i];
		}
	}
	x = pos_x;
	y = pos_y;
}

void setChecked(Point center){
	int x = center.x-20, y = center.y-20;
	for (int i = 0; i < TAM; ++i){
		for (int j = 0; j < TAM; ++j){
			if(checked.at<uchar>(i,j) >= 50){
				imgOrig.at<Vec3b>(y + i, j + x)[0] = 0;
				imgOrig.at<Vec3b>(y + i, j + x)[1] = 255;
				imgOrig.at<Vec3b>(y + i, j + x)[2] = 0;
			}
		}
	}
}

bool loadChecked(){
	checked = imread("checked.png", 0);
	return !checked.empty();
}

void mousefunc(int event, int x, int y, int flags, void* userdata) {
	if(event == EVENT_LBUTTONDOWN) {
		//x = coluna
		getNear(y, x);
		pilha.push_back(Point(x,y));
		setChecked(Point(x, y));
	}
}

int main(int argc, char const *argv[]) {
	string winname = "Display window";
	imgOrig = imread(argv[1]); //ver parâmetros
	cout << (loadChecked()? "Loaded checked!" : "Error! Load image checked Failed.") << '\n';
	resize(checked, checked, Size(40, 40));
	if (argc < 2){
		cerr << "Usage: " << argv[0] << " <image-file-name>\n";
		exit(0);
	}
	namedWindow(winname, CV_WINDOW_AUTOSIZE );// Create a window for display.
	setMouseCallback(winname, mousefunc, NULL);
	char c;
	int cont =0;
	while((c = waitKey(10)) != 27) {
		switch(c) {
			case 's':
				string path = "result_fluxograma" + to_string(cont++) +".png";
				imwrite(path, imgOrig);
				cout << "Saved file!" << endl;
				//destroyWindow(winname);
				break;
		}
		imshow(winname, imgOrig);
	}
	return 0;
}
//line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)¶
//circle(vis, Point(y,x), 3, Scalar(255,0,0), -1);
// coluna - linha
//(58,170) (934, 170)
//(58,615) (934, 615)
