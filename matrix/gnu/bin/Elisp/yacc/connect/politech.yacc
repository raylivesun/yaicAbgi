
%{

LIVE(D):
   | D -> +1
   | D -> +2
pop_back();
void LIVE(D) {
    pop_back();
    return +1;
}
void LIVE(D) {
    pop_back();
    return +2;
}

%}


%{

DIE(OFF):
   | OFF -> -1
   | OFF -> -0
pop_back();
void DIE(OFF) {
    pop_back();
    return -1;
}
void DIE(OFF) {
    pop_back();
    return -0;
}

%}
