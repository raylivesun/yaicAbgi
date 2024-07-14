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

