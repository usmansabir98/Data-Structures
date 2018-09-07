def shell_sort(num):
    """
    num is a list of integers to be sorted
    we h-sort the list using 3x+1 increments
    """
    N = len(num)    # N = number of elements

    h = 1
    while h<int(N/3):
        h=3*h+1     # 1, 4, 13, 40, 121,....

    while h>=1:

        for i in range(h,N):
            temp = num[i]
            j=i
            while j>0 and num[j-h]>temp:
                num[j] = num[j-h]
                j-=h
            num[j] = temp

        h=int(h/3)

a = [6,2,11,1,4,18,3,7]
shell_sort(a)
print(a)
