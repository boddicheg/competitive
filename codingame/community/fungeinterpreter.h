// https://www.codingame.com/ide/puzzle/cgfunge-interpreter

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cassert>

constexpr const char END = 'E';
constexpr const char INPUT = 'I';
constexpr const char CONVERT = 'C';
constexpr const char SKIP = 'S';

constexpr const char POP = 'P';
constexpr const char SWITCH = 'X';
constexpr const char DUPL = 'D';

constexpr const char STRINGMODE = '"';
constexpr const char SPACE = ' ';
constexpr const char COMMA = ',';
constexpr const char EXCLAM = '!';

constexpr const char ZERO = '0';
constexpr const char NINE = '9';
constexpr const char BIGA = 'A';
constexpr const char BIGZ = 'Z';

typedef std::function<void()> Callback;

inline void LOG(const std::string &str)
{
//    std::cerr << "[Interpreter] " << str << std::endl;
}

class Interpreter
{
public:
    Interpreter()
        : m_string_mode(false)
        , m_x(0)
        , m_y(0)
        , m_direction('>')
        , m_skip_next(false)
    {
        for (char i = ZERO; i <= NINE; i++)
        {
            auto state = std::make_pair(i, [ &, i] ()
            {
                int code = (int)i - (int)ZERO;
                LOG("Push to stack integer value " + std::to_string(code));
                m_numbers.push(code);
            });
            m_states.insert(state);
        }

        for (char i = BIGA; i <= BIGZ; i++)
        {
            m_states.insert(std::make_pair(i, [this, i] ()
            {
                if (m_string_mode)
                {
                    LOG("Push to stack char value " + std::to_string((char)i));
                    m_numbers.push((int)i);
                }
            }));

            m_states.insert(std::make_pair((char)((int) i + 32), [this, i] ()
            {
                if (m_string_mode)
                {
                    LOG("Push to stack char value " + std::to_string((char)i));
                    m_numbers.push((int)i + 32);
                }
            }));
        }

        m_states.insert(std::make_pair(SPACE,  [this] ()
        {

            if (m_string_mode)
            {
                LOG("Push space to stack");
                m_numbers.push((int) SPACE);
            }
        }));

        m_states.insert(std::make_pair(COMMA,  [this] ()
        {

            if (m_string_mode)
            {
                LOG("Push comma to stack");
                m_numbers.push((int) COMMA);
            }
        }));

        m_states.insert(std::make_pair(EXCLAM,  [this] ()
        {

            if (m_string_mode)
            {
                LOG("Push ! to stack");
                m_numbers.push((int) EXCLAM);
            }
        }));

        // Operators
        // +
        m_states.insert(std::make_pair('+',  [&] ()
        {
            int first = m_numbers.top();
            m_numbers.pop();
            int second = m_numbers.top();
            m_numbers.pop();
            LOG("Push to stack: " + std::to_string(first) + " + " + std::to_string(second));
            m_numbers.push(second + first);
        }));
        // -
        m_states.insert(std::make_pair('-',  [&] ()
        {
            int first = m_numbers.top();
            m_numbers.pop();
            int second = m_numbers.top();
            m_numbers.pop();
            LOG("Push to stack: " + std::to_string(first) + " - " + std::to_string(second));
            m_numbers.push(second - first);
        }));
        // *
        m_states.insert(std::make_pair('*',  [&] ()
        {
            int first = m_numbers.top();
            m_numbers.pop();
            int second = m_numbers.top();
            m_numbers.pop();
            LOG("Push to stack: " + std::to_string(first) + " * " + std::to_string(second));
            m_numbers.push(second * first);
        }));
    }

    void ProcessingDirection(char input)
    {
        if (input == '>')
        {
            m_x++;
            m_direction = '>';
        }

        if (input == '<')
        {
            m_x--;
            m_direction = '<';
        }

        if (input == '^')
        {
            m_y--;
            m_direction = '^';
        }

        if (input == 'v')
        {
            m_y++;
            m_direction = 'v';
        }

        if (input == '|')
        {
            auto top = m_numbers.top();
            m_numbers.pop();

            if (top == 0)
            {
                m_y++;
                m_direction = 'v';
            }
            else
            {
                m_direction = '^';
                m_y--;
            }
        }

        if (input == '_')
        {
            auto top = m_numbers.top();
            m_numbers.pop();
            if (top == 0)
            {
                m_direction = '>';
                m_x++;
            }
            else
            {
                m_direction = '<';
                m_x--;
            }
        }
    }

    bool IsDirectionSymbol(char s)
    {
        return s == '>' ||
               s == '<' ||
               s == '^' ||
               (s == 'v' && !m_string_mode) ||
               s == '|' ||
               s == '_';
    }

