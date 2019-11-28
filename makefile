evolve_A.png : evolve_30_450.dat wave.x graficar.py
	python graficar.py

evolve_30_450.dat : wave.x
	./wave.x 0 > evolve_30_450.dat
	
wave.x : wave.cpp
	c++ wave.cpp -o wave.x
	
clean :
	rm -r *.dat *.x *.png
