@echo off
set one=%1

if "%one%"=="" (
set one=.
)

for /r %one% %%i in ("*.*") do (
type "%%i" >"%%i~1"
move /Y "%%i~1" "%%i"
)