    std::string Calculate(const std::vector<std::string> &board)
    {
        char input = END;
        std::string result;
        do
        {
            input = board.at(m_y).at(m_x);

            if (m_skip_next)
            {
                m_skip_next = false;
                ProcessingDirection(m_direction);
                continue;
            }

            if (IsDirectionSymbol(input))
            {
                ProcessingDirection(input);
                continue;
            }
            else
            {
                // Processing " symbol - string mode.
                // When in string mode, the ASCII codes for all
                // characters encountered are pushed onto the stack.
                if (input == STRINGMODE)
                    m_string_mode = !m_string_mode;

                if (!m_string_mode)
                {
                    // Processing 'P' - Pop the top value
                    if (input == POP)
                        m_numbers.pop();
                    // Processing 'X' - Switch the order of the top two stack values
                    if (input == SWITCH)
                    {
                        int first = m_numbers.top();
                        m_numbers.pop();
                        int second = m_numbers.top();
                        m_numbers.pop();
                        m_numbers.push(first);
                        m_numbers.push(second);
                    }
                    // Processing 'D' - Push a duplicate of the top value onto the stack
                    if (input == DUPL)
                    {
                        int first = m_numbers.top();
                        m_numbers.push(first);
                    }
                    // Processing 'S' - Skip the next character and continue with the subsequent character
                    if (input == SKIP)
                        m_skip_next = true;

                    // Processing 'I' - Pop the top integer from the stack and print it to stdout.
                    if (input == INPUT)
                    {
                        result += std::to_string(m_numbers.top());
                        m_numbers.pop();
                    }
                    // Processing 'C' - Pop the top integer from the stack and interpret it as an ASCII code,
                    // printing the corresponding character to stdout.
                    if (input == CONVERT)
                    {
                        result += (char) m_numbers.top();
                        m_numbers.pop();
                    }
                    // Processing 'E' symbol - End the program immediately
                    if (input == END)
                        return result;
                }
                // Processing states
                Check(input);
                ProcessingDirection(m_direction);
            }
        }
        while (true);

        return "fail";
    }

private:
    std::stack<int> m_numbers;
    std::map<char, Callback> m_states;
    bool m_string_mode;
    int m_x;
    int m_y;
    int m_direction;
    int m_skip_next;

private:
    void Check(char symbol)
    {
        auto it = m_states.find(symbol);
        if (it != m_states.end())
            ((*it).second) ();
    }
};

#define PRODUCTION

//#define EXAMPLE1
//#define EXAMPLE1_1
//#define EXAMPLE2
//#define EXAMPLE3
//#define EXAMPLE3_1
//#define EXAMPLE5
//#define EXAMPLE6
//#define EXAMPLE7

int main()
{
    std::vector<std::string> lines;
    Interpreter e;

    std::string expected;

#ifdef PRODUCTION
    int N;
    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        std::string line;
        std::getline(std::cin, line);
        std::cerr << "|" << line << "|" << std::endl;
        lines.push_back(line);
    }
#endif

#ifdef EXAMPLE1
    lines.push_back("2419+*+IE"); // 42
    expected = "42";
#endif

#ifdef EXAMPLE1_1
    lines.push_back("\"tset\"CCCCE");
    expected = "test";
#endif

#ifdef EXAMPLE2
    lines.push_back("\"txet elpmiS\"CCCCCCCCCCCE");
    expected = "Simple text";
#endif

#ifdef EXAMPLE3
    lines.push_back(">>v");
    lines.push_back("v4<");
    lines.push_back(">Iv");
    lines.push_back("E<<");
    expected = "4";
#endif

#ifdef EXAMPLE3_1
    lines.push_back("v > v");
    lines.push_back("  C \"");
    lines.push_back(" vC GS<");
    lines.push_back("> \"GC\"^");
    lines.push_back("  C \"");
    lines.push_back("  G C");
    lines.push_back(" C\" C");
    lines.push_back(" >^ E");
    //"GC"SG CC"GC"CC"GC"CCE
    expected = "CGCGCG";
#endif

#ifdef EXAMPLE5
    lines.push_back("39DD1+*+DI  >11091+   v>v");
    lines.push_back(" v  \" on the wall\"    < D ");
    lines.push_back(">>     \"reeb fo\"      v S");
    lines.push_back("0v<\" bottles \"        < C");
    lines.push_back("X>DSC_SvPD      _25*+Cv |");
    lines.push_back("       *v   IS        < P");
    lines.push_back("^IDX-1 <>  SC        0v X");
    lines.push_back("v   \"pass it around\"  < 1");
    lines.push_back(">    \" ,nwod eno ekat\" ^-");
    lines.push_back(" Sing it!   ^+55D-1X_ESD<");
    expected = "99 bottles of beer on the wall\n99 bottles of beer\ntake one down, pass it around";
#endif

#ifdef EXAMPLE6
    lines.push_back(">22-_Sv2IE");
    lines.push_back("EC 1  <   ");
    expected = "2";
#endif

#ifdef EXAMPLE7
    lines.push_back("                v Go down!");
    lines.push_back("Skip next line  S");
    lines.push_back("Short line");
    lines.push_back("Finish here --> > \"!yaY\" CCCCE");
    expected = "Yay!";
#endif

    size_t max = 0;
    for (const auto &l : lines)
    {
        if (l.size() > max)
            max = l.size();
    }

    for (auto &l : lines)
    {
        size_t diff = max - l.size();
        if (diff > 0)
        {
            for (size_t i = 0; i < diff; ++i)
                l += " ";
        }
    }

    std::string result = e.Calculate(lines);
    std::cout << result << std::endl;
}
