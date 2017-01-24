.PHONY: clean

eigen: eigen.exe

eigen.exe: source.cc		\
		matrix.cc 
	@if [ ! -d "./bin" ]; then mkdir ./bin; fi
	g++  -std=c++11 $^ -o bin/eigen.exe 

clean:
	@if [ -d "./bin" ]; then rm -rf ./bin; fi
	@echo "Removed bin directory."
