run: build
	./build/main.exe

build: main.c arener/*
	echo "builting..."
	if not exist build mkdir build
	gcc main.c arener/arener.c -o build/main.exe
	echo "can use -O2 later lol"

# Also there's totally a silly bug here LOL:
# if you clean then run without changing any files, it borks

clean:
# wow, apparently `rm` doesn't actually exist on windows. heck
	del /Q build
# leaving this here for poor normal people:
# rm -r build