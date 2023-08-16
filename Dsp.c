Bubble Sort

def bubble_sort(array):
  for i in range(len(array) - 1):
    for j in range(len(array) - i - 1):
      if array[j] > array[j + 1]:
        swap(array[j], array[j + 1])

Selection Sort

def selection_sort(array):
  for i in range(len(array) - 1):
    min_index = i
    for j in range(i + 1, len(array)):
      if array[j] < array[min_index]:
        min_index = j

    swap(array[i], array[min_index])

Insertion Sort

def insertion_sort(array):
  for i in range(1, len(array)):
    j = i
    while j > 0 and array[j - 1] > array[j]:
      swap(array[j - 1], array[j])
      j -= 1
procedure swap(A, i, j)
    // Swap elements at indices i and j in array A
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

procedure quick_sort(A, low, high)
    if low < high
        // Partition the array and get pivot index
        pivot = partition(A, low, high)
        
        // Recursive call on the left and right subarrays
        quick_sort(A, low, pivot - 1)
        quick_sort(A, pivot + 1, high)

procedure partition(A, low, high)
    pivot = A[high] // Choose the pivot as the last element
    i = low - 1 // Index of smaller element
    
    for j = low to high - 1
        if A[j] < pivot
            i = i + 1
            swap(A, i, j)
    
    swap(A, i + 1, high)
    return i + 1

// Example usage
array = [10, 7, 8, 9, 1, 5]
quick_sort(array, 0, length(array) - 1)


