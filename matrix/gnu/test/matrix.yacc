%{

IERL(1):
    | IRLA -> long long magic number;
    | IRLB -> long long magic number;
    | IRLC -> long long magic number;
    | IRLD -> long long magic number;
    | IERE -> long long magic number;
    | IERF -> long long magic number;
    | IERG -> long long magic number;
    | IERY -> long long magic number;
    | IERZ -> long long magic number;

void IRL(1) {
    long long magic_number = 0;
    magic_number = 0;
    sort(magic, [](int a, int b) { return a > b; });
    for (int i = 0; i < magic.size(); i++) {
        magic_number += magic[i];
    
    }
    cout << magic_number << endl;
    return 0;
}    

%}

%{

LALR(1):
   | long long one;
   | long long two;
   | long long three;
   | long long four;
   | long long five;
   | long long six;
   | long long seven;
   | long long eight;
   | long long nine;
   | long long ten;
   | long long eleven;
   

   | unsigned long long one;
   | unsigned long long two;
   | unsigned long long three;
   | unsigned long long four;
   | long long five;
   | long long six;
   | long long seven;
   | long long eight;
   | long long nine;
   | long long ten;
   | long long eleven;

void main() {
    long long one = 1;
    long long two = 2;
    long long three = 3;
    long long four = 4;
    long long five = 5;
    long long six = 6;
    long long seven = 7;
    long long eight = 8;
    long long nine = 9;
    long long ten = 10;
    long long eleven = 11;

    unsigned long long one = 1;
    unsigned long long two = 2;
    unsigned long long three = 3;
    unsigned long long four = 4;
    unsigned long long five = 5;
    unsigned long long six = 6;
    unsigned long long seven = 7;
    unsigned long long eight = 8;
    unsigned long long nine = 9;
    unsigned long long ten = 10;
    unsigned long long eleven = 11;
}   


%}

BISON = <<START<<END
%{

LR(GLR):
  | GLR -> GPL -> set<int>(arrival);
  | GLR -> GPR -> set<int>(arrival);
  | GLR -> GRL -> set<int>(arrival);
  | GLR -> GRR -> set<int>(arrival);
  | GLR -> GRL -> set<int>(arrival);
  | GLR -> GRR -> set<int>(arrival);

void set(int arrival) { 
    arrival = arrival;
    char arrival[] = "";
    arrival = arrival;
    for (int i = 0; i < 512; i++) {
        arrival = arrival[i++];
        write(arrival);
    }
sort(arrival, [](int a, int b) { return a > b; });
return arrival;
%}
END 

