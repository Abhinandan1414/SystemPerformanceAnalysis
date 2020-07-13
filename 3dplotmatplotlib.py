import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

DataAll1D = np.loadtxt("custompowmodresult1.csv", delimiter=",")

# create 2d x,y grid (both X and Y will be 2d)
#X, Y = np.meshgrid(DataAll1D[:,1], DataAll1D[:,2])
#X, Y = np.meshgrid(DataAll1D[:,1], DataAll1D[:,2])
X = DataAll1D[:,2]
Y = DataAll1D[:,4]
Z = DataAll1D[:,6]
S = DataAll1D[:,4]

print (X)
print (Y)
print (Z)
print (S)



#Z = np.interp(Z, (Z.min(), Z.max()), (1, 10000))
#S = np.interp(S, (S.min(), S.max()), (1, 10000))
print (X)
print (Y)
print (Z)
print (S)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(X, Y, Z)
plt.show()
# repeat Z to make it a 2d grid
#Z = np.tile(DataAll1D[:,3], (len(DataAll1D[:,3]), 1))

#fig = plt.figure()
#ax = fig.add_subplot(111, projection='3d')

#ax.scatter(X, Y, Z, cmap='ocean')

#plt.show()
