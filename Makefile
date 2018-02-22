build: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	@echo Building .cpp files

run: *.o
	for f in $^; do ./$$f 2>&1 > $$f.output.txt ; done

%.o: %.cpp
	@echo Building target $@
	g++ --std=c++14 -I$(HOME)/git/networking-ts-impl/include/ -o $@ $< -lpthread

clean:
	@echo Clean .o and .txt files
	rm -f *.o
	rm -f *.txt
