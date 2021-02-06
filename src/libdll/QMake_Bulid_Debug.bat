call QMake_Clean.bat

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
qmake -o makefile libdll.pro
jom /f makefile.Debug

pause