# Дан массив a1,a2,…,an. Рассмотрим мультимножество S={ai⋅aj,i<j}. 
# Другими словами, S содержит все попарные произведения элементов массива.
# Требуется найти k-й элемент по возрастанию в этом мультимножестве.

# Входные данные
# В первой строке записаны два числа n,k (1≤n≤2⋅10^5,1≤k≤n(n−1)2) — 
# размер массива и какой элемент необходимо найти.
# Во второй строке записано n чисел a1,a2,…,an — элементы массива.

# Выходные данные
# Выведите k-й элемент по возрастанию в мультимножестве S.




def Solve():
    n,k = map(int, input().split())
    arr = [int(x) for x in input().split()]

    arr.sort()

    def lover_bound(val):
        lo, hi = 0, n
        while (lo<hi):
            mid = (lo+hi)//2
            if arr[mid] < val:
                lo = mid+1
            else:
                hi = mid
        return lo

    def upper_bound(val):
        lo, hi = 0, n
        while (lo<hi):
            mid = (lo+hi)//2
            if arr[mid] <= val:
                lo = mid+1
            else:
                hi = mid
        return lo

    candidates = [
        arr[0] * arr[1], 
        arr[0] * arr[-1],
        arr[-1] * arr[-2]
    ]
    left = min(candidates)
    right = max(candidates)

    def count_less_equal(x):
        first_zero = lover_bound(0)
        first_positive = upper_bound(0)

        neg = first_zero
        zero = first_positive - first_zero
        pos = n - first_positive

        if x < 0:
            cnt = 0
            j = pos - 1
            for i in range(neg):
                while j >= 0 and arr[i] * arr[first_positive + j] <= x:
                    j -= 1
                cnt += pos - 1 - j
            return cnt

        

    while (left<right):
        mid = (left+right)//2
        if (count_less_equal(mid) <= k):
            right = mid
        else:
            left = mid+1

    print(left)

Solve()