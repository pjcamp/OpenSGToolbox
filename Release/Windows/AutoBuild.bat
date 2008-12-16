echo off
set SUBVERSION_PATH=C:\Program Files\SlikSvn\bin
set REPOSITORY_URL=https://subversion.vrac.iastate.edu/Subversion/OpenSGToolbox/svn/OpenSGToolbox
set PROJECT_DIR=OpenSGToolbox
set BUILD_DIR=Builds\Windows
set VS_PATH=C:\Program Files\Microsoft Visual Studio 8\Common7\IDE
set SOLUTION_NAME=vs-8.0-OpenSGToolbox.sln

set LIBRARY_BUILD_ORDER=(Toolbox Input Sound Animation Dynamics ParticleSystem UserInterface Game)
set LIBRARY_BUILD_CONFIGURATIONS=(Debug Release)

:Setup the Directory
:rd /Q /S "%PROJECT_DIR%"
:md "%PROJECT_DIR%"

:Checkout the Repository
:"%SUBVERSION_PATH%\svn.exe" checkout "%REPOSITORY_URL%" "%PROJECT_DIR%" --non-interactive

:Move to Main Build Directory
cd "%PROJECT_DIR%"
pushd "%BUILD_DIR%"

:Build the Libraries
:FOR %%p in %LIBRARY_BUILD_ORDER% DO FOR %%c in %LIBRARY_BUILD_CONFIGURATIONS% DO "%VS_PATH%\devenv.com" "%SOLUTION_NAME%" /build %%c /project OSG%%p

:Build the Tutorials
popd
FOR %%p in %LIBRARY_BUILD_ORDER% DO (
    pushd %%p/Tutorials
    dir
    popd
)

:Build the Installer

pause