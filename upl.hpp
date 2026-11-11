#pragma once
#include <iostream>

using string = std::string; // shortened std::string
using costr = const std::string; // const string
using cstring = const char *; // cstring
using colour = const char *; // cstring but used for colours
using textdata = const char *; // even more type bullshi-

namespace Colour {
    // Cant forget the useful stuff

    // Foreground colours
    constexpr colour Black     = "\033[30m";
    constexpr colour Green     = "\033[32m";
    constexpr colour Blue      = "\033[34m";
    constexpr colour Red       = "\033[31m";
    constexpr colour Yellow    = "\033[33m";
    constexpr colour Violet    = "\033[35m";
    constexpr colour Brown     = "\033[38;5;94m";
    constexpr colour Orange    = "\033[38;5;208m";
    constexpr colour Pink      = "\033[38;5;213m";
    constexpr colour Cyan      = "\033[36m";
    constexpr colour Maroon    = "\033[38;5;88m";
    constexpr colour Gray      = "\033[90m";
    constexpr colour DarkGray  = "\033[90m";
    constexpr colour White     = "\033[97m";
    constexpr colour DarkBlue  = "\033[38;5;18m";

    // Background colours
    constexpr colour BgBlack     = "\033[40m";
    constexpr colour BgRed       = "\033[41m";
    constexpr colour BgGreen     = "\033[42m";
    constexpr colour BgYellow    = "\033[43m";
    constexpr colour BgBlue      = "\033[44m";
    constexpr colour BgViolet    = "\033[45m";
    constexpr colour BgCyan      = "\033[46m";
    constexpr colour BgWhite     = "\033[47m";

    // Bright background colours
    constexpr colour BgDarkGray  = "\033[100m";
    constexpr colour BgBrightRed = "\033[101m";
    constexpr colour BgBrightGreen = "\033[102m";
    constexpr colour BgBrightYellow = "\033[103m";
    constexpr colour BgBrightBlue = "\033[104m";
    constexpr colour BgBrightViolet = "\033[105m";
    constexpr colour BgBrightCyan = "\033[106m";
    constexpr colour BgBrightWhite = "\033[107m";

    // 256-colour backgrounds
    constexpr colour BgBrown   = "\033[48;5;94m";
    constexpr colour BgOrange  = "\033[48;5;208m";
    constexpr colour BgPink    = "\033[48;5;213m";
    constexpr colour BgMaroon  = "\033[48;5;88m";
    constexpr colour BgDarkBlue = "\033[48;5;18m";

    inline std::string RGB(int r, int g, int b) {
        return "\033[38;2;" + std::to_string(r) + ";" +
               std::to_string(g) + ";" + std::to_string(b) + "m";
    }

    inline std::string BgRGB(int r, int g, int b) {
        return "\033[48;2;" + std::to_string(r) + ";" +
               std::to_string(g) + ";" + std::to_string(b) + "m";
    }
}

namespace Control {
  constexpr textdata Clear = "\033[2J";
  constexpr textdata CursorHome = "\033[H";
  constexpr textdata ClearScreen = "\033[2J\033[H";
  constexpr textdata Open = "\033[";
  constexpr textdata Close = "m";
  constexpr textdata ColourReset = "\033[0m";
  constexpr textdata Foreground = "38;2;";
  constexpr textdata Background = "48;2;";
  constexpr textdata CursorHide = "\033[?25l";
  constexpr textdata CursorShow = "\033[?25h";
}

class Text {
  public:
  Text(colour c, string t) : clr(c), text(t) {}
  string clr;
  string text;
};

class Console {
  string __c_col;
  public:
  Console(){}
  ~Console()
  {
    std::cout << Control::CursorShow << Control::ColourReset;
  }

  inline void write(costr s) {
    std::cout << s;
  }

  inline void writeln(costr s) {
    std::cout << s << "\n";
  }

  inline void flush() {
    std::cout << std::flush;
  }

  void setcolour(colour c) {
    __c_col = c;
  }

  void applycolour() {
    printf("%s", __c_col.c_str());
  }

  void makecolour(colour c) {
    setcolour(c);
    applycolour();
  }

  void textwrite(const Text &t) {
    std::cout << t.clr << t.text << Colour::White;
  }

  void textwriteln(const Text &t) {
    std::cout << t.clr << t.text << '\n' << Colour::White;
  }

  void clear() {
    printf("\033[2J");
  }
};