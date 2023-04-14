#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
using namespace std;



class Assembler{
    //data structures
    //condition and registers
    map<string, int> conditionInd;
    map<string, int> registerInd;
    vector<pair<string, int>> symTab;
    vector<pair<string, int>> litTab;

    //mnemonics
    struct mnemonics{
        string mnemonic;
        string m_class;
        int  opcode;
    }optab[18];

    string IC_OP_fname, litTab_fname, SymTab_fname, PoolTab_fname;
    string machineCode_fname; 

public:

    Assembler();
    void init_Pass1_DS();    
    int ispresent_symTsb(string);
    int get_LC(string);
    int get_LC(vector<pair<string, int>>&, int);
    int processSubToken(string);
    bool issubtoken(string);
    void update_symTsb(string, int);
    string IC_mnemonic(string);
    string IC_operand(string);
    int MC_operand(string);
    void pass1(string);
    void pass2();

};

Assembler :: Assembler(){
    IC_OP_fname = "ICoutput.txt";
    litTab_fname = "LitTab.txt";
    SymTab_fname = "symTab.txt";
    PoolTab_fname = "PoolTab.txt";
    machineCode_fname = "machineCode.txt";
}

//pass1 functions

void Assembler :: init_Pass1_DS(){

    registerInd.emplace("areg", 1);
    registerInd.emplace("breg", 2);
    registerInd.emplace("creg", 3);
    registerInd.emplace("dreg", 4);

    conditionInd.emplace("LT", 1);
    conditionInd.emplace("LE", 2);
    conditionInd.emplace("EQ", 3);
    conditionInd.emplace("GT", 4);
    conditionInd.emplace("GE", 5);
    conditionInd.emplace("ANY", 6);

    optab[0] = {"stop", "IS", 0};
    optab[1] = {"add", "IS", 1};
    optab[2] = {"sub", "IS", 2};
    optab[3] = {"mult", "IS", 3};
    optab[4] = {"mover", "IS", 4};
    optab[5] = {"movem", "IS", 5};
    optab[6] = {"comp", "IS", 6};
    optab[7] = {"bc", "IS", 7};
    optab[8] = {"div", "IS", 8};
    optab[9] = {"read", "IS", 9};
    optab[10] = {"print", "IS", 10};
    optab[11] = {"start", "AD", 1};
    optab[12] = {"end", "AD", 2};
    optab[13] = {"origin", "AD", 3};
    optab[14] = {"equ", "AD", 4};
    optab[15] = {"ltorg", "AD", 5};
    optab[16] = {"dc", "DL", 1};
    optab[17] = {"ds", "DL", 2}; 
} 

int Assembler :: ispresent_symTsb(string lab){
    for(int i = 0; i < symTab.size(); i++){
        if(symTab[i].first == lab) return i + 1;
    }
    
    pair<string, int> pr = {lab, 0};
    symTab.emplace_back(pr);
    
    return symTab.size();
}

void Assembler :: update_symTsb(string lab, int LC){
    for(int i = 0; i < symTab.size(); i++){
        if(symTab[i].first == lab) {symTab[i].second = LC; return;}
    }

    pair<string, int> pr = {lab, LC};
    symTab.emplace_back(pr);

    return;
}

int Assembler :: get_LC(string lab){
   for(int i = 0; i < symTab.size(); i++){
        if(symTab[i].first == lab) return symTab[i].second;
    } 
}

int Assembler :: processSubToken(string str){
    int nlc = 0;
    string o1, o2;
    char opr;
    for(auto c : str){
        if(c == '+' || c == '-'){
            opr = c;
            o1 = o2;
            o2 = "";
        }
        else{
            o2 += c;
        }
    }

    if(atoi(o2.c_str())){

        //op2 is number    
        if(opr == '+') nlc = get_LC(o1) + atoi(o2.c_str());
        else nlc = get_LC(o1) - atoi(o2.c_str());
    
    }
    else{
    
        if(opr == '+') nlc = get_LC(o1) + get_LC(o2);
        else nlc = get_LC(o1) - get_LC(o2);
    }

    return nlc;
}

bool Assembler ::  issubtoken(string op){
    for(auto c : op) if(c == '+' || c == '-') return true;
    return false;
}

string Assembler :: IC_mnemonic(string mnemo){
    string mne = "(";
    int i = 0;
    for(; i < 18; i++) if(optab[i].mnemonic == mnemo) break;
    mne += optab[i].m_class;
    mne += ",";
    mne += to_string(optab[i].opcode);
    mne += ")";
    return mne;
}

