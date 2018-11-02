sample.pdf: analizeGaussian.py sample.dat
	python analizeGaussian.py

sample.dat: sample.c
	g++ sample.c -o sample.x
	./sample.x 1000 0 1

clean:
	rm *.x
	rm *.dat
	rm *.pdf