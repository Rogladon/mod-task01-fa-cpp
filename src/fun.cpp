unsigned int faStr1(const char *str) {
    int count = 0;
    bool inWord = false;
    bool isCorrectWord = true;
    while (*str) {
        if (*str != ' ' && isCorrectWord) {
            if (isDigit(*str)) isCorrectWord = false;
            inWord = true;
        }
        else if (*str == ' ' && inWord) {
            count++;
            inWord = false;
        }
    }
    if (inWord && isCorrectWord) count++;
    return count;
}
unsigned int faStr2(const char *str) {
    int count = 0;
    bool inWord = false;
    bool isCorrectWord = true;
    while (*str) {
        if (*str != ' ' && isCorrectWord) {
            if (!inWord) {
                if (!isUpperChar(*str)) isCorrectWord = false;
            }
            else {
                if (!isLowerChar(*str)) isCorrectWord = false;
            }
            inWord = true;
        }
        else if (*str == ' ' && inWord) {
            count++;
            inWord = false;
        }
    }
    if (inWord && isCorrectWord) count++;
    return count;
}
unsigned int faStr3(const char *str) {
    int count = 0;
    double totalLenght = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ') {
            totalLenght++;
            inWord = true;
        }
        else if (*str == ' ' && inWord) {
            count++;
            inWord = false;
        }
    }
    return round(totalLenght / count);
}

#pragma region Utilits
/// <summary>
/// �������� ������� �� ����� (�� 0 �� 9)
/// </summary>
/// <param name="ch">����������� ������</param>
/// <returns>true - �����, false - ���</returns>
bool isDigit(const char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}
/// <summary>
/// �������� ������� �� ��������� ���������
/// </summary>
/// <param name="ch">����������� ������</param>
/// <returns>true - ��������� ���������, false - ���</returns>
bool isLowerChar(const char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}
/// <summary>
/// �������� ������� �� ��������� ���������
/// </summary>
/// <param name="ch">����������� ������</param>
/// <returns>true - ��������� ���������, false - ���</returns>
bool isUpperChar(const char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return true;
    }
    return false;
}
/// <summary>
/// ���������� �� ���������� ������
/// </summary>
/// <param name="d">����� double</param>
/// <returns>������������� ����������� ��������</returns>
int round(double d) {
    int r = int(d);
    if (d - r < 0.5) return r;
    return r + 1;
}
#pragma endregion

