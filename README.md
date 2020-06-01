# math-tool

## Anleitung

### Abhängigkeiten
- `g++ (MinGW.org GCC-6.3.0-1) 6.3.0`
- `SDL2-2.0.12`
- `SDL2_ttf-2.0.15`

### Struktur
- `math-tool/` - Unser Projekt mit dem gesamten Quellcode.
    - `math-tool/gui/` - Der Grafik-Part unseres Projekts.
        - `math-tool/gui/lib/` - Die SDL2-Abhängigkeiten, nicht von uns(!) aber benötigt um das Programm zu kompilieren.
    - `math-tool/backend/` - Das "Backend" unseres Projekts.
    - `math-tool/bin/` - Der "Distributions"-Ordner des Projekts. Hier befinden sich die benötigten `dll`'s und hier landet die Executable und die Font-Datei. Dieser Ordner kann am Ende kopiert und verteilt werden um das Programm zu verbreiten. **Das Programm sollte aus diesem Ordner heraus ausgeführt werden.**
- `MinGW/` - Der von uns genutzte Compiler, portable, zum Mitschleppen!
- `start-mingw.bat` - Batch-Datei zum ausführen des Compilers.

### Kompilieren
Um das Projekt zu kompilieren muss zunächst die beiliegende Batch-Datei `start-mingw.bat` ausgeführt werden. Diese wird den `MinGW/bin`-Ordner temporär dem Path hinzufügen, damit wir über die geöffnete Konsole arbeiten können. Wenn der Ordner dem Path hinzugefügt wurde wird die `Powershell` geöffnet. Diese brauchen wir um das Projekt zu kompilieren.

Zum kompilieren des Projekts haben wir ein `Makefile` erstellt. Mit dem Befehl `make clean` werden alle zuvor kompilierten Object-Files und Executables gelöscht.
Mit `make` wird das gesamte Projekt kompiliert.
Diese Befehle müssen alle in der durch `start-mingw.bat` geöffneten Konsole mit der `Powershell` eingegeben werden!

### Programm ausführen
Wenn das Projekt erfolgreich durch `make` kompiliert wurde, kann das Programm dann auch gestartet werden. Einige Abhängigkeiten (wie SDL2 und SDL2_ttf) müssen als `dll` Datei im selben Ordner wie die `math_tool.exe` sein. Hierzu wurde der `bin/` Ordner erstellt. Um also das Programm auszuführen oder zu verbreiten, einfach in den `math-tool/bin/`-Ordner navigieren und den Inhalt kopieren oder die darin befindliche `math_tool.exe` ausführen um das Programm zu starten.

Der `bin/`-Ordner ist zur Distribution gedacht und das Programm sollte in dieser Konstellation auf jedem halbwegs aktuellen Windows-Rechner ausführbar sein.
