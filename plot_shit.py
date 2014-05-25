import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt('shit.txt')

plt.figure(figsize=[8,8])
plt.scatter(data[:,0], data[:,1], edgecolor='None',s=6)
plt.xlim([-10e-3, 10e-3]); plt.ylim([-10e-3, 10e-3])

plt.figure()
plt.plot(data[:,0])