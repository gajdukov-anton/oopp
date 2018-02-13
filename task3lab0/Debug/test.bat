REM запуск программы без параметров
task3.exe
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним нечисловым параметром
task3.exe notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с отрицательным числом в качестве одного из параметров
task3.exe -10 > output.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /B output.txt zero.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
task3.exe 6 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 6.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
task3.exe 14000000 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 14000000.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
task3.exe 1600 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 1600.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
task3.exe 2550000000000 > output.txt
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT