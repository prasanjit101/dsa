def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        k = arr[i]
        j = i-1
        while j >= 0 and arr[j] > k:
            arr[j+1] = arr[j]
            j -= 1
        arr[j] = k


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        m = i
        for j in range(i+1, n):
            if arr[j] < arr[m]:
                m = j
        arr[m], arr[i] = arr[i], arr[m]


def partition(l, r, nums):
    # Last element will be the pivot and the first element the pointer
    pivot, ptr = nums[r], l
    for i in range(l, r):
        if nums[i] <= pivot:
            # Swapping values smaller than the pivot to the front
            nums[i], nums[ptr] = nums[ptr], nums[i]
            ptr += 1
    # Finally swapping the last element with the pointer indexed number
    nums[ptr], nums[r] = nums[r], nums[ptr]
    return ptr


def Quick_sort(arr, low, high):
    if low < high:
        p = partition(arr, low, high)
        Quick_sort(arr, low, p-1)
        Quick_sort(arr, p+1, high)


# from leetcode

def sortArray(self, nums):
    # self.quickSort(nums)
    # self.mergeSort(nums)
    # self.bubbleSort(nums)
    # self.insertionSort(nums)
    # self.selectionSort(nums)
    self.heapSort(nums)
    return nums

# @bubbleSort, TLE


def bubbleSort(self, nums):
    n = len(nums)
    for i in range(n):
        for j in range(0, n - i - 1):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]

# @insertionSort, TLE


def insertionSort(self, nums):
    for i in range(1, len(nums)):
        key = nums[i]
        j = i-1
        while j >= 0 and key < nums[j]:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = key

# @selectionSort, TLE


def selectionSort(self, nums):
    for i in range(len(nums)):
        _min = min(nums[i:])
        min_index = nums[i:].index(_min)
        nums[i + min_index] = nums[i]
        nums[i] = _min
    return nums

# @quickSort


def quickSort(self, nums):
    def helper(head, tail):
        if head >= tail:
            return
        l, r = head, tail
        m = (r - l) // 2 + l
        pivot = nums[m]
        while r >= l:
            while r >= l and nums[l] < pivot:
                l += 1
            while r >= l and nums[r] > pivot:
                r -= 1
            if r >= l:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        helper(head, r)
        helper(l, tail)

    helper(0, len(nums)-1)
    return nums

# @mergeSort


def mergeSort(self, nums):
    if len(nums) > 1:
        mid = len(nums)//2
        L = nums[:mid]
        R = nums[mid:]

        self.mergeSort(L)
        self.mergeSort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                nums[k] = L[i]
                i += 1
            else:
                nums[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            nums[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            nums[k] = R[j]
            j += 1
            k += 1

# @heapSort


def heapSort(self, nums):
    def heapify(nums, n, i):
        l = 2 * i + 1
        r = 2 * i + 2

        largest = i
        if l < n and nums[largest] < nums[l]:
            largest = l

        if r < n and nums[largest] < nums[r]:
            largest = r

        if largest != i:
            nums[i], nums[largest] = nums[largest], nums[i]

            heapify(nums, n, largest)

    n = len(nums)

    for i in range(n//2+1)[::-1]:
        heapify(nums, n, i)

    for i in range(n)[::-1]:
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)
