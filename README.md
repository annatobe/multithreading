# MULTI THREADING

## Beschreibung des Programmes

In diesem Programm führen mehrere Threads gleichzeitig dieselbe Aufgabe aus und erhöhen dabei den gemeinsamen Zähler.

Auf den Zähler kann entweder ohne Synchronisation oder mit einem sogenannten Mutex zugegriffen werden.

Ziel ist es, zu zeigen, dass kritische Bereiche in Multithreading Programmen geschützt werden müssen.

## Mutex-Erklärung

Der Mutex schützt den kritischen Bereich im Programm. In diesem Projekt ist der kritische Bereich die Stelle, an der der gemeinsame Zähler erhöht wird.

Wenn die Synchronisation aktiviert ist, darf immer nur ein Thread gleichzeitig diesen Bereich betreten. Der Thread sperrt zuerst den Mutex, erhöht dann den Zähler und gibt den Mutex danach wieder frei.

Dadurch wird verhindert, dass mehrere Threads gleichzeitig denselben alten Zählerwert lesen und Änderungen verloren gehen.

## Verwendung

Das Programm wird über die Kommandozeile gesteuert und erwartet genau drei Parameter:

```bash
./multithreading threads runs sync
```

### Bedeutung der Parameter

* `threads`: Anzahl der zu startenden Threads
* `runs`: Anzahl der Durchläufe pro Thread
* `sync`: 0 = keine Synchronisation, 1 = Synchronisation mit Mutex

### Beispiel mit Mutex

```bash
./multithreading 4 1000000 1
```

### Beispiel ohne Mutex

```bash
./multithreading 4 1000000 0
```

## Kompilierung

```bash
gcc main.c shared.c parser.c utils.c -o multithreading -pthread
```

## Bibliotheken

Das Programm verwendet folgende Standard- und POSIX-Bibliotheken:

* `stdio.h` für Ein- und Ausgabe
* `stdlib.h` für Speicherreservierung und atoi
* `stdbool.h` für boolesche Werte
* `pthread.h` für POSIX-Threads und Mutex
* `time.h` für die Zeitmessung

## Dateien

* `shared.c`: verwaltet den gemeinsamen Zähler und Mutex, kritischer Bereich
* `utils.c`: enthält Thread-, Zeitmessung- und Fehlerausgabefunktionen
* `parser.c`: liest und überprüft Kommandozeilenargumente
* `main.c`: steuert Programmablauf. Argumente werden eingelesen, Threads erstellt und Ergebnisse berechent und ausgegeben

## Exit-Codes

* `WRONG_AR_NUMBER`: Es wurden zu viele oder zu wenige Argumente eingegeben
* `WRONG_INPUT`: Es wurden ungültige Werte für Threads, Runs oder active angegeben
* `MEMORY_ERROR = 3`: Es konnte kein Speicher reserviert werden
* `THREAD_ERROR = 4`: Es konnte kein Thread erstellt werden
* `OK = 0`
