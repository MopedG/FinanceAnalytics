pushd .

:: copy dependencies
cd ..\build\build-release
..\..\releases\copyDep.cmd

popd

pause

:: more of your deployment steps