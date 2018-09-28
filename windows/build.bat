SET PATH=%PATH%;..\GWLLSD\bin
call del.bat
cd ../src
mingw32-make windows -s
cd ../windows
PAUSE