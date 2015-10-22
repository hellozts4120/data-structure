/*	Simple Insertion Sort	*/
template<typename Comparable>
void InsertionSort(vector<Comparable> &a){
	int j;
	for(int p = 1; p < a.size(); p++){
		Comparable temp = a[p];
		for(j = p; j > 0 && a[j] < a[j - 1]; j--){
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
}

/*	ShellSort, using Shell's poor increment	*/
template<typename Comparable>
void ShellSort(vector<Comparable> &a){
	int j;
	for(int gap = a.size() / 2; gap > 0; gap /= 2){
		for(int i = gap; i < a.size(); i++){
			Comparable temp = a[i];
			for(j = i; j >= gap && a[j] < a[j - gap]; j -= gap){
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

/*	HeapSort	*/
template<typename Comparable>
inline int LeftChild(int i){
	return 2 * i + 1;
}
void PercolateDown(vector<Comparable> &a, int i, int n){
	int child;
	Comparable temp;
	for(temp = a[i]; LeftChild(i) < n; i = child){
		child = LeftChild(i);
		if(child != n - 1 && a[child] < a[child + 1]){
			child++;
		}
		if(temp < a[child]){
			a[i] = a[child];
		}
		else break;
	}
	a[i] = temp;
}

void HeapSort(vector<Comparable> &a){
	for(int i = a.size() / 2; i >= 0; i--){
		PercolateDown(a,i,a.size());
	}
	for(int j = a.size() - 1; j > 0; j--){
		Swap(a[0],a[j]);	//delete Max;
		PercolateDown(a,0,j);
	}
}