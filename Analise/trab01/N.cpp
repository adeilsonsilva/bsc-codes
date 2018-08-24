#include <iostream>
#define MAXM 1000001

using namespace std;

int main(int argc, char *argv[]) {
	bool tower[MAXM] = {false};	
	int K = 0, L = 0, M = 0;
	cin >> K >> L >> M;

	tower[1] = tower[L] = tower[K] = true;
	
	for (int i = 2; i < MAXM; i++)
	{
		tower[i] = ((!tower[i-1]) || (i - K >= 0 && !tower[i - K]) || (i - L >= 0 && !tower[i - L])) ? true : false;
	}

	for (int i = 0; i < M; i++) {
		int Mi;
		cin >> Mi;
		tower[Mi] ? cout << "A" : cout << "B";
	}
    cout << endl;
    
	return 0;
}
