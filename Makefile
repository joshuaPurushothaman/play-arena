run: build
	./build/main

build: main.c arener/*
	echo "builting..."
	mkdir -p build
	gcc main.c arener/arener.c -o build/main
	echo "can use -O2 later lol"

clean:
# wow, apparently `rm` doesn't actually exist on windows. heck
# del /Q build
# leaving this here for poor normal people:
	rm -r build


# ifeq ($(OS),Windows_NT)
#     DLLEXT := .dll
# else
#     DLLEXT := .so
# endif

# DLL := libfoo$(DLLEXT)

# lib : $(DLL)