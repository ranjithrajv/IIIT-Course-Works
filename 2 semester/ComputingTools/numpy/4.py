from numpy import *
from csv import *
from datetime import *
mon,tue,wed,thu,fri=[],[],[],[],[]
def a1(s):
	day=s.split("-")
	return date(int(day[2]),int(day[1]),int(day[0])).strftime("%A")
price = loadtxt('stock.csv', dtype=str, delimiter=',',usecols=(1,6),converters={1:a1})
#print price
for i in range(len(price)):
	if price[i,0]=="Monday":
		mon.append(price[i,1])
	elif price[i,0]=="Tuesday":
		tue.append(price[i,1])
	elif price[i,0]=="Wednesday":
		wed.append(price[i,1])
	elif price[i,0]=="Thursday":
		thu.append(price[i,1])
	elif price[i,0]=="Friday":
		fri.append(price[i,1])
	elif price[i,0]=="Saturday":
		sat.append(price[i,1])
mon,tue,wed,thu,fri = array(mon,dtype=float64), array(tue,dtype=float64), array(wed,dtype=float64), array(thu,dtype=float64),array(fri,dtype=float64)
mon,tue,wed,thu,fri = average(mon), average(tue), average(wed),average(thu),average(fri)
weekdays = array(['Monday','Tuesday','Wednesday','Thursday','Friday'])
days = array([mon,tue,wed,thu,fri],dtype=float64)
print "Average of each day is :\n"
print weekdays,"\n",days	
print "Lowest average weekday is :", weekdays[argmin(days)]
print "Highest average weekday is ", weekdays[argmax(days)]
