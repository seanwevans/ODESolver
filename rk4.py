def f(t,y):
	return(-2*y+t+4)
	
def k1(tn,yn,h):
	return(f(tn,yn))
	
def k2(tn,yn,h):
	return(f(tn+(h/2),yn+(h/2)*(k1(tn,yn,h))))
	
def k3(tn,yn,h):
	return(f(tn+(h/2),yn+(h/2)*(k2(tn,yn,h))))
	
def k4(tn,yn,h):
	return(f(tn+h,yn+(h*k3(tn,yn,h))))
	
t0 = 0
y0 = 1

h = 0.2

y1 = y0 + (h/6) * (k1(t0,y0,h) + 2*k2(t0,y0,h) + 2*k3(t0,y0,h) + k4(t0,y0,h))
t1 = t0 + h

print("y(",t1,") ~= ",y1)