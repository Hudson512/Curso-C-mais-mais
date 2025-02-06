/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:48:27 by hmateque          #+#    #+#             */
/*   Updated: 2025/02/03 14:03:21 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"
#include <fstream>

std::string replace_all(const std::string &str, const std::string &from, const std::string &to)
{
    if (from.empty()) return str;

    std::string result = str;
    size_t pos = 0;

    while ((pos = result.find(from, pos)) != std::string::npos)
    {
        result.erase(pos, from.length());
        result.insert(pos, to);
        pos += to.length();
    }
    return (result);
}



int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.empty() || s2.empty())
    {
        std::cout << "Error: Empty strings" << std::endl;
        return 1;
    }
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: File not found" << std::endl;
        return 1;
    }
    std::ofstream file_replace((filename + ".replace").c_str());
    if (!file_replace.is_open())
    {
        std::cout << "Error: File not created" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = replace_all(line, s1, s2);
            pos += s2.length();
        }
        file_replace << line << std::endl;
    }
    file.close();
    file_replace.close();
    return 0;
}

