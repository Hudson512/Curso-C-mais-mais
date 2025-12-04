/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:06:51 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/04 17:17:17 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class BitcoinExchange 
{
    private:
        std::map<time_t, std::string> _db;
        
        float stringToFloat(const std::string &str) const;
        time_t stringToTimeT(const std::string &dateStr) const;
        bool hasExtension(const std::string &filename, const std::string &ext) const;
        float validateAndParseValue(const std::string &valueStr) const;
        int parseLine(const std::string &line, std::string &dateStr, std::string &valueStr) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename);
        void processInputFile(const std::string &filename) const;
        void printDatabase() const;
};

#endif
