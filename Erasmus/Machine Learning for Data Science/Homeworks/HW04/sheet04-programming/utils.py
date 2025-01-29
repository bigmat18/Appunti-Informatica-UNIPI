import matplotlib
from matplotlib import pyplot as plt

def preparefigure():
    plt.figure(figsize=(8,4))
    plt.xlim(-3,3)
    plt.ylim(-1.5,1.5)
    plt.xlabel('PCA1')
    plt.ylabel('PCA2')
