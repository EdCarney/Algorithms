start /wait  C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\demo-caesar\LDRA\Caesar_V10.tcf -95q


REM Setup TBINI for V10 minGW Safe_Utilities
set COMPILER=MinGW200 GCC C/C++ v3.2
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" CSTANDARDS_MODEL=MISRA-C:2012/AMD1
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" METFILE="C:\Demo\demo-safe-utilities\Configuration\Metpen.dat"


start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" TBRUN_BUILD_OPTIONS_FILE=%TBRUNINI%
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" BUILD_OPTIONS_FILE=%TESTBEDINI%


REM Setup TBINI for V10 demo-caesar
set COMPILER=MinGW200 GCC C/C++ v3.2
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" CSTANDARDS_MODEL=CWE-3.4
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" METFILE="C:\Demo\demo-caesar\LDRA\Metpen.dat"

----------------
REM config LDRA LDRA setup c:\demo\demo-safe-utilities

mkdir C:\Demo\demo-safe-utilities\LDRA
mkdir C:\Demo\demo-safe-utilities\Reports
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed safe-utilities -94q
if exist C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls rmdir /s /q C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls
if exist C:\Demo\demo-safe-utilities\Reports rmdir /s /q C:\Demo\demo-safe-utilities\Reports
mkdir C:\Demo\demo-safe-utilities\Reports

REM LDRA TBINI
set COMPILER=MinGW200 GCC C/C++ v3.2
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" CSTANDARDS_MODEL=CWE-3.4
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" METFILE="C:\Demo\demo-safe-utilities\LDRA\Metpen.dat"

rem LDRA scan V10
start /wait  C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\demo-safe-utilities\LDRA\safe-utilities.tcf -95q
start /wait  C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\demo-safe-utilities\LDRA\safe-utilities.tcf -review -CSTANDARDS_MODEL=CWE-3.4
start /wait  C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\demo-safe-utilities\LDRA\safe-utilities.tcf -review -CSTANDARDS_MODEL=MISRA-C:2012/AMD2

rem LDRA Regress UT
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_compress.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_int_to_dec.tcf /regress /tas /quit
rem C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed.exe "devops-safe-utilities" /32panq 

start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf1.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf2.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf3.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf4.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_string_compare.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\decops-safe-utilities\LowLevelTests\ut_safe_string_length.tcf /regress /tas /quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_uncompress.tcf /regress /tas /quit


start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_compress.tcf 212q
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_compress.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_int_to_dec.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf1.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf2.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf3.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_sprintf4.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_string_compare.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\decops-safe-utilities\LowLevelTests\ut_safe_string_length.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\devops-safe-utilities\LowLevelTests\ut_safe_uncompress.tcf -regress -box=white -quit


start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\contestbed C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_compress.tcf 212q
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_compress.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_int_to_dec.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_sprintf.tcf.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_sprintf1.tcf -regress -box=white -quit

rem LDRA regress UT
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_sprintf2.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_sprintf3.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_sprintf4.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_string_compare.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_string_length.tcf -regress -box=white -quit
start /wait c:\LDRA_Toolsuite_C_CPP_10.0.2\contbrun C:\Demo\demo-safe-utilities\LowLevelTests\ut_safe_uncompress.tcf -regress -box=white -quit

REM TBpublish Classic Report
if exist C:\Demo\devops-safe-utilities\Reports rmdir /s /q C:\Demo\devops-safe-utilities\Reports
mkdir C:\Demo\devops-safe-utilities\Reports

start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities.ldra –tbpublish –tbpublish_dir=C:\Demo\devops-safe-utilities\Reports

start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities.ldra –tbpublish –tbpublish_dir=C:\Demo\devops-safe-utilities\Reports
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities.ldra –preset="Classic" -tbpublish
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities.ldra –iso26262_compliance_report
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities.ldra –preset="ISO 26262 Compliance" -tbpublish
xcopy C:\LDRA_Workarea_C_CPP_10.0.2\devops-safe-utilities_tbwrkfls\devops-safe-utilities_publish\*.*  /S/Y/Q C:\Demo\devops-demo-safe-utilities\Reports

if exist C:\Demo\demo-safe-utilities\Reports rmdir /s /q C:\Demo\demo-safe-utilities\Reports
mkdir C:\Demo\demo-safe-utilities\Reports
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities.ldra –tbpublish –tbpublish_dir=C:\Demo\demo-safe-utilities\Reports
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities.ldra –preset="Classic" -tbpublish
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities.ldra –preset="Security Report" -tbpublish
start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities.ldra –preset="ISO 26262 Compliance" -tbpublish
xcopy C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities_publish\*.*  /S/Y/Q C:\Demo\demo-safe-utilities\Reports

start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities.ldra –preset="Classic" -tbpublish
copy C:\LDRA_Workarea_C_CPP_10.0.2\Caesar_V10_tbwrkfls\Caesar_V10_publish\*.* C:\Demo\demo-safe-utilities\Reports\

REM Word Report
cd C:\Program Files\Pandoc\
pandoc C:\Demo\demo-safe-utilities\Reports\index.htm -f html -t docx -o C:\Demo\demo-safe-utilities\Reports\demo-safe-utilities-report.docx


REM pdf Report
c:\LDRA_Workarea_C_CPP_10.0.2\safe-utilities_tbwrkfls\safe-utilities_publish\Index.htm -f html -t pdf -o C:\Demo\demo-safe-utilities\Reports\safe-utilities_Report.pdf --pdf-engine=pdflatex

Security Report
rem Generating Security Report
set PRJ=Cashregister
set WORK=C:\LDRA_Workarea_C_CPP_10.0.3
set TBR=start "ldra" /wait /min tbreports
set SECURITY_REPORT=%WORK%\%PRJ%_tbwrkfls\%PRJ%_publish\security\%PRJ%.seco.htm

%TBR% %WORK_DIR%\%PRJ%.ldra -preset="Security Report" -report_format=html,txt

--
set COMPILER=MinGW200 GCC C/C++ v3.2
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" COMPILER_SELECTED="%COMPILER%"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" CSTANDARDS_MODEL=CWE-3.4
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe /Section="C/C++ %COMPILER% LDRA Testbed" METFILE="C:\Demo\demo-algorithms\LDRA\Metpen.dat"
start  /wait /min C:\LDRA_Toolsuite_C_CPP_10.0.2\TBini.exe set SECURITY_REPORT=C:\LDRA_Workarea_C_CPP_10.0.2\devops-algorithms.exe_tbwrkfls\devops-algorithms.exe_publish\security\devops-algorithms.exe.seco.htm

start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-algorithms.exe_tbwrkfls\devops-algorithms.exe.ldra –preset="Security Report" -tbpublish
copy C:\LDRA_Workarea_C_CPP_10.0.2\devops-algorithms.exe_tbwrkfls\devops-algorithms.exe_publish\*.* C:\Demo\demo-algorithms\Publish

start /wait C:\LDRA_Toolsuite_C_CPP_10.0.2\tbreports C:\LDRA_Workarea_C_CPP_10.0.2\devops-algorithms.exe_tbwrkfls\devops-algorithms.exe.ldra –preset="Security Report" -report_format=html