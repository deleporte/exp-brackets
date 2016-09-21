# Begin functions.sage
S(x,y,N)=pi/N*exp(N*(-abs(x)^2/2-abs(y)^2/2+x*conjugate(y)))

def phi(x):
    if abs(x)<=1:
        return 0:
    elif abs(x)>=2:
    	return 1:
    else:
	return exp(-1/(abs(x)-1))*(1-exp(1/(abs(x)-2)))

