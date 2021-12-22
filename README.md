### About
Sync files from A to B where A is the main file you want to be synced to file B

    A ➜ B

### Instruction
- **NOTE: Make sure to be inside of this repository for it to work**
1. Edit the **MainPath.txt** and **SyncPath.txt**
2. Add the full path of the file of which you want to place to be synced
3. In the MainPath add the _(A)_ Files that will be synced to _(B)_ File

- **NOTE: Make sure that both txt files are in the same exact order.
Example:**

|   MainPath.txt             |   SyncFiles.txt            |
|----------------------------|----------------------------|
| /home/Downloads/config.txt | /github/repo/config.txt    |
| /home/Documents/sample.py  | /github/repo/sample.py      |
| ...                        | ...                        |

- Linux: Run `make` command in terminal
- Windows:
    - Make sure to have `g++` installed and set to `$PATH`
    - Build project through editor or just do `g++ SyncFiles.cpp -o Main.exe; del Main.exe`