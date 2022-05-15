def util(upRight):
	diff = []
	
	for i in range(105):
		diff.append([0 for i in range(105)])
		
	# a[1][y] += 1 and a[x + 1][y] -= 1
	for ele in upRight:
		temp = ele.split()
		y = int(temp[0])
		x = int(temp[1])
		
		for i in range(1, y + 1):
			diff[1][i] += 1
			diff[x + 1][i] -= 1
	
	return diff 

def countMax(upRight):
	a = util(upRight)
	
	maxi = -1
	
	for i in range(105):
		maxi = max(maxi, max(a[i]))
		
	cnt = 0 
	
	for i in range(105):
		for j in range(105):
			if a[i][j] == maxi:
				cnt += 1
				
	return cnt
	
upRight = ["1 4", "2 3", "4 1"]
print(countMax(upRight))