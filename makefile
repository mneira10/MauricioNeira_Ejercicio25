sample.pdf: analizeGaussian.py sample.dat
	python analizeGaussian.py

sample.dat: sample.cpp
	g++ sample.cpp -o sample.x
	./sample.x 5000 5 2

clean:
	rm *.x
	rm *.dat
	rm *.pdf