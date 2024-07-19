##
## EPITECH PROJECT, 2023
## B-AIA-500-LIL-5-1-gomoku-maxence.crespel
## File description:
## Makefile
##

SOURCE = pbrain-gomoku-ai $(shell find src -name '*.py' -type f)

NAME =  pbrain-gomoku-ai

PATHS = $(shell python -c "import site; print('z:'.join(site.getsitepackages()))")

all:
ifeq ($(OS),Windows_NT)
	pyinstaller.exe  --paths $(PATHS) $(SOURCE) --name $(NAME).exe --onefile
	powershell copy dist\$(NAME).exe .
else
	chmod +x $(NAME)
endif


exe:
	wine pyinstaller.exe $(SOURCE) --name $(NAME).exe --onefile
	cp "dist/$(NAME).exe" .

clean:
ifeq ($(OS),Windows_NT)
	powershell -Command "if (Test-Path build) { Remove-Item -Recurse -Force build }"
	powershell -Command "if (Test-Path dist) { Remove-Item -Recurse -Force dist }"
	powershell -Command "Get-ChildItem -Filter *.spec | ForEach-Object { if (Test-Path $$_) { Remove-Item $$_ -Force } }"
else
	rm -rf build dist *.spec
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	powershell -Command "if (Test-Path $(NAME).exe) { Remove-Item -Recurse -Force $(NAME).exe }"
else
	rm -f $(NAME).exe
endif

re: fclean all

reexe: fclean exe

.PHONY: all clean
