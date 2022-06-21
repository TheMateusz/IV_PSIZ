#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>


std::fstream logFile;
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void createFile1(const std::string name, const int count, const char value);
calculateBer(std::string fpath1, std::string fpath2);
void printResult(results);

int main(int argc, char * argv[])
{
    std::string fpath1;
    std::string fpath2;
    results;

    if (argc != 3)
    {
        createFile1("t2file2.bin", 10, 0x91);
        createFile1("t1file1.bin", 100, 0x91);
        createFile1("t1file2.bin", 100, 0x91);
    }
    else
    {
        fpath1 = argv[1];
        fpath2 = argv[2];
    }


    return 0;
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2;
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value,1);
    }
    f.close();
}




