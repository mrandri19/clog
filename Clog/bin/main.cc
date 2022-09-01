#include "clog.h"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage " << argv[0] << "site_source site_output" << std::endl;
        return 1;
    }
    try
    {
        clog_lib::Run(argv[1], argv[2]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
