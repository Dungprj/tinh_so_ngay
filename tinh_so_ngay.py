a = [13,6,2000]
b = [3,12,2024]



def is_Nhuan(b):
	a = str(b)
	
	if (a[-1] == "0" and a[-2]=="0"):
		if (b%400==0):
			return True
		else:
			return False
	else:
		if (b%4==0):
			return True
		else:
			return False


def calc_day_in_year(a):
	if is_Nhuan(a) :
		return 366
	else:
		return 365


def calc_day_in_month(a):
	if (is_Nhuan(a[2])):
		if (a[1] in [1,3,5,7,8,10,12]):
			return 31
		elif a[1] == 2:
			return 29
		else:
			return 30
	else:
		if (a[1] in [1,3,5,7,8,10,12]):
			return 31
		elif a[1] == 2:
			return 28
		else:
			return 30


def is_year(a):
	if (a[2]>=1900 and a[2]<=9999):
		return True
	else:
	
		return False

def is_month(a):
	if (a[1]>=1 and a[1]<=12):
		return 1
	else:
		
		return 0


def is_day(a):
	if (a[0] >0 and a[0] <= calc_day_in_month(a)):
		return True
	else:
		return False

def is_Day(a):
	if (is_day(a) == True and is_year(a) == True and is_month(a) == True):
		return True
	else:
		return False


def calc_betwwen_year(a,b):
	if (a[2]==b[2]):
		s_day = 0
		for i in range(a[1]+1,b[1]):
			s_day+=calc_day_in_month([1,i,a[2]])
	
		ngay_du_truoc = calc_day_in_month(a)-a[0]
		ngay_du_sau = b[0]

		return s_day + ngay_du_truoc+ngay_du_sau
	else:
		s_day_in_year = 0
		for i in range(a[2]+1,b[2]+1):
			s_day_in_year +=calc_day_in_year(i)

		s_day = 0
		for i in range(a[1]+1,b[1]):
			s_day+=calc_day_in_month([1,i,a[2]])
	
		ngay_du_truoc = calc_day_in_month(a)-a[0]
		ngay_du_sau = b[0]

		return s_day_in_year+s_day+ngay_du_sau+ngay_du_truoc


def calc(a,b):
	if is_Day(a)== True and is_Day(b)== True:
		return calc_betwwen_year(a,b)
	else:
		return "nhap sai"

print(calc(a,b))

