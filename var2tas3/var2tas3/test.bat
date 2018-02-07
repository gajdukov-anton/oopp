REM запуск программы без параметров
Debug/var2tas3.exe 
IF ERRORLEVEL 1 GOTO err

REM запуск программы с несуществующим файлом
var2tas3.exe  notANumber.txt
IF NOT ERRORLEVEL 1 GOTO err

REM запууск программы со стандартной матрицей №1 (и проверяет результат)
var2tas3.exe  matrix.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы со стандартной матрицей №2 (и проверяет результат)
var2tas3.exe  matrix2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы с матрицей, имеющий нулевой определитель (и проверяет результат)
var2tas3.exe  matrix3.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT