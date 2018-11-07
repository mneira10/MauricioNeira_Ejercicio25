sample.pdf: analizeGaussian.py sample.dat
	python3 analizeGaussian.py

sample.dat: sample.c
	g++ sample.c -o sample -std=c++11 
	./sample 5000 5 2

clean:
	rm sample
	rm *.dat
	rm *.pdf
