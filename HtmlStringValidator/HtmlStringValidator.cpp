#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

/*
 * A simple HTML string validator. 
 */

using namespace std;

const string test_string{ "<div><p>Blabla</div>" };

string ValidateHTMLElement(string str)
{
    vector<string> tags{};
    vector<string> values{};

    string extract = str;

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
                    if (tags.size())
                        return tags.back();
                    else
                        return "";
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
                    if (tags.size())
                        return tags.back();
                    else
                        return "";
                }
                tag = extract.substr(2, off - 2);
                extract = extract.substr(off + 1);
                if (tags.size() && (tag != tags.back()))
                    return tags.back();
                else
                    return "";
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
                return "";

            auto value = extract.substr(0, off);
            extract = extract.substr(off);
            values.push_back(value);
        }
    }

    if (values.size())
        return values.back();
    else
        return "";
}

int main()
{
    string result{};

    result = ValidateHTMLElement(test_string);

    return EXIT_SUCCESS;
}
