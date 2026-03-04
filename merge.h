#pragma once


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
	int leftArraySize = midIndex - leftIndex + 1;
	int rightArraySize = rightIndex - midIndex;

	int* leftArray = new int[leftArraySize];
	int* rightArray = new int[rightArraySize];

	for (size_t i = 0; i < leftArraySize; i++)
		leftArray[i] = array[leftIndex + i];

	for (size_t i = 0; i < rightArraySize; i++)
		rightArray[i] = array[midIndex + 1 + i];

	int index = leftIndex;
	int i = 0;
	int j = 0;

	while (i < leftArraySize && j < rightArraySize) {
		if (leftArray[i] <= rightArray[j]) {
			array[index] = leftArray[i];
			index++;
			i++;
		}
		else {
			array[index] = rightArray[j];
			index++;
			j++;
		}
	}

	while (i < leftArraySize) {
		array[index] = leftArray[i];
		index++;
		i++;
	}

	while (j < rightArraySize) {
		array[index] = rightArray[j];
		index++;
		j++;
	}

	delete[] rightArray;
	delete[] leftArray;

	
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
	if (leftIndex >= rightIndex) return; 
	int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	mergeSort(array, leftIndex, midIndex);
	mergeSort(array, midIndex + 1, rightIndex);

	merge(array, leftIndex, midIndex, rightIndex);
}