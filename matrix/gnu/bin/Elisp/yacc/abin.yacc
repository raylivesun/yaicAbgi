%{

LR(GLR):
// GPL version
   | GLR -> GPL -> SDL -> OK;
   | GLR -> SDL -> OK;
   | GLR -> OK;
   | SDL -> OK;

void GLR(GLR):
   typedef int GLR;
   typedef int SDL;
   typedef int OK;
END;

GLR(GLR);

%}

%token 
