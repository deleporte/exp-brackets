from scipy import integrate
import ctypes
import numpy as np
import os

pathlib = os.getcwd() + '/base-functions.so'
lib = ctypes.CDLL(pathlib)
mytype = (ctypes.c_int, ctypes.c_int, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double)
lib.realInt.restype = ctypes.c_double
lib.realInt.argtypes = mytype
lib.imagInt.restype = ctypes.c_double
lib.imagInt.argtypes = mytype

#def integrand(N,k,l,x,y):
#    return e(N,k,x,y)*h(x,y)*np.conj(e(N,l,x,y))/(1+x*x+y*y)**2

def I(N,k,d):
    return integrate.nquad(lambda x,y,z,w,u,v,s,t: lib.realInt(N,k,x,y,z,w,u,v,s,t,d), [[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf]])[0] + integrate.nquad(lambda x, y: lib.imagInt(N,k,x,y,z,w,u,v,s,t,d), [[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf],[-np.inf,np.inf]])[0]*1j
