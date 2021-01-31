#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

// do something after 10 minutes of user inactivity
static const unsigned int idle_milliseconds = 60 * 10 * 1000;

int main() {
    LASTINPUTINFO last_input;
    // without setting cbSize GetLastError() returns the parameter is incorrect
    last_input.cbSize = sizeof(last_input);
    BOOL screensaver_running;

    DWORD idle_time;
    bool screensaverOn = false;

    // main loop to check if user has been idle long enough
    for (;;) {
        if (!GetLastInputInfo(&last_input)
            || !SystemParametersInfo(SPI_GETSCREENSAVERRUNNING, 0,
                &screensaver_running, 0))
        {
            std::cerr << "WinAPI failed!" << std::endl;
            return 0;
        }

        // calculate idle time
        idle_time = GetTickCount() - last_input.dwTime;

        if (idle_time > this->user_idle_time&& TRUE == screensaver_running)
        {
            if (!screensaverOn)
            {
                // screensaver is running
                rest();
                screensaverOn = true;
            }
        }
        else if (idle_time < this->user_idle_time && screensaverOn)
        {
            // screensaver is not running
            notRest();
            screensaverOn = false;
        }
        // wait 500ms before next loop
        Sleep(500);
    }
}

void rest() {
    LONG IResult;
    HKEY hKey;
    DWORD dwType;
    DWORD dwBytes = 100;
    char buffer[100];

    IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\75b0ae3f-bce0-45a7-8c89-c9611c25e100", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
    if (IResult != ERROR_SUCCESS) {
        MessageBox(NULL, "Can't open target Registry", "Error", MB_OK);
    }
    RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 0, 1);

    IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
    if (IResult != ERROR_SUCCESS) {
        MessageBox(NULL, "Can't open target Registry", "Error", MB_OK);
    }
    RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 0, 1);
}
void notRest() {
    LONG IResult;
    HKEY hKey;
    DWORD dwType;
    DWORD dwBytes = 100;
    char buffer[100];

    IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\75b0ae3f-bce0-45a7-8c89-c9611c25e100", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
    if (IResult != ERROR_SUCCESS) {
        MessageBox(NULL, "Can't open target Registry", "Error", MB_OK);
    }
    RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 1, 1);

    IResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\CurrentControlSet\Control\Power\PowerSettings\54533251-82be-4824-96c1-47b60b740d00\be337238-0d82-4146-a960-4f3749d470c7", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hKey);
    if (IResult != ERROR_SUCCESS) {
        MessageBox(NULL, "Can't open target Registry", "Error", MB_OK);
    }
    RegSetValueEx(hKey, "Attributes", 0, REG_DWORD, 1, 1);
}