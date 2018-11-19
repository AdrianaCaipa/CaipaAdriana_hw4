# -*- coding: utf-8 -*-
"""
Created on Sat Nov 17 14:36:39 2018

@author: adria
"""

import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import Axes3D

#Angulo45 = np.genfromtxt('Datos1.txt')

#plt.figure()
#plt.plot(Angulo45[:,1], Angulo45[:,2])
#plt.xlabel('Trayectoria (m)')
#plt.ylabel('Altura (m)')
#plt.savefig('Adriana_CaipaGrafica45.pdf')

Promedio_f=np.genfromtxt('promedio_f.txt')
Promedio_p=np.genfromtxt('promedio_p.txt')
Promedio_l=np.genfromtxt('promedio_l.txt')

plt.figure()
plt.plot(Promedio_f)
plt.xlabel('tiempo')
plt.ylabel('temperatura')
plt.savefig('Promedio_f.png')


plt.figure()
plt.plot(Promedio_p)
plt.xlabel('tiempo')
plt.ylabel('temperatura')
plt.savefig('Promedio_p.png')


plt.figure()
plt.plot(Promedio_l)
plt.xlabel('tiempo')
plt.ylabel('temperatura')
plt.savefig('Promedio_l.png')

###Grafica3D####
colormap='cool'
temp_f=np.genfromtxt('Temperatura_f.txt')
mesh = np.linspace(0,0.5,50)
i,j=np.meshgrid(mesh, mesh)
figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_f[:50,:],cmap =colormap,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_f[1500:1500+50,:],cmap =colormap,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_f[2000:2000+50,:],cmap =colormap,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_f[-50:,:],cmap =colormap,rstride=1,cstride=1)
#plt.show()
####Segundagrafica3D

colormap1='seismic'
temp_p=np.genfromtxt('Temperatura_p.txt')
mesh = np.linspace(0,0.5,50)
i,j=np.meshgrid(mesh, mesh)
figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[:50,:],cmap =colormap1,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[2500:2500+50,:],cmap =colormap1,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[3000:3000+50,:],cmap =colormap1,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[-50:,:],cmap =colormap1,rstride=1,cstride=1)
plt.show()
######TerceraGrafica
temp_l=np.genfromtxt('Temperatura_l.txt')
colormap2='Spectral'
temp_p=np.genfromtxt('Temperatura_p.txt')
mesh = np.linspace(0,0.5,50)
i,j=np.meshgrid(mesh, mesh)
figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[:50,:],cmap =colormap2,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[2500:2500+50,:],cmap =colormap2,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[3000:3000+50,:],cmap =colormap2,rstride=1,cstride=1)


figura=plt.figure()
eje=Axes3D(figura)
eje.plot_surface(i,j,temp_p[-50:,:],cmap =colormap2,rstride=1,cstride=1)
plt.show()
