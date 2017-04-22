#include <iostream>

void newtonInterpolation(double *, double *, int);
double countNewton(const double *, const double *, int, double);

int main(int argc, const char * argv[]) {
	const int size = 7;
	double tabX[] = { 10, 20, 40, 60, 90, 110, 150 };
	double tabY[] = { -20, 10, -30, 20, -10, 30, -20 };
	newtonInterpolation(tabX, tabY, size);

	for (int i = 10; i <= 150; i += 5) {

		std::cout << countNewton(tabX, tabY, size, i) << std::endl;
	}


	system("pause");
	return 0;
}

void newtonInterpolation(double *tabx, double *taby, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			taby[j] = (taby[j] - taby[j - 1]) / (tabx[j] - tabx[j - i - 1]);
		}
	}
	for (int i = 0; i < size; i++) {
		std::cout << "a'(" << i << ") = " << taby[i] << std::endl;
	}
}

double countNewton(const double *tabx, const double *taby, int size, double var) {
	double sum = 0.;
	int j = 0;
	for (int i = size - 1; i >= 0; i--) {
		double pom = 1.;
		for (j = 0; j < i; j++) {
			pom *= (var - tabx[j]);
		}
		pom *= taby[j];
		sum += pom;
	}
	return sum;
}
