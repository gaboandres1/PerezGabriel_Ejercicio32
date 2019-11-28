grafica.png : data.dat wave.x graficar.py
	python graficar.py

data.dat : wave.x
	./wave.x 1 > data.dat
	
wave.x : wave.cpp
	c++ wave.cpp -o wave.x
	
clean :
	rm -r *.dat *.x *.png
