#include<stdlib.h>

class Dynamic {
public:
	//matrix chain
	void testMatrixChain();

	//longest subchain
	void testLCSLength();

	//01 package, the condition are package's weight and volume
	void testZeroOnePackageTwo();

private:
	//matrix chain
	void MatrixChain(int *p, int n, int **m, int **s);
	void Traceback(int i, int j, int **s);
	void printMatrix(int **m, int r, int c);

	//longest subchain
	void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
	void GetLCSResult(int i, int j, char *x, int **b);
	void printArray(int **a, int r, int c);

	//01 package, the condition are package's weight and volume
	void ZeroOnePackageTwo(const int *weight, const int *value, const int *volume, int sum, int pWeight,
		int pVolume, int ***m, int *res);

	int getMax(int x, int y);
};

void Dynamic::testMatrixChain() {
	int p[] = { 30,35,15,5,10,20,25 };
	const int n = 6;

	int **m = new int*[n];
	int **s = new int*[n];

	for (int i = 1; i <= n; ++i) {

		*(m + i) = new int[n];
		*(s + i) = new int[n];
	}

	MatrixChain(p, n, m, s);
	Traceback(1, n, s);

	printMatrix(m, n, n);
	printMatrix(s, n, n);

}

void Dynamic::MatrixChain(int *p, int n, int **m, int **s) {
	for (int i = 1; i <= n; ++i) {
		m[i][i] = 0;
		s[i][i] = 0;
	}

	for (int r = 2; r <= n; ++r) {
		for (int i = 1; i <= n - r + 1; ++i) {
			int j = i + r - 1;
			m[i][j] = m[i+1][j] + p[i-1] * p[i] * p[j];
			s[i][j] = i;

			cout << "r: " << r << ", i: " << i << ", j: " << j << ", min: " <<m[i][j]<< ", s: "<<s[i][j]<<endl;
			for (int k = i + 1; k < j; ++k) {

				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				cout << "inner: i: " << i << ", k: " << k << ", j: " << j << ", temp: "<<temp<< endl;
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
			cout << endl;
		}
	}
}

void Dynamic::Traceback(int i, int j, int **s) {

	if (i == j) {
		return;
	}

	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);

	cout << "A" << i << "-A" << j << endl;
}

void Dynamic::printMatrix(int **m, int r, int c) {
	for (int i = 1; i <= r; ++i) {
		for (int k = 1; k < i; ++k) {
			cout << "\t";
		}

		for (int j = i; j <= c; ++j) {
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


void Dynamic::testLCSLength() {

/*	int m = 1;
	int n = 4;
	char x[] = {'A'};
	char y[] = {'A', 'C', 'D', 'G' };*/

	int m = 7;
	int n = 6;
	char x[] = {'0', 'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	char y[] = {'0', 'B', 'D', 'C', 'A', 'B', 'A'};

	int **c = (int **)malloc((m+1) * sizeof(int *));
	int **b = (int **)malloc((m+1) * sizeof(int *));

	for (int i = 0; i <= m+1; ++i) {
		*(c + i) = (int *)malloc((n+1) * sizeof(int));
		*(b + i) = (int *)malloc((n+1) * sizeof(int));
	}

	LCSLength(m, n, x, y, c, b);
	printArray(c, m, n);
	printArray(b, m, n);

	GetLCSResult(m, n, x, b);
}

void Dynamic::LCSLength(int m, int n, char *x, char *y, int **c, int **b) {

	for (int i = 0; i <= m; ++i) {
		c[i][0] = 0;
	}

	for (int i = 0; i <= n; ++i) {
		c[0][i] = 0;
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {

			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}

		}
	}
}

void Dynamic::GetLCSResult(int i, int j, char *x, int **b) {
	if (i == 0 || j == 0){
		return;
	}

	if (b[i][j] == 1){
		cout<<x[i]<<' ';
		GetLCSResult(i - 1, j - 1, x, b);
	} else if (b[i][j] == 2){
		GetLCSResult(i - 1, j, x, b);
	} else {
		GetLCSResult(i, j - 1, x, b);
	}
}

void Dynamic::printArray(int **a, int r, int c) {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


void Dynamic::testZeroOnePackageTwo() {

	int sum = 6;//待装入背包的物品总数
	int pWeight = 10;//背包的重量
	int pVolume = 8;//背包的容量

	int weight[] = { 0, 5, 6, 5, 1, 10, 7 };//每个物品的重量
    int volume[] = { 0, 3, 2, 4, 5, 1, 3 };//每个物品的体积

    int value[] = { 0, 2, 3, 1, 4, 6, 5 };//每个物品的价值

	int ***m = new int **[sum+1];
	for (int i = 0; i <= sum; ++i) {
		m[i] = new int *[pWeight + 1];

		for (int j = 0; j <= pWeight; ++j) {
			m[i][j] = new int[pVolume + 1];
		}
	}

	int *res = (int *)malloc((sum + 1) * sizeof(int));

	ZeroOnePackageTwo(weight, value, volume, sum, pWeight, pVolume, m, res);

	for (int i = 1; i <= sum; ++i) {
		cout << i << " : " << res[i] << endl;
	}
	cout<<"max value: "<<m[1][pWeight][pVolume]<<endl;
	cout << endl;

}

void Dynamic::ZeroOnePackageTwo(const int *weight, const int *value, const int *volume, int sum,
	int pWeight, int pVolume, int ***m, int *res) {

    cout<<"i: "<<sum<<endl;
	for (int j = 0; j <= pWeight; ++j) {
		for (int k = 0; k <= pVolume; ++k) {
			if (weight[sum] <= j && volume[sum] <= k){
				m[sum][j][k] = value[sum];
			} else{
				m[sum][j][k] = 0;
			}
			cout<<m[sum][j][k]<<" ";
		}
		cout<<endl;
	}

	for (int i = sum - 1; i >= 1; --i) {
	    cout<<"i: "<<i<<endl;
		for (int j = 0; j <= pWeight; ++j) {
			for (int k = 0; k <= pVolume; ++k) {

				if (weight[i] <= j && volume[i] <= k){
					m[i][j][k] = getMax(m[i+1][j][k], m[i+1][j - weight[i]][k - volume[i]] + value[i]);
				} else{
					m[i][j][k] = m[i+1][j][k];
				}
				cout<<m[i][j][k]<<" ";
			}
			cout<<endl;
		}
	}

/*	m[1][pWeight][pVolume] = m[2][pWeight][pVolume];
	if (pWeight >= weight[1] && pVolume >= volume[1]){
		m[1][pWeight][pVolume] = getMax(m[1][pWeight][pVolume], m[2][pWeight - weight[1]][pVolume - volume[1]] + value[1]);
	}*/

	//get result
	for (int i = 1; i < sum; ++i) {
		if (m[i][pWeight][pVolume] == m[i+1][pWeight][pVolume]){
			res[i] = 0;
		} else{
			res[i] = 1;
			pWeight -= weight[i];
			pVolume -= volume[i];
		}
	}
	res[sum] = m[sum][pWeight][pVolume] ? 1 : 0;
}

int Dynamic::getMax(int x, int y){
	return x >= y ? x : y;
}


