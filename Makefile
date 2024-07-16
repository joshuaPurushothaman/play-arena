MAKEFLAGS += --silent

build: main.c arener/*
	echo "builting..."
	mkdir -p build
	gcc main.c arener/arener.c -o build/main 
# -O2

run: build
	echo "running...\n"
	./build/main

clean:
	rm -r build
# del /Q build