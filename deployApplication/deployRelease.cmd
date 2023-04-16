pushd .

:: copy dependencies
cd ..\build\build-release
..\..\deployApplication\copyDep.cmd

popd

pause

:: more of your deployment steps