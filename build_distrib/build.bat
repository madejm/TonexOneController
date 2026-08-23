rem build all variants
python .\batch_build.py -p ../source

rem build installers and Polar artifacts
python .\build_distrib.py
pause