string Assembler :: IC_operand(string op){
    string operand = "-1";

    //registers
    if(op == "areg" || op == "breg" || op == "creg" || op == "dreg"){
        operand = "(";
        operand += to_string(registerInd.find(op)->second);
        operand += ")";
    }

    //conditions
    else if(op == "lt" || op == "le" || op == "eq" || op == "gt" || op == "ge" || op == "any"){
        operand = "(";
        operand +=  to_string(conditionInd.find(op)->second);
        operand +=  ")";
    }

    //literals
    else if(op[0] == '='){
        pair<string, int> pr;
        pr.first = op;
        pr.second = 0;
        litTab.emplace_back(pr);
        operand = "(l,";
        operand +=  to_string(litTab.size());
        operand +=  ")";
    }

    //string constants
    else if(op[0] == '\''){
        string str = op.substr(1, op.length()- 2);
        operand = "(c,";
        operand +=  str;
        operand +=  ")";
    }

    //sub token
    else if(issubtoken(op)){

        string o1, o2;
        char opr;
        for(auto c : op){
            if(c == '+' || c == '-'){
                opr = c;
                o1 = o2;
                o2 = "";
            }
            else{
                o2 += c;
            }
        }

        operand = "(s,";
        operand += to_string(ispresent_symTsb(o1));
        operand += ")";
        operand += opr;

        if(atoi(o2.c_str())){
            //op2 is number
            operand += o2;
        }
        else{
            operand = "(s,";
            operand += to_string(ispresent_symTsb(o2));
            operand += ")";
        }
    }

    //numeric constants
    else if(atoi(op.c_str())){
        operand = "(c,";
        operand +=  op;
        operand +=  ")";
    }

    //variables
    else{
        int ind = ispresent_symTsb(op);
        operand = "(s,";
        operand +=  to_string(ind);
        operand +=  ")";
    }

    return operand;
}

void Assembler :: pass1(string srcFile){
    
    init_Pass1_DS();
    int lc = 0, LitInd = 0; 

    fstream fin(srcFile.c_str(), ios::in);
    fstream IC_fout(IC_OP_fname.c_str(), ios::out);
    fstream symTab_fout(SymTab_fname.c_str(), ios::out);
    fstream PoolTab_fout(PoolTab_fname.c_str(), ios::out);
    fstream LitTab_fout(litTab_fname.c_str(), ios::out);
    
    string Str, label, opcode, op1, op2;
    bool end = false;
    getline(fin, Str);

    while(!end){

        stringstream ss;
        ss.str(Str);
        ss>>label>>opcode>>op1>>op2;
        
        //cout<<"label: "<<label<<"   opcode: "<<opcode<<"    op1: "<<op1<<"  op2: "<<op2<<endl;
        
        //label processing
        if(label != "$"  && opcode != "equ") update_symTsb(label, lc);

        //opcode processing
        if(opcode == "start"){
            lc = atoi(op1.c_str());
            IC_fout<<"-"<<" ";
        }

        else if(opcode == "stop" || opcode == "add" || opcode == "sub" || opcode == "mult" || opcode == "mover" || opcode == "movem" ||
                opcode == "comp" || opcode == "bc" || opcode == "div" || opcode == "read" || opcode == "print"){
            IC_fout<<lc<<" ";
            lc++;
        }

        else if(opcode == "end"){
            IC_fout<<"-"<<" ";
            end = true;
        }

        else if(opcode == "dc"){
            IC_fout<<lc<<" ";
            lc++;
        }

        else if(opcode == "ds"){
            IC_fout<<lc<<" ";
            lc = lc + atoi(op1.c_str());
        }

        else if(opcode == "equ"){

            //process lc for sub token
            update_symTsb(label, processSubToken(op1));
        }

        else if(opcode == "origin"){
            IC_fout<<"-"<<" ";

            lc = processSubToken(op1);
        }

        else if(opcode == "ltorg"){
            
            PoolTab_fout<<"#" + to_string(LitInd + 1)<<endl;
            vector<pair<string, int>> :: iterator itr;
            string line = "(DL,1) (c,"; 
            for(itr = litTab.begin() + LitInd; itr != litTab.end(); itr++){
                itr->second = lc;
                line += (itr->first).substr(2, (itr->first).length()- 3);
                line += ")";
                IC_fout<<to_string(lc)<<" "<<line<<endl;
                lc++;
                line = "(DL,1) (c,";
            }
            
            LitInd = litTab.size();

        }

        string IC_opcode, IC_op1, IC_op2;

        IC_opcode = IC_mnemonic(opcode);
        
        //operand processing
        if(op1 != "-"){IC_op1 = IC_operand(op1);}

        if(op2 != "-"){IC_op2 = IC_operand(op2);}
        
        //printing IC
        if(opcode != "equ" && opcode != "ltorg"){        
            IC_fout<<IC_opcode<<" "<<IC_op1<<" "<<IC_op2<<endl;
        }

        getline(fin, Str);
    }


    for(int i = 0; i < symTab.size(); i++){
        symTab_fout<<i+1<<" "<<symTab[i].first<<" "<<to_string(symTab[i].second)<<endl;
    }

    if(LitInd != litTab.size()){
        PoolTab_fout<<"#" + to_string(LitInd + 1)<<endl;
        vector<pair<string, int>> :: iterator itr;
        string line = "(DL,1) (c,"; 
        for(itr = litTab.begin() + LitInd; itr != litTab.end(); itr++){
            itr->second = lc;
            line += (itr->first).substr(2, (itr->first).length()- 3);
            line += ")";
            IC_fout<<to_string(lc)<<" "<<line<<endl;
            lc++;
            line = "(DL,1) (c,";
        }
    }
            
    for(int i = 0; i < litTab.size(); i++){
        LitTab_fout<<i+1<<" "<<litTab[i].first<<" "<<to_string(litTab[i].second)<<endl;
    }

    cout<<"Pass 1 implemented successfully!! => Intermediate code generated!"<<endl;
}

