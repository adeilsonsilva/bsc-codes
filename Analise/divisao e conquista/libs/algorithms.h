void insertionSort() {
	printf("=========INSERTION SORT==============\n");
	time(&startSort);
	for (i = 1; i < NELEMS(sortArray); i++) {
		ticks = clock();
		printSortArray();
		v = sortArray[i];
		j = i - 1;
		while((j > 0) && (sortArray[j] > v)) {
			sortArray[j + 1] = sortArray[j];
			j--;
		}
		sortArray[j + 1] = v;
	}
	time(&stopSort);
	printSortArray();
	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("=================================================\n");
}

void bubbleSort(){
	printf("=========BUBBLE SORT==============\n");
	time(&startSort);
	for (i = 0; i < NELEMS(sortArray) - 2; i++) {
		//ticks = clock();
		printSortArray();
		for(j = NELEMS(sortArray)-2; j > i; j--) {
			//printf("::%d %d::\n", i, j);
			//printSortArray();
			if (sortArray[j] < sortArray[j - 1]) {
				v = sortArray[j];
				sortArray[j] = sortArray[j - 1];
				sortArray[j - 1] = v;
			}
			//printSortArray();
		}
	}
	time(&stopSort);
	printSortArray();
	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("=================================================\n");
}

void merge(int p, int q, int r) {
	int n1, n2, k;

	n1 = q - p + 1;
	n2 = r - q;
	int V[n1], W[n2];
	//printf("::p: %d q: %d r: %d n1: %d n2: %d::\n", p, q, r, n1, n2);
	for (i = 0; i < n1; i++) {
		//printf("%d\n", sortArray[i]);
		V[i] = sortArray[p+i];
	}

	for (j = 0; j < n2; j++) {
		//printf("%d\n", sortArray[i]);
		W[j] = sortArray[q+j+1];
	}

	for (i = 0, j = 0, k = p; i < n1 && j < n2; k++) {
		//printf("V[i]: %d W[j]: %d k: %d sortArray[k]: %d i: %d j: %d\n", V[i], W[j], k, sortArray[k], i, j);
		if (V[i] <= W[j]) {
			sortArray[k] = V[i++];
		} else {
			sortArray[k] = W[j++];
		}
		//printf("%d\n", sortArray[k]);
	}

	while (i < n1){
		//printf("sortArray[k]: %d, V[i]: %d, k: %d, i: %d\n", sortArray[k], V[i], k, i);
	    sortArray[k++] = V[i++];
	    //printf("sortArray[k]: %d, V[i]: %d, k: %d, i: %d\n", sortArray[k], V[i], k, i);
	}

	while (j < n2){
		//printf("Two\n");
	    sortArray[k] = W[j++];
	}
}

void mergeSort(int p, int r) {
	int q;
	// printf("==%d %d==\n", p, r);
	for (i = p; i <= r; i++){
		printf("| %d ", sortArray[i]);
	}
	printf("|\n");
	if(p < r){
		ticks = clock();
		q = p+(r-p)/2;
		// printf("++%d++\n", q);
		mergeSort(p, q);
		mergeSort(q+1, r);
		merge(p,q,r);
	}
}

int particiona(int a, int b) {
	int v, l, r, y;
	printf("a: %d, b: %d, sortArray[a]: %d\n", a,b, sortArray[a]);
	for (i = a; i <= b; i++){
		printf("| %d ", sortArray[i]);
	}
	printf("|\n");
	v = sortArray[a];
	l = a;
	r = b;

	while(l < r){
		while(sortArray[l] <= v && l <= b){
			// printf("l: %d, sortArray[l]: %d\n", l, sortArray[l]);
			l++;
		}
		while(sortArray[r] > v && r >= a){
			// printf("r: %d, sortArray[r]: %d\n", r, sortArray[r]);
			r--;
		}
		if (l < r){
			//printf("l: %d, r: %d, sortArray[l]: %d, sortArray[r]: %d\n", l,r,sortArray[l],sortArray[r]);
			y = sortArray[l];
			sortArray[l] = sortArray[r];
			sortArray[r] = y;
		}
	}

	sortArray[a] = sortArray[r];
	sortArray[r] = v;

	return r;
}

void quickSort(int a, int b) {
	int p;
	// for (i = 0; i <= b; i++){
	// 	printf("| %d ", sortArray[i]);
	// }
	// printf("|\n");
	if (a < b){
		p = particiona(a, b);
		quickSort(a, p-1);
		quickSort(p+1, b);
	}
}

/* Constroi Heap Maximo */
void constroiHeap(){
	printSortArray();
	for (j = ((NELEMS(sortArray) - 1) / 2); j >= 0; j--){
		arrumaHeap(j, NELEMS(sortArray));
		printSortArray();
	}
	printf("_____________________\n");
}

void arrumaHeap(int a, int n){
	int p, f;

	if(n == 0) return;

	p = a;
	f = 2*a+1;
	printf("p: %d, f: %d, n: %d\n", p, f, n);
	while(f <=n){
		if (f < n && sortArray[f] < sortArray[f+1]){
			f++;
		}

		if (sortArray[f] > sortArray[p]){
			v = sortArray[p];
			sortArray[p] = sortArray[f];
			sortArray[f] = v;
			p = f;
			f = 2*p+1;
		}else{
			f = n + 1;
		}
	}
}

void heapSort() {
	int l;
	constroiHeap();
	for (i = NELEMS(sortArray) - 1; i > 0; i--)	{
		for (j = 0; j <= i; j++){
			printf("| %d ", sortArray[j]);
		}
		printf("|\n");
		v = sortArray[i];
		sortArray[i] = sortArray[0];
		sortArray[0] = v;
		arrumaHeap(0, i - 1);
	}
}

void menu() {

	printf("===== ALGORITMOS =====\n");
	printf("1 - Insertion Sort\n");
	printf("2 - Bubble Sort\n");
	printf("3 - Merge Sort\n");
	printf("4 - Quick Sort\n");
	printf("5 - Heap Sort\n");

	printf("Início da ordenação!\n");
	insertionSort();
	copyArray();
	bubbleSort();
	copyArray();
	printf("=========MERGE SORT==============\n");
	mergeSort(0, NELEMS(sortArray)-1);
	printSortArray();
	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("=================================================\n");
	copyArray();
	printf("=========QUICK SORT==============\n");
	quickSort(0, NELEMS(sortArray)-1);
	printSortArray();
	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("=================================================\n");
	copyArray();
	printf("=========HEAP SORT==============\n");
	heapSort();
	printSortArray();
	printf("Foram usados %0.2f segundos do tempo da CPU.\n", (double)ticks/CLOCKS_PER_SEC);
	printf("=================================================\n");
	// printSortArray();
	// copyArray();
}
