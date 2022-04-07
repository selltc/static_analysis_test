:: of course these assignments are temporary, for demo purposes only
set SQLOGIN=adc2f94c9d79b4097f3fe63dd6b1a069dc05741b
set WRAPPER="C:\Program Files\SonarQube\build-wrapper-win-x86\build-wrapper-win-x86-64.exe"
set SCANNER="C:\Program Files\SonarQube\sonar-scanner-cli-4.7.0.2747\bin\sonar-scanner.bat"
nmake clean
%WRAPPER% --out-dir ./sq-buildwrapper-output nmake
%SCANNER% -D"sonar.login=%SQLOGIN%" -Dproject.settings=./sonar.properties
rd /s/q sq-buildwrapper-output
