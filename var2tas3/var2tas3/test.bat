REM ������ ��������� ��� ����������
Debug/var2tas3.exe 
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � �������������� ������
var2tas3.exe  notANumber.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ������� ��������� �� ����������� �������� �1 (� ��������� ���������)
var2tas3.exe  matrix.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� �� ����������� �������� �2 (� ��������� ���������)
var2tas3.exe  matrix2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� � ��������, ������� ������� ������������ (� ��������� ���������)
var2tas3.exe  matrix3.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT