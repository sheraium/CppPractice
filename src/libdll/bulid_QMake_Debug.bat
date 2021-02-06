del makefile
del makefile.Debug
del makefile.Release
del .qmake.stash

rmdir /s/q debug
rmdir /s/q release
rmdir /s/q bin

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
qmake -o makefile libdll.pro
jom /f makefile.Debug

pause