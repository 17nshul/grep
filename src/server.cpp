#include<iostream>
#include<string>

//function called for pattern matching
bool match_pattern(const std::string& input_line, const std::string& pattern){
    if(pattern.length()==1){
        return input_line.find(pattern)!= std::string::npos;
    }
    else{
        throw std::runtime_error("unhandled pattern" + pattern);
    }
}

int main(int argc, char* argv[]){
    
    //FLush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    if(argc != 3){
        std::cerr << "Expected two arguments" << std::endl;
        return 1;
    }

    std::string flag = argv[1];
    std::string pattern = argv[2];

    if(flag != "-E"){
        std::cerr<<"Expected first argument to be '-E'"<<std::endl;
        return 1;
    }

    std::string input_line;
    std::getline(std::cin, input_line);

    try{
        if(match_pattern(input_line, pattern)){
            return 0;
        } else {
            return 1;
        }

    } catch (const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}