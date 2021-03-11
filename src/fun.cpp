
#pragma region Utilits
/// <summary>
/// Checking a character for a digit (from 0 to 9)
/// </summary>
/// <param name="ch">checking character</param>
/// <returns>true - digit, false - other</returns>
bool isDigit(const char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}
/// <summary>
/// Checking a character for a lowecase
/// </summary>
/// <param name="ch">checking character</param>
/// <returns>true - lowercase, false - other</returns>
bool isLowerChar(const char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}
/// <summary>
/// Checking a character for Uppercase
/// </summary>
/// <param name="ch">checking character</param>
/// <returns>true - Uppercase, false - other</returns>
bool isUpperChar(const char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return true;
    }
    return false;
}
/// <summary>
/// Rounding to the nearest whole number
/// </summary>
/// <param name="d">double number</param>
/// <returns>int number</returns>
int round(double d) {
    int r = int(d);
    if (d - r < 0.5) return r;
    return r + 1;
}
#pragma endregion



unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool isCorrectWord = true;
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] != ' ' && isCorrectWord) {
            if (isDigit(str[index])) isCorrectWord = false;
            inWord = true;
        }
        else if (str[index] == ' ' && inWord) {
            count++;
            inWord = false;
        }
        index++;
    }
    if (inWord && isCorrectWord) count++;
    return count;
}
unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool isCorrectWord = true;
    int index = 0;
    while (str[index] != '\0') {
        if (str[index] != ' ' && isCorrectWord) {
            if (!inWord) {
                if (!isUpperChar(str[index])) isCorrectWord = false;
            }
            else {
                if (!isLowerChar(str[index])) isCorrectWord = false;
            }
            inWord = true;
        }
        else if (str[index] == ' ' && inWord) {
            count++;
            inWord = false;
        }
        index++;
    }
    if (inWord && isCorrectWord) count++;
    return count;
}
unsigned int faStr3(const char *str) {
    int count = 0;
    double totalLenght = 0;
    bool inWord = false;
    int index = 0;
    while (str[index] == '\0') {
        if (str[index] != ' ') {
            totalLenght++;
            inWord = true;
        }
        else if (str[index] == ' ' && inWord) {
            count++;
            inWord = false;
        }
        index++;
    }
    if (inWord) count++;
    if (totalLenght == 0 || count == 0) return 0;
    return round(totalLenght / count);
}
