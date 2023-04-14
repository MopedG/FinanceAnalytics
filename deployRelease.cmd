pushd .

:: copy dependencies
cd build\build-release
..\..\copyDep.cmd

popd

pause

:: more of your deployment steps