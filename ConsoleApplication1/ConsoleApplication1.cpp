#include <stdio.h>
#include <conio.h>
#include <windows.h>

char getKey();

int main(void) {
    char key;
    while (1) {
        key = getKey();
        if (key != '\0') {
            printf("%c", key);
            addnotRest();
        }
        else {
            printf("null");
            addRest();
        }
    }
    return 0;
}

char getKey() {
    if (kbhit()) {
        return getch();
    }
    return '\0'
}

int addreg(text) {
    LONG IResult;
    HKEY hKey;
    DWORD dwType;
    DWORD dwBytes = 100;
    char buffer[100];

    if (text = Rest) {
        IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\75b0ae3f-bce0-45a7-8c89-c9611c25e100", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
        if (IResult != ERROR_SUCCESS) {
            MessageBox(NULL, "Can't open target Registry", "Error", MB_0K);
        }
        RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 0, 1);

        IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
        if (IResult != ERROR_SUCCESS) {
            MessageBox(NULL, "Can't open target Registry", "Error", MB_0K);
        }
        RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 0, 1);
    }
    if (text = notRest) {
        IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\75b0ae3f-bce0-45a7-8c89-c9611c25e100", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
        if (IResult != ERROR_SUCCESS) {
            MessageBox(NULL, "Can't open target Registry", "Error", MB_0K);
        }
        RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 1, 1);

        IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
        if (IResult != ERROR_SUCCESS) {
            MessageBox(NULL, "Can't open target Registry", "Error", MB_0K);
        }
        RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 1, 1);
    }
}