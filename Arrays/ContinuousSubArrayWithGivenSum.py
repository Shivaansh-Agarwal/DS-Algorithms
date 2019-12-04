n,s = map(int,input().strip().split())
arr = list(map(int,input().strip().split()))

currSum = arr[0]
start = 0
temp = False

for i in range(1,n+1):
    while currSum<s and start<i-1:
        currSum -= arr[start]
        start+=1
    if currSum==s:
        print("Subarray found from",start+1,i)
        temp = True
        break
    if i<n:
        currSum += arr[i]

if not(temp):
    print(-1)

        
