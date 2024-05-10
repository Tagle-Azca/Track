def Mergesort(mylist):
    
    if len(mylist) > 1:
    
        mid = len(mylist) // 2
        left = mylist[:mid]
        right = mylist[mid:]
        
        Mergesort(left)
        Mergesort(right)
        
        i = j = k = 0
        
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                mylist[k] = left[i]
                i += 1
            else:
                mylist[k] = right[j]
                j += 1
            k += 1
            
        while i < len(left):
            mylist[k] = left[i]
            i += 1
            k += 1
            
        while j < len(right):
            mylist[k] = right[j]
            j += 1
            k += 1
            
mylist = [2,5,76,7,8,6,4,345,7,568,6,123,3,26,6,734,34,3,4,3,4,34,46,6,6,3,7,7,2,1,7,45,7,47,8,5,685,3,5,673,7]

Mergesort(mylist)

print(mylist)