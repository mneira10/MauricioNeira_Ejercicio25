import matplotlib
matplotlib.use("Agg")
import numpy as np 
import matplotlib.pyplot as plt
from scipy.stats import norm

data = np.loadtxt('sample.dat')
plt.hist(data,normed = True)

mu, std = norm.fit(data)
xmin, xmax = plt.xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mu, std)
plt.plot(x, p, 'k', linewidth=2)
title = "Fit results: mu = %.2f,  std = %.2f" % (mu, std)
plt.title(title)
# plt.show()
plt.savefig('sample.pdf')
