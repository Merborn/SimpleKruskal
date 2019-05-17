#include<stdio.h>
#include<stdlib.h>
#define N 7

int boss[N] = {0,1,2,3,4,5,6};

int way[N][N] = { {0} };//����ͼ

int miniway[N][N] = { {0} };  //������


void createWay() {
	//0Ϊ�ñ�ʧЧ
	
	//1��������Ȩֵ
	way[1][2] = 6;
	way[1][3] = 1;
	way[1][4] = 5;

	// 2 ��������Ȩֵ
	way[2][1] = 6;
	way[2][3] = 5;
	way[2][5] = 3;
	

	//3��������Ȩֵ
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
		temp = boss[j]; //��¼��ǰ��bossֵ
		for (int m = 1; m < 7; m++) {
			if (boss[m] == temp) {
				boss[m] = boss[i]; //�����е�����ǰbossֵ��ȫ��Ϊ���µ�bossֵ
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
				if (way[i][j] != 0 && way[i][j] < MIN) {  //ѭ���ҵ���СȨ����¼����
					MIN = way[i][j];
					//printf("MIN = %d\n", MIN);
					pi = i;
					pj = j;
				}
			}
		}
		/// �ҵ���СȨֵ�ߺ�ʼ�ж�pi,pj���˵��bossֵ

		if (!bossEquals(pi, pj)) {
			//�������ͬ��˵��������Ȧ
			setBoss(pi, pj);  //��boss��Ϊ����������һ��
			miniway[pi][pj] = way[pi][pj];
		}
		else {//�����bossֵ��ͬ������·������Ч
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
	printf("��������Ϊ��(��������1��ͷ)\n");
	showMartix();
}



		

