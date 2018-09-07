def radix(arr):
    buckets = [[],[],[],[],[],[],[],[],[],[]]
    m = 10
    n = 1
    # Pass=1
    flag=1
    while(flag): #flag becomes 0 if all the MSBs become 0.
        flag = 0
        for i in arr: #traversing array
            bucket = i%m
            bucket = int(bucket/n)
            buckets[bucket].append(i)
            if bucket!=0:
                flag=1

        count=0;
        for j in buckets:
            while j:
                arr[count] = j.pop(0)
                count+=1
        m*=10
        n*=10
        # Pass+=1

num = [23,21,221,105,4,11,67]

radix(num)
print(num)

