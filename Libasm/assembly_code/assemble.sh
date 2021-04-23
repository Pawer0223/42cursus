nasm -f macho64 hello.asm
ld hello.o -o hello -macosx_version_min 11.0 -L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib -lSystem
./hello
rm hello.o hello
