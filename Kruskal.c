#include<stdio.h>
#include<stdlib.h>
#define N 7

int boss[N] = {0,1,2,3,4,5,6};

int way[N][N] = { {0} };//遍历图

int miniway[N][N] = { {0} };  //生成树


void createWay() {
	//0为该边失效
	
	//1到其他的权值
	way[1][2] = 6;
	way[1][3] = 1;
	way[1][4] = 5;

	// 2 到其他的权值
	way[2][1] = 6;
	way[2][3] = 5;
	way[2][5] = 3;
	

	//3到其他的权值
	way[3][1] = 1;
	way[3][2] = 5;
	way[3][4] = 5;
	way[3][5] = 6;
	way[3][6] = 4;

	//4
	way[4][1] = 5;
	way[4][3] = 5;
	way[4][6] = 2;

	//5
	way[5][2] = 3;
	way[5][3] = 6;
	way[5][6] = 6;
	
	//6
	way[6][3] = 4;
	way[6][4] = 2;
	way[6][5] = 6;
}


int setBoss(int i, int j) {
	int temp = 0;

	if (boss[i] == boss[j]) return 0;

	if (boss[i] > boss[j]) {
		temp = boss[j]; //记录以前的boss值
		for (int m = 1; m < 7; m++) {
			if (boss[m] == temp) {
				boss[m] = boss[i]; //将所有等于以前boss值的全改为最新的boss值
			}
		}
		return 1;
	}
	else {
		temp = boss[i];
		for (int m = 1; m < 7; m++) {
			if (boss[m] == temp) {
				boss[m] = boss[j];
			}
		}
		return 1;
	}
}

int bossEquals(int i, int j) {
	if (boss[i] == boss[j]) {
		return 1;
	}
	else {
		return 0;
	}
}

void cycleK() {
	int i, j;
	int MIN = 999;
	int pi, pj; //point_i , point_j

	do {
		//----------------------------------
		MIN = 999;
		pi = 0, pj = 0;

		for (i = 1; i < N; i++) {
			for (j = 1; j < N; j++) {
				if (way[i][j] != 0 && way[i][j] < MIN) {  //循环找到最小权，记录下来
					MIN = way[i][j];
					//printf("MIN = %d\n", MIN);
					pi = i;
					pj = j;
				}
			}
		}
		/// 找到最小权值边后开始判断pi,pj两端点的boss值

		if (!bossEquals(pi, pj)) {
			//如果不相同，说明不构成圈
			setBoss(pi, pj);  //将boss置为两个中最大的一个
			miniway[pi][pj] = way[pi][pj];
		}
		else {//如果两boss值相同，该条路会变成无效
			way[pi][pj] = 0;
		}
		//-----------------------------------------
		//printf("pi = %d  pj = %d\n", pi, pj);
	} while (pi != 0 && pj != 0);
}

showMartix() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			printf("\t%d", miniway[i][j]);
		}
		printf("\n");
	}
}

int main() {
//	showMartix();
	createWay();
	cycleK();
	printf("生成树表为：(数组编号以1开头)\n");
	showMartix();
}



		

