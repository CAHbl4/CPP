template<class T>
T* min(T* arr, int size) {
	if (size > 0){
		T* result = &arr[0];
		for (int i = 0; i < size; ++i) {
			if (arr[i] < *result)
				result = &arr[i];
		}
		return result;
	}
	return nullptr;
}

template<class T>
T* max(T* arr, int size) {
	if (size > 0){
		T* result = &arr[0];
		for (int i = 0; i < size; ++i) {
			if (arr[i] > *result)
				result = &arr[i];
		}
		return result;
	}
	return nullptr;
}

template<class T>
void sort(T* arr, int size){
	if (size > 0){
		bool sorted = false;
		T tmp;
		int i, j = 0;

		do {
			sorted = true;
			for (i = 0; i < size - j - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
					tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
					sorted = false;
				}
			}
			++j;
		} while (!sorted);
	}
}

template<class T>
T* bsearch(T* arr, int size, T value) {
	T* result = nullptr;
	if (size > 0) {
		T* left = arr;
		T* right = arr + size - 1;
		T* mid = left + (right - left) / 2;
		
		if (value < *mid)
			result = bsearch(arr, mid - left, value);
		else if (value > *mid)
			result = bsearch(mid + 1, right - mid, value);
		else
			result = mid;
	}
	return result;
}

template<class T>
void replace(T* arr, int size, int index, T value) {
	if (size > 0 && index < size)
		arr[index] = value;
}