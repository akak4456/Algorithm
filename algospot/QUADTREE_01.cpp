//result:정답
#include <iostream>
#include <string>
using namespace std;
int C;
string quaddata;
struct space {
	int color;
	//0:흰색 1:검은색 2:나눠짐
	space* spaces[4] = { NULL,NULL,NULL,NULL };
};
int decompress(space* sp,int minIdx) {
	if (quaddata[minIdx] == 'w') {
		sp->color = 0;
		return 1;
	}else if (quaddata[minIdx] == 'b') {
		sp->color = 1;
		return 1;
	}
	else if (quaddata[minIdx] == 'x') {
		sp->color = 2;
		int nextIdx = minIdx + 1;
		for (int i = 0; i < 4; i++) {
			sp->spaces[i] = new space;
			nextIdx += decompress(sp->spaces[i], nextIdx);
		}
		return (nextIdx - minIdx);
	}
}
void show(space* sp,int step) {
	/*
	if (sp->color == 0) {
		cout << step<<" w" << endl;
	}
	else if (sp->color == 1) {
		cout << step<< " b" << endl;
	}
	else if (sp->color == 2) {
		for (int i = 0; i < 4; i++) {
			show(sp->spaces[i],step+1);
		}
	}
	*/
	if (sp->color == 0) {
		cout << "w";
	}
	else if (sp->color == 1) {
		cout <<"b";
	}
	else if (sp->color == 2) {
		cout << "x";
		for (int i = 0; i < 4; i++) {
			show(sp->spaces[i], step + 1);
		}
	}
}
void updown(space* sp) {
	if (sp->color == 2) {
		space* tmp = sp->spaces[0];
		sp->spaces[0] = sp->spaces[2];
		sp->spaces[2] = tmp;
		tmp = sp->spaces[1];
		sp->spaces[1] = sp->spaces[3];
		sp->spaces[3] = tmp;
		for (int i = 0; i < 4; i++) {
			updown(sp->spaces[i]);
		}
	}
}
int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		cin >> quaddata;
		space* ret = new space;
		decompress(ret, 0);
		updown(ret);
		show(ret,0);
		cout << endl;
	}
}