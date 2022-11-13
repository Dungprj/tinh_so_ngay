a = ["python","java","c++","sql","python","java"]

b = {}


for i in range(len(a)):
	b[a[i]] = 0;
for i in range(len(a)):
	b[a[i]] +=1

for key,value in b.items():
	print(key,":",value)
