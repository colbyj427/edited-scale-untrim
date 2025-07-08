#include <iostream>
#include "merge_fit.h"

int main(int argc, char *argv[])
{
    // My addition
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " input.obj output.obj [config.txt]" << std::endl;
        return 1;
    }
    std::string cad_in = argv[1];
    std::string cad_out = argv[2];
    std::string config_file = (argc > 3) ? argv[3] : "";
    // *****

    // Uncomment for original
    // std::string cad_in, cad_out, config_file;

    MergeFit mf;
    mf.set_surface_degree(3);
    mf.run(cad_in, cad_out, config_file);
    return 0;
}