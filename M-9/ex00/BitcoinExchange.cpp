/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:25:50 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/06 10:42:40 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other)
        _db = other._db;
    return *this;
}

// Load CSV database
void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }
    // verify extension
    if (!hasExtension(filename, "csv"))
    {
        file.close();
        std::cerr << "Error: invalid database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        time_t date;

        std::string dateStr, priceStr;
        if (std::getline(ss, dateStr, ',') && std::getline(ss, priceStr))
        {
            struct tm tm = {};
            strptime(dateStr.c_str(), "%Y-%m-%d", &tm);
            date = mktime(&tm);
            _db[date] = priceStr;
        }
    }
}

// process input file
void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    if (!hasExtension(filename, "txt"))
    {
        file.close();
        std::cerr << "Error: invalid input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {

        std::string dateStr;
        std::string valueStr;
        time_t inputDate;

        // Parse line
        if (parseLine(line, dateStr, valueStr) != 0)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Convert date string to time_t
        try
        {
            inputDate = stringToTimeT(dateStr);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }

        // Convert value string to float
        float value;
        try
        {
            value = validateAndParseValue(valueStr);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        
        // Encontrar a taxa de câmbio mais próxima
        std::map<time_t, std::string>::const_iterator it = _db.lower_bound(inputDate);
        if (it == _db.begin() && it->first != inputDate)
        {
            std::cerr << "Error: no earlier date available for " << dateStr << std::endl;
            continue;
        }
        if (it == _db.end() || it->first != inputDate)
            --it;
        float rate = stringToFloat(it->second);

        // Calcular o valor em Bitcoin
        float bitcoinValue = value * rate;
        std::cout << dateStr << " => " << value << " => " << bitcoinValue << std::endl;
    }
}

/*
    Functions helpers
*/

// Parse line into date and value
int BitcoinExchange::parseLine(const std::string &line, std::string &dateStr, std::string &valueStr) const
{
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos ||
        pipePos == 0 || pipePos == line.length() - 3)
    {
        return -1;
    }

    dateStr = line.substr(0, pipePos);
    valueStr = line.substr(pipePos + 3);
    return 0;
}


// Validate and parse value
float BitcoinExchange::validateAndParseValue(const std::string &valueStr) const
{
    if (valueStr.empty()) {
        throw std::invalid_argument("Error: empty value.");
    }

    char *end;
    float value = strtof(valueStr.c_str(), &end);
    
    if (*end != '\0') {
        throw std::invalid_argument("Error: invalid value format => " + valueStr);
    }
    if (value < 0) {
        throw std::invalid_argument("Error: not a positive number.");
    }
    if (value > 1000) {
        throw std::invalid_argument("Error: too large a number.");
    }

    return value;
}

// Print database (for debugging)
void BitcoinExchange::printDatabase() const
{
    std::map<time_t, std::string>::const_iterator it = _db.begin();

    for ( ;it != _db.end(); ++it) 
    {
        struct tm *tm = localtime(&it->first);
        char dateStr[11];
        strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", tm);
        std::cout << dateStr << " => " << it->second << std::endl;
        //std::cout << dateStr << " => " << it->second << " => double: " << stringToDouble(it->second) << std::endl;
    }
}

// Convert string to double
float BitcoinExchange::stringToFloat(const std::string &str) const
{
    char *end;
    float value = strtof(str.c_str(), &end);
    if (*end != '\0') {
        throw std::invalid_argument("Invalid float format: " + str);
    }
    return value;
}

// Convert string to time_t
time_t BitcoinExchange::stringToTimeT(const std::string &dateStr) const
{
    if (dateStr.length() != 10)
    {
        throw std::invalid_argument("Error: Invalid date format (must be YYYY-MM-DD): " + dateStr);
    }

    struct tm tm = {};
    
    char *dateEnd = strptime(dateStr.c_str(), "%Y-%m-%d", &tm);
    if (dateEnd == 0 || *dateEnd != '\0')
    {
        throw std::invalid_argument("Error: Invalid date format: " + dateStr);
    }
    
    int original_day = tm.tm_mday;
    int original_month = tm.tm_mon;

    time_t raw_time = mktime(&tm);
    if (raw_time == -1)
    {
        throw std::invalid_argument("Error: Date out of range or unrepresentable: " + dateStr);
    }

    struct tm *normalized_tm = localtime(&raw_time);
    if (normalized_tm->tm_mday != original_day || normalized_tm->tm_mon != original_month)
    {
        throw std::invalid_argument("Error: Invalid date: " + dateStr);
    }
    return raw_time;
}

// check extension
bool BitcoinExchange::hasExtension(const std::string &filename, const std::string &ext) const {
    size_t pos = filename.find_last_of(".");
    if (pos == std::string::npos) return false;
    return filename.substr(pos + 1) == ext || filename.substr(pos + 1) == "csv";
}

