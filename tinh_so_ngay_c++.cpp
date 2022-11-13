#include <bits/stdc++.h>


using namespace std;



struct date
{	
	int d;
	int m;
	int y;	
};

bool is_Nhuan(date b)
{
	string a = to_string(b.y);
	if (a[2] =='0' && a[3] == '0')
	{
		return b.y % 400 == 0;
	}else
	{
		return b.y%4==0;
	}
	
}


int calc_day_in_year(date a)
{
	if (is_Nhuan(a))
	{
		return 366;
	}else
	{
		return 365;
	}
}

int calc_day_in_month(date a)
{
	if (is_Nhuan(a))
	{
		switch(a.m)
		{
		
			case 1 : case 3: case 5 :case 7 :case 8 :case 10 :case 12:
				return 31;
				break;
			case 4 : case 6 : case 9 :case 11:
				return 30;
				break;
			case 2 :
				return 29;
				break;
			default :
				return false;
				break;
		}
	}else
	{
		switch(a.m)
		{
		
			case 1 : case 3: case 5 :case 7 :case 8 :case 10 :case 12:
				return 31;
				break;
			case 4 : case 6 : case 9 :case 11:
				return 30;
				break;
			case 2 :
				return 28;
				break;
			default :
				return false;
				break;
		}
	}
}


bool is_year(date a)
{
	return a.y >=1900 && a.y <=9999;
}


bool is_month(date a)
{
	return a.m >=1 and a.m <=12;
}


bool is_day(date a)
{
	return a.d >0 && a.d <= calc_day_in_month(a);
}
	
bool is_Day(date a)
{
	return is_day(a) == is_month(a)== is_year(a);
}


int calc_betweent_year(date a,date b)
{
	if (a.y == b.y)
	{
		int s_day = 0;
		for (int i = a.m+1;i<b.m;i++)
		{
			date tmp;
			tmp.d = 1;
			tmp.y = a.y;
			tmp.m = i;
			s_day+=calc_day_in_month(tmp);
			
		}
		int ngay_du_truoc = calc_day_in_month(a)-a.d;
		int ngay_du_sau = b.d;
		return s_day + ngay_du_truoc+ngay_du_sau;
	}else
	{
		int s_day_in_year =0;
		for (int i = a.y+1;i<=b.y;i++)
		{
			date tmp;
			tmp.d = 1;
			tmp.y = i;
			tmp.m = 2;
			s_day_in_year +=calc_day_in_year(tmp);
		}
		int s_day = 0;
		for (int i = a.m+1;i<b.m;i++)
		{
			date tmp;
			tmp.d = 1;
			tmp.y = a.y;
			tmp.m = i;
			s_day+=calc_day_in_month(tmp);
			
		}
		int ngay_du_truoc = calc_day_in_month(a)-a.d;
		int ngay_du_sau = b.d;
		return s_day + ngay_du_truoc+ngay_du_sau +s_day_in_year;
		
		
		
		
	}
}

int calc(date a,date b)
{
	if (is_day(a)==true&&is_month(a)==true&&is_year(a)==true&&is_day(b)==true&&is_month(b)==true&&is_year(b)==true)
	{
		calc_betweent_year(a,b);
	}
	else
	{
		return 0;
	}
}
int main()

{
	date a,b;
	a.d = 13;
	a.m = 6;
	a.y = 20004;
	b.d = 3;
	b.m = 12;
	b.y = 2024;
	
	
	
	cout<<calc(a,b);
	return 0;
	
}
