import numpy
import matplotlib
from matplotlib import pyplot as plt

def getdata():
    t = numpy.linspace(0,4*numpy.pi,100)
    r = (0.25+t/10)
    X = (numpy.array([r*numpy.sin(2*t)+1,r*numpy.sin(1.1*t-0.5)]))
    Y = (numpy.array([r*numpy.sin(t),   -r*numpy.cos(t)+1]))
    return X,Y

def plotdata(X,Y):
    N = X.shape[1]
    f = plt.figure(figsize=(8,4))
    p1 = f.add_subplot(1,2,1); p1.set_xlim(-3,3); p1.set_ylim(-3,3)
    p1.scatter(X[0],X[1],c=numpy.arange(N))
    p2 = f.add_subplot(1,2,2); p2.set_xlim(-3,3); p2.set_ylim(-3,3)
    p2.scatter(Y[0],Y[1],c=numpy.arange(N))
    return p1,p2

def getHDdata():
    l = numpy.linspace(-2,2,100)
    p1,p2 = numpy.meshgrid(l,l)
    na = numpy.newaxis
    t = numpy.linspace(0,20*numpy.pi,200)[:,na,na]
    t = t - t.mean()

    def bfunc(r,t): return 2/(1+r**2)*numpy.cos(12*r-t)*numpy.cos(4*r-t)

    X = bfunc(((p1+1)**2+(p2+0)**2)**.5,t)+bfunc(((p1-1)**2+(p2+2)**2)**.5,t*0.468)
    Y = bfunc(((p1+1)**2+(p2+2)**2)**.5,t-1)+bfunc(((p1-1)**2+(p2+4)**2)**.5,t*0.468)

    X = X + numpy.random.normal(0,1.5,X.shape)
    Y = Y + numpy.random.normal(0,1.5,X.shape)

    return X.reshape(-1,10000).T,Y.reshape(-1,10000).T

def plotHDdata(x,y):
    f = plt.figure(figsize=(4,2))
    p1 = f.add_subplot(1,2,1)
    a = numpy.maximum(numpy.abs(x).max(),numpy.abs(y).max())
    p1.imshow(x.reshape(100,100),cmap='cividis',vmin=-a,vmax=a)
    p2 = f.add_subplot(1,2,2)
    p2.imshow(y.reshape(100,100),cmap='cividis',vmin=-a,vmax=a)
    return p1,p2

