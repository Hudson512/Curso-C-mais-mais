/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:01:39 by hmateque          #+#    #+#             */
/*   Updated: 2025/12/04 18:15:33 by hmateque         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    (void)argv;
    std::string dbFile = "./data.csv";
    BitcoinExchange btc;

    btc.loadDatabase(dbFile);
    btc.processInputFile(argv[1]);
    //btc.printDatabase();

    return 0;
}
