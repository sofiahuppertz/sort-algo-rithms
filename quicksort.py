from random import randint


def main():
    arr = [2, 4, 5, 36, 3, 5, 45, 12, 64, 23, 1, 0, 9, 9]
    quickSort(arr, 0, len(arr) - 1)
    print(arr)

def swap(list, a, b):
    list[a], list[b] = list[b], list[a]
    return list


def partition(arr, low, high):
    pivotal_idx = randint(low, high)
    swap(arr, pivotal_idx, high)
    i  = low
    for j in range(low, high):
        if arr[j] < arr[high]:
            swap(arr, i, j)
            i += 1
    swap(arr, i, high)
    return i



def quickSort(arr, low, high):
    if low < high:
        pivotal_idx = partition(arr, low, high)
        quickSort(arr, low, pivotal_idx - 1)
        quickSort(arr, pivotal_idx + 1, high)

main()