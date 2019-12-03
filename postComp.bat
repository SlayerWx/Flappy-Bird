copy %1raylib.dll %2 /y
mkdir %2assets
xcopy %1resource\assets %2\assets /s /e /y /i
pause