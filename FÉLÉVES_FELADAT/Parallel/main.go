package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// the sync.WaitGroup need the parallelism cuz the algorythm is using goroutines and sychronization
func shellSort(array []int, gap int, wg *sync.WaitGroup) {
	defer wg.Done()

	n := len(array) //the regullar shell sort on a subarrays
	for g := gap; g < n; g++ {
		temp := array[g]
		j := g
		for j >= gap && array[j-gap] > temp {
			array[j] = array[j-gap]
			j -= gap
		}
		array[j] = temp
	}
}
func parallelShellSort(array []int) {
	n := len(array) // size fo the array
	gap := n / 2

	var wg sync.WaitGroup

	for gap > 0 {
		wg.Add(n - gap)

		for i := 0; i < n-gap; i++ {
			go shellSort(array[i:], gap, &wg)
		}

		wg.Wait()

		gap /= 2
	}
}

func generateRandomarray(size int) []int {
	array := make([]int, size)
	for i := 0; i < size; i++ {
		array[i] = rand.Intn(100)
	}
	return array
}

func main() {
	start := time.Now() //starting measuring

	rand.Seed(time.Now().UnixNano())

	size := 10 //rand.Intn(50) + 25

	array := generateRandomarray(size)

	fmt.Println("\nBefore sorting:", array)

	parallelShellSort(array)

	fmt.Println("\nAfter sorting:", array)

	elapsed := time.Since(start)
	//elapsedDuration := time.Duration(elapsed) * time.Microsecond
	//elapsedSecond := elapsedDuration.Seconds()
	fmt.Println("\n\nElapsed time: ", elapsed)

}
