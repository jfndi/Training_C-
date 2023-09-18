#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

/*
 * A simple HTML string validator. 
 */

using namespace std;

const string test_string{ "<div><p>Blabla</div>" };

int main()
{
    vector<string> tags{};
    vector<string> values{};

    string extract = test_string;

    while (extract.length())
    {
        string tag{};
        if (extract[0] == '<')
        {
            if (extract[1] != '/')
            {
                /*
                *  Starting tag.
                 */
                auto off = extract.find_first_of('>', 1);
                if (off != string::npos)
                {
                    tag = extract.substr(1, off - 1);
                    extract = extract.substr(off + 1);
                    tags.push_back(tag);
                }
                else
                {
                    cout << "Invalid format.\n";
                    return EXIT_FAILURE;
                }
            }
            else
            {
                /*
                * This is a closing tag.
                 */
                auto off = extract.find_first_of('>', 1);
                if (off == string::npos)
                {
                    cout << "Invalid format.\n";
                    return EXIT_FAILURE;
                }
                tag = extract.substr(2, off - 2);
                extract = extract.substr(off + 1);
                if (tag != tags.back())
                {
                    cout << "Invalid format.\n";
                    return EXIT_FAILURE;
                }
                tags.pop_back();
            }
        }
        else
        {
            /*
            * It is a value.
             */
            auto off = extract.find_first_of('<', 1);
            if (off == string::npos)
            {
                cout << "Invalid format.\n";
                return EXIT_FAILURE;
            }
            auto value = extract.substr(0, off);
            cout << "Value: " << value << endl;
            extract = extract.substr(off);
            values.push_back(value);
        }
    }

    return EXIT_SUCCESS;
}
