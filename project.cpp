#include<bits/stdc++.h>
using namespace std;

vector<string> keyword = {"int", "main", "scanf", "printf", "auto", "case", "break", "char", "float", "double", "bool", "const", "static",
"struct", "switch", "typedef", "volatile", "continue", "default", "do", "while", "if", "else", "enum", "extern", "for", "goto", "long",
"register", "return", "short", "sign", "sizeof", "union", "void", "unsigned"};

vector<char> Operator = {'+', '-', '*', '/', '=', '&'};
vector<char> seperator = {',', '(', ')', '{', '}', '[', ']', ';'};


int is_keyword(string n){
    int count = 0;

    for(int i = 0; i<sizeof(keyword); i++){
        if(n == keyword[i]){
            count = 1;
            break;
        }
    }
    return count;
}

int is_operator(char n){
    int count = 0;

    for(int i = 0; i<sizeof(Operator); i++){
        if(n == Operator[i]){
            count = 1;
            break;
        }
    }
    return count;
}

int is_seperator(char n){
    int count = 0;

    for(int i = 0; i<sizeof(seperator); i++){
        if(n == seperator[i]){
            count = 1;
            break;
        }
    }
    return count;
}

int is_validIdentifier(string n){
    int count = 0;
    if(n.size()>1){
        if((n[0]>='a' && n[0]<='z') || (n[0]>='A' && n[0]<='Z' || n[0] == '_')){
            for(int k=1; k<n.size(); k++){
                if(n[k]>='a' && n[k]<='z' || n[k]>='A' && n[k]<='Z' || n[k]>='0' && n[k]<='9' || n[k]=='_'){
                    count = 1;
                }else{
                    count = 0;
                    break;
                }
            }
        }
    }else{
        if((n[0]>='a' && n[0]<='z') || (n[0]>='A' && n[0]<='Z')) {count = 1;}
    }

    return count;
}


int main(){
    vector<string> token;
    string data, word, q;
    map<string, int> Identifier;
    int idx = 1;
    bool flag = false;
    int add = 0, sub = 0, mul = 0, div = 0;

    ifstream infile;
    infile.open("project.txt");

    while(!infile.eof()){
        getline(infile, data);

        stringstream s(data);
        while(s >> word){
            if(word[0] == '#'){continue;}
            token.push_back(word);
        }
    }
    infile.close();

    // for(int i = 0; i<token.size(); i++){
    //     cout<< token[i] <<endl;
    // }

    for(int i = 0; i<token.size(); i++){
        q = token[i];

        if(q[0] == '#' || q[0] == '"'){
            continue;
        }
        if(is_keyword(q)){
            cout<< q << " is keyword\n";
            continue;
        }
        else if(is_operator(q[0])){
            cout<< q << " is operator\n";
            continue;
        }
        else if(is_seperator(q[0])){
            cout<< q << " is seperator\n";
            continue;
        }
        else if(is_validIdentifier(q)){
            if(Identifier[q]<1){
                cout<< q <<" Id "<< idx << endl;
                Identifier[q] = idx;
                idx++;
            }
            else{
                cout<< q <<" Id "<< Identifier[q] <<endl;
            }

            continue;
        }
    }

}