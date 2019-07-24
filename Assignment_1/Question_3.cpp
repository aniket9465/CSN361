#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

template <typename TP>
TP str2num( std::string const& value ){

    std::stringstream sin;
    sin << value;
    TP output;
    sin >> output;
    return output;
}

template <typename TP>
std::string num2str( TP const& value ){
    std::stringstream sin;
    sin << value;
    return sin.str();
}
int Execute_Command( const std::string&  command,
                     std::string&        output,
                     const std::string&  mode = "r")
{
    std::stringstream sout;
    FILE *in;
    char buff[512];
    if(!(in = popen(command.c_str(), mode.c_str()))){
        return 1;
    }
    while(fgets(buff, sizeof(buff), in)!=NULL){
        sout << buff;
    }
    int exit_code = pclose(in);
    output = sout.str();
    return exit_code;
}
bool Ping( const std::string& address,
           const int&         max_attempts,
           std::string&       details )
{
    std::string command = "ping -c " + num2str(max_attempts) + " " + address + " 2>&1";
    std::string output;
    int code = Execute_Command( command, details );

    return (code == 0);
}

int main( int argc, char* argv[] )
{
    if( argc < 2 ){
        std::cerr << "usage: " << argv[0] << " <address> <max-attempts = 3>" << std::endl;
        return 1;
    }
    std::string host = argv[1];
    int max_attempts = 1;
    if( argc > 2 ){
        max_attempts = str2num<int>(argv[2]);
    }
    if( max_attempts < 1 ){
        std::cerr << "max-attempts must be > 0" << std::endl;
        return 1;
    }
    std::string details;
    bool result = Ping( host, max_attempts, details );
    std::cout << host << " ";
    if( result == true ){
        std::cout << " is responding." << std::endl;
    }
    else{
        std::cout << " is not responding.  Cause: " << details << std::endl;
    }
   return 0;
}
