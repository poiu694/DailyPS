void DualPivotQuickSort(int arr[], int left, int right){
	// lp : Left Pivot, rp : Right Pivot
	// left > right인 경우는 배열상으로 성립이 되지 않는다.
	if(left <= right){
		int lp = arr[left]; // 분할의 가장 왼쪽
		int rp = arr[right]; // 분할의 가장 오른쪽
		
		// 양 끝의 값을 비교한다.
		if(arr[lp] > arr[rp]){
			swap(arr, lp, rp); // lp가 크면 lp와 rp의 위치를 바꾸어준다. 
		}
		int l = left + 1; 
		int k = left + 1; // left+1의 원소부터 차례로 비교해준다.
		int g = right - 1;
			
		while(k <= g){ //서로 엇갈릴 때 까지
			//arr[k]가 lp보다 작으면, lp보다 작은 (1)영역에 들어간다.
			if(arr[k] < lp){
				swap(arr, k, l);
				l++;
			}
			// lp보다 큰 (2)영역, (3)영역
			else{
				//rp보다 큰 (3) 영역
				if(arr[k] > rp){
					while(arr[g] > rp && k < g){
						g--;
					}
					swap(arr, k, g);
					g--;
					if(arr[k] < lp){
						swap(arr, k, l);
						l++;
					}
				}
			}
			k++;
		}
		l--; g--;
		swap(arr, left, l);
		swap(arr, right, r);
		DualPivotQuickSort(arr, left, l-1);
		DualPivotQuickSort(arr, l+1, g-1);
		DualPivotQuickSort(arr, g+1, right);
	}	
}