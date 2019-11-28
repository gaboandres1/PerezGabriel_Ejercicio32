#Copia descarada del código de Jaime. Ejercicio 29.
import numpy as np
import matplotlib.pyplot as plt

def grafica(datafile, plotfile, plotlabel):
    data = np.loadtxt(datafile)
    
    
    plt.figure(figsize=(25,4))
    
    plt.subplot(1,3,1)
    s = np.shape(data)
    print(s)
    n_x = s[1]
    n_t = s[0]
    plt.imshow(data, extent = [-1,1,1,0], aspect=2.0)
    plt.colorbar(label="$Tension$")
    plt.xlabel("Posicion")
    plt.ylabel("Tiempo")
    plt.title(plotlabel+str(n_t))


    plt.subplot(1,3,2)
    x = np.linspace(0,1,n_x)
    delta_t = 0.1/n_t
    for i in range(n_t):
        if i%(n_t//9) == 0:
            plt.plot(x, data[i,:], label="t={:.02f}".format(i*delta_t))
    plt.legend(loc=1)
    plt.xlabel("Posicion")
    plt.ylabel("$Tension$")
            
    plt.subplot(1,3,3)
    t = np.linspace(0,0.1,n_t)
    plt.plot(t, data[:,n_x//4], alpha=i/n_t, color='black')
    plt.xlabel("Tiempo")
    plt.ylabel("$T$(x=0)")

    plt.savefig(plotfile, bbox_inches='tight')

grafica("evolve_30_450.dat", "evolve_A.png", "$N_x=101$ ,  $N_{tc}=$")
