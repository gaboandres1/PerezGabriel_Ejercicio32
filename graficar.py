import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

data = np.loadtxt('data.dat')

x = np.linspace(0,1,data.shape[1])
t = np.linspace(0,10,data.shape[0])

X,T = np.meshgrid(x,t)

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X,T,data)
ax.set( xlabel='Space', ylabel='Time', zlabel='Tension')
plt.savefig('grafica.png')