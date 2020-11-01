class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
public:
    friend void Window_mgr::clear(ScreenIndex);

    using pos = std::string::size_type;
    
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}
    Screen(pos ht, pos wd) : Screen(ht, wd, 'X') {}
    Screen() : Screen(24, 80, 'X') {}

    char get() const {return content[cursor];};
    char get(pos r, pos c) const {return content[r * width + c];};
    Screen &move(pos r, pos c);
    Screen &set(char cj);
    Screen &set(pos r, pos c, char ch);
    Screen &display(std::ostream&);
    const Screen &display(std::ostream&) const;

private:
    void do_display(std::ostream &os) const {os << content;};
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string content = "";
};

inline
void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.content = std::string(s.height * s.width, ' ');
}

inline
Screen &Screen::move(pos r, pos c){
    cursor = r * width + c;
    return *this;
}

inline
Screen &Screen::set(char ch){
    content[cursor] = ch;
    return *this;
}

inline
Screen &Screen::set(pos r, pos c, char ch){
    content[r * width + c] = ch;
    return *this;
}

inline
Screen &Screen::display(std::ostream& os){
    do_display(os);
    return *this;
}

inline
const Screen &Screen::display(std::ostream& os) const {
    do_display(os);
    return *this;
}