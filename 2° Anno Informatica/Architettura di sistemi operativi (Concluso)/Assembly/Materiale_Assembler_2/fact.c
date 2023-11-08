unsigned int fact(unsigned int n)
{
    unsigned int ris = 1;
    while (n != 0) {
        ris = ris * n;
        n = n - 1;
    }
    return ris;
}