//Pass 2 functions

int Assembler :: get_LC(vector<pair<string, int>>& tab, int ind){
   for(int i = 0; i < tab.size(); i++){
        if(i == ind - 1) return tab[i].second;
    } 
}

void Assembler :: pass2(){
    fstream MC_fout(machineCode_fname.c_str(), ios::out);
    fstream IC_fin(IC_OP_fname.c_str(), ios::in);

    //Generate machine code

    string Str;
    getline(IC_fin, Str);
    
    while(!IC_fin.eof()){
        string lc, opcode, op1, op2;
        stringstream ss;
        ss.str(Str);
        ss>>lc>>opcode>>op1>>op2;

        
        if(lc != "-"){
            
            //update LC
            lc = lc + ")";
            MC_fout<<lc<<" ";
            
            //opcode update
            if(opcode.substr(1, 2) == "IS"){
                MC_fout<<opcode.substr(4, opcode.length() - 5)<<" ";
            }

            else{
                if(opcode[4] == '1'){
                    MC_fout<<"00"<<" "<<"0"<<" "<<op1.substr(3, op1.length() - 4)<<endl;
                }
                else{
                    MC_fout<<endl;
                }
                
                getline(IC_fin, Str);
                continue;
            }

            //generate opcode machine code
            string MC_op1, MC_op2;
            MC_op1 = to_string(MC_operand(op1)); 
            MC_op2 = to_string(MC_operand(op2));
            
            if(MC_op1 == "-1" && MC_op2 == "-1"){
                MC_fout<<"0"<<" "<<"000"<<endl;
            }
            else if(MC_op1 != "-1" && MC_op2 == "-1"){
                MC_fout<<"0"<<" "<<MC_op1<<endl;
            }
            else{
                MC_fout<<MC_op1<<" "<<MC_op2<<endl;
            }
        }

        getline(IC_fin, Str);
    }

    cout<<"Pass 2 implemented successfully!! => Machine code generated!"<<endl;
}

int Assembler :: MC_operand(string op){
    if(op.length() > 0){
        if(op[1] == 'l'){
            return get_LC(litTab, atoi(op.substr(3, op.length() - 4).c_str()));
        }   
        else if(op[1] == 's'){
            return get_LC(symTab, atoi(op.substr(3, op.length() - 4).c_str()));
        } 
        else{
            return atoi(op.substr(1, op.length() - 2).c_str());
        }
    }
    return -1;
}


int main(){
    Assembler driver;
    string fname;
    cout<<"enter src code file name: ";
    cin>>fname;
    fname += ".txt";
    driver.pass1(fname);
    driver.pass2();

    return 0;
}