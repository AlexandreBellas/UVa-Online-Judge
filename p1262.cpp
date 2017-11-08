#include <bits/stdc++.h>
using namespace std;

char first_grid[7][7], second_grid[7][7];

int main() {
	int T, K;
	cin >> T;

	while (T--) {
		scanf("%d", &K);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> first_grid[j][i];
				if (first_grid[j][i] == '\n')
					j--;
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> second_grid[j][i];
				if (second_grid[j][i] == '\n')
					j--;
			}
		}

		for (int i = 0; i < 5; i++) {
			sort(first_grid[i], first_grid[i] + 6);
			sort(second_grid[i], second_grid[i] + 6);
		}

		char p1, p2, p3, p4, p5;
		int count = 0;
		for (int i = 0; i < 6; i++) {
			if (i > 0 && first_grid[0][i] == first_grid[0][i-1])
				continue;

			for (int j = 0; j < 6; j++) {
				if (j > 0 && first_grid[1][j] == first_grid[1][j-1])
					continue;

				for (int k = 0; k < 6; k++) {
					if (k > 0 && first_grid[2][k] == first_grid[2][k-1])
						continue;

					for (int l = 0; l < 6; l++) {
						if (l > 0 && first_grid[3][l] == first_grid[3][l-1])
							continue;

						for (int m = 0; m < 6; m++) {
							if (m > 0 && first_grid[4][m] == first_grid[4][m-1])
								continue;

							p1 = first_grid[0][i];
							p2 = first_grid[1][j];
							p3 = first_grid[2][k];
							p4 = first_grid[3][l];
							p5 = first_grid[4][m];
							if (binary_search(second_grid[0], second_grid[0] + 6, p1) && binary_search(second_grid[1], second_grid[1] + 6, p2) && binary_search(second_grid[2], second_grid[2] + 6, p3) && binary_search(second_grid[3], second_grid[3] + 6, p4) && binary_search(second_grid[4], second_grid[4] + 6, p5))
								count++;

							if (count == K)
								break;
						}
						if (count == K)
							break;
					}
					if (count == K)
						break;
				}
				if (count == K)
					break;
			}
			if (count == K)
				break;
		}

		if (count == K)
			cout << p1 << p2 << p3 << p4 << p5 << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}