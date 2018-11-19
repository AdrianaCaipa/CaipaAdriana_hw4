# -*- coding: utf-8 -*-
"""
Created on Sat Nov 17 14:36:39 2018

@author: adria
"""

import numpy as np
import matplotlib.pylab as plt

Angulo45 = np.genfromtxt('datos45.txt')

plt.figure()
plt.plot(Angulo45[:,1], Angulo45[:,2])
plt.xlabel('Trayectoria (m)')
plt.ylabel('Altura (m)')
plt.savefig('Adriana_CaipaGrafica45.pdf')


