#include"outils.h"
#include"Point.h"
#include <Imagine/Graphics.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <cassert>
using namespace Imagine;
using namespace std;
int keyboard() {
    Event e;
    do {
        getEvent(40, e);
        if (e.type == EVT_KEY_ON) {
            cout << e.key << endl;
            return e.key;
        }
    } while (e.type != EVT_NONE);
    return 0; // rien n’a été pressé
}

