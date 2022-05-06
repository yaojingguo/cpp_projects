#include "glog/logging.h"

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "Found " << 10 << " cookies";
    LOG(ERROR) << "an error message";

    // vlog
    VLOG(0) << "vlog 0 message";
    VLOG(1) << "vlog 1 message";
    VLOG(2) << "vlog 2 message";
}