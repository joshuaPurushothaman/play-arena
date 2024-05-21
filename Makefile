build: main.c arener/*
	echo "builting..."
	mkdir -p build
	gcc main.c arener/arener.c -o build/main -O2

run: build
	./build/main

clean:
	ifeq ($(OS),Windows_NT)
		del /Q build
	else
		rm -r build
	endif
# wow, apparently `rm` doesn't actually exist on windows. heck
# del /Q build
# leaving this here for poor normal people:
# rm -r build


### This was kept here for reference of
### how to have an conditional OS check...
# ifeq ($(OS),Windows_NT)
#     DLLEXT := .dll
# else
#     DLLEXT := .so
# endif

# DLL := libfoo$(DLLEXT)

# lib : $(DLL)