#include <iostream>
#include "merge_fit.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " input.obj [setting.config]" << std::endl;
        return 1;
    }
    std::string cad_in = argv[1];
    std::string cad_out = "";
    std::string config_file = argv[2];

    // std::string cad_in, cad_out, config_file;

    MergeFit mf;
    mf.set_surface_degree(3);
    mf.run(cad_in, cad_out, config_file);
    return 0;
}