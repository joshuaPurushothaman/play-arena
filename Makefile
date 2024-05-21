run: build
	./build/main

build: main.c arener/*
	echo "builting..."
	mkdir -p build
	gcc main.c arener/arener.c -o build/main -O2

clean:
# wow, apparently `rm` doesn't actually exist on windows. heck
# del /Q build
# leaving this here for poor normal people:
	rm -r build


### This was kept here for reference of
### how to have an conditional OS check...
# ifeq ($(OS),Windows_NT)
#     DLLEXT := .dll
# else
#     DLLEXT := .so
# endif

# DLL := libfoo$(DLLEXT)

# lib : $(DLL)