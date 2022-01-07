import os


def equalfilesize():
    pass


def syncfiles():
    pass


def main():
    GREEN = '\033[1;32m'
    RED = '\033[0;31m'
    RESET = '\033[0m'

    MAINPATH = open('MainPath.txt', 'r')
    SYNCPATH = open('SyncPath.txt', 'r')

    mainpath_lines = MAINPATH.read().splitlines()
    syncpath_lines = SYNCPATH.read().splitlines()
    
    for i in range(0, len(mainpath_lines)):
        if os.path.getsize(mainpath_lines[i]) == os.path.getsize(syncpath_lines[i]):
            sub_mainpath_lines = open(mainpath_lines[i], 'r')
            sub_syncpath_lines = open(syncpath_lines[i], 'r')

            if sub_mainpath_lines.read().splitlines()[i] == sub_syncpath_lines.read().splitlines()[i]:
                print('{0}"{1}" and "{2}" are already synced!{3}'.format(GREEN, mainpath_lines[i], syncpath_lines[i], RESET))
        else:
            # sync files
            print('{0}"{1}" is NOT Up to Date! Syncing File to "{2}"'.format(RED, syncpath_lines[i], mainpath_lines[i], RESET))
            sub_syncpath_lines_w = open(syncpath_lines[i], 'w')
            


if __name__ == '__main__':
    main()