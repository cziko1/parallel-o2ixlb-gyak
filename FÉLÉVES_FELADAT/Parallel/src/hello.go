package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func shellSort(arr []int, wg *sync.WaitGroup) {
	defer wg.Done()

	n := len(arr)
	gap := n / 2

	for gap > 0 {
		for i := gap; i < n; i++ {
			temp := arr[i]
			j := i
			for j >= gap && arr[j-gap] > temp {
				arr[j] = arr[j-gap]
				j -= gap
			}
			arr[j] = temp
		}
		gap /= 2
	}
}

func parallelShellSort(arr []int) {
	// Should be Randum Number
	numWorkers := 4 // Number of parallel workers like threads in C
	n := len(arr)

	var wg sync.WaitGroup
	wg.Add(numWorkers)

	for i := 0; i < numWorkers; i++ {
		go shellSort(arr[i*(n/numWorkers):(i+1)*(n/numWorkers)], &wg)
	}

	wg.Wait()

	// Merge the sorted subarrays
	mergeSubarrays(arr, numWorkers)
}

func mergeSubarrays(arr []int, numSubarrays int) {
	n := len(arr)

	for numSubarrays > 1 {
		for i := 0; i < numSubarrays/2; i++ {
			merge(arr[i*(n/numSubarrays):(i+1)*(n/numSubarrays)], arr[(i+1)*(n/numSubarrays):])
		}
		numSubarrays /= 2
	}
}

func merge(arr1, arr2 []int) {
	n1 := len(arr1)
	n2 := len(arr2)

	merged := make([]int, n1+n2)

	i, j, k := 0, 0, 0

	for i < n1 && j < n2 {
		if arr1[i] <= arr2[j] {
			merged[k] = arr1[i]
			i++
		} else {
			merged[k] = arr2[j]
			j++
		}
		k++
	}

	for i < n1 {
		merged[k] = arr1[i]
		i++
		k++
	}

	for j < n2 {
		merged[k] = arr2[j]
		j++
		k++
	}

	copy(arr1, merged[:n1])
	copy(arr2, merged[n1:])
}

func main() {
	rand.Seed(time.Now().UnixNano())

	array := generateRandomArray(100)

	fmt.Println("\nBefore sorting:", array)

	parallelShellSort(array)

	fmt.Println("\n\nAfter sorting:", array)
}

func generateRandomArray(size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = rand.Intn(100)
	}
	return array
}
