sample.pdf: analizeGaussian.py sample.dat
	python analizeGaussian.py

sample.dat: sample.c
	g++ sample.c -o sample
	./sample 5000 5 2

clean:
	rm sample
	rm *.dat
	rm *.pdf