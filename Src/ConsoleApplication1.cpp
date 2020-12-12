#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>

static const char allchars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int get_string_length = sizeof(allchars) - 1;
int password_length = 0;
int password_int;

char random() {
    return allchars[rand() % get_string_length];
}


int main()
{
    gen_password_save:
    system("title Secure pass");
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "Type pw length (max 256); ";
    std::cin >> password_length;

    if (password_length < 256 && password_length > 4) {
        std::string password;
        std::cout << "How much secured pw ? (Max 100)";
        std::cin >> password_int;
        if (password_int > 0 || password_length != NULL) {
            if (password_int < 100 && password_int > 0) {
                std::cout << "Pass created \n \n \n";
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                for (int j = 0; j < password_int; j++) {
                    for (int i = 0; i < password_length; i++) {
                        password += random();
                    }
                    std::cout << "pw(" << j + 1 << "): " << password << std::endl;
                    password = "";
                }
                std::cout << "\n" << std::endl;
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "Number OF Passwords must be bigger then 0 and less 1000. \n\n\n";
                goto gen_password_save;
            }

        }
        else {
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            std::cout << "Unexpected error FUCK YOU! \n \n \n";
            goto gen_password_save;
        }
        goto gen_password_save;
    }
    else {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "Password lenght must be bigger than 4 and less than 256 \n \n\ n";
        goto gen_password_save;
    }
    return 0;
}
