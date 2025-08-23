#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string search_replace( std::string& content,  std::string& search_string,  std::string& replace_string)
{

    std::string result;
    size_t pos = 0;
    size_t len = search_string.length();

    while (true)
    {
        size_t found = content.find(search_string, pos);
        if (found == std::string::npos)
        {
            result += content.substr(pos);
            break ;
        }
        result += content.substr(pos, found - pos);
        result += replace_string;
        pos = found + len;
    }
    return result;
}


int main (int arc, char *arg[])
{
	if (arc != 4)
	{
		std::cout << "not enough arguments" << "\n";
		return 0;
	}

	std::string file_name = arg[1];
	std::string search_string = arg[2];
	if (search_string.empty())
	{
		std::cout << "search string is empty \n";
		return 0;
	}
	std::string replace_string = arg[3];

	
	std::ifstream MyReadFile(file_name.c_str());
	if (!MyReadFile.is_open())
	{
		std::cout << "failed open file \n";
		return 0;
	}
	std::stringstream buffer;
	buffer << MyReadFile.rdbuf();
	std::string all_file_in_string  = buffer.str();
	MyReadFile.close();



	std::string new_string = search_replace(all_file_in_string, search_string, replace_string);
	std::string new_file_name = file_name + ".replace";
	std::ofstream  cfile(new_file_name.c_str());
	cfile << new_string;
	cfile.close();
	return 0 ;
} 