#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
    HKEY h;
    unsigned long value = 1;
    unsigned long buff = 3;
    char* path = TEXT("COUNT");
    if (RegCreateKeyEx(HKEY_CURRENT_USER, path, NULL, NULL, 0x00000001L, KEY_ALL_ACCESS, NULL, &h, NULL) == ERROR_SUCCESS)
    {
        printf_s("Start program\n");
        if (RegQueryValueEx(h, path, NULL, NULL, &value, &buff) == ERROR_SUCCESS)
        {
            value++;
            if (value > 3)
            {
                printf_s("End demo version");
                exit(1);
            }
            else
            {
                printf_s("%d launch\n", value);
            }
            RegSetValueEx(h, path, NULL, REG_QWORD, &value, 3);
        }
        else
        {
            RegSetValueEx(h, path, NULL, REG_QWORD, &value, 3);
            printf_s("%d launch\n", value);
        }
    }
    return 0;
}