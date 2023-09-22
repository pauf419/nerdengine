#include "Common.h"

Common::Common() {

}

void Common::log_CARTP_stats(CARTPoint p) {
    cout << "-- CARTPoint stats -- \n";
    cout << "__X: " << p.x << "\n";
    cout << "__Y: " << p.y << "\n";
}