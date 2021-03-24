#include <iostream>
#include <vector>
#include <map>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

map<string, string> rule_map;

string get_next_string(string parse_string){
    istringstream ss(parse_string);
    string stringBuffer;
    getline(ss, stringBuffer, ' ');

    return stringBuffer;
}

void mapping_flag_rules(vector<string> &flag_rules){
    for(auto flag_rule_string : flag_rules){
        string command = get_next_string(flag_rule_string);
        string rule = get_next_string(flag_rule_string);
        rule_map[command] = rule;
    }
}

boolean check_program_right(string program, string command){
    if(program == command) return true;
    return false;
}

int main() {
    FAIO;

    string command_program = get_next_string(command_program);
    if(!check_program_right(program, command_program)){
        answer.push_back(False);
    }

    for(auto s : commands)
    
    
    

   
    return 0;
}

