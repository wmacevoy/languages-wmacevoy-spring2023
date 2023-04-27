
#include <stdint.h>
#include <fstream>
#include <vector>

// Stream - (bytes -> codepoints)

class Stream {
    // return next codepoint, or -1 for EOF
    public: virtual int32_t read() = 0;
};

class FileStream : Stream {
    private: std::ifstream input;
    FileStream(std::string filename) : input(filename) {}
    int32_t read() {
        // TODO: read bytes from "input" and return
        // the next unicode code point.
    }
};

enum TokenTypes { NUM_TOKEN,
                  LPAREN_TOKEN,
                  RPAREN_TOKEN,
                  ADD_TOKEN,
                  MUL_TOKEN,
                  EOF_TOKEN};
class Token {
    int lineno;
    int columno;
    public: virtual int32_t type() const = 0;
};

class NumToken : Token {
    int value;
    public: virtual int32_t type() const {
        return NUM_TOKEN;
    }
    NumToken(int _value) : value(_value) {
    }
};

class LParenToken : Token {
    public: virtual int32_t type() const {
        return LPAREN_TOKEN;
    }
};

class AddToken : Token {
    public: virtual int32_t type() const {
        return ADD_TOKEN;
    }
};

class EofToken : Token {
    public: virtual int32_t type() const {
        return EOF_TOKEN;
    }
};


class Scanner {
    public: Stream *stream;
    // read until return EOF_TOKEN
    public: virtual Token* read() = 0;
};

class DefaultScanner : public Scanner {
    public: virtual Token* read() {
        int32_t codepoint = stream->read();
        if ('0' <= codepoint && codepoint <= '9') {
            int value = codepoint - '0';
            for (;;) {
                int32_t codepoint = stream->read();
                if ('0' <= codepoint && codepoint <= '9') {
                    value = value * 10 + (codepoint - '0');
                } else {
                    stream->unread(codepoint);
                    break;
                }
            }
            return new NumToken(value);
        }
        if (codepoint == '+') {
            return new LParenToken();
        }
    }
};

enum SyntaxTreeType {
    ADD_NODE,
    MUL_NODE,
    NUM_NODE
};

class SyntaxTreeNode;


class SyntaxTreeNode {
    public: virtual int32_t type() const = 0;
    public: std::vector<SyntaxTreeNode*> children;
};

class NumNode : SyntaxTreeNode {
    NumToken *numToken;
    virtual int32_t type() const { return NUM_NODE; }
    NumNode(NumToken *_numToken) : numToken(_numToken) {}
};

class AddNode : SyntaxTreeNode {
    virtual int32_t type() const { return ADD_NODE; }
    AddNode(SyntaxTreeNode *left, SyntaxTreeNode *right) {
        children.push_back(left);
        children.push_back(right);
    }
};

class MulNode : SyntaxTreeNode {
    virtual int32_t type() const { return MUL_NODE; }
    MulNode(SyntaxTreeNode *left, SyntaxTreeNode *right) {
        children.push_back(left);
        children.push_back(right);
    }
};


class Parser {
    public: Scanner *scanner;
    public: virtual SyntaxTreeNode *parse() = 0;
};

class RecursiveDescentParser : Parser {
    // E -> T + E | T
    // T -> F * T | F
    // F -> ( E ) | number
   SyntaxTreeNode* E() {
      SyntaxTreeNode *t = T();
      if (t != NULL) {
         Token *token = scanner->read();
         if (token->type() == ADD_TOKEN) {
            SyntaxTreeNode *e = E();
            if (e != null) {
                return new AddNode(t,e);
            }
         } else {
            scanner->unread(token);
            return t;
         }
      }
      return NULL;
   }

   SyntaxTreeNode* T() {
      if tokens from scanner match an expression
         return that syntax tree
      else return null;
   }

   SyntaxTreeNode* F() {
      if tokens from scanner match an expression
         return that syntax tree
      else return null;
   }

   parse() { return E(); }
};








// ...



