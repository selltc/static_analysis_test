:: of course these assignments are temporary, for demo purposes only
set COVCONFIGURE="C:\tools\cov-analysis-win64-2021.12.1\bin\cov-configure.exe"
set COVBUILD="C:\tools\cov-analysis-win64-2021.12.1\bin\cov-build.exe"
nmake clean
%COVCONFIGURE% -msvc
%COVBUILD% --dir ./cov-int nmake
del static_analysis_test.zip
zip -r static_analysis_test.zip cov-int
@echo submit static_analysis_test.zip for analysis to
@echo https://scan.coverity.com/projects/selltc-static_analysis_test?tab=project_settings
rd /s/q cov-int
