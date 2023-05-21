package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// the sync.WaitGroup need the parallelism cuz the algorythm is using goroutines and sychronization
func shellSort(array []int, wg *sync.WaitGroup) {
	defer wg.Done()

	n := len(array) //the regullar shell sort on a subarrays
	gap := n / 2

	for gap > 0 {
		for i := gap; i < n; i++ {
			temp := array[i]
			j := i
			for j >= gap && array[j-gap] > temp {
				array[j] = array[j-gap]
				j -= gap
			}
			array[j] = temp
		}
		gap /= 2
	}
}

// The function divides the array into multiple subarrays and lounches gorutines
func parallelShellSort(array []int) {
	numWorkers := 4 // Number of parallel workers like thread in C but I think it's thread here
	n := len(array)

	var wg sync.WaitGroup
	wg.Add(numWorkers)

	for i := 0; i < numWorkers; i++ {
		go shellSort(array[i*(n/numWorkers):(i+1)*(n/numWorkers)], &wg)
	}

	wg.Wait()

	// Merge the sorted the subarrays
	mergeSubarrays(array, numWorkers)
}

func mergeSubarrays(array []int, numSubarrays int) {
	n := len(array)

	for numSubarrays > 1 {
		for i := 0; i < numSubarrays/2; i++ {
			merge(array[i*(n/numSubarrays):(i+1)*(n/numSubarrays)], array[(i+1)*(n/numSubarrays):])
		}
		numSubarrays /= 2
	}
}

func merge(array1, array2 []int) {
	n1 := len(array1)
	n2 := len(array2)

	merged := make([]int, n1+n2)

	i, j, k := 0, 0, 0

	for i < n1 && j < n2 {
		if array1[i] <= array2[j] {
			merged[k] = array1[i]
			i++
		} else {
			merged[k] = array2[j]
			j++
		}
		k++
	}

	for i < n1 {
		merged[k] = array1[i]
		i++
		k++
	}

	for j < n2 {
		merged[k] = array2[j]
		j++
		k++
	}

	copy(array1, merged[:n1])
	copy(array2, merged[n1:])
}

func main() {
	rand.Seed(time.Now().UnixNano())

	array := generateRandomArray(100)

	fmt.Println("Before sorting:", array)

	parallelShellSort(array)

	fmt.Println("After sorting:", array)
}

func generateRandomArray(size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = rand.Intn(100)
	}
	return array
}
