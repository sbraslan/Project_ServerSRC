@echo off
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
cd %~dp0
REM msbuild m2server.sln /property:Configuration=Release /maxcpucount -target:Clean
msbuild m2server.sln /property:Configuration=Release /maxcpucount
pause
