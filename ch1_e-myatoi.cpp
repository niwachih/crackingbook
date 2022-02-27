//CHIH: leetcode medium problem
//20220227
int myAtoi(char * s){
    char *ptr = s;
    int ret = 0;
    int sign;
    int i;
    
    if ((*ptr <= 'z') && (*ptr >= 'a'))
        return 0;
    while (*ptr == ' ')
        ptr++;
    if ((ptr[0] == '+') && (ptr[1] == '-'))
        return 0;
    if ((ptr[0] == '-') && (ptr[1] == '+'))
        return 0;
    if (*ptr == '-') {
        //negative number
        sign = -1;
        ptr++;
    } else if (*ptr == '+') {
        sign = 1;
        ptr++;
    } else {
        sign = 1;
    }
    while (*ptr == '0')
        ptr++;
    for (i = 0; ptr[i] != '\0'; i++) {
        if ((ptr[i] == ' ') || (ptr[i] == '.'))
            ptr[i] = '\0';
    }
    for (i = 0; ptr[i] != '\0'; i++) {
        if (i >= 9) {
            if (sign == 1)
                return pow(2,31);
            else
                return pow(2,31)*(-1);
        } else {
            ret = (ret * 10) + (ptr[i] - '0');
        }
        if (ptr[i] == '-')
            return 0;
        if ((ptr[i] <= 'z') && (ptr[i] >= 'a'))
            return 0;
    }
    return ret*sign;
}
