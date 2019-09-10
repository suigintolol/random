#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

ofstream log("log_random.txt");

int * mhack(int * souse, unsigned int iter) {
    srand(iter);
    for(int i = 0; i < 5; i++) {
        souse[i] = rand();
    }
    return souse;
}

void print(int * souse) {
    for(int i = 0; i < 4; i++) {
        log << souse[i] << endl;
    }
    log << endl;
}

bool test(int * souse, int * bruthack) {
    for (int i = 0; i < 4; i++) {
        if(souse[i] != bruthack[i]) {
            return 0;
        }
    }
    return 1;
}

int * fortest(int * souse) {
    int * mh = new int[5];
    for (unsigned int i = 0; i < 1000000; i++) {
        mh = mhack(souse, i);
        if (test(mh, souse)) {
            return mh;
        }
    }
    log << "ERROR"<<endl;
    return mh;
}

int fortest(int one, int two, int tree, int four) {
    int * mh = new int[5];
    //int * souse = new int[4];
    int souse[] = {one, two, tree, four};
    for (unsigned int i = 0; i < 1000000; i++) {
        mh = mhack(mh, i);
        if (test(souse, mh)) {
            return mh[4];
        }
    }
    log << "ERROR" << endl;
    return -1;
}

bool check(int * souse) {
    int * number = fortest(souse);
    if (number[4] == souse[4]) {
            return true;
    } else {
        print(souse);
        print(number);
        log << number[4] << " != " << souse[4] << endl;
        return false;
    }
}

void nagruzka(int kol) {
    int * souse = new int[5];
    for (int i = 0; i < kol; i++) {
        souse = mhack(souse, time(NULL)%1000000);
        if (!check(souse)) {
            log << "-" << endl;
        } else {
            log << "+" << endl;
        }
    }
    log << " vse OK" << endl;
}

int main()
{
    nagruzka(1000000);
    log.close();
    return 0;
}
