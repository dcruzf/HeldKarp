CXX = g++
CXXFLAGS = -O3

output: main.o tomatrix.o combinations.o heldkarptsp.o
	${CXX} main.o tomatrix.o combinations.o heldkarptsp.o -o output

tomatrix.o: tomatrix.h
combinations.o: combinations.h
heldkarptsp.o: heldkarptsp.h

clean:
	rm *.o output